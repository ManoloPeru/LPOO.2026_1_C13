#pragma once
#include "ComponenteRobotico.h"
#include "ISensorizable.h"

namespace SGELProdAutomModel {
    using namespace System;

    public ref class ArticulacionRotativa : public ComponenteRobotico, public ISensorizable {
    private:
        double anguloMinimo;   // grados
        double anguloMaximo;   // grados
        double torqueMaximo;   // N·m
        double anguloActual;   // grados (posición actual)

    public:
        ArticulacionRotativa();
        ArticulacionRotativa(String^ idHardware, String^ fabricante, double tiempoOperacion,
            double minAng, double maxAng, double torque);

        double getAnguloMinimo();
        void setAnguloMinimo(double minAng);

        double getAnguloMaximo();
        void setAnguloMaximo(double maxAng);

        double getTorqueMaximo();
        void setTorqueMaximo(double torque);

        double obtenerAnguloActual();
        void rotar(double grados);

        // Implementación de ISensorizable
        virtual void leerTelemetria(double% temperatura, double% vibracion);
        virtual void verificarAlertas(bool% alertaTemp, bool% alertaVib);

        // Reporte
        virtual String^ ReportarConfiguracion() override;
    };
}