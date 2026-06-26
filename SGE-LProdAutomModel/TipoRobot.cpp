#include "TipoRobot.h"

namespace SGELProdAutomModel {
	TipoRobot::TipoRobot() {
		this->idTipoRobot = 0;
		this->tipoRobot = "Desconocido";
	}
	TipoRobot::TipoRobot(int id, String^ tipoRobot) {
		this->idTipoRobot = id;
		this->tipoRobot = tipoRobot;
	}
	int TipoRobot::getIdTipoRobot() {
		return idTipoRobot;
	}
	void TipoRobot::setIdTipoRobot(int id) {
		idTipoRobot = id;
	}
	String^ TipoRobot::getTipoRobot() {
		return tipoRobot;
	}
	void TipoRobot::setTipoRobot(String^ tipoRobot) {
		this->tipoRobot = tipoRobot;
	}
}