#include "MantenimientoDetalle.h"

namespace SGELProdAutomModel {
    // Constructor por defecto
    MantenimientoDetalle::MantenimientoDetalle() {
        this->mantenimientoDetailId = 0;
        this->mantenimientoId = 0;
        this->actividad = "SIN_ACTIVIDAD";
        this->duracionMinutos = 0;
    }

    // Constructor con parámetros
    MantenimientoDetalle::MantenimientoDetalle(int mantenimientoDetailId, int mantenimientoId, String^ actividad, int duracionMinutos) {
        this->mantenimientoDetailId = mantenimientoDetailId;
        this->mantenimientoId = mantenimientoId;
        this->actividad = actividad;
        this->duracionMinutos = duracionMinutos;
    }

    // Getters y Setters
    int MantenimientoDetalle::getMantenimientoDetailId() {
        return mantenimientoDetailId;
    }

    void MantenimientoDetalle::setMantenimientoDetailId(int value) {
        mantenimientoDetailId = value;
    }

    int MantenimientoDetalle::getMantenimientoId() {
        return mantenimientoId;
    }

    void MantenimientoDetalle::setMantenimientoId(int value) {
        mantenimientoId = value;
    }

    String^ MantenimientoDetalle::getActividad() {
        return actividad;
    }

    void MantenimientoDetalle::setActividad(String^ value) {
        actividad = value;
    }

    int MantenimientoDetalle::getDuracionMinutos() {
        return duracionMinutos;
    }

    void MantenimientoDetalle::setDuracionMinutos(int value) {
        duracionMinutos = value;
    }

    // Método para obtener duración formateada
    String^ MantenimientoDetalle::ObtenerDuracionFormateada() {
        if (duracionMinutos >= 60) {
            int horas = duracionMinutos / 60;
            int minutos = duracionMinutos % 60;
            if (minutos > 0) {
                return String::Format("{0}h {1}min", horas, minutos);
            }
            else {
                return String::Format("{0}h", horas);
            }
        }
        else {
            return String::Format("{0}min", duracionMinutos);
        }
    }

    // ToString
    String^ MantenimientoDetalle::ToString() {
        return String::Format(
            "Detalle ID: {0}\n  Actividad: {1}\n  Duración: {2}",
            mantenimientoDetailId, actividad, ObtenerDuracionFormateada());
    }
}