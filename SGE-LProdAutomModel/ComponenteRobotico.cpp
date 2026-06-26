#include "ComponenteRobotico.h"

namespace SGELProdAutomModel {
	ComponenteRobotico::ComponenteRobotico() {
		idComponente = 0;
		identificadorHardware = "Desconocido";
		fabricante = "Desconocido";
		tiempoOperacionAcumulado = 0.0;
	}
	ComponenteRobotico::ComponenteRobotico(int id, String^ idHardware, String^ fabricante, double tiempoOperacion) {
		idComponente = id;
		identificadorHardware = idHardware;
		this->fabricante = fabricante;
		tiempoOperacionAcumulado = tiempoOperacion;
	}
	int ComponenteRobotico::getIdComponente() {
		return idComponente;
	}
	void ComponenteRobotico::setIdComponente(int id) {
		idComponente = id;
	}
	String^ ComponenteRobotico::getIdentificadorHardware() {
		return identificadorHardware;
	}
	void ComponenteRobotico::setIdentificadorHardware(String^ idHardware) {
		identificadorHardware = idHardware;
	}
	String^ ComponenteRobotico::getFabricante() {
		return fabricante;
	}
	void ComponenteRobotico::setFabricante(String^ fabricante) {
		this->fabricante = fabricante;
	}
	double ComponenteRobotico::getTiempoOperacionAcumulado() {
		return tiempoOperacionAcumulado;
	}
	void ComponenteRobotico::setTiempoOperacionAcumulado(double tiempo) {
		tiempoOperacionAcumulado = tiempo;
	}
	void ComponenteRobotico::incrementarTiempoOperacion(double horas) {
		tiempoOperacionAcumulado += horas;
	}
}