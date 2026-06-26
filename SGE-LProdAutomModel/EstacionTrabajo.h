#pragma once

namespace SGELProdAutomModel {
    using namespace System;

    /// <summary>
    /// Enumeración para los estados operativos de una estación de trabajo
    /// </summary>
    public enum class EstadoEstacion {
        Activa,
        EnConfiguracion,
        DetenidaPorAlerta
    };

    /// <summary>
    /// Clase que representa una Estación de Trabajo en la línea de producción
    /// </summary>
    [Serializable] //IMPORTANTE, AGREGAR ESTA LINEA PARA SERIALIZAR
    public ref class EstacionTrabajo {
    private:
        String^ id;              // Identificador único
        String^ nombre;          // Nombre descriptivo
        String^ tipo;            // Tipo de estación (Ensamble, Inspección, Paletizado)
        EstadoEstacion estado;   // Estado operativo
        int capacidadMaxima;     // Capacidad máxima de procesamiento en paralelo

    public:
        // Constructores
        EstacionTrabajo();
        EstacionTrabajo(String^ id, String^ nombre, String^ tipo, EstadoEstacion estado, int capacidadMaxima);

        // Getters y Setters
        String^ getId();
        void setId(String^ value);

        String^ getNombre();
        void setNombre(String^ value);

        String^ getTipo();
        void setTipo(String^ value);

        EstadoEstacion getEstado();
        void setEstado(EstadoEstacion value);

        int getCapacidadMaxima();
        void setCapacidadMaxima(int value);

        // Métodos
        virtual String^ ToString() override;
        String^ ObtenerEstadoString();

        // Método estático para convertir string a EstadoEstacion
        static EstadoEstacion ConvertirEstadoEstacion(String^ estadoStr);
        static String^ ConvertirEstadoToString(EstadoEstacion estado);
    };
}