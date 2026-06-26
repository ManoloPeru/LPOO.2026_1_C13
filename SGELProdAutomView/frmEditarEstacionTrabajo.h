#pragma once

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SGELProdAutomModel;
	using namespace SGELProdAutomController;

	/// <summary>
	/// Resumen de frmEditarEstacionTrabajo
	/// </summary>
	public ref class frmEditarEstacionTrabajo : public System::Windows::Forms::Form
	{
	public:
		frmEditarEstacionTrabajo(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmEditarEstacionTrabajo(EstacionController^ estacionController, TipoEstacionController^ tipoEstacionController, EstacionTrabajo^ objEstacionTrabajo)
		{
			InitializeComponent();
			this->estacionController = estacionController;
			this->tipoEstacionController = tipoEstacionController;
			this->objEstacionTrabajo = objEstacionTrabajo;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarEstacionTrabajo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnGrabar;
	protected:
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::ComboBox^ cmbTipoEstacion;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtCapacidadMax;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;

		   /* Este atributo se crea porque el constructor está recibiendo un objeto del tipo Operador y
			  ese objeto hay que asignarselo a un atributo */
	private: EstacionController^ estacionController;
	private: EstacionTrabajo^ objEstacionTrabajo;
	private: TipoEstacionController^ tipoEstacionController;

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
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->cmbTipoEstacion = (gcnew System::Windows::Forms::ComboBox());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCapacidadMax = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->grpBoxPrincipal->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(123, 355);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(173, 56);
			this->btnGrabar->TabIndex = 18;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmEditarEstacionTrabajo::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(349, 355);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(173, 56);
			this->btnCancelar->TabIndex = 19;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmEditarEstacionTrabajo::btnCancelar_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->Controls->Add(this->cmbTipoEstacion);
			this->grpBoxPrincipal->Controls->Add(this->cmbEstado);
			this->grpBoxPrincipal->Controls->Add(this->label2);
			this->grpBoxPrincipal->Controls->Add(this->txtCapacidadMax);
			this->grpBoxPrincipal->Controls->Add(this->txtNombre);
			this->grpBoxPrincipal->Controls->Add(this->txtId);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(14, 14);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(619, 314);
			this->grpBoxPrincipal->TabIndex = 20;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Información general de la Unidad Robótica";
			// 
			// cmbTipoEstacion
			// 
			this->cmbTipoEstacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbTipoEstacion->FormattingEnabled = true;
			this->cmbTipoEstacion->Location = System::Drawing::Point(190, 150);
			this->cmbTipoEstacion->Name = L"cmbTipoEstacion";
			this->cmbTipoEstacion->Size = System::Drawing::Size(215, 30);
			this->cmbTipoEstacion->TabIndex = 3;
			// 
			// cmbEstado
			// 
			this->cmbEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->Location = System::Drawing::Point(190, 201);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(215, 30);
			this->cmbEstado->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 256);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(176, 24);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Capacidad máxima:";
			// 
			// txtCapacidadMax
			// 
			this->txtCapacidadMax->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCapacidadMax->Location = System::Drawing::Point(190, 252);
			this->txtCapacidadMax->Margin = System::Windows::Forms::Padding(5);
			this->txtCapacidadMax->Name = L"txtCapacidadMax";
			this->txtCapacidadMax->Size = System::Drawing::Size(403, 28);
			this->txtCapacidadMax->TabIndex = 5;
			// 
			// txtNombre
			// 
			this->txtNombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNombre->Location = System::Drawing::Point(190, 104);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(403, 28);
			this->txtNombre->TabIndex = 2;
			// 
			// txtId
			// 
			this->txtId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtId->Location = System::Drawing::Point(190, 57);
			this->txtId->Margin = System::Windows::Forms::Padding(5);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(126, 28);
			this->txtId->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 201);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 24);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Estado:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 150);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Tipo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 104);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Nombre:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 62);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código:";
			// 
			// frmEditarEstacionTrabajo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(657, 450);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Name = L"frmEditarEstacionTrabajo";
			this->Text = L"Mantenimiento de Estación de Trabajo - Edición";
			this->Load += gcnew System::EventHandler(this, &frmEditarEstacionTrabajo::frmEditarEstacionTrabajo_Load);
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEditarEstacionTrabajo_Load(System::Object^ sender, System::EventArgs^ e) {
		List<TipoEstacion^>^ listaTiposEstacion = this->tipoEstacionController->ListarTiposEstacion();
		List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();
		for each (TipoEstacion ^ obj in listaTiposEstacion) {
			int id = obj->getIdTipoEstacion();
			String^ nombre = obj->getTipoEstacion();
			items->Add(KeyValuePair<String^, String^>(id.ToString(), nombre));
		}
		cmbTipoEstacion->DataSource = items;
		cmbTipoEstacion->DisplayMember = "Value"; // muestra el nombre
		cmbTipoEstacion->ValueMember = "Key";     // mantiene el ID como valor
		cmbTipoEstacion->SelectedIndex = -1;      // opcional: sin selección inicial 

		// Cargar los posibles estados operativos en el ComboBox cmbEstado
		this->cmbEstado->Items->Add("Activa");
		this->cmbEstado->Items->Add("En Configuración");
		this->cmbEstado->Items->Add("Detenida por Alerta");

		// Cargar los datos del objeto EstacionTrabajo en los controles del formulario
		this->txtId->Text = this->objEstacionTrabajo->getId();
		this->txtNombre->Text = this->objEstacionTrabajo->getNombre();
		this->cmbTipoEstacion->Text = this->objEstacionTrabajo->getTipo();
		// si tuviera el ID del tipo de robot, se podría establecer la selección del ComboBox utilizando el SelectedValue
		// this->cmbTipoEstacion->SelectedValue = this->objEstacionTrabajo->getIdTipoEstacion().ToString();
		this->cmbEstado->Text = this->objEstacionTrabajo->ObtenerEstadoString();
		int iCapacidadMaxima = this->objEstacionTrabajo->getCapacidadMaxima();
		this->txtCapacidadMax->Text = iCapacidadMaxima.ToString();
	}
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Se obtienen los valores de los campos de texto
		String^ sId = this->txtId->Text;
		String^ nombre = this->txtNombre->Text;
		String^ tipo = this->cmbTipoEstacion->Text; // Se obtiene el texto del tipo de robot seleccionado en el ComboBox
		String^ idTipoEstacion = this->cmbTipoEstacion->SelectedValue->ToString(); // Se obtiene el ID del tipo de robot seleccionado en el ComboBox
		String^ estado = "";
		if (cmbEstado->SelectedIndex != -1) {
			// Si se ha seleccionado un estado en el ComboBox, se obtiene el valor seleccionado
			estado = cmbEstado->SelectedItem->ToString();
		}
		String^ capacidadMax = this->txtCapacidadMax->Text;

		// Validar los campos antes de guardar
		if (nombre->Equals("") || tipo->Equals("") || estado->Equals("") || capacidadMax->Equals("")) {
			MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		int capacidadMaxInt; // Variable para almacenar la capacidad máxima convertida a entero
		if (!Int32::TryParse(capacidadMax, capacidadMaxInt)) {
			MessageBox::Show("La capacidad máxima debe ser un número válido.", "Error de validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			txtCapacidadMax->Focus();
			return;
		}

		// Validar que la capacidad sea positiva
		if (capacidadMaxInt <= 0) {
			MessageBox::Show("La capacidad máxima debe ser mayor que cero.", "Error de validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			txtCapacidadMax->Focus();
			return;
		}

		// Convertir el estado ingresado a un valor del enum ConvertirEstadoEstacion
		EstadoEstacion estadoEstacion = EstacionTrabajo::ConvertirEstadoEstacion(estado);
		// Llamando al controlador para actualizar la estación de trabajo en la base de datos
		bool resultado = this->estacionController->ModificarEstacion(sId, nombre, tipo, estadoEstacion, capacidadMaxInt);
		if (resultado) {
			MessageBox::Show("La estación de trabajo se actualizó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close(); // Cierra el formulario actual
		}
		else {
			MessageBox::Show("Error al actualizar la estación de trabajo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); // Cierra el formulario actual
	}
};
}
