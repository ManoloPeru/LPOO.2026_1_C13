#include "Mantenimiento.h"

namespace SGELProdAutomModel {
    // Constructor por defecto
    Mantenimiento::Mantenimiento() {
        this->mantenimientoId = 0;
        this->robotId = 0;
        this->tecnico = "SIN_TECNICO";
        this->tipoMantenimiento = "Preventivo";
        this->fechaMantenimiento = DateTime::Now;
        this->listaMantenimientoDetalle = gcnew List<MantenimientoDetalle^>();
    }

    // Constructor con parámetros
    Mantenimiento::Mantenimiento(int mantenimientoId, int robotId, String^ tecnico,
        String^ tipoMantenimiento, DateTime fechaMantenimiento) {
        this->mantenimientoId = mantenimientoId;
        this->robotId = robotId;
        this->tecnico = tecnico;
        this->tipoMantenimiento = tipoMantenimiento;
        this->fechaMantenimiento = fechaMantenimiento;
        this->listaMantenimientoDetalle = gcnew List<MantenimientoDetalle^>();
    }

    // Getters y Setters
    int Mantenimiento::getMantenimientoId() {
        return mantenimientoId;
    }

    void Mantenimiento::setMantenimientoId(int value) {
        mantenimientoId = value;
    }

    int Mantenimiento::getRobotId() {
        return robotId;
    }

    void Mantenimiento::setRobotId(int value) {
        robotId = value;
    }

    String^ Mantenimiento::getTecnico() {
        return tecnico;
    }

    void Mantenimiento::setTecnico(String^ value) {
        tecnico = value;
    }

    String^ Mantenimiento::getTipoMantenimiento() {
        return tipoMantenimiento;
    }

    void Mantenimiento::setTipoMantenimiento(String^ value) {
        tipoMantenimiento = value;
    }

    DateTime Mantenimiento::getFechaMantenimiento() {
        return fechaMantenimiento;
    }

    void Mantenimiento::setFechaMantenimiento(DateTime value) {
        fechaMantenimiento = value;
    }

    List<MantenimientoDetalle^>^ Mantenimiento::getListaMantenimientoDetalle() {
        return listaMantenimientoDetalle;
    }

    void Mantenimiento::setListaMantenimientoDetalle(List<MantenimientoDetalle^>^ value) {
        listaMantenimientoDetalle = value;
    }

    // Métodos para gestionar la lista de MantenimientoDetalle
    void Mantenimiento::AgregarMantenimientoDetalle(MantenimientoDetalle^ detalle) {
        if (detalle != nullptr) {
            listaMantenimientoDetalle->Add(detalle);
        }
    }

    void Mantenimiento::RemoverMantenimientoDetalle(int mantenimientoDetailId) {
        for (int i = 0; i < listaMantenimientoDetalle->Count; i++) {
            if (listaMantenimientoDetalle[i]->getMantenimientoDetailId() == mantenimientoDetailId) {
                listaMantenimientoDetalle->RemoveAt(i);
                break;
            }
        }
    }

    void Mantenimiento::LimpiarListaMantenimientoDetalle() {
        listaMantenimientoDetalle->Clear();
    }

    // Métodos de utilidad
    int Mantenimiento::ContarListaMantenimientoDetalle() {
        return listaMantenimientoDetalle->Count;
    }

    int Mantenimiento::ObtenerDuracionTotalMinutos() {
        int totalMinutos = 0;
        for each (MantenimientoDetalle ^ detalle in listaMantenimientoDetalle) {
            totalMinutos += detalle->getDuracionMinutos();
        }
        return totalMinutos;
    }

    String^ Mantenimiento::ObtenerDuracionTotalFormateada() {
        int totalMinutos = ObtenerDuracionTotalMinutos();

        if (totalMinutos >= 60) {
            int horas = totalMinutos / 60;
            int minutos = totalMinutos % 60;
            if (minutos > 0) {
                return String::Format("{0}h {1}min", horas, minutos);
            }
            else {
                return String::Format("{0}h", horas);
            }
        }
        else {
            return String::Format("{0}min", totalMinutos);
        }
    }

    // Método para obtener el tipo de mantenimiento como string
    String^ Mantenimiento::ObtenerTipoMantenimientoString() {
        return tipoMantenimiento;
    }

    // ToString
    String^ Mantenimiento::ToString() {
        String^ resultado = String::Format(
            "Mantenimiento ID: {0}\n" +
            "  Robot ID: {1}\n" +
            "  Técnico: {2}\n" +
            "  Tipo: {3}\n" +
            "  Fecha: {4:dd/MM/yyyy HH:mm}\n" +
            "  Duración Total: {5}\n" +
            "  Actividades: {6}",
            mantenimientoId, robotId, tecnico, tipoMantenimiento,
            fechaMantenimiento, ObtenerDuracionTotalFormateada(),
            listaMantenimientoDetalle->Count);

        // Agregar detalles de cada actividad
        if (listaMantenimientoDetalle->Count > 0) {
            resultado += "\n\n  --- ACTIVIDADES/CALIBRACIONES ---";
            int contador = 1;
            for each (MantenimientoDetalle ^ detalle in listaMantenimientoDetalle) {
                resultado += String::Format("\n  {0}. {1} ({2})",
                    contador++,
                    detalle->getActividad(),
                    detalle->ObtenerDuracionFormateada());
            }
        }
        else {
            resultado += "\n\n  --- Sin actividades/calibraciones registradas ---";
        }

        return resultado;
    }
}