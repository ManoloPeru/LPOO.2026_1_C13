#pragma once
namespace SGELProdAutomController {
	using namespace System;
	using namespace System::Data;
	using namespace System::Data::SqlClient; //Agregar las referencias: System / System::Data

	public ref class BaseController {
	private:
		SqlConnection^ objConexion; /*Es el atributo que va a ayudarnos a establecer la conexion con la BD*/

	public:
		BaseController(); // Constructor
		SqlConnection^ getObjConexion(); // Metodo para obtener el objeto de conexion
		void abrirConexion();	// Metodo para abrir la conexion
		int insertSql(String^ sSql); // Metodo para ejecutar sentencias INSERT SQL en la Base de Datos
		bool executeSql(String^ sSql); // Metodo para ejecutar sentencias UPDATE/DELETE SQL en la Base de Datos
		void cerrarConexion(); // Metodo para cerrar la conexion

		//Metodo para ejecutar procedimientos almacenados
		SqlDataReader^ executeStoredProcedureReader(String^ procedureName, array<SqlParameter^>^ parameters);
		bool executeStoredProcedure(String^ procedureName, array<SqlParameter^>^ parameters);
		int executeStoredProcedureWithOutput(String^ procedureName, array<SqlParameter^>^ parameters, String^ outputParamName);

	};
}