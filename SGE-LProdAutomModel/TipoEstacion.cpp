#include "TipoEstacion.h"

namespace SGELProdAutomModel {
	TipoEstacion::TipoEstacion() {
		this->idTipoEstacion = 0;
		this->tipoEstacion = "Desconocido";
	}
	TipoEstacion::TipoEstacion(int id, String^ tipoEstacion) {
		this->idTipoEstacion = id;
		this->tipoEstacion = tipoEstacion;
	}
	int TipoEstacion::getIdTipoEstacion() {
		return idTipoEstacion;
	}
	void TipoEstacion::setIdTipoEstacion(int id) {
		idTipoEstacion = id;
	}
	String^ TipoEstacion::getTipoEstacion() {
		return tipoEstacion;
	}
	void TipoEstacion::setTipoEstacion(String^ tipoEstacion) {
		this->tipoEstacion = tipoEstacion;
	}
}