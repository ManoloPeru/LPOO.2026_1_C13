#pragma once
#include "ComponenteRobotico.h"
#include "ISensorizable.h"

namespace SGELProdAutomModel {
    using namespace System;

    public ref class ActuadorLineal : public ComponenteRobotico, public ISensorizable {
    private:
        double longitudMinima;     // mm
        double longitudMaxima;     // mm
        double velocidadDesplazamiento; // mm/s
        double longitudActual;     // mm (posición actual)

    public:
        ActuadorLineal();
        ActuadorLineal(String^ idHardware, String^ fabricante, double tiempoOperacion,
            double minLong, double maxLong, double velocidad);

        double getLongitudMinima();
        void setLongitudMinima(double minLong);

        double getLongitudMaxima();
        void setLongitudMaxima(double maxLong);

        double getVelocidadDesplazamiento();
        void setVelocidadDesplazamiento(double velocidad);

        double obtenerLongitudActual();
        void mover(double distanciaMM);

        // Implementación de ISensorizable
        virtual void leerTelemetria(double% temperatura, double% vibracion);
        virtual void verificarAlertas(bool% alertaTemp, bool% alertaVib);

        // Reporte
        virtual String^ ReportarConfiguracion() override;
    };
}