#pragma once

namespace SGELProdAutomModel {
    using namespace System;

    public interface class ISensorizable {
    public:
        void leerTelemetria(double% temperatura, double% vibracion);
        void verificarAlertas(bool% alertaTemp, bool% alertaVib);
    };
}