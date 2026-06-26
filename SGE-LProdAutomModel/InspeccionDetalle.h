#pragma once

namespace SGELProdAutomModel {
    using namespace System;

    public ref class InspeccionDetalle {
    private:
        int inspeccionDetalleId;
        int inspeccionId;
        String^ parametro;
        String^ resultadoParametro;
        String^ notas;

    public:
        InspeccionDetalle();
        InspeccionDetalle(int inspeccionDetalleId, int inspeccionId, String^ parametro, String^ resultadoParametro, String^ notas);

        // Propiedades
        int getInspeccionDetalleId();
        void setInspeccionDetalleId(int id);

        int getInspeccionId();
        void setInspeccionId(int id);

        String^ getParametro();
        void setParametro(String^ parametro);

        String^ getResultadoParametro();
        void setResultadoParametro(String^ result);

        String^ getNotas();
        void setNotas(String^ notas);

        // Métodos de utilidad
        String^ ToString() override;
        bool isValid();
    };
}