#pragma once

namespace SGELProdAutomModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public value struct PointF {
        float X;
        float Y;
        PointF(float x, float y) : X(x), Y(y) {}
    };

    public value struct Point {
        int X;
        int Y;
        Point(int x, int y) : X(x), Y(y) {}
    };

    /// <summary>
    /// Clase especializada para calcular el límite de seguridad (cardioide) de un robot
    /// </summary>
    public ref class WorkspaceCalculator {
    private:
        double a;           // Longitud del eslabón principal (mm)
        double b;           // Factor de excentricidad (mm)
        double pasoAngulo;  // Paso de discretización del ángulo (radianes)

        // Listas para almacenar coordenadas
        List<PointF>^ puntosMilimetros;  // Puntos en coordenadas reales (mm)
        List<Point>^ puntosPixeles;       // Puntos en coordenadas de pantalla (píxeles)

    public:
        WorkspaceCalculator();
        WorkspaceCalculator(double a, double b);
    
        // Getters y Setters
        double getLongitudEslabonPrincipal();
        void setLongitudEslabonPrincipal(double value);

        double getFactorExcentricidad();
        void setFactorExcentricidad(double value);

        double getPasoAngulo();
        void setPasoAngulo(double value);

        // Método principal: Calcula todos los puntos de la cardioide
        void CalcularPuntos();

        // Método para convertir coordenadas milímetros a píxeles
        void ConvertirAPixeles(int centroX, int centroY, float escala);

        // Getters para acceder a los puntos calculados
        List<PointF>^ ObtenerPuntosMilimetros();
        List<Point>^ ObtenerPuntosPixeles();

        // Validar que la cardioide sea válida
        bool EsCardioideValida();

        // Obtener el radio máximo de la cardioide
        double ObtenerRadioMaximo();

        // Obtener el radio mínimo de la cardioide
        double ObtenerRadioMinimo();

        // Obtener estadísticas del workspace
        String^ ObtenerEstadisticas();

        // Limpiar puntos calculados
        void LimpiarPuntos();
    };
}