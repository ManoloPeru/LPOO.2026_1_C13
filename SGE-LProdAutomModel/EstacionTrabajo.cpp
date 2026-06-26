#include "EstacionTrabajo.h"

namespace SGELProdAutomModel {
    EstacionTrabajo::EstacionTrabajo() {
        id = "DESCONOCIDO";
        nombre = "SIN_NOMBRE";
        tipo = "DESCONOCIDO";
        estado = EstadoEstacion::DetenidaPorAlerta;
        capacidadMaxima = 0;
    }

    EstacionTrabajo::EstacionTrabajo(String^ id, String^ nombre, String^ tipo, EstadoEstacion estado, int capacidadMaxima) {
        this->id = id;
        this->nombre = nombre;
        this->tipo = tipo;
        this->estado = estado;
        this->capacidadMaxima = capacidadMaxima;
    }

    String^ EstacionTrabajo::getId() { return id; }
    void EstacionTrabajo::setId(String^ value) { id = value; }
    String^ EstacionTrabajo::getNombre() { return nombre; }
    void EstacionTrabajo::setNombre(String^ value) { nombre = value; }
    String^ EstacionTrabajo::getTipo() { return tipo; }
    void EstacionTrabajo::setTipo(String^ value) { tipo = value; }
    EstadoEstacion EstacionTrabajo::getEstado() { return estado; }
    void EstacionTrabajo::setEstado(EstadoEstacion value) { estado = value; }
    int EstacionTrabajo::getCapacidadMaxima() { return capacidadMaxima; }
    void EstacionTrabajo::setCapacidadMaxima(int value) { capacidadMaxima = value; }

    String^ EstacionTrabajo::ObtenerEstadoString() {
        switch (estado) {
        case EstadoEstacion::Activa: return "Activa";
        case EstadoEstacion::EnConfiguracion: return "En Configuración";
        case EstadoEstacion::DetenidaPorAlerta: return "Detenida por Alerta";
        default: return "Desconocido";
        }
    }

    EstadoEstacion EstacionTrabajo::ConvertirEstadoEstacion(String^ estadoStr) {
        if (estadoStr == "Activa") return EstadoEstacion::Activa;
        if (estadoStr == "En Configuración") return EstadoEstacion::EnConfiguracion;
        return EstadoEstacion::DetenidaPorAlerta;
    }

    String^ EstacionTrabajo::ConvertirEstadoToString(EstadoEstacion estado) {
        switch (estado) {
        case EstadoEstacion::Activa: return "Activa";
        case EstadoEstacion::EnConfiguracion: return "En Configuración";
        case EstadoEstacion::DetenidaPorAlerta: return "Detenida por Alerta";
        default: return "Desconocido";
        }
    }

    String^ EstacionTrabajo::ToString() {
        return String::Format("ID: {0}\nNombre: {1}\nTipo: {2}\nEstado: {3}\nCapacidad Máxima: {4}",
            id, nombre, tipo, ObtenerEstadoString(), capacidadMaxima);
    }
}