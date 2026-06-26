#include "UnidadRobotica.h"

namespace SGELProdAutomModel {
    UnidadRobotica::UnidadRobotica() {
        this->robotId = 0;
        this->alias = "SIN_NOMBRE";
        this->ubicacion = "SIN_UBICACION";
        this->estado = EstadoOperativo::Falla;
        this->gradosLibertad = 0;
        this->horasTrabajo = 0.0;
    }

    UnidadRobotica::UnidadRobotica(int robotId, String^ alias, String^ ubicacion,
        EstadoOperativo estado, int gradosLibertad, double horasTrabajo) {
        this->robotId = robotId;
        this->alias = alias;
        this->ubicacion = ubicacion;
        this->estado = estado;
        this->gradosLibertad = gradosLibertad;
        this->horasTrabajo = horasTrabajo;
    }

    // Getters y Setters
    int UnidadRobotica::getRobotId() {
        return this->robotId;
    }

    void UnidadRobotica::setRobotId(int value) {
        this->robotId = value;
    }

    String^ UnidadRobotica::getAlias() {
        return this->alias;
    }

    void UnidadRobotica::setAlias(String^ value) {
        this->alias = value;
    }

    String^ UnidadRobotica::getUbicacion() {
        return this->ubicacion;
    }

    void UnidadRobotica::setUbicacion(String^ value) {
        this->ubicacion = value;
    }

    EstadoOperativo UnidadRobotica::getEstado() {
        return this->estado;
    }

    void UnidadRobotica::setEstado(EstadoOperativo value) {
        this->estado = value;
    }

    int UnidadRobotica::getGradosLibertad() {
        return this->gradosLibertad;
    }

    void UnidadRobotica::setGradosLibertad(int value) {
        this->gradosLibertad = value;
    }

    double UnidadRobotica::getHorasTrabajo() {
        return this->horasTrabajo;
    }

    void UnidadRobotica::setHorasTrabajo(double value) {
        this->horasTrabajo = value;
    }

    // Método para convertir el estado operativo a una cadena legible
    String^ UnidadRobotica::ObtenerEstadoString() {
        switch (this->estado) {
        case EstadoOperativo::Operativo:
            return "Operativo";
        case EstadoOperativo::EnMantenimiento:
            return "En Mantenimiento";
        case EstadoOperativo::Falla:
            return "Falla";
        default:
            return "Desconocido";
        }
    }

    // Método para convertir una cadena a un valor del enum EstadoOperativo
    EstadoOperativo UnidadRobotica::ConvertirEstadoOperativo(String^ estadoStr) {
        if (estadoStr == "Operativo") return EstadoOperativo::Operativo;
        if (estadoStr == "En Mantenimiento") return EstadoOperativo::EnMantenimiento;
        if (estadoStr == "Mantenimiento") return EstadoOperativo::EnMantenimiento;  // Variante
        return EstadoOperativo::Falla;
    }

    // Método ToString para representar la unidad robótica
    String^ UnidadRobotica::ToString() {
        return String::Format(
            "Robot ID: {0},  Alias: {1},  Ubicacion: {2},  Estado: {3},  Grados Libertad: {4},  Horas Trabajo: {5:F2}",
            this->robotId, this->alias, this->ubicacion, ObtenerEstadoString(),
            this->gradosLibertad, this->horasTrabajo);
    }
}