#pragma once
#include "InspeccionDetalle.h"

namespace SGELProdAutomModel {
    using namespace System;
    using namespace Collections::Generic;

    public ref class Inspeccion {
    private:
        int inspeccionId;
        String^ codigoLote;
        int robotId;
        String^ inspector;
        DateTime fechaInspeccion;
        String^ resultadoGeneral;
        List<InspeccionDetalle^>^ listaInspeccionesDetalle;

    public:
        Inspeccion();
        Inspeccion(int inspeccionId, String^ codigoLote, int robotId, String^ inspector, DateTime fechaInspeccion, String^ resultadoGeneral);

        // Propiedades
        int getInspeccionId();
        void setInspeccionId(int id);

        String^ getCodigoLote();
        void setCodigoLote(String^ codigoLote);

        int getRobotId();
        void setRobotId(int robotId);

        String^ getInspector();
        void setInspector(String^ inspector);

        DateTime getFechaInspeccion();
        void setFechaInspeccion(DateTime date);

        String^ getResultadoGeneral();
        void setResultadoGeneral(String^ result);

        List<InspeccionDetalle^>^ getListaInspeccionesDetalle();
        void setListaInspeccionesDetalle(List<InspeccionDetalle^>^ listaInspeccionesDetalle);
        void addDetalle(InspeccionDetalle^ detalle);
        bool removeDetalle(int detalleId);

        // Métodos de validación y utilidad
        String^ ToString() override;
        int getDetalleCount();
    };
}