#pragma once

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace SGELProdAutomModel;
	using namespace SGELProdAutomController;

	/// <summary>
	/// Resumen de frmNuevoEstacionTrabajo
	/// </summary>
	public ref class frmNuevoEstacionTrabajo : public System::Windows::Forms::Form
	{
	public:
		frmNuevoEstacionTrabajo(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmNuevoEstacionTrabajo(EstacionController^ estacionController, TipoEstacionController^ tipoEstacionController)
		{	// Constructor que recibe una instancia del controlador para poder registrar la nueva Estacion de trabajo
			InitializeComponent();
			this->estacionController = estacionController;
			this->tipoEstacionController = tipoEstacionController;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoEstacionTrabajo()
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

	private: EstacionController^ estacionController;	// Variable para almacenar la instancia del controlador y poder registrar la nueva Estacion de trabajo
	private: TipoEstacionController^ tipoEstacionController;	// Variable para almacenar la instancia del controlador de tipos de robots y poder cargar los tipos disponibles en el ComboBox cmbTipoEstacion

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
			this->btnGrabar->TabIndex = 15;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmNuevoEstacionTrabajo::btnGrabar_Click);
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
			this->btnCancelar->TabIndex = 16;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmNuevoEstacionTrabajo::btnCancelar_Click);
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
			this->grpBoxPrincipal->TabIndex = 17;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Información general de la Estacion de trabajo";
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
			// frmNuevoEstacionTrabajo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(653, 455);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Name = L"frmNuevoEstacionTrabajo";
			this->Text = L"Mantenimiento de Estación de Trabajo - Nuevo";
			this->Load += gcnew System::EventHandler(this, &frmNuevoEstacionTrabajo::frmNuevoEstacionTrabajo_Load);
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmNuevoEstacionTrabajo_Load(System::Object^ sender, System::EventArgs^ e) {
		// Aquí puedes agregar la lógica para inicializar componentes o cargar datos necesarios para el registro de la nueva Estacion de trabajo

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

		// Por ejemplo, podrías cargar los posibles estados operativos en el ComboBox cmbEstado
		this->cmbEstado->Items->Add("Activa");
		this->cmbEstado->Items->Add("En Configuración");
		this->cmbEstado->Items->Add("Detenida por Alerta");
	}
private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Aquí puedes agregar la lógica para grabar la nueva Estacion de trabajo utilizando el controlador
	String^ sId = txtId->Text;
	String^ nombre = txtNombre->Text;
	String^ tipo = this->cmbTipoEstacion->Text; // Se obtiene el texto del tipo de robot seleccionado en el ComboBox
	String^ idTipoEstacion = this->cmbTipoEstacion->SelectedValue->ToString(); // Se obtiene el ID del tipo de robot seleccionado en el ComboBox
	String^ estado = "";
	if (cmbEstado->SelectedIndex != -1) {
		// Si se ha seleccionado un estado en el ComboBox, se obtiene el valor seleccionado
		String^ idEstado = cmbEstado->SelectedItem->ToString(); // Obtener el Id del estado seleccionado
		estado = cmbEstado->Text; // Obtener el nombre del estado seleccionado
	}
	String^ capacidadMax = txtCapacidadMax->Text;
	// Validar los campos antes de guardar
	if (sId->Equals("") || nombre->Equals("") || tipo->Equals("") || estado->Equals("") || capacidadMax->Equals("")) {
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

	// Lógica para guardar la nueva Estacion de trabajo
	// Convertir el estado ingresado a un valor del enum EstadoOperativo
	EstadoEstacion estadoEstacion = EstacionTrabajo::ConvertirEstadoEstacion(estado);
	//Creando la nueva Estacion de trabajo
	EstacionTrabajo^ nuevaEstacionTrabajo = gcnew EstacionTrabajo(sId, nombre, tipo, estadoEstacion, capacidadMaxInt);
	bool resultado = this->estacionController->RegistrarEstacion(nuevaEstacionTrabajo);
	if (resultado) {
		MessageBox::Show("Estacion de trabajo agregada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close(); // Cierra el formulario actual
	}
	else {
		MessageBox::Show("Error al agregar la Estacion de trabajo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}
private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close(); // Cierra el formulario actual	
}
};
}
