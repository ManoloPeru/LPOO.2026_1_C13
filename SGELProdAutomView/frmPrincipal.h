#pragma once
#include "frmMantUnidadRobotica.h"
#include "frmMantEstacionTrabajo.h"
#include "frmWorkspaceVisualizer.h"
#include "frmNuevoMantenimiento.h"
#include "frmNuevaInspeccion.h"

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ unidadRoboticaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ estacionDeTrabajoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ seguridadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ workspaceLimitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ unidadRobóticaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ inspeccionesToolStripMenuItem;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mantenimientoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unidadRoboticaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->estacionDeTrabajoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenimientosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->unidadRobóticaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->seguridadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->workspaceLimitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inspeccionesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->mantenimientoToolStripMenuItem,
					this->mantenimientosToolStripMenuItem, this->seguridadToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(862, 33);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mantenimientoToolStripMenuItem
			// 
			this->mantenimientoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->unidadRoboticaToolStripMenuItem,
					this->estacionDeTrabajoToolStripMenuItem
			});
			this->mantenimientoToolStripMenuItem->Name = L"mantenimientoToolStripMenuItem";
			this->mantenimientoToolStripMenuItem->Size = System::Drawing::Size(151, 29);
			this->mantenimientoToolStripMenuItem->Text = L"Administración";
			// 
			// unidadRoboticaToolStripMenuItem
			// 
			this->unidadRoboticaToolStripMenuItem->Name = L"unidadRoboticaToolStripMenuItem";
			this->unidadRoboticaToolStripMenuItem->Size = System::Drawing::Size(245, 30);
			this->unidadRoboticaToolStripMenuItem->Text = L"Unidad robótica";
			this->unidadRoboticaToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::unidadRoboticaToolStripMenuItem_Click);
			// 
			// estacionDeTrabajoToolStripMenuItem
			// 
			this->estacionDeTrabajoToolStripMenuItem->Name = L"estacionDeTrabajoToolStripMenuItem";
			this->estacionDeTrabajoToolStripMenuItem->Size = System::Drawing::Size(245, 30);
			this->estacionDeTrabajoToolStripMenuItem->Text = L"Estacion de trabajo";
			this->estacionDeTrabajoToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::estacionDeTrabajoToolStripMenuItem_Click);
			// 
			// mantenimientosToolStripMenuItem
			// 
			this->mantenimientosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->unidadRobóticaToolStripMenuItem,
					this->inspeccionesToolStripMenuItem
			});
			this->mantenimientosToolStripMenuItem->Name = L"mantenimientosToolStripMenuItem";
			this->mantenimientosToolStripMenuItem->Size = System::Drawing::Size(161, 29);
			this->mantenimientosToolStripMenuItem->Text = L"Mantenimientos";
			// 
			// unidadRobóticaToolStripMenuItem
			// 
			this->unidadRobóticaToolStripMenuItem->Name = L"unidadRobóticaToolStripMenuItem";
			this->unidadRobóticaToolStripMenuItem->Size = System::Drawing::Size(220, 30);
			this->unidadRobóticaToolStripMenuItem->Text = L"Unidad robótica";
			this->unidadRobóticaToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::unidadRobóticaToolStripMenuItem_Click);
			// 
			// seguridadToolStripMenuItem
			// 
			this->seguridadToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->workspaceLimitToolStripMenuItem });
			this->seguridadToolStripMenuItem->Name = L"seguridadToolStripMenuItem";
			this->seguridadToolStripMenuItem->Size = System::Drawing::Size(110, 29);
			this->seguridadToolStripMenuItem->Text = L"Seguridad";
			// 
			// workspaceLimitToolStripMenuItem
			// 
			this->workspaceLimitToolStripMenuItem->Name = L"workspaceLimitToolStripMenuItem";
			this->workspaceLimitToolStripMenuItem->Size = System::Drawing::Size(222, 30);
			this->workspaceLimitToolStripMenuItem->Text = L"Workspace Limit";
			this->workspaceLimitToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::workspaceLimitToolStripMenuItem_Click);
			// 
			// inspeccionesToolStripMenuItem
			// 
			this->inspeccionesToolStripMenuItem->Name = L"inspeccionesToolStripMenuItem";
			this->inspeccionesToolStripMenuItem->Size = System::Drawing::Size(220, 30);
			this->inspeccionesToolStripMenuItem->Text = L"Inspecciones";
			this->inspeccionesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::inspeccionesToolStripMenuItem_Click);
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(862, 460);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"frmPrincipal";
			this->Text = L"Sistema de Gestión de Ensamblaje - Línea de Producción Automatizada de Mecatrónic"
				L"a";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void unidadRoboticaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Crear una nueva instancia del formulario de unidadRobotica
		// y mostrarlo como un formulario hijo dentro del contenedor MDI
		frmMantUnidadRobotica^ unidadRoboticaForm = gcnew frmMantUnidadRobotica();
		unidadRoboticaForm->MdiParent = this; // Establecer el formulario principal como padre
		unidadRoboticaForm->Show(); // Mostrar el formulario hijo
	}
private: System::Void estacionDeTrabajoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	frmMantEstacionTrabajo^ estacionTrabajoForm = gcnew frmMantEstacionTrabajo();
	estacionTrabajoForm->MdiParent = this; // Establecer el formulario principal como padre
	estacionTrabajoForm->Show(); // Mostrar el formulario hijo
}
private: System::Void workspaceLimitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	frmWorkspaceVisualizer^ workspaceVisualizerForm = gcnew frmWorkspaceVisualizer();
	workspaceVisualizerForm->MdiParent = this; // Establecer el formulario principal como padre
	workspaceVisualizerForm->Show(); // Mostrar el formulario hijo
}
private: System::Void unidadRobóticaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	frmNuevoMantenimiento^ nuevoMantenimientoForm = gcnew frmNuevoMantenimiento();
	nuevoMantenimientoForm->MdiParent = this; // Establecer el formulario principal como padre
	nuevoMantenimientoForm->Show(); // Mostrar el formulario hijo
}
private: System::Void inspeccionesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	frmNuevaInspeccion^ nuevaInspeccionForm = gcnew frmNuevaInspeccion();
	nuevaInspeccionForm->MdiParent = this; // Establecer el formulario principal como padre
	nuevaInspeccionForm->Show(); // Mostrar el formulario hijo
}
};
}
