#pragma once
#include "BaseController.h" // 1.- Incluyendo la clase base para conectarme a la BD

namespace SGELProdAutomController {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Data;
    using namespace System::Data::SqlClient;
    using namespace SGELProdAutomModel;

    /// <summary>
    /// Controlador para gestionar las operaciones CRUD de Mantenimiento
    /// Hereda de BaseController para acceso a la base de datos
    /// </summary>
    public ref class MantenimientoController : public BaseController {
    private:
        List<Mantenimiento^>^ listaMantenimientos;

    public:
        MantenimientoController();

        // =====================================================================
        // OPERACIONES TRANSACCIONALES PRINCIPALES (Cabecera + Detalles)
        // =====================================================================

        /// <summary>
        /// Registra un mantenimiento completo (cabecera + detalles) en la base de datos
        /// Utiliza una transacción para asegurar la integridad de los datos
        /// </summary>
        /// <param name="mantenimiento">Objeto Mantenimiento con sus detalles</param>
        /// <returns>El ID del mantenimiento registrado, o 0 si falla</returns>
        int RegistrarMantenimientoCompleto(Mantenimiento^ mantenimiento);


        /// <summary>
        /// Registra un mantenimiento 
        /// </summary>
        /// <param name="mantenimiento">Objeto Mantenimiento con sus detalles actualizados</param>
        /// <returns>mantenimientoId si la actualización fue exitosa, 0 en caso contrario</returns>
        int MantenimientoController::AgregarMantenimiento(Mantenimiento^ mantenimiento);

        /// <summary>
        /// Actualiza un mantenimiento completo (cabecera + detalles)
        /// </summary>
        /// <param name="mantenimiento">Objeto Mantenimiento con sus detalles actualizados</param>
        /// <returns>true si la actualización fue exitosa, false en caso contrario</returns>
        bool ActualizarMantenimientoCompleto(Mantenimiento^ mantenimiento);

        /// <summary>
        /// Elimina un mantenimiento y todos sus detalles asociados
        /// </summary>
        /// <param name="mantenimientoId">ID del mantenimiento a eliminar</param>
        /// <returns>true si la eliminación fue exitosa, false en caso contrario</returns>
        bool EliminarMantenimiento(int mantenimientoId);

        // =====================================================================
        // OPERACIONES DE CONSULTA (READ)
        // =====================================================================

        /// <summary>
        /// Obtiene un mantenimiento con todos sus detalles por ID
        /// </summary>
        /// <param name="mantenimientoId">ID del mantenimiento</param>
        /// <returns>Objeto Mantenimiento con sus detalles, o nullptr si no existe</returns>
        Mantenimiento^ ConsultarMantenimientoPorId(int mantenimientoId);

        /// <summary>
        /// Obtiene todos los mantenimientos de un robot específico
        /// </summary>
        /// <param name="robotId">ID del robot</param>
        /// <returns>Lista de mantenimientos del robot</returns>
        List<Mantenimiento^>^ ConsultarMantenimientosPorRobot(int robotId);

        /// <summary>
        /// Obtiene todos los mantenimientos registrados en el sistema
        /// </summary>
        /// <returns>Lista completa de mantenimientos</returns>
        List<Mantenimiento^>^ ListarTodosMantenimientos();

        /// <summary>
        /// Obtiene mantenimientos por tipo (Preventivo, Correctivo)
        /// </summary>
        /// <param name="tipoMantenimiento">Tipo de mantenimiento</param>
        /// <returns>Lista de mantenimientos del tipo especificado</returns>
        List<Mantenimiento^>^ ConsultarMantenimientosPorTipo(String^ tipoMantenimiento);

        /// <summary>
        /// Obtiene mantenimientos por técnico responsable
        /// </summary>
        /// <param name="tecnico">Nombre del técnico</param>
        /// <returns>Lista de mantenimientos realizados por el técnico</returns>
        List<Mantenimiento^>^ ConsultarMantenimientosPorTecnico(String^ tecnico);

        /// <summary>
        /// Obtiene mantenimientos por rango de fechas
        /// </summary>
        /// <param name="fechaInicio">Fecha de inicio</param>
        /// <param name="fechaFin">Fecha de fin</param>
        /// <returns>Lista de mantenimientos en el rango de fechas</returns>
        List<Mantenimiento^>^ ConsultarMantenimientosPorFecha(DateTime fechaInicio, DateTime fechaFin);

        // =====================================================================
        // OPERACIONES DE DETALLE (operaciones auxiliares)
        // =====================================================================

        /// <summary>
        /// Agrega un detalle a un mantenimiento existente
        /// </summary>
        /// <param name="detalle">Detalle a agregar</param>
        /// <returns>true si la operación fue exitosa, false en caso contrario</returns>
        bool AgregarDetalleMantenimiento(MantenimientoDetalle^ detalle);

        /// <summary>
        /// Elimina un detalle específico de un mantenimiento
        /// </summary>
        /// <param name="detalleId">ID del detalle a eliminar</param>
        /// <returns>true si la operación fue exitosa, false en caso contrario</returns>
        bool EliminarDetalleMantenimiento(int detalleId);

        /// <summary>
        /// Obtiene todos los detalles de un mantenimiento
        /// </summary>
        /// <param name="mantenimientoId">ID del mantenimiento</param>
        /// <returns>Lista de detalles del mantenimiento</returns>
        List<MantenimientoDetalle^>^ ConsultarDetallesPorMantenimiento(int mantenimientoId);

        // =====================================================================
        // OPERACIONES DE LIMPIEZA Y CIERRE
        // =====================================================================

        /// <summary>
        /// Libera los recursos utilizados por el controlador
        /// </summary>
        void Close();
    };
}