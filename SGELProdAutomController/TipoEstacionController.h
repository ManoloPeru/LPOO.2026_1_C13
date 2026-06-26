#pragma once

namespace SGELProdAutomController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace SGELProdAutomModel;

    public ref class TipoEstacionController {
    private:
        // Ruta del archivo para almacenar los tipos de robots, esto se puede modificar según sea necesario
        String^ pathArchivo;
        // Repositorio en memoria para almacenar las unidades roboticas
        List<TipoEstacion^>^ repositorio;

    public:
        TipoEstacionController(String^ pathArchivo);

        // ListarTipos devuelve la lista completa de tipos de robots registrados
        List<TipoEstacion^>^ ListarTiposEstacion();

    };
}