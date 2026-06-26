#include "Firmware.h"

namespace SGELProdAutomModel {
	Firmware::Firmware() {
		idFirmware = 0;
		versionSistema = "1.0.0";
		fechaCompilacion = "2026-01-01";
		memoriaInterna = 256.0;
	}
	Firmware::Firmware(int id, String^ version, String^ fechaCompilacion, double memoria) {
		idFirmware = id;
		this->versionSistema = version;
		this->fechaCompilacion = fechaCompilacion;
		this->memoriaInterna = memoria;
	}
	int Firmware::getIdFirmware() {
		return idFirmware;
	}
	void Firmware::setIdFirmware(int id) {
		idFirmware = id;
	}
	String^ Firmware::getVersionSistema() {
		return versionSistema;
	}
	void Firmware::setVersionSistema(String^ version) {
		versionSistema = version;
	}
	String^ Firmware::getFechaCompilacion() {
		return fechaCompilacion;
	}
	void Firmware::setFechaCompilacion(String^ fecha) {
		fechaCompilacion = fecha;
	}
	double Firmware::getMemoriaInterna() {
		return memoriaInterna;
	}
	void Firmware::setMemoriaInterna(double memoria) {
		memoriaInterna = memoria;
	}
	void Firmware::actualizarVersion(String^ nuevaVersion, String^ nuevaFecha) {
		versionSistema = nuevaVersion;
		fechaCompilacion = nuevaFecha;
	}
	String^ Firmware::ReportarConfiguracion() {
		return String::Format("Firmware ID: {0}, Version: {1}, Fecha Compilación: {2}, Memoria Interna: {3} KB",
			idFirmware, versionSistema, fechaCompilacion, memoriaInterna);
	}
}