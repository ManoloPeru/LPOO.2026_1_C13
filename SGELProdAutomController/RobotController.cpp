#include "RobotController.h"
using namespace System::IO;

namespace SGELProdAutomController {
    RobotController::RobotController() {
        // Inicializar el repositorio en memoria
        this->repositorio = gcnew List<UnidadRobotica^>();

        // BD: Leer desde la base de datos y cargar los datos en la lista
        try {
            // Paso1: Establecer la conexion
            abrirConexion();

            // Paso2: Crear el comando SQL
            String^ sSql = "SELECT RobotId, Alias, Ubicacion, Estado, GradosLibertad, HorasTrabajo ";
            sSql += " FROM UnidadRobotica ";

            // Paso3: Crear el SqlCommand, donde le paso la sentencia SQL y la conexion
            SqlCommand^ comando = gcnew SqlCommand(sSql, getObjConexion());

            // Paso4: Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT
            // Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader
            SqlDataReader^ objData = comando->ExecuteReader();

            // Paso5: Leer los registros de la tabla
            while (objData->Read()) {
                int id = objData->GetInt32(0);                    // RobotId
                String^ alias = objData->GetString(1);            // Alias
                String^ ubicacion = objData->GetString(2);        // Ubicacion
                String^ estadoStr = objData->GetString(3);           // Estado
                int gradosLibertad = objData->GetInt32(4);        // GradosLibertad
                double horasTrabajo = objData->GetDouble(5);      // HorasTrabajo

                // Convertir el estado de string a enum
                EstadoOperativo estado = UnidadRobotica::ConvertirEstadoOperativo(estadoStr);

                // Asumiendo que tu clase se llama UnidadRobotica en lugar de Maquina
                UnidadRobotica^ robot = gcnew UnidadRobotica(id, alias, ubicacion, estado, gradosLibertad, horasTrabajo);
                this->repositorio->Add(robot);
            }

            // Paso6: Cerrar el DataReader y la conexion
            objData->Close();
            cerrarConexion();
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al conectar a la base de datos: " + ex->Message);
            // En caso de cualquier error, crear lista vacía
            this->repositorio = gcnew List<UnidadRobotica^>();
        }
    }

    // Implementación de los métodos CRUD y auxiliares:

    bool RobotController::AgregarRobot(UnidadRobotica^ robot) {
        if (!ExisteRobot(robot->getRobotId())) {
            this->repositorio->Add(robot);

            // Preparamos el SQL para Insertar en la Base de Datos
            String^ sSql = "INSERT INTO UnidadRobotica (RobotId, Alias, Ubicacion, Estado, GradosLibertad, HorasTrabajo) ";
            sSql += " VALUES(" + robot->getRobotId() + ", ";
            sSql += " '" + robot->getAlias() + "', ";
            sSql += " '" + robot->getUbicacion() + "', ";
            sSql += " '" + robot->ObtenerEstadoString() + "', ";
            sSql += " " + robot->getGradosLibertad() + ", ";
            sSql += " " + robot->getHorasTrabajo() + ")";

            return executeSql(sSql);
        }
        return false; // Si ya existe el robot
    }

    List<UnidadRobotica^>^ RobotController::ObtenerTodosRobots() {
        return this->repositorio;
    }

    UnidadRobotica^ RobotController::ConsultarRobotPorId(int robotId) {
        for each (UnidadRobotica ^ robot in this->repositorio) {
            if (robot->getRobotId() == robotId) {
                return robot;
            }
        }
        return nullptr;
    }

    bool RobotController::ExisteRobot(int robotId) {
        return ConsultarRobotPorId(robotId) != nullptr;
    }

    bool RobotController::ModificarRobot(int robotId, String^ alias, String^ ubicacion, EstadoOperativo estado, int gradosLibertad, double horasTrabajo) {
        UnidadRobotica^ robot = ConsultarRobotPorId(robotId);
        if (robot != nullptr) {
            robot->setAlias(alias);
            robot->setUbicacion(ubicacion);
            robot->setEstado(estado);
            robot->setGradosLibertad(gradosLibertad);
            robot->setHorasTrabajo(horasTrabajo);

            // Preparamos el SQL para Actualizar en la Base de Datos
            String^ sSql = "UPDATE UnidadRobotica SET ";
            sSql += " Alias = '" + alias + "', ";
            sSql += " Ubicacion = '" + ubicacion + "', ";
            sSql += " Estado = '" + robot->ObtenerEstadoString() + "', ";
            sSql += " GradosLibertad = " + gradosLibertad + ", ";
            sSql += " HorasTrabajo = " + horasTrabajo;
            sSql += " WHERE RobotId = " + robotId;

            return executeSql(sSql);
        }
        return false;
    }

    bool RobotController::EliminarRobot(int robotId) {
        UnidadRobotica^ robot = ConsultarRobotPorId(robotId);
        if (robot != nullptr) {
            this->repositorio->Remove(robot);

            // Preparamos el SQL para Eliminar en la Base de Datos
            String^ sSql = "DELETE FROM UnidadRobotica WHERE RobotId = " + robotId;
            return executeSql(sSql);
        }
        return false;
    }

    int RobotController::ContarUnidades() {
        return this->repositorio->Count;
    }

    void RobotController::LiberarMemoria() {
        this->repositorio = nullptr;
    }

    // =============================================================
    // MÉTODOS CON PROCEDIMIENTOS ALMACENADOS
    // =============================================================

    List<UnidadRobotica^>^ RobotController::spObtenerTodosRobots() {
        this->repositorio = gcnew List<UnidadRobotica^>();
        // BD con procedimiento almacenado: Leer desde la base de datos y cargar los datos en la lista
        try {
            // Paso1: ejecutar el procedimiento almacenado (SELECT) que me devuelve un SqlDataReader
            SqlDataReader^ objData = executeStoredProcedureReader("usp_QueryAllRobots", nullptr);

            // Paso2: Validamos que el DataReader [objData] no sea nulo antes de intentar recuperar los datos
            if (objData != nullptr) {
                // Paso3: Leer los registros del procedimiento almacenado
                while (objData->Read()) {
                    // Usamos el nombre de la columna para obtener los valores
                    int id = safe_cast<int>(objData["RobotId"]);
                    String^ alias = safe_cast<String^>(objData["Alias"]);
                    String^ ubicacion = safe_cast<String^>(objData["Ubicacion"]);
                    String^ estadoStr = safe_cast<String^>(objData["Estado"]);
                    int gradosLibertad = safe_cast<int>(objData["GradosLibertad"]);
                    double horasTrabajo = safe_cast<double>(objData["HorasTrabajo"]);

                    // Convertir el estado de string a enum
                    EstadoOperativo estado = UnidadRobotica::ConvertirEstadoOperativo(estadoStr);

                    // Crear el objeto UnidadRobotica y agregarlo a la lista
                    UnidadRobotica^ robot = gcnew UnidadRobotica(id, alias, ubicacion, estado, gradosLibertad, horasTrabajo);
                    this->repositorio->Add(robot);
                }
                objData->Close();
            }
            cerrarConexion();
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error al cargar robots: " + ex->Message);
            // En caso de cualquier error, se devuelve la lista vacía
        }
        return this->repositorio;
    }

    // Método para ejecutar el procedimiento almacenado de agregar un robot
    bool RobotController::spAgregarRobot(UnidadRobotica^ robot) {
        if (!ExisteRobot(robot->getRobotId())) {
            this->repositorio->Add(robot);

            // Asignando los valores a cada atributo de la tabla UnidadRobotica
            array<SqlParameter^>^ parameters = gcnew array<SqlParameter^> {
                gcnew SqlParameter("@RobotId", robot->getRobotId()),
                    gcnew SqlParameter("@Alias", robot->getAlias()),
                    gcnew SqlParameter("@Ubicacion", robot->getUbicacion()),
                    gcnew SqlParameter("@Estado", robot->ObtenerEstadoString()),
                    gcnew SqlParameter("@GradosLibertad", robot->getGradosLibertad()),
                    gcnew SqlParameter("@HorasTrabajo", robot->getHorasTrabajo())
            };

            // Llamar al procedimiento almacenado para insertar el robot en la base de datos
            bool resultado = executeStoredProcedure("usp_AddRobot", parameters);

            // Verificar el resultado
            if (resultado) {
                return true;
            }
            else {
                this->repositorio->Remove(robot);
                return false;
            }
        }
        return false;
    }

    // Método para ejecutar el procedimiento almacenado de modificar un robot existente
    bool RobotController::spModificarRobot(int robotId, String^ alias, String^ ubicacion, EstadoOperativo estado, int gradosLibertad, double horasTrabajo) {
        UnidadRobotica^ robot = ConsultarRobotPorId(robotId);

        // Actualizar los valores en el objeto UnidadRobotica
        if (robot != nullptr) {
            robot->setAlias(alias);
            robot->setUbicacion(ubicacion);
            robot->setEstado(estado);
            robot->setGradosLibertad(gradosLibertad);
            robot->setHorasTrabajo(horasTrabajo);

            // Crear parámetros para el procedimiento almacenado
            array<SqlParameter^>^ parameters = gcnew array<SqlParameter^> {
                gcnew SqlParameter("@RobotId", robotId),
                    gcnew SqlParameter("@Alias", alias),
                    gcnew SqlParameter("@Ubicacion", ubicacion),
                    gcnew SqlParameter("@Estado", robot->ObtenerEstadoString()), 
                    gcnew SqlParameter("@GradosLibertad", gradosLibertad),
                    gcnew SqlParameter("@HorasTrabajo", horasTrabajo)
            };

            // Llamar al procedimiento almacenado para actualizar la información
            bool resultado = executeStoredProcedure("usp_UpdateRobot", parameters);
            return resultado;
        }
        return false;
    }

    // Método para ejecutar el procedimiento almacenado de eliminar un robot
    bool RobotController::spEliminarRobot(int robotId) {
        UnidadRobotica^ robot = ConsultarRobotPorId(robotId);
        if (robot != nullptr) {
            this->repositorio->Remove(robot);

            // Crear parámetro para el procedimiento almacenado
            array<SqlParameter^>^ parameters = gcnew array<SqlParameter^> {
                gcnew SqlParameter("@RobotId", robotId)
            };

            // Llamar al procedimiento almacenado para eliminar el registro
            bool resultado = executeStoredProcedure("usp_DeleteRobot", parameters);
            return resultado;
        }
        return false;
    }
}