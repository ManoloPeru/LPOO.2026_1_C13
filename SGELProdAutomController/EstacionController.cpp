#include "EstacionController.h"
using namespace System::IO; // Agregar esta línea para usar System::IO para manejo de archivos
using namespace System::Runtime::Serialization::Formatters::Binary;

namespace SGELProdAutomController {
    EstacionController::EstacionController(String^ pathArchivo) {
        // Paso 1: Inicializar el repositorio en memoria
        this->repositorio = gcnew List<EstacionTrabajo^>();

        // Paso 2: Construir la ruta completa del archivo
        this->pathArchivo = Path::Combine(pathArchivo, "estacionTrabajo.bin");

        // Paso 3: Asegurar que el directorio exista
        String^ dir = Path::GetDirectoryName(this->pathArchivo);
        Directory::CreateDirectory(dir);

        // Paso 4: Si el archivo no existe, lo crea vacío
        if (!File::Exists(this->pathArchivo)) {
            // Crear un archivo vacío pero con una lista serializable vacía
            List<EstacionTrabajo^>^ listaVacia = gcnew List<EstacionTrabajo^>();
            Stream^ stream = File::Open(this->pathArchivo, FileMode::Create);
            BinaryFormatter^ formateador = gcnew BinaryFormatter();
            formateador->Serialize(stream, listaVacia);
            stream->Close();
        }

        // Paso 5: Verificar si el archivo está vacío
        FileInfo^ infoArchivo = gcnew FileInfo(this->pathArchivo);
        if (infoArchivo->Length == 0) {
            return; // Archivo vacío, inicializar lista vacía
        }

        // Intentar deserializar el archivo
        Stream^ stream = File::Open(this->pathArchivo, FileMode::Open);
        BinaryFormatter^ formateador = gcnew BinaryFormatter();
        // Deserializar y convertir al tipo correcto
        this->repositorio = dynamic_cast<List<EstacionTrabajo^>^>(formateador->Deserialize(stream));
        stream->Close();
    }

	// RegistrarEstacion valida que la estación no sea nula y que el ID no esté duplicado antes de agregarla al repositorio
    bool EstacionController::RegistrarEstacion(EstacionTrabajo^ estacion) {
		if (estacion == nullptr) return false; // Estación nula, no se puede registrar
		// Validar que el ID no esté vacío o nulo
		if (String::IsNullOrEmpty(estacion->getId()) || ExisteEstacion(estacion->getId())) return false; // ID vacío o duplicado, no se puede registrar

		// Agregar la estación al repositorio
        this->repositorio->Add(estacion);
        escribirArchivoBIN();
        return true;
    }

	// ConsultarEstacion busca una estación de trabajo por su ID, devolviendo la estación encontrada o nullptr si no se encuentra
    EstacionTrabajo^ EstacionController::ConsultarEstacion(String^ id) {
        if (String::IsNullOrEmpty(id)) return nullptr;

        for each (EstacionTrabajo ^ estacion in this->repositorio) {
            if (estacion->getId()->Equals(id, StringComparison::OrdinalIgnoreCase)) {
                return estacion;
            }
        }
        return nullptr;
    }

	// ListarEstaciones devuelve la lista completa de estaciones de trabajo registradas en el repositorio
    List<EstacionTrabajo^>^ EstacionController::ListarEstaciones() {
        return this->repositorio;
    }

	// ModificarEstacion busca una estación por su ID y actualiza sus propiedades con los nuevos valores proporcionados, devolviendo true si la modificación fue exitosa o false si no se encuentra la estación
    bool EstacionController::ModificarEstacion(String^ id, String^ nuevoNombre, String^ nuevoTipo, EstadoEstacion nuevoEstado, int nuevaCapacidad) {
        EstacionTrabajo^ estacion = ConsultarEstacion(id);
		// Validar que la estación exista antes de intentar modificarla
		if (estacion == nullptr) return false; // Estación no encontrada, no se puede modificar

		// Actualizar las propiedades de la estación solo si se proporcionan nuevos valores, de lo contrario mantener los actuales
        if (!String::IsNullOrEmpty(nuevoNombre)) estacion->setNombre(nuevoNombre);
        if (!String::IsNullOrEmpty(nuevoTipo)) estacion->setTipo(nuevoTipo);
        estacion->setEstado(nuevoEstado);
		// La capacidad máxima se actualiza solo si se proporciona un nuevo valor mayor que 0, de lo contrario se mantiene la capacidad actual
        if (nuevaCapacidad > 0) estacion->setCapacidadMaxima(nuevaCapacidad);
		// Escribir los cambios en el archivo
        escribirArchivoBIN();
        return true;
    }

	// EliminarEstacion busca una estación por su ID y la elimina del repositorio si se encuentra, devolviendo true si la eliminación fue exitosa o false si no se encuentra la estación
    bool EstacionController::EliminarEstacion(String^ id) {
		// Buscar la estación por ID
        for (int i = 0; i < this->repositorio->Count; i++) {
			// Comparar ID ignorando mayúsculas/minúsculas
            if (this->repositorio[i]->getId()->Equals(id, StringComparison::OrdinalIgnoreCase)) {
				// Estación encontrada, eliminarla del repositorio
                this->repositorio->RemoveAt(i);
                escribirArchivoBIN();
                return true;
            }
        }
		// Estación no encontrada, no se puede eliminar
        return false;
    }

	// ContarEstaciones devuelve el número total de estaciones de trabajo registradas en el repositorio
    int EstacionController::ContarEstaciones() {
        return this->repositorio->Count;
    }

	// ExisteEstacion utiliza el método ConsultarEstacion para verificar si una estación con el ID dado existe en el repositorio, devolviendo true si se encuentra o false si no se encuentra
    bool EstacionController::ExisteEstacion(String^ id) {
        return ConsultarEstacion(id) != nullptr;
    }

    List<EstacionTrabajo^>^ EstacionController::ConsultarIdTipo(String^ sId, String^ tipoEstacion) {
        List<EstacionTrabajo^>^ listaFiltrada = gcnew List<EstacionTrabajo^>();
        for each (EstacionTrabajo^ estacion in this->repositorio) {
			// La condición de filtrado se ajusta para permitir que si sId o tipoEstacion están vacíos o nulos, se ignore ese criterio en la comparación, lo que permite una búsqueda más flexible
            if (estacion->getId()->Equals(sId, StringComparison::OrdinalIgnoreCase)) {
                // Estación encontrada
                listaFiltrada->Add(estacion);
            }
            else if (estacion->getTipo()->Equals(tipoEstacion, StringComparison::OrdinalIgnoreCase)) {
                // Estación encontrada
                listaFiltrada->Add(estacion);
            }
        }
        return listaFiltrada;
    }

	// escribirArchivoBIN serializa el repositorio de estaciones de trabajo en un archivo binario utilizando BinaryFormatter, asegurando que los cambios se guarden en el disco después de cada operación que modifique el repositorio
    void EstacionController::escribirArchivoBIN() {
        //Creamos el archivo
        Stream^ stream = File::Open(this->pathArchivo, FileMode::Create);
        BinaryFormatter^ formateador = gcnew BinaryFormatter();
        formateador->Serialize(stream, this->repositorio);
        stream->Close();
    }

	// LiberarMemoria establece el repositorio a nullptr para liberar la memoria utilizada por el controlador, aunque en C++/CLI el recolector de basura se encargará de liberar la memoria automáticamente cuando el objeto sea destruido
    void EstacionController::LiberarMemoria() {
        this->repositorio = nullptr;
    }
}