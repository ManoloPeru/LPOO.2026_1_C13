#pragma once

namespace SGELProdAutomModel {
    using namespace System;

    public ref class FuentePotencia {
    private:
        int idFuente;
        double voltajeSalida;      // V
        double corrienteMaxima;    // A
        double eficienciaEnergetica; // %

    public:
        FuentePotencia();
        FuentePotencia(int id, double voltaje, double corriente, double eficiencia);

        int getIdFuente();
        void setIdFuente(int id);

        double getVoltajeSalida();
        void setVoltajeSalida(double voltaje);

        double getCorrienteMaxima();
        void setCorrienteMaxima(double corriente);

        double getEficienciaEnergetica();
        void setEficienciaEnergetica(double eficiencia);

        double suministrarPotencia();  // Calcula V * I * (eficiencia/100)
        String^ ReportarConfiguracion();
    };
}