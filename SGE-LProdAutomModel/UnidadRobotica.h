#pragma once

namespace SGELProdAutomModel {
    using namespace System;

    // Empleamos Enumeración para listar Estados
    public enum class EstadoOperativo {
        Operativo,
        EnMantenimiento,
        Falla
    };

    public ref class UnidadRobotica {
    private:
        int robotId;                // Identificador único (INT, clave primaria)
        String^ alias;              // Nombre descriptivo
        String^ ubicacion;          // Ubicación en la planta
        EstadoOperativo estado;     // Estado operativo
        int gradosLibertad;         // Grados de libertad del robot
        double horasTrabajo;        // Horas de trabajo acumuladas

    public:
        UnidadRobotica();
        UnidadRobotica(int robotId, String^ alias, String^ ubicacion,
            EstadoOperativo estado, int gradosLibertad, double horasTrabajo);

        // Getters y Setters
        int getRobotId();
        void setRobotId(int value);

        String^ getAlias();
        void setAlias(String^ value);

        String^ getUbicacion();
        void setUbicacion(String^ value);

        EstadoOperativo getEstado();
        void setEstado(EstadoOperativo value);

        int getGradosLibertad();
        void setGradosLibertad(int value);

        double getHorasTrabajo();
        void setHorasTrabajo(double value);

        // Métodos
        virtual String^ ToString() override;                    // Representación legible
        String^ ObtenerEstadoString();                          // Convertir estado a cadena
        static EstadoOperativo ConvertirEstadoOperativo(String^ estado);  // Convertir cadena a enum
    };
}