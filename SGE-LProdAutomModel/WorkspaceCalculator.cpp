#include "WorkspaceCalculator.h"

namespace SGELProdAutomModel {

    WorkspaceCalculator::WorkspaceCalculator() {
        this->a = 100.0;      // Valor por defecto: 100 mm
        this->b = 80.0;       // Valor por defecto: 80 mm
        this->pasoAngulo = 0.05;  // Paso de 0.05 rad (~2.86 grados)

        this->puntosMilimetros = gcnew List<PointF>();
        this->puntosPixeles = gcnew List<Point>();
    }

    WorkspaceCalculator::WorkspaceCalculator(double a, double b) {
        this->a = a;
        this->b = b;
        this->pasoAngulo = 0.05;  // Paso de 0.05 rad (~2.86 grados)

        this->puntosMilimetros = gcnew List<PointF>();
        this->puntosPixeles = gcnew List<Point>();
    }

    double WorkspaceCalculator::getLongitudEslabonPrincipal() {
        return a;
    }

    void WorkspaceCalculator::setLongitudEslabonPrincipal(double value) {
        this->a = value;
    }

    double WorkspaceCalculator::getFactorExcentricidad() {
        return b;
    }

    void WorkspaceCalculator::setFactorExcentricidad(double value) {
        this->b = value;
    }

    double WorkspaceCalculator::getPasoAngulo() {
        return pasoAngulo;
    }

    void WorkspaceCalculator::setPasoAngulo(double value) {
        this->pasoAngulo = value;
    }

    void WorkspaceCalculator::CalcularPuntos() {
        // Limpiar listas anteriores
        puntosMilimetros->Clear();
        puntosPixeles->Clear();

        // Validar parámetros
        if (a <= 0 || b <= 0) {
            return;
        }

        // Discretización del ángulo theta desde 0 hasta 2*PI
        double theta = 0.0;                 // O grados
        double thetaMax = 2.0 * Math::PI;   // 2PI

        while (theta <= thetaMax + 0.001) {  // Pequeño margen para incluir el último punto
            // Ecuación polar: r = a + b * cos(theta)
            double r = a + b * Math::Cos(theta);

            // Asegurar que el radio no sea negativo (seguridad)
            if (r < 0) r = 0;

            // Conversión a coordenadas cartesianas (milímetros)
            double x_mm = r * Math::Cos(theta);
            double y_mm = r * Math::Sin(theta);

            // Almacenar el punto en milímetros
            puntosMilimetros->Add(PointF((float)x_mm, (float)y_mm));

            // Incrementar el ángulo
            theta += pasoAngulo;
        }

        // Para cerrar la curva, agregar el primer punto al final (si hay puntos)
        if (puntosMilimetros->Count > 0) {
            PointF primerPunto = puntosMilimetros[0];
            puntosMilimetros->Add(primerPunto);
        }
    }

    void WorkspaceCalculator::ConvertirAPixeles(int centroX, int centroY, float escala) {
        puntosPixeles->Clear();

        for each (PointF punto in puntosMilimetros) {
            // Fórmulas de conversión:
            // px = centroX + (x_mm * escala)
            // py = centroY - (y_mm * escala)  (invertir Y para pantalla)
            int px = centroX + (int)(punto.X * escala);
            int py = centroY - (int)(punto.Y * escala);

            puntosPixeles->Add(Point(px, py));
        }
    }

    List<PointF>^ WorkspaceCalculator::ObtenerPuntosMilimetros() {
        return puntosMilimetros;
    }

    List<Point>^ WorkspaceCalculator::ObtenerPuntosPixeles() {
        return puntosPixeles;
    }

    bool WorkspaceCalculator::EsCardioideValida() {
        // Validar que los parámetros sean positivos
        if (a <= 0 || b <= 0) return false;
        return true;
    }

    double WorkspaceCalculator::ObtenerRadioMaximo() {
        // r_max = a + b (cuando cos(theta) = 1)
        return a + b;
    }

    double WorkspaceCalculator::ObtenerRadioMinimo() {
        // r_min = a - b (cuando cos(theta) = -1)
        double r_min = a - b;
        if (r_min < 0) r_min = 0;
        return r_min;
    }

    String^ WorkspaceCalculator::ObtenerEstadisticas() {
        if (puntosMilimetros->Count == 0) {
            CalcularPuntos();
        }

        double radioMax = ObtenerRadioMaximo();
        double radioMin = ObtenerRadioMinimo();
        double relacion = (b / a) * 100.0;

        return String::Format(
            "Estadísticas del Workspace:\r\n" +
            "  - Longitud eslabón principal (a): {0:F2} mm\r\n" +
            "  - Factor de excentricidad (b): {1:F2} mm\r\n" +
            "  - Relación b/a: {2:F1}%\r\n" +
            "  - Radio máximo alcanzado: {3:F2} mm\r\n" +
            "  - Radio mínimo: {4:F2} mm\r\n" +
            "  - Puntos calculados: {5}\r\n" +
            "  - Paso angular: {6:F3} rad ({7:F2}°)\r\n" +
            "  - Ecuación: r = {0:F2} + {1:F2}·cos(θ)",
            a, b, relacion, radioMax, radioMin,
            puntosMilimetros->Count, pasoAngulo, (pasoAngulo * 180.0 / Math::PI));
    }

    void WorkspaceCalculator::LimpiarPuntos() {
        puntosMilimetros->Clear();
        puntosPixeles->Clear();
    }
}