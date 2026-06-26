#pragma once

namespace SGELProdAutomModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class ComponenteRobotico {
    protected:
		int idComponente;
        String^ identificadorHardware;
        String^ fabricante;
        double tiempoOperacionAcumulado; // horas

    public:
        ComponenteRobotico();
        ComponenteRobotico(int id, String^ idHardware, String^ fabricante, double tiempoOperacion);

		int getIdComponente();
		void setIdComponente(int id);

        String^ getIdentificadorHardware();
        void setIdentificadorHardware(String^ idHardware);

        String^ getFabricante();
        void setFabricante(String^ fabricante);

        double getTiempoOperacionAcumulado();
        void setTiempoOperacionAcumulado(double tiempo);

        void incrementarTiempoOperacion(double horas);

        virtual String^ ReportarConfiguracion() = 0;
    };
}