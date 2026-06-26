#include "InspeccionController.h"

namespace SGELProdAutomController {
    using namespace System::Text;

    // Constructor
    InspeccionController::InspeccionController() {
        this->listaInspecciones = gcnew List<Inspeccion^>();
        // BD: Leer desde la base de datos y cargar los datos en la lista
        try {
            // Paso1: Establecer la conexion
            abrirConexion();

            // Paso2: Crear el comando SQL
            String^ sSql = "SELECT InspeccionId, CodigoLote, RobotId, Inspector, FechaInspeccion, ResultadoGeneral ";
            sSql += " FROM Inspeccion ";

            // Paso3: Crear el SqlCommand, donde le paso la sentencia SQL y la conexion
            SqlCommand^ comando = gcnew SqlCommand(sSql, getObjConexion());

            // Paso4: Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT
            // Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader
            SqlDataReader^ objData = comando->ExecuteReader();

            // Paso5: Leer los registros de la tabla
            while (objData->Read()) {
                int InspeccionId = objData->GetInt32(0);            // InspeccionId
                String^ CodigoLote = objData->GetString(1);         // CodigoLote
                int RobotId = objData->GetInt32(2);                 // RobotId
                String^ Inspector = objData->GetString(3);          // Inspector
                DateTime FechaInspeccion = objData->GetDateTime(4); // FechaInspeccion
                String^ ResultadoGeneral = objData->GetString(5);   // ResultadoGeneral

                // Asumiendo que tu clase se llama Inspeccion en lugar de Maquina
                Inspeccion^ inspeccion = gcnew Inspeccion(InspeccionId, CodigoLote, RobotId, Inspector, FechaInspeccion, ResultadoGeneral);
                this->listaInspecciones->Add(inspeccion);
            }

            // Paso6: Cerrar el DataReader y la conexion
            objData->Close();
            cerrarConexion();
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al conectar a la base de datos: " + ex->Message);
            // En caso de cualquier error, crear lista vacía
            this->listaInspecciones = gcnew List<Inspeccion^>();
        }
    }

    List<Inspeccion^>^ InspeccionController::ListarTodos() {
        return this->listaInspecciones;
    }

    // =====================================================================
    // OPERACIONES DE TRANSACCIÓN ATÓMICA COMPLETA
    // =====================================================================

    int InspeccionController::RegistrarInspeccionTransaccional(Inspeccion^ inspeccion) {
        if (inspeccion == nullptr) {
            Console::WriteLine("Error: El inspeccion es nulo.");
            return 0;
        }
        SqlConnection^ connection = nullptr;
        SqlTransaction^ transaction = nullptr;
        int inspeccionId = 0;

        try {
            // 1. Abrir conexión usando el método de BaseController
            this->abrirConexion();
            connection = this->getObjConexion();

            // 2. INICIAR TRANSACCIÓN
            transaction = connection->BeginTransaction();
            Console::WriteLine("Transacción iniciada desde C++/CLI");

            // 3. Insertar cabecera usando el SP existente, pero dentro de la transacción
            inspeccionId = AgregarInspeccionConTransaccion(inspeccion, connection, transaction);
            if (inspeccionId <= 0) {
                throw gcnew Exception("No se pudo crear la cabecera de inspección");
            }
            // 4. Insertar detalles usando el SP existente, dentro de la misma transacción
            for each (InspeccionDetalle ^ detalle in inspeccion->getListaInspeccionesDetalle()) {
                detalle->setInspeccionId(inspeccionId);

                if (!AgregarDetalleInspeccionConTransaccion(detalle, connection, transaction)) {
                    throw gcnew Exception("Error al guardar un detalle de inspección");
                }
            }

            // 5. Si todo fue bien: CONFIRMAR TRANSACCIÓN (COMMIT)
            transaction->Commit();
            Console::WriteLine("Transacción confirmada (COMMIT). Inspección registrada exitosamente.");

            // 6. Actualizar objeto local
            inspeccion->setInspeccionId(inspeccionId);
            this->listaInspecciones->Add(inspeccion);

            return inspeccionId;
        }
        catch (Exception^ ex) {
            // 7. Si algo falla: REVERTIR TRANSACCIÓN (ROLLBACK)
            if (transaction != nullptr) {
                try {
                    transaction->Rollback();
                    Console::WriteLine("Transacción revertida (ROLLBACK) debido a error: " + ex->Message);
                }
                catch (Exception^ rollbackEx) {
                    Console::WriteLine("Error al hacer Rollback: " + rollbackEx->Message);
                }
            }

            Console::WriteLine("Error al registrar inspección: " + ex->Message);
            return 0;
        }
        finally {
            // 8. Cerrar conexión
            if (connection != nullptr && connection->State == ConnectionState::Open) {
                connection->Close();
                Console::WriteLine("Conexión cerrada.");
            }
        }
    }

    /// <summary>
    /// Inserta cabecera usando el SP existente dentro de una transacción
    /// SP: usp_CreateInspeccion (sin modificar)
    /// </summary>
    int InspeccionController::AgregarInspeccionConTransaccion(Inspeccion^ inspeccion, SqlConnection^ connection, SqlTransaction^ transaction) {

        try {
            // Crear comando asociado a la conexión y transacción
            SqlCommand^ cmd = gcnew SqlCommand("usp_CreateInspeccion", connection);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Transaction = transaction;  // ¡CLAVE! Asociar el comando a la transacción

            // Agregar parámetros
            cmd->Parameters->AddWithValue("@CodigoLote", inspeccion->getCodigoLote());
            cmd->Parameters->AddWithValue("@RobotId", inspeccion->getRobotId());
            cmd->Parameters->AddWithValue("@Inspector", inspeccion->getInspector());
            cmd->Parameters->AddWithValue("@FechaInspeccion", inspeccion->getFechaInspeccion());
            cmd->Parameters->AddWithValue("@ResultadoGeneral", inspeccion->getResultadoGeneral());

            // Parámetro de salida para el ID
            SqlParameter^ outputParam = gcnew SqlParameter("@InspeccionId", SqlDbType::Int);
            outputParam->Direction = ParameterDirection::Output;
            cmd->Parameters->Add(outputParam);

            // Ejecutar el SP dentro de la transacción
            cmd->ExecuteNonQuery();

            // Obtener el ID generado
            int inspeccionId = safe_cast<int>(outputParam->Value);
            Console::WriteLine("Cabecera insertada con ID: " + inspeccionId);

            return inspeccionId;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error en AgregarInspeccionConTransaccion: " + ex->Message);
            throw; // Re-lanzar para que la transacción haga Rollback
        }
    }

    /// <summary>
    /// Inserta detalle usando el SP existente dentro de una transacción
    /// SP: usp_AddInspeccionDetail (sin modificar)
    /// </summary>
    bool InspeccionController::AgregarDetalleInspeccionConTransaccion(InspeccionDetalle^ detalle, SqlConnection^ connection, SqlTransaction^ transaction) {
        try {
            // Crear comando asociado a la conexión y transacción
            SqlCommand^ cmd = gcnew SqlCommand("usp_AddInspeccionDetail", connection);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Transaction = transaction;  // ¡CLAVE! Asociar el comando a la transacción

            // Agregar parámetros
            cmd->Parameters->AddWithValue("@InspeccionId", detalle->getInspeccionId());
            cmd->Parameters->AddWithValue("@Parametro", detalle->getParametro());
            cmd->Parameters->AddWithValue("@ResultadoParametro", detalle->getResultadoParametro());
            cmd->Parameters->AddWithValue("@Notas", detalle->getNotas());

            // Ejecutar el SP dentro de la transacción
            int rowsAffected = cmd->ExecuteNonQuery();

            Console::WriteLine("Detalle insertado: " + detalle->getParametro());
            return rowsAffected > 0;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error en AgregarDetalleInspeccionConTransaccion: " + ex->Message);
            throw; // Re-lanzar para que la transacción haga Rollback
        }
    }
}