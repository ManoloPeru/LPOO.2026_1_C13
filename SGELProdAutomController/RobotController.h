#pragma once
#include "BaseController.h" // 1.- Incluyendo la clase base para conectarme a la BD

namespace SGELProdAutomController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGELProdAutomModel;

    public ref class RobotController : public BaseController { // 2.- Herencia de BaseController
    private:
        // Repositorio en memoria para almacenar las unidades roboticas
        List<UnidadRobotica^>^ repositorio;

    public:
        RobotController();

        // CRUD Operations:
        bool AgregarRobot(UnidadRobotica^ robot);
        List<UnidadRobotica^>^ ObtenerTodosRobots();
        UnidadRobotica^ ConsultarRobotPorId(int robotId);
        bool ExisteRobot(int robotId);
        bool ModificarRobot(int robotId, String^ alias, String^ ubicacion, EstadoOperativo estado, int gradosLibertad, double horasTrabajo);
        bool EliminarRobot(int robotId);

        // Métodos auxiliares:
        int ContarUnidades();

        // Ultima acción para liberar memoria, conexiones
        void LiberarMemoria();

        // Metodos para procedimientos almacenados
        List<UnidadRobotica^>^ spObtenerTodosRobots();
        bool spAgregarRobot(UnidadRobotica^ robot);
        bool spModificarRobot(int robotId, String^ alias, String^ ubicacion, EstadoOperativo estado, int gradosLibertad, double horasTrabajo);
        bool spEliminarRobot(int robotId);
    };
}