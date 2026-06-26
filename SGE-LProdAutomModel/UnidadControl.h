#pragma once
#include "Firmware.h"

namespace SGELProdAutomModel {
    using namespace System;

    public ref class UnidadControl {
    private:
		int idUnidad;
        double voltajeOperacionNominal; // VDC (fijo 24.0)
        double frecuenciaReloj;          // MHz
        Firmware^ firmware;              // Composición: vida ligada

    public:
        UnidadControl();
        UnidadControl(int id, double frecuenciaReloj);
        ~UnidadControl();  // Destructor para liberar firmware

        int getIdUnidad();
		void setIdUnidad(int id);

        double getVoltajeOperacionNominal();
        void setVoltajeOperacionNominal(double voltaje);

        double getFrecuenciaReloj();
        void setFrecuenciaReloj(double frecuencia);

        Firmware^ getFirmware();
        void procesarSenales();

        String^ ReportarConfiguracion();
    };
}