#pragma once
#include "BaseController.h" // 1.- Incluyendo la clase base para conectarme a la BD

namespace SGELProdAutomController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Data;
    using namespace System::Data::SqlClient;
    using namespace SGELProdAutomModel;

    /// <summary>
    /// Controlador para gestionar las operaciones CRUD de Inspeccion
    /// Hereda de BaseController para acceso a la base de datos
    /// </summary>
    public ref class InspeccionController : public BaseController {
    private:
        List<Inspeccion^>^ listaInspecciones;

    public:
        InspeccionController();
        List<Inspeccion^>^ ListarTodos();

        // =====================================================================
        // OPERACIONES DE TRANSACCIÓN ATÓMICA COMPLETA
        // =====================================================================
        int RegistrarInspeccionTransaccional(Inspeccion^ inspeccion);
        int InspeccionController::AgregarInspeccionConTransaccion(Inspeccion^ inspeccion, SqlConnection^ connection, SqlTransaction^ transaction);
        bool InspeccionController::AgregarDetalleInspeccionConTransaccion(InspeccionDetalle^ detalle, SqlConnection^ connection, SqlTransaction^ transaction);
    };
}