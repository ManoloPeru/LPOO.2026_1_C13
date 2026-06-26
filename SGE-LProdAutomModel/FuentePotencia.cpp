#include "FuentePotencia.h"

namespace SGELProdAutomModel {
	FuentePotencia::FuentePotencia() {
		idFuente = 0;
		voltajeSalida = 220.0; // V
		corrienteMaxima = 10.0; // A
		eficienciaEnergetica = 85.0; // %
	}
	FuentePotencia::FuentePotencia(int id, double voltaje, double corriente, double eficiencia) {
		idFuente = id;
		voltajeSalida = voltaje;
		corrienteMaxima = corriente;
		eficienciaEnergetica = eficiencia;
	}
	int FuentePotencia::getIdFuente() {
		return idFuente;
	}
	void FuentePotencia::setIdFuente(int id) {
		idFuente = id;
	}
	double FuentePotencia::getVoltajeSalida() {
		return voltajeSalida;
	}
	void FuentePotencia::setVoltajeSalida(double voltaje) {
		voltajeSalida = voltaje;
	}
	double FuentePotencia::getCorrienteMaxima() {
		return corrienteMaxima;
	}
	void FuentePotencia::setCorrienteMaxima(double corriente) {
		corrienteMaxima = corriente;
	}
	double FuentePotencia::getEficienciaEnergetica() {
		return eficienciaEnergetica;
	}
	void FuentePotencia::setEficienciaEnergetica(double eficiencia) {
		eficienciaEnergetica = eficiencia;
	}
	double FuentePotencia::suministrarPotencia() {
		// Potencia real = V * I * (eficiencia/100)
		return this->voltajeSalida * this->corrienteMaxima * (this->eficienciaEnergetica / 100.0);
	}
	String^ FuentePotencia::ReportarConfiguracion() {
		return String::Format("Fuente Potencia ID: {0}, Voltaje Salida: {1} V, Corriente Máxima: {2} A, Eficiencia: {3}%",
			idFuente, voltajeSalida, corrienteMaxima, eficienciaEnergetica);
	}
}