#include "UnidadControl.h"

namespace SGELProdAutomModel {
	UnidadControl::UnidadControl() {
		idUnidad = 0;
		voltajeOperacionNominal = 24.0; // VDC
		frecuenciaReloj = 100.0; // MHz
		firmware = gcnew Firmware(0, "1.0.0", "2026-01-01", 256.0);
	}
	UnidadControl::UnidadControl(int id, double frecuenciaReloj) {
		idUnidad = id;
		voltajeOperacionNominal = 24.0; // VDC
		this->frecuenciaReloj = frecuenciaReloj;
		firmware = gcnew Firmware(id, "1.0.0", "2026-01-01", 256.0);
	}
	UnidadControl::~UnidadControl() {
		delete firmware;
	}
	int UnidadControl::getIdUnidad() {
		return idUnidad;
	}
	void UnidadControl::setIdUnidad(int id) {
		idUnidad = id;
	}
	double UnidadControl::getVoltajeOperacionNominal() {
		return voltajeOperacionNominal;
	}
	void UnidadControl::setVoltajeOperacionNominal(double voltaje) {
		voltajeOperacionNominal = voltaje;
	}
	double UnidadControl::getFrecuenciaReloj() {
		return frecuenciaReloj;
	}
	void UnidadControl::setFrecuenciaReloj(double frecuencia) {
		frecuenciaReloj = frecuencia;
	}
	Firmware^ UnidadControl::getFirmware() {
		return firmware;
	}
	void UnidadControl::procesarSenales() {
		// Simulación de procesamiento
		Console::WriteLine("UnidadControl procesando señales a {0} MHz", frecuenciaReloj);
	}
	String^ UnidadControl::ReportarConfiguracion() {
		return String::Format("Unidad Control ID: {0}, Voltaje Operación: {1} VDC, Frecuencia Reloj: {2} MHz\n{3}",
			idUnidad, voltajeOperacionNominal, frecuenciaReloj, firmware->ReportarConfiguracion());
	}
}