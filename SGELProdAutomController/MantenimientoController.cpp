#include "MantenimientoController.h"

namespace SGELProdAutomController {
    using namespace System::Text;

    // Constructor
    MantenimientoController::MantenimientoController() {
        this->listaMantenimientos = gcnew List<Mantenimiento^>();
    }

    // =====================================================================
    // OPERACIONES TRANSACCIONALES PRINCIPALES
    // =====================================================================

    /// <summary>
    /// Registra un mantenimiento completo (cabecera + detalles) en la base de datos
    /// Utiliza una transacción para asegurar la integridad de los datos
    /// </summary>
    int MantenimientoController::RegistrarMantenimientoCompleto(Mantenimiento^ mantenimiento) {
        if (mantenimiento == nullptr) {
            Console::WriteLine("Error: El mantenimiento es nulo.");
            return 0;
        }

        try {
            int mantenimientoId = AgregarMantenimiento(mantenimiento);
            if (mantenimientoId <= 0) {
                Console::WriteLine("No se pudo crear la cabecera de inspección");
                return false;
            }

            // 2. Persistir detalles
            for each (MantenimientoDetalle^ detalle in mantenimiento->getListaMantenimientoDetalle()) {
                detalle->setMantenimientoId(mantenimientoId);
                if (!AgregarDetalleMantenimiento(detalle)) {
                    Console::WriteLine("Error al guardar los detalles de inspección");
                    return false;
                }
            }

            // 3. Actualizar objeto local
            mantenimiento->setMantenimientoId(mantenimientoId);
            this->listaMantenimientos->Add(mantenimiento);

            return mantenimientoId; //true
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al registrar mantenimiento: " + ex->Message);
            cerrarConexion();
            return 0;
        }
    }

    /// <summary>
    /// Insertar un mantenimiento 
    /// </summary>
    int MantenimientoController::AgregarMantenimiento(Mantenimiento^ mantenimiento) {
        try {
            array<SqlParameter^>^ parameters = gcnew array<SqlParameter^> {
                gcnew SqlParameter("@RobotId", mantenimiento->getRobotId()), //parameters[0]
                    gcnew SqlParameter("@Tecnico", mantenimiento->getTecnico()), //parameters[1]
                    gcnew SqlParameter("@TipoMantenimiento", mantenimiento->getTipoMantenimiento()), //parameters[2]
                    gcnew SqlParameter("@MantenimientoId", SqlDbType::Int) //parameters[3]
            };
            // Configurar el parámetro OUTPUT
            parameters[3]->Direction = ParameterDirection::Output;

            BaseController^ controller = gcnew BaseController();
            int inspectionId = controller->executeStoredProcedureWithOutput("usp_CreateMantenimiento", parameters, "@MantenimientoId");

            return inspectionId;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error en AgregarMantenimiento: " + ex->Message);
            return 0;
        }
    }


    /// DML
    /*
    int MantenimientoController::RegistrarMantenimientoCompleto(Mantenimiento^ mantenimiento) {
        if (mantenimiento == nullptr) {
            Console::WriteLine("Error: El mantenimiento es nulo.");
            return 0;
        }

        try {
            // Iniciar transacción
            abrirConexion();
            SqlTransaction^ transaccion = this->getObjConexion()->BeginTransaction();

            // ---- PASO 1: Insertar la cabecera del mantenimiento ----
            String^ sqlCabecera = String::Format(
                "INSERT INTO Mantenimiento (RobotId, Tecnico, TipoMantenimiento, FechaMantenimiento) " +
                "VALUES ({0}, '{1}', '{2}', '{3}'); " +
                "SELECT SCOPE_IDENTITY();",
                mantenimiento->getRobotId(),
                mantenimiento->getTecnico()->Replace("'", "''"),  // Escapar comillas simples
                mantenimiento->getTipoMantenimiento(),
                mantenimiento->getFechaMantenimiento().ToString("yyyy-MM-dd HH:mm:ss")
            );

            SqlCommand^ cmdCabecera = gcnew SqlCommand(sqlCabecera, this->getObjConexion(), transaccion);
            int mantenimientoId = Convert::ToInt32(cmdCabecera->ExecuteScalar());

            // ---- PASO 2: Insertar los detalles del mantenimiento ----
            if (mantenimiento->getActividades()->Count > 0) {
                for each (MantenimientoDetalle ^ detalle in mantenimiento->getActividades()) {
                    String^ sqlDetalle = String::Format(
                        "INSERT INTO MantenimientoDetalle (MantenimientoId, Actividad, DuracionMinutos) " +
                        "VALUES ({0}, '{1}', {2});",
                        mantenimientoId,
                        detalle->getActividad()->Replace("'", "''"),
                        detalle->getDuracionMinutos()
                    );

                    SqlCommand^ cmdDetalle = gcnew SqlCommand(sqlDetalle, this->getObjConexion(), transaccion);
                    cmdDetalle->ExecuteNonQuery();
                }
            }

            // Confirmar la transacción
            transaccion->Commit();
            cerrarConexion();

            // Actualizar el objeto con el ID generado
            mantenimiento->setMantenimientoId(mantenimientoId);
            Console::WriteLine("Mantenimiento registrado exitosamente. ID: {0}", mantenimientoId);

            return mantenimientoId;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al registrar mantenimiento: " + ex->Message);
            cerrarConexion();
            return 0;
        }
    }
    */

    /// <summary>
    /// Actualiza un mantenimiento completo (cabecera + detalles)
    /// </summary>
    bool MantenimientoController::ActualizarMantenimientoCompleto(Mantenimiento^ mantenimiento) {
        if (mantenimiento == nullptr || mantenimiento->getMantenimientoId() == 0) {
            Console::WriteLine("Error: Mantenimiento inválido para actualizar.");
            return false;
        }

        try {
            // Iniciar transacción
            abrirConexion();
            SqlTransaction^ transaccion = this->getObjConexion()->BeginTransaction();

            // ---- PASO 1: Actualizar la cabecera ----
            String^ sqlCabecera = String::Format(
                "UPDATE Mantenimiento SET " +
                "RobotId = {0}, " +
                "Tecnico = '{1}', " +
                "TipoMantenimiento = '{2}', " +
                "FechaMantenimiento = '{3}' " +
                "WHERE MantenimientoId = {4}",
                mantenimiento->getRobotId(),
                mantenimiento->getTecnico()->Replace("'", "''"),
                mantenimiento->getTipoMantenimiento(),
                mantenimiento->getFechaMantenimiento().ToString("yyyy-MM-dd HH:mm:ss"),
                mantenimiento->getMantenimientoId()
            );

            SqlCommand^ cmdCabecera = gcnew SqlCommand(sqlCabecera, this->getObjConexion(), transaccion);
            cmdCabecera->ExecuteNonQuery();

            // ---- PASO 2: Eliminar los detalles antiguos ----
            String^ sqlDeleteDetalles = String::Format(
                "DELETE FROM MantenimientoDetalle WHERE MantenimientoId = {0}",
                mantenimiento->getMantenimientoId()
            );
            SqlCommand^ cmdDelete = gcnew SqlCommand(sqlDeleteDetalles, this->getObjConexion(), transaccion);
            cmdDelete->ExecuteNonQuery();

            // ---- PASO 3: Insertar los nuevos detalles ----
            if (mantenimiento->getListaMantenimientoDetalle()->Count > 0) {
                for each (MantenimientoDetalle ^ detalle in mantenimiento->getListaMantenimientoDetalle()) {
                    String^ sqlDetalle = String::Format(
                        "INSERT INTO MantenimientoDetalle (MantenimientoId, Actividad, DuracionMinutos) " +
                        "VALUES ({0}, '{1}', {2});",
                        mantenimiento->getMantenimientoId(),
                        detalle->getActividad()->Replace("'", "''"),
                        detalle->getDuracionMinutos()
                    );

                    SqlCommand^ cmdDetalle = gcnew SqlCommand(sqlDetalle, this->getObjConexion(), transaccion);
                    cmdDetalle->ExecuteNonQuery();
                }
            }

            // Confirmar la transacción
            transaccion->Commit();
            cerrarConexion();

            Console::WriteLine("Mantenimiento actualizado exitosamente. ID: {0}", mantenimiento->getMantenimientoId());
            return true;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al actualizar mantenimiento: " + ex->Message);
            cerrarConexion();
            return false;
        }
    }

    /// <summary>
    /// Elimina un mantenimiento y todos sus detalles asociados
    /// </summary>
    bool MantenimientoController::EliminarMantenimiento(int mantenimientoId) {
        if (mantenimientoId <= 0) {
            Console::WriteLine("Error: ID de mantenimiento inválido.");
            return false;
        }

        try {
            // Verificar si el mantenimiento existe
            Mantenimiento^ existente = ConsultarMantenimientoPorId(mantenimientoId);
            if (existente == nullptr) {
                Console::WriteLine("Error: No existe mantenimiento con ID {0}", mantenimientoId);
                return false;
            }

            // Iniciar transacción
            abrirConexion();
            SqlTransaction^ transaccion = this->getObjConexion()->BeginTransaction();

            // ---- PASO 1: Eliminar los detalles ----
            String^ sqlDeleteDetalles = String::Format(
                "DELETE FROM MantenimientoDetalle WHERE MantenimientoId = {0}",
                mantenimientoId
            );
            SqlCommand^ cmdDetalles = gcnew SqlCommand(sqlDeleteDetalles, this->getObjConexion(), transaccion);
            cmdDetalles->ExecuteNonQuery();

            // ---- PASO 2: Eliminar la cabecera ----
            String^ sqlDeleteCabecera = String::Format(
                "DELETE FROM Mantenimiento WHERE MantenimientoId = {0}",
                mantenimientoId
            );
            SqlCommand^ cmdCabecera = gcnew SqlCommand(sqlDeleteCabecera, this->getObjConexion(), transaccion);
            cmdCabecera->ExecuteNonQuery();

            // Confirmar la transacción
            transaccion->Commit();
            cerrarConexion();

            Console::WriteLine("Mantenimiento ID {0} eliminado exitosamente.", mantenimientoId);
            return true;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al eliminar mantenimiento: " + ex->Message);
            cerrarConexion();
            return false;
        }
    }

    // =====================================================================
    // OPERACIONES DE CONSULTA (READ)
    // =====================================================================

    /// <summary>
    /// Obtiene un mantenimiento con todos sus detalles por ID
    /// </summary>
    Mantenimiento^ MantenimientoController::ConsultarMantenimientoPorId(int mantenimientoId) {
        if (mantenimientoId <= 0) {
            Console::WriteLine("Error: ID de mantenimiento inválido.");
            return nullptr;
        }

        try {
            abrirConexion();

            // ---- Consultar cabecera ----
            String^ sqlCabecera = String::Format(
                "SELECT * FROM Mantenimiento WHERE MantenimientoId = {0}",
                mantenimientoId
            );
            SqlCommand^ cmdCabecera = gcnew SqlCommand(sqlCabecera, this->getObjConexion());
            SqlDataReader^ readerCabecera = cmdCabecera->ExecuteReader();

            Mantenimiento^ resultado = nullptr;

            if (readerCabecera->Read()) {
                resultado = gcnew Mantenimiento(
                    Convert::ToInt32(readerCabecera["MantenimientoId"]),
                    Convert::ToInt32(readerCabecera["RobotId"]),
                    readerCabecera["Tecnico"]->ToString(),
                    readerCabecera["TipoMantenimiento"]->ToString(),
                    Convert::ToDateTime(readerCabecera["FechaMantenimiento"])
                );
            }
            readerCabecera->Close();

            // ---- Consultar detalles ----
            if (resultado != nullptr) {
                String^ sqlDetalles = String::Format(
                    "SELECT * FROM MantenimientoDetalle WHERE MantenimientoId = {0} ORDER BY MantenimientoDetailId",
                    mantenimientoId
                );
                SqlCommand^ cmdDetalles = gcnew SqlCommand(sqlDetalles, this->getObjConexion());
                SqlDataReader^ readerDetalles = cmdDetalles->ExecuteReader();

                while (readerDetalles->Read()) {
                    MantenimientoDetalle^ detalle = gcnew MantenimientoDetalle(
                        Convert::ToInt32(readerDetalles["MantenimientoDetailId"]),
                        Convert::ToInt32(readerDetalles["MantenimientoId"]),
                        readerDetalles["Actividad"]->ToString(),
                        Convert::ToInt32(readerDetalles["DuracionMinutos"])
                    );
                    resultado->AgregarMantenimientoDetalle(detalle);
                }
                readerDetalles->Close();
            }

            cerrarConexion();
            return resultado;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar mantenimiento: " + ex->Message);
            cerrarConexion();
            return nullptr;
        }
    }

    /// <summary>
    /// Obtiene todos los mantenimientos de un robot específico
    /// </summary>
    List<Mantenimiento^>^ MantenimientoController::ConsultarMantenimientosPorRobot(int robotId) {
        List<Mantenimiento^>^ lista = gcnew List<Mantenimiento^>();

        if (robotId <= 0) {
            Console::WriteLine("Error: ID de robot inválido.");
            return lista;
        }

        try {
            abrirConexion();

            String^ sql = String::Format(
                "SELECT MantenimientoId FROM Mantenimiento WHERE RobotId = {0} ORDER BY FechaMantenimiento DESC",
                robotId
            );
            SqlCommand^ cmd = gcnew SqlCommand(sql, this->getObjConexion());
            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int mantenimientoId = Convert::ToInt32(reader["MantenimientoId"]);
                Mantenimiento^ mant = ConsultarMantenimientoPorId(mantenimientoId);
                if (mant != nullptr) {
                    lista->Add(mant);
                }
            }
            reader->Close();
            cerrarConexion();

            return lista;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar mantenimientos por robot: " + ex->Message);
            cerrarConexion();
            return lista;
        }
    }

    /// <summary>
    /// Obtiene todos los mantenimientos registrados en el sistema
    /// </summary>
    List<Mantenimiento^>^ MantenimientoController::ListarTodosMantenimientos() {
        List<Mantenimiento^>^ lista = gcnew List<Mantenimiento^>();

        try {
            abrirConexion();

            String^ sql = "SELECT MantenimientoId FROM Mantenimiento ORDER BY FechaMantenimiento DESC";
            SqlCommand^ cmd = gcnew SqlCommand(sql, this->getObjConexion());
            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int mantenimientoId = Convert::ToInt32(reader["MantenimientoId"]);
                Mantenimiento^ mant = ConsultarMantenimientoPorId(mantenimientoId);
                if (mant != nullptr) {
                    lista->Add(mant);
                }
            }
            reader->Close();
            cerrarConexion();

            return lista;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al listar mantenimientos: " + ex->Message);
            cerrarConexion();
            return lista;
        }
    }

    /// <summary>
    /// Obtiene mantenimientos por tipo (Preventivo, Correctivo)
    /// </summary>
    List<Mantenimiento^>^ MantenimientoController::ConsultarMantenimientosPorTipo(String^ tipoMantenimiento) {
        List<Mantenimiento^>^ lista = gcnew List<Mantenimiento^>();

        if (String::IsNullOrEmpty(tipoMantenimiento)) {
            Console::WriteLine("Error: Tipo de mantenimiento vacío.");
            return lista;
        }

        try {
            abrirConexion();

            String^ sql = String::Format(
                "SELECT MantenimientoId FROM Mantenimiento WHERE TipoMantenimiento = '{0}' ORDER BY FechaMantenimiento DESC",
                tipoMantenimiento->Replace("'", "''")
            );
            SqlCommand^ cmd = gcnew SqlCommand(sql, this->getObjConexion());
            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int mantenimientoId = Convert::ToInt32(reader["MantenimientoId"]);
                Mantenimiento^ mant = ConsultarMantenimientoPorId(mantenimientoId);
                if (mant != nullptr) {
                    lista->Add(mant);
                }
            }
            reader->Close();
            cerrarConexion();

            return lista;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar mantenimientos por tipo: " + ex->Message);
            cerrarConexion();
            return lista;
        }
    }

    /// <summary>
    /// Obtiene mantenimientos por técnico responsable
    /// </summary>
    List<Mantenimiento^>^ MantenimientoController::ConsultarMantenimientosPorTecnico(String^ tecnico) {
        List<Mantenimiento^>^ lista = gcnew List<Mantenimiento^>();

        if (String::IsNullOrEmpty(tecnico)) {
            Console::WriteLine("Error: Técnico vacío.");
            return lista;
        }

        try {
            abrirConexion();

            String^ sql = String::Format(
                "SELECT MantenimientoId FROM Mantenimiento WHERE Tecnico LIKE '%{0}%' ORDER BY FechaMantenimiento DESC",
                tecnico->Replace("'", "''")
            );
            SqlCommand^ cmd = gcnew SqlCommand(sql, this->getObjConexion());
            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int mantenimientoId = Convert::ToInt32(reader["MantenimientoId"]);
                Mantenimiento^ mant = ConsultarMantenimientoPorId(mantenimientoId);
                if (mant != nullptr) {
                    lista->Add(mant);
                }
            }
            reader->Close();
            cerrarConexion();

            return lista;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar mantenimientos por técnico: " + ex->Message);
            cerrarConexion();
            return lista;
        }
    }

    /// <summary>
    /// Obtiene mantenimientos por rango de fechas
    /// </summary>
    List<Mantenimiento^>^ MantenimientoController::ConsultarMantenimientosPorFecha(DateTime fechaInicio, DateTime fechaFin) {
        List<Mantenimiento^>^ lista = gcnew List<Mantenimiento^>();

        try {
            abrirConexion();

            String^ sql = String::Format(
                "SELECT MantenimientoId FROM Mantenimiento " +
                "WHERE FechaMantenimiento BETWEEN '{0}' AND '{1}' " +
                "ORDER BY FechaMantenimiento DESC",
                fechaInicio.ToString("yyyy-MM-dd HH:mm:ss"),
                fechaFin.ToString("yyyy-MM-dd HH:mm:ss")
            );
            SqlCommand^ cmd = gcnew SqlCommand(sql, this->getObjConexion());
            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                int mantenimientoId = Convert::ToInt32(reader["MantenimientoId"]);
                Mantenimiento^ mant = ConsultarMantenimientoPorId(mantenimientoId);
                if (mant != nullptr) {
                    lista->Add(mant);
                }
            }
            reader->Close();
            cerrarConexion();

            return lista;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar mantenimientos por fecha: " + ex->Message);
            cerrarConexion();
            return lista;
        }
    }

    // =====================================================================
    // OPERACIONES DE DETALLE
    // =====================================================================

    /// <summary>
    /// Agrega un detalle a un mantenimiento existente
    /// </summary>
    bool MantenimientoController::AgregarDetalleMantenimiento(MantenimientoDetalle^ detalle) {
        if (detalle == nullptr) {
            Console::WriteLine("Error: Parámetros inválidos para agregar detalle.");
            return false;
        }
        try {
            array<SqlParameter^>^ parameters = gcnew array<SqlParameter^>{
                gcnew SqlParameter("@MantenimientoId", detalle->getMantenimientoId()),
                    gcnew SqlParameter("@Actividad", detalle->getActividad()),
                    gcnew SqlParameter("@DuracionMinutos", detalle->getDuracionMinutos())
            };

            return executeStoredProcedure("usp_AddMantenimientoDetail", parameters);
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error en AgregarDetalleMantenimiento: " + ex->Message);
            return false;
        }
    }

    /*
    bool MantenimientoController::AgregarDetalleMantenimiento(int mantenimientoId, MantenimientoDetalle^ detalle) {
        if (mantenimientoId <= 0 || detalle == nullptr) {
            Console::WriteLine("Error: Parámetros inválidos para agregar detalle.");
            return false;
        }

        try {
            abrirConexion();

            String^ sql = String::Format(
                "INSERT INTO MantenimientoDetalle (MantenimientoId, Actividad, DuracionMinutos) " +
                "VALUES ({0}, '{1}', {2})",
                mantenimientoId,
                detalle->getActividad()->Replace("'", "''"),
                detalle->getDuracionMinutos()
            );

            bool resultado = executeSql(sql);
            cerrarConexion();

            if (resultado) {
                Console::WriteLine("Detalle agregado exitosamente al mantenimiento {0}", mantenimientoId);
            }
            return resultado;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al agregar detalle: " + ex->Message);
            cerrarConexion();
            return false;
        }
    }*/

    /// <summary>
    /// Elimina un detalle específico de un mantenimiento
    /// </summary>
    bool MantenimientoController::EliminarDetalleMantenimiento(int detalleId) {
        if (detalleId <= 0) {
            Console::WriteLine("Error: ID de detalle inválido.");
            return false;
        }

        try {
            String^ sql = String::Format(
                "DELETE FROM MantenimientoDetalle WHERE MantenimientoDetailId = {0}",
                detalleId
            );

            bool resultado = executeSql(sql);
            if (resultado) {
                Console::WriteLine("Detalle ID {0} eliminado exitosamente.", detalleId);
            }
            return resultado;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al eliminar detalle: " + ex->Message);
            return false;
        }
    }

    /// <summary>
    /// Obtiene todos los detalles de un mantenimiento
    /// </summary>
    List<MantenimientoDetalle^>^ MantenimientoController::ConsultarDetallesPorMantenimiento(int mantenimientoId) {
        List<MantenimientoDetalle^>^ lista = gcnew List<MantenimientoDetalle^>();

        if (mantenimientoId <= 0) {
            Console::WriteLine("Error: ID de mantenimiento inválido.");
            return lista;
        }

        try {
            abrirConexion();

            String^ sql = String::Format(
                "SELECT * FROM MantenimientoDetalle WHERE MantenimientoId = {0} ORDER BY MantenimientoDetailId",
                mantenimientoId
            );
            SqlCommand^ cmd = gcnew SqlCommand(sql, this->getObjConexion());
            SqlDataReader^ reader = cmd->ExecuteReader();

            while (reader->Read()) {
                MantenimientoDetalle^ detalle = gcnew MantenimientoDetalle(
                    Convert::ToInt32(reader["MantenimientoDetailId"]),
                    Convert::ToInt32(reader["MantenimientoId"]),
                    reader["Actividad"]->ToString(),
                    Convert::ToInt32(reader["DuracionMinutos"])
                );
                lista->Add(detalle);
            }
            reader->Close();
            cerrarConexion();

            return lista;
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al consultar detalles: " + ex->Message);
            cerrarConexion();
            return lista;
        }
    }

    // =====================================================================
    // OPERACIONES DE LIMPIEZA Y CIERRE
    // =====================================================================

    /// <summary>
    /// Libera los recursos utilizados por el controlador
    /// </summary>
    void MantenimientoController::Close() {
        try {
            if (this->getObjConexion() != nullptr) {
                if (this->getObjConexion()->State == ConnectionState::Open) {
                    cerrarConexion();
                }
            }
            Console::WriteLine("MantenimientoController liberado correctamente.");
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al liberar MantenimientoController: " + ex->Message);
        }
    }
}