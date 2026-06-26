#pragma once
#include "ComponenteRobotico.h"
#include "FuentePotencia.h"
#include <List>

namespace SGELProdAutomModel {
    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Robot {
    private:
        int idRobot;
        String^ nombre;
        String^ modeloChasis;
        double cargaUtilMaxima;    // kg
        double masaTotal;          // kg
        double alcanceMaximo;      // m
        List<ComponenteRobotico^>^ listaComponentes;  // Agregación
        FuentePotencia^ fuenteAsociada;               // Asociación

    public:
        Robot();
        Robot(int id, String^ nombre, String^ modelo, double payload, double masa, double reach);

        int getIdRobot();
        void setIdRobot(int id);

        String^ getNombre();
        void setNombre(String^ nombre);

        String^ getModeloChasis();
        void setModeloChasis(String^ modelo);

        double getCargaUtilMaxima();
        void setCargaUtilMaxima(double payload);

        double getMasaTotal();
        void setMasaTotal(double masa);

        double getAlcanceMaximo();
        void setAlcanceMaximo(double reach);

        void agregarComponente(ComponenteRobotico^ componente);
        void removerComponente(String^ idHardware);
        void asociarFuente(FuentePotencia^ fuente);
        double calcularMasaTotal();  // Suma masas de componentes + chasis (estimado)
        String^ ReportarConfiguracion();
    };
}