#pragma once

#include "MantenimientoDetalle.h"

namespace SGELProdAutomModel {
    using namespace System;
    using namespace System::Collections::Generic;

    /// <summary>
    /// Clase que representa la cabecera de un mantenimiento
    /// </summary>
    public ref class Mantenimiento {
    private:
        int mantenimientoId;
        int robotId;
        String^ tecnico;
        String^ tipoMantenimiento;     // e.g., "Preventivo", "Correctivo"
        DateTime fechaMantenimiento;
        List<MantenimientoDetalle^>^ listaMantenimientoDetalle;  // Lista dinámica de detalles

    public:
        // Constructores
        Mantenimiento();
        Mantenimiento(int mantenimientoId, int robotId, String^ tecnico,
            String^ tipoMantenimiento, DateTime fechaMantenimiento);

        // Getters y Setters
        int getMantenimientoId();
        void setMantenimientoId(int value);

        int getRobotId();
        void setRobotId(int value);

        String^ getTecnico();
        void setTecnico(String^ value);

        String^ getTipoMantenimiento();
        void setTipoMantenimiento(String^ value);

        DateTime getFechaMantenimiento();
        void setFechaMantenimiento(DateTime value);

        // Métodos para gestionar la ListaMantenimientoDetalle (detalles)
        List<MantenimientoDetalle^>^ getListaMantenimientoDetalle();
        void setListaMantenimientoDetalle(List<MantenimientoDetalle^>^ value);

        void AgregarMantenimientoDetalle(MantenimientoDetalle^ detalle);
        void RemoverMantenimientoDetalle(int mantenimientoDetailId);
        void LimpiarListaMantenimientoDetalle();

        // Métodos de utilidad
        int ContarListaMantenimientoDetalle();
        int ObtenerDuracionTotalMinutos();
        String^ ObtenerDuracionTotalFormateada();

        // Métodos
        virtual String^ ToString() override;
        String^ ObtenerTipoMantenimientoString();
    };
}