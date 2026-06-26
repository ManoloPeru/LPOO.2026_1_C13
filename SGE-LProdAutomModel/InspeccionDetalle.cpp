#include "InspeccionDetalle.h"

using namespace SGELProdAutomModel;

InspeccionDetalle::InspeccionDetalle() {
    this->inspeccionDetalleId = 0;
    this->inspeccionId = 0;
    this->parametro = "Sin parámetro";
    this->resultadoParametro = "Pendiente";
    this->notas = "";
}

InspeccionDetalle::InspeccionDetalle(int inspeccionDetalleId, int inspeccionId, String^ parametro, String^ resultadoParametro, String^ notas) {
    this->inspeccionDetalleId = inspeccionDetalleId;
    this->inspeccionId = inspeccionId;
    this->parametro = parametro;
    this->resultadoParametro = resultadoParametro;
    this->notas = notas;
}

int InspeccionDetalle::getInspeccionDetalleId() {
    return this->inspeccionDetalleId;
}

void InspeccionDetalle::setInspeccionDetalleId(int id) {
    this->inspeccionDetalleId = id;
}

int InspeccionDetalle::getInspeccionId() {
    return this->inspeccionId;
}

void InspeccionDetalle::setInspeccionId(int id) {
    this->inspeccionId = id;
}

String^ InspeccionDetalle::getParametro() {
    return this->parametro;
}

void InspeccionDetalle::setParametro(String^ parametro) {
    this->parametro = parametro;
}

String^ InspeccionDetalle::getResultadoParametro() {
    return this->resultadoParametro;
}

void InspeccionDetalle::setResultadoParametro(String^ result) {
    this->resultadoParametro = result;
}

String^ InspeccionDetalle::getNotas() {
    return this->notas;
}

void InspeccionDetalle::setNotas(String^ notas) {
    this->notas = notas;
}

String^ InspeccionDetalle::ToString() {
    return String::Format("Parámetro: {0}, Resultado: {1}, Notas: {2}",
        this->parametro, this->resultadoParametro, this->notas);
}

bool InspeccionDetalle::isValid() {
    return !String::IsNullOrWhiteSpace(this->parametro) &&
        !String::IsNullOrWhiteSpace(this->resultadoParametro);
}