#pragma once

namespace SGELProdAutomModel {
    using namespace System;

    public ref class Firmware {
    private:
		int idFirmware;
        String^ versionSistema;
        String^ fechaCompilacion;
        double memoriaInterna;   // KB

    public:
        Firmware();
        Firmware(int id, String^ version, String^ fechaCompilacion, double memoria);

		int getIdFirmware();
		void setIdFirmware(int id);

        String^ getVersionSistema();
        void setVersionSistema(String^ version);

        String^ getFechaCompilacion();
        void setFechaCompilacion(String^ fecha);

        double getMemoriaInterna();
        void setMemoriaInterna(double memoria);

        void actualizarVersion(String^ nuevaVersion, String^ nuevaFecha);
        String^ ReportarConfiguracion();
    };
}