#include "BaseController.h"

using namespace SGELProdAutomController;
using namespace System::IO;

// Constructor de la clase BaseController, se encarga de inicializar el objeto de conexion
BaseController::BaseController() {
	this->objConexion = gcnew SqlConnection();
}

// Metodo para obtener el objeto de conexion
SqlConnection^ BaseController::getObjConexion() {
	return this->objConexion;
}

// Metodo para establecer la conexion a la base de datos
void BaseController::abrirConexion() {
	/*Paso 1, establecer la cadena de conexion*/
	/*LOCAL*/
	//this->objConexion->ConnectionString = "Server=localhost;DataBase=lpoo_2025_2;User id=sa;Password={PWD}";
	
	/*PUCP*/
	//this->objConexion->ConnectionString = "Server={IP};DataBase={BD};User id={User};Password={PWD}";

	/*AWS*/
	//this->objConexion->ConnectionString = "Server={PORT_LINK};DataBase={DB};User id={USR};Password={PWD}";
	
	/*Paso 2, abrir la conexion*/
	this->objConexion->Open();
}

// Metodo para ejecutar sentencias INSERT SQL en la Base de Datos, devuelve el IdPK generado
int BaseController::insertSql(String^ sSql) {
	try {
		abrirConexion();
		String^ sSqlPK = sSql + "; SELECT SCOPE_IDENTITY();"; // SCOPE_IDENTITY(): Permite obtener el valor del IdPK generado
		SqlCommand^ comando = gcnew SqlCommand(sSqlPK, this->getObjConexion());
		int idPK = Convert::ToInt32(comando->ExecuteScalar()); // ExecuteScalar(): Ejecuta la consulta y devuelve la primera columna de la primera fila del conjunto de resultados
		this->cerrarConexion();
		return idPK;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar SQL: " + ex->Message);
		return 0;
	}
}

// Metodo para ejecutar sentencias UPDATE/DELETE SQL en la Base de Datos, devuelve true si se ejecutó correctamente
bool BaseController::executeSql(String^ sSql) {
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(sSql, this->getObjConexion());
		comando->ExecuteNonQuery(); // ExecuteNonQuery(): Ejecuta una sentencia SQL que no devuelve filas (como UPDATE o DELETE)
		this->cerrarConexion();
		return true;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar SQL: " + ex->Message);
		return false;
	}
}

// Metodo para cerrar la conexion a la base de datos
void BaseController::cerrarConexion() {
	//Paso 3, cerrar la conexion
	this->objConexion->Close();
}

/******************************************************************************************************************************/
/* METODOS PARA PROCEDIMIENTOS ALMACENADOS (SIN TRANSACCIÓN)                                                                   */
/******************************************************************************************************************************/

// Metodo para ejecutar procedimientos almacenados (tipo SELECT) que devuelven un SqlDataReader
SqlDataReader^ BaseController::executeStoredProcedureReader(String^ procedureName, array<SqlParameter^>^ parameters) {
	//procedureName: Nombre del procedimiento almacenado
	//parameters: Arreglo de parÃ¡metros para el procedimiento almacenado
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(procedureName, this->getObjConexion());
		comando->CommandType = CommandType::StoredProcedure;

		if (parameters != nullptr) {
			for each (SqlParameter ^ param in parameters) {
				comando->Parameters->Add(param);
			}
		}

		return comando->ExecuteReader();
		// Nota: La conexiÃ³n se cierra despuÃ©s de usar el DataReader
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar procedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return nullptr;
	}
}

// Metodo para ejecutar procedimientos almacenados (tipo INSERT/UPDATE/DELETE) que no devuelven resultados
bool BaseController::executeStoredProcedure(String^ procedureName, array<SqlParameter^>^ parameters) {
	//procedureName: Nombre del procedimiento almacenado
	//parameters: Arreglo de parÃ¡metros para el procedimiento almacenado
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(procedureName, this->getObjConexion());
		comando->CommandType = CommandType::StoredProcedure;

		// Agregar parÃ¡metros si existen
		if (parameters != nullptr) {
			for each (SqlParameter ^ param in parameters) {
				comando->Parameters->Add(param);
			}
		}

		comando->ExecuteNonQuery();
		cerrarConexion();
		return true;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar procedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return false;
	}
}

// Método para ejecutar procedimientos almacenados que tienen parámetros OUTPUT
int BaseController::executeStoredProcedureWithOutput(String^ procedureName, array<SqlParameter^>^ parameters, String^ outputParamName) {
	try {
		abrirConexion();
		SqlCommand^ comando = gcnew SqlCommand(procedureName, this->getObjConexion());
		comando->CommandType = CommandType::StoredProcedure;

		if (parameters != nullptr) {
			for each (SqlParameter ^ param in parameters) {
				comando->Parameters->Add(param);
			}
		}

		comando->ExecuteNonQuery();

		// Obtener el valor del parámetro OUTPUT
		int outputValue = 0;
		if (comando->Parameters->Contains(outputParamName)) {
			Object^ result = comando->Parameters[outputParamName]->Value;
			if (result != nullptr && result != DBNull::Value) {
				outputValue = Convert::ToInt32(result);
			}
		}

		cerrarConexion();
		return outputValue;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error al ejecutar procedimiento almacenado: " + ex->Message);
		cerrarConexion();
		return 0;
	}
}
