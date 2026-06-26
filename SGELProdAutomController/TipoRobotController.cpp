#include "TipoRobotController.h"
using namespace System::IO;

namespace SGELProdAutomController {
    TipoRobotController::TipoRobotController(String^ pathArchivo) {
        //Paso 1: Construye la ruta completa del archivo de operadores
        this->pathArchivo = Path::Combine(pathArchivo, "tipoRobot.txt");
        //Paso 2: Asegura que el directorio exista y carga los operadores desde el archivo
        String^ dir = Path::GetDirectoryName(this->pathArchivo);
        //Paso3: Si el directorio no existe, lo crea (no falla si ya existe)
        Directory::CreateDirectory(dir);
        //Paso 4: Si el archivo no existe, lo crea vacío. Luego lee las líneas del archivo y carga los operadores en la lista
        if (!File::Exists(this->pathArchivo)) {
            // Si el archivo no existe, lo crea vacío
            File::WriteAllText(this->pathArchivo, "");
        }
        // Lee las líneas del archivo y carga los operadores en la lista
        array<String^>^ lineas = File::ReadAllLines(this->pathArchivo);
        // Inicializar el repositorio en memoria
        this->repositorio = gcnew List<TipoRobot^>();
        // Define el separador para dividir los campos en cada línea
        String^ separadores = ";";
        for each (String ^ linea in lineas) {
            array<String^>^ campos = linea->Split(separadores->ToCharArray());
            int id = Convert::ToInt32(campos[0]);
            String^ tipoRobot = campos[1];

            TipoRobot^ tipo = gcnew TipoRobot(id, tipoRobot);
            this->repositorio->Add(tipo);
        }
    }

	// ListarTiposRobot devuelve la lista completa de tipos de robots registrados en el repositorio
    List<TipoRobot^>^ TipoRobotController::ListarTiposRobot() {
		return repositorio; // Devuelve la referencia a la lista completa de tipos de robots
    }
}