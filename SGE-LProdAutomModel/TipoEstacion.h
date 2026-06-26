#pragma once

namespace SGELProdAutomModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class TipoEstacion {
    protected:
        int idTipoEstacion;
        String^ tipoEstacion;

    public:
        TipoEstacion();
        TipoEstacion(int id, String^ tipoEstacion);

        int getIdTipoEstacion();
        void setIdTipoEstacion(int id);

        String^ getTipoEstacion();
        void setTipoEstacion(String^ tipoEstacion);
    };
}