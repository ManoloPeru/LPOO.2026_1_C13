#include "Robot.h"

namespace SGELProdAutomModel {
	Robot::Robot() {
		idRobot = 0;
		nombre = "RobotBase";
		modeloChasis = "ChasisStd";
		cargaUtilMaxima = 10.0;
		masaTotal = 50.0;
		alcanceMaximo = 1.5;
		listaComponentes = gcnew List<ComponenteRobotico^>();
		fuenteAsociada = nullptr;
	}
	Robot::Robot(int id, String^ nombre, String^ modelo, double payload, double masa, double reach) {
		idRobot = id;
		this->nombre = nombre;
		modeloChasis = modelo;
		cargaUtilMaxima = payload;
		masaTotal = masa;
		alcanceMaximo = reach;
		listaComponentes = gcnew List<ComponenteRobotico^>();
		fuenteAsociada = nullptr;
	}
	int Robot::getIdRobot() {
		return idRobot;
	}
	void Robot::setIdRobot(int id) {
		idRobot = id;
	}
	String^ Robot::getNombre() {
		return nombre;
	}
	void Robot::setNombre(String^ nombre) {
		this->nombre = nombre;
	}
	String^ Robot::getModeloChasis() {
		return modeloChasis;
	}
	void Robot::setModeloChasis(String^ modelo) {
		modeloChasis = modelo;
	}
	double Robot::getCargaUtilMaxima() {
		return cargaUtilMaxima;
	}
	void Robot::setCargaUtilMaxima(double payload) {
		cargaUtilMaxima = payload;
	}
	double Robot::getMasaTotal() {
		return masaTotal;
	}
	void Robot::setMasaTotal(double masa) {
		masaTotal = masa;
	}
	double Robot::getAlcanceMaximo() {
		return alcanceMaximo;
	}
	void Robot::setAlcanceMaximo(double reach) {
		alcanceMaximo = reach;
	}

	void Robot::agregarComponente(ComponenteRobotico^ componente) {
		if (componente != nullptr) {
			this->listaComponentes->Add(componente);
		}
	}

	void Robot::removerComponente(String^ idHardware) {
		for (int i = 0; i < listaComponentes->Count; i++) {
			if (listaComponentes[i]->getIdentificadorHardware() == idHardware) {
				listaComponentes->RemoveAt(i);
				break;
			}
		}
	}

	void Robot::asociarFuente(FuentePotencia^ fuente) {
		fuenteAsociada = fuente;
	}

	double Robot::calcularMasaTotal() {
		double masaComponentes = 0.0;
		for each (ComponenteRobotico ^ componente in listaComponentes) {
			// Aquí se podría agregar un método getMasa() a ComponenteRobotico para obtener la masa de cada componente
			// Por ahora, asumiremos una masa fija por componente para la simulación
			masaComponentes += 5.0; // kg por componente (simulación)
		}
		return masaTotal + masaComponentes; // Masa del chasis + componentes
	}

	String^ Robot::ReportarConfiguracion() {
		String^ reporte = String::Format("Robot ID: {0}, Nombre: {1}, Modelo Chasis: {2}, Carga Útil Máxima: {3} kg, Masa Total: {4} kg, Alcance Máximo: {5} m\n",
			idRobot, nombre, modeloChasis, cargaUtilMaxima, masaTotal, alcanceMaximo);
		reporte += "Componentes:\n";
		for each (ComponenteRobotico ^ componente in listaComponentes) {
			reporte += "- " + componente->ReportarConfiguracion() + "\n";
		}
		if (fuenteAsociada != nullptr) {
			reporte += "Fuente de Potencia Asociada:\n" + fuenteAsociada->ReportarConfiguracion() + "\n";
		}
		else {
			reporte += "No hay fuente de potencia asociada.\n";
		}
		return reporte;
	}
}