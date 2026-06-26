#include "ActuadorLineal.h"
#include <stdlib.h>

namespace SGELProdAutomModel {
	ActuadorLineal::ActuadorLineal() : ComponenteRobotico() {
		longitudMinima = 0.0;
		longitudMaxima = 100.0;
		velocidadDesplazamiento = 10.0;
		longitudActual = 0.0;
	}
	ActuadorLineal::ActuadorLineal(String^ idHardware, String^ fabricante, double tiempoOperacion,
		double minLong, double maxLong, double velocidad) : ComponenteRobotico(0, idHardware, fabricante, tiempoOperacion) {
		longitudMinima = minLong;
		longitudMaxima = maxLong;
		velocidadDesplazamiento = velocidad;
		longitudActual = minLong; // Inicia en posición mínima
	}
	double ActuadorLineal::getLongitudMinima() {
		return longitudMinima;
	}
	void ActuadorLineal::setLongitudMinima(double minLong) {
		longitudMinima = minLong;
	}
	double ActuadorLineal::getLongitudMaxima() {
		return longitudMaxima;
	}
	void ActuadorLineal::setLongitudMaxima(double maxLong) {
		longitudMaxima = maxLong;
	}
	double ActuadorLineal::getVelocidadDesplazamiento() {
		return velocidadDesplazamiento;
	}
	void ActuadorLineal::setVelocidadDesplazamiento(double velocidad) {
		velocidadDesplazamiento = velocidad;
	}
	double ActuadorLineal::obtenerLongitudActual() {
		return longitudActual;
	}
	void ActuadorLineal::mover(double distanciaMM) {
		double nuevaPosicion = longitudActual + distanciaMM;
		if (nuevaPosicion < longitudMinima) {
			longitudActual = longitudMinima;
		}
		else if (nuevaPosicion > longitudMaxima) {
			longitudActual = longitudMaxima;
		}
		else {
			longitudActual = nuevaPosicion;
		}
	}

	void ActuadorLineal::leerTelemetria(double% temperatura, double% vibracion) {
		// Simulación de lectura de sensores
		temperatura = 25.0 + (rand() % 30);  // 25-55 °C
		vibracion = 0.5 + (rand() % 100) / 100.0;  // 0.5-1.5 Hz
	}

	void ActuadorLineal::verificarAlertas(bool% alertaTemp, bool% alertaVib) {
		double temperatura, vibracion;
		leerTelemetria(temperatura, vibracion);
		alertaTemp = (temperatura > 50.0); // Alerta si temperatura > 50 °C
		alertaVib = (vibracion > 1.2); // Alerta si vibración > 1.2 Hz
	}

	String^ ActuadorLineal::ReportarConfiguracion() {
		return String::Format("Actuador Lineal - ID: {0}, Hardware: {1}, Fabricante: {2}, Tiempo Operación: {3} horas, " +
			"Longitud Min: {4} mm, Longitud Max: {5} mm, Velocidad: {6} mm/s, Longitud Actual: {7} mm",
			idComponente, identificadorHardware, fabricante, tiempoOperacionAcumulado,
			longitudMinima, longitudMaxima, velocidadDesplazamiento, longitudActual);
	}
}