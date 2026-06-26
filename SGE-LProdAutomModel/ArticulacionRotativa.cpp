#include "ArticulacionRotativa.h"
#include <stdlib.h>

namespace SGELProdAutomModel {
	ArticulacionRotativa::ArticulacionRotativa() : ComponenteRobotico() {
		anguloMinimo = -180.0;
		anguloMaximo = 180.0;
		torqueMaximo = 50.0;
		anguloActual = 0.0;
	}
	ArticulacionRotativa::ArticulacionRotativa(String^ idHardware, String^ fabricante, double tiempoOperacion,
		double minAng, double maxAng, double torque) : ComponenteRobotico(0, idHardware, fabricante, tiempoOperacion) {
		anguloMinimo = minAng;
		anguloMaximo = maxAng;
		torqueMaximo = torque;
		anguloActual = 0.0; 
	}
	double ArticulacionRotativa::getAnguloMinimo() {
		return anguloMinimo;
	}
	void ArticulacionRotativa::setAnguloMinimo(double minAng) {
		anguloMinimo = minAng;
	}
	double ArticulacionRotativa::getAnguloMaximo() {
		return anguloMaximo;
	}
	void ArticulacionRotativa::setAnguloMaximo(double maxAng) {
		anguloMaximo = maxAng;
	}
	double ArticulacionRotativa::getTorqueMaximo() {
		return torqueMaximo;
	}
	void ArticulacionRotativa::setTorqueMaximo(double torque) {
		torqueMaximo = torque;
	}
	double ArticulacionRotativa::obtenerAnguloActual() {
		return anguloActual;
	}
	void ArticulacionRotativa::rotar(double grados) {
		double nuevaPosicion = anguloActual + grados;
		if (nuevaPosicion < anguloMinimo) {
			anguloActual = anguloMinimo;
		}
		else if (nuevaPosicion > anguloMaximo) {
			anguloActual = anguloMaximo;
		}
		else {
			anguloActual = nuevaPosicion;
		}
	}

	// Implementación de ISensorizable
	void ArticulacionRotativa::leerTelemetria(double% temperatura, double% vibracion) {
		// Simulación de lectura de sensores
		temperatura = 30.0 + (rand() % 40);  // 30-70 °C
		vibracion = 0.3 + (rand() % 150) / 100.0;  // 0.3-1.8 Hz
	}

	void ArticulacionRotativa::verificarAlertas(bool% alertaTemp, bool% alertaVib) {
		double temperatura, vibracion;
		leerTelemetria(temperatura, vibracion);
		alertaTemp = (temperatura > 65.0); // Alerta si temperatura > 65 °C
		alertaVib = (vibracion > 1.5); // Alerta si vibración > 1.5 mm/s
	}

	String^ ArticulacionRotativa::ReportarConfiguracion() {
		return String::Format("Articulación Rotativa - ID: {0}, Hardware: {1}, Fabricante: {2}, Tiempo Operación: {3} horas, " +
			"Ángulo Mínimo: {4}°, Ángulo Máximo: {5}°, Torque Máximo: {6} N·m, Ángulo Actual: {7}°",
			idComponente, identificadorHardware, fabricante, tiempoOperacionAcumulado,
			anguloMinimo, anguloMaximo, torqueMaximo, anguloActual);
	}
}