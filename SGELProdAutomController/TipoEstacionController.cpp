#include "TipoEstacionController.h"
using namespace System::IO;
using namespace System::Runtime::Serialization::Formatters::Binary;

namespace SGELProdAutomController {
    TipoEstacionController::TipoEstacionController(String^ pathArchivo) {
        /*
        //Paso 1: Construye la ruta completa del archivo de operadores
        this->pathArchivo = Path::Combine(pathArchivo, "tipoEstacion.bin");
        //Paso 2: Asegura que el directorio exista y carga los operadores desde el archivo
        String^ dir = Path::GetDirectoryName(this->pathArchivo);
        //Paso3: Si el directorio no existe, lo crea (no falla si ya existe)
        Directory::CreateDirectory(dir);
        //Paso 4: Si el archivo no existe, lo crea vacío. Luego lee las líneas del archivo y carga los operadores en la lista
        if (!File::Exists(this->pathArchivo)) {
            // Si el archivo no existe, lo crea vacío
            File::WriteAllText(this->pathArchivo, "");
        }
        //Paso5: proceder con la lectura
        Stream^ stream = File::Open(this->pathArchivo, FileMode::Open);
        BinaryFormatter^ formateador = gcnew BinaryFormatter();
        this->repositorio = dynamic_cast<List<TipoEstacion^>^>(formateador->Deserialize(stream));
        stream->Close();
        */
		// Para simplificar el ejemplo, se inicializa el repositorio con algunos tipos de estaciones predefinidos
		this->repositorio = gcnew List<TipoEstacion^>();
		this->repositorio->Add(gcnew TipoEstacion(1, "Ensamble"));
		this->repositorio->Add(gcnew TipoEstacion(2, "Inspección"));
		this->repositorio->Add(gcnew TipoEstacion(3, "Paletizado"));
    }

    // ListarTiposEstacion devuelve la lista completa de tipos de robots registrados en el repositorio
    List<TipoEstacion^>^ TipoEstacionController::ListarTiposEstacion() {
        return repositorio; // Devuelve la referencia a la lista completa de tipos de robots
    }
}