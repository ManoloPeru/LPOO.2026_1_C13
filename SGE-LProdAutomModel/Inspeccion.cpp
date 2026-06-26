#include "Inspeccion.h"
#include "InspeccionDetalle.h"

using namespace SGELProdAutomModel;

Inspeccion::Inspeccion() {
    this->inspeccionId = 0;
    this->codigoLote = "Sin lote";
    this->robotId = 0;
    this->inspector = "Sin inspector";
    this->fechaInspeccion = DateTime::Now;
    this->resultadoGeneral = "Pendiente";
    this->listaInspeccionesDetalle = gcnew List<InspeccionDetalle^>();
}

Inspeccion::Inspeccion(int inspeccionId, String^ codigoLote, int robotId, String^ inspector, DateTime fechaInspeccion, String^ resultadoGeneral) {
    this->inspeccionId = inspeccionId;
    this->codigoLote = codigoLote;
    this->robotId = robotId;
    this->inspector = inspector;
    this->fechaInspeccion = fechaInspeccion;
    this->resultadoGeneral = resultadoGeneral;
    this->listaInspeccionesDetalle = gcnew List<InspeccionDetalle^>();
}

int Inspeccion::getInspeccionId() {
    return this->inspeccionId;
}

void Inspeccion::setInspeccionId(int id) {
    this->inspeccionId = id;
}

String^ Inspeccion::getCodigoLote() {
    return this->codigoLote;
}

void Inspeccion::setCodigoLote(String^ codigoLote) {
    this->codigoLote = codigoLote;
}

int Inspeccion::getRobotId() {
    return this->robotId;
}

void Inspeccion::setRobotId(int id) {
    this->robotId = id;
}

String^ Inspeccion::getInspector() {
    return this->inspector;
}

void Inspeccion::setInspector(String^ inspector) {
    this->inspector = inspector;
}

DateTime Inspeccion::getFechaInspeccion() {
    return this->fechaInspeccion;
}

void Inspeccion::setFechaInspeccion(DateTime date) {
    this->fechaInspeccion = date;
}

String^ Inspeccion::getResultadoGeneral() {
    return this->resultadoGeneral;
}

void Inspeccion::setResultadoGeneral(String^ result) {
    this->resultadoGeneral = result;
}

List<InspeccionDetalle^>^ Inspeccion::getListaInspeccionesDetalle() {
    return this->listaInspeccionesDetalle;
}

void Inspeccion::setListaInspeccionesDetalle(List<InspeccionDetalle^>^ listaInspeccionesDetalle) {
    this->listaInspeccionesDetalle = listaInspeccionesDetalle;
}

void Inspeccion::addDetalle(InspeccionDetalle^ detalle) {
    this->listaInspeccionesDetalle->Add(detalle);
}

bool Inspeccion::removeDetalle(int detalleId) {
    for (int i = 0; i < this->listaInspeccionesDetalle->Count; i++) {
        if (this->listaInspeccionesDetalle[i]->getInspeccionDetalleId() == detalleId) {
            this->listaInspeccionesDetalle->RemoveAt(i);
            return true;
        }
    }
    return false;
}

String^ Inspeccion::ToString() {
    return String::Format("Inspección #{0} - Lote: {1}, Inspector: {2}, Resultado: {3}",
        this->inspeccionId, this->codigoLote, this->inspector, this->resultadoGeneral);
}

int Inspeccion::getDetalleCount() {
    return this->listaInspeccionesDetalle->Count;
}

