#pragma once

namespace SGELProdAutomController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGELProdAutomModel;

    /// <summary>
    /// Controlador para gestionar las operaciones CRUD de Estaciones de Trabajo
    /// </summary>
    public ref class EstacionController {
    private:
        // Ruta del archivo para almacenar los tipos de robots, esto se puede modificar según sea necesario
        String^ pathArchivo;
		// Repositorio en memoria para almacenar las estaciones de trabajo
        List<EstacionTrabajo^>^ repositorio;

    public:
        EstacionController(String^ pathArchivo);

        // CRUD Operations
        bool RegistrarEstacion(EstacionTrabajo^ estacion);
        EstacionTrabajo^ ConsultarEstacion(String^ id);
        List<EstacionTrabajo^>^ ListarEstaciones();
        bool ModificarEstacion(String^ id, String^ nuevoNombre, String^ nuevoTipo,
            EstadoEstacion nuevoEstado, int nuevaCapacidad);
        bool EliminarEstacion(String^ id);

        // Métodos auxiliares
        int ContarEstaciones();
        bool ExisteEstacion(String^ id);
        List<EstacionTrabajo^>^ ConsultarIdTipo(String^ sId, String^ tipoEstacion);

        //Para los archivos BIN
        void escribirArchivoBIN();

        // Ultima acción para liberar memoria, conexiones
        void LiberarMemoria();
    };
}