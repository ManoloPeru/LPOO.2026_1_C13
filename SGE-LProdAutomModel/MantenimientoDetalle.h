#pragma once

namespace SGELProdAutomModel {
    using namespace System;

    /// <summary>
    /// Clase que representa el detalle de una actividad de mantenimiento
    /// </summary>
    public ref class MantenimientoDetalle {
    private:
        int mantenimientoDetailId;
        int mantenimientoId;
        String^ actividad;          // e.g., "Calibración de home", "Cambio de grasa"
        int duracionMinutos;

    public:
        // Constructores
        MantenimientoDetalle();
        MantenimientoDetalle(int mantenimientoDetailId, int mantenimientoId,  String^ actividad, int duracionMinutos);

        // Getters y Setters
        int getMantenimientoDetailId();
        void setMantenimientoDetailId(int value);

        int getMantenimientoId();
        void setMantenimientoId(int value);

        String^ getActividad();
        void setActividad(String^ value);

        int getDuracionMinutos();
        void setDuracionMinutos(int value);

        // Métodos
        virtual String^ ToString() override;
        String^ ObtenerDuracionFormateada();  // Devuelve "2h 30min" o "45min"
    };
}