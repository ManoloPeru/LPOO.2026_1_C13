#pragma once

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SGELProdAutomModel;
	using namespace SGELProdAutomController;

	/// <summary>
	/// Resumen de frmNuevoUnidadRobotica
	/// </summary>
	public ref class frmNuevoUnidadRobotica : public System::Windows::Forms::Form
	{
	public:
		frmNuevoUnidadRobotica(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			
		}

		frmNuevoUnidadRobotica(RobotController^ robotController)
		{
			InitializeComponent();
			this->robotController = robotController;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmNuevoUnidadRobotica()
		{
			if (components)
			{
				delete components;
			}
		}
	private: RobotController^ robotController;	// Variable para almacenar la instancia del controlador y poder registrar la nueva unidad robótica
	protected:
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtUbicacion;
	private: System::Windows::Forms::TextBox^ txtAlias;
	private: System::Windows::Forms::TextBox^ txtSerialId;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::TextBox^ txtHorasTrabajo;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtGradosLibertad;
	private: System::Windows::Forms::Button^ btnSPGrabar;


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
			this->txtHorasTrabajo = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtGradosLibertad = (gcnew System::Windows::Forms::TextBox());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtUbicacion = (gcnew System::Windows::Forms::TextBox());
			this->txtAlias = (gcnew System::Windows::Forms::TextBox());
			this->txtSerialId = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSPGrabar = (gcnew System::Windows::Forms::Button());
			this->grpBoxPrincipal->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(40, 428);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(173, 56);
			this->btnGrabar->TabIndex = 7;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmNuevoUnidadRobotica::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(255, 428);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(173, 56);
			this->btnCancelar->TabIndex = 8;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmNuevoUnidadRobotica::btnCancelar_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->Controls->Add(this->txtHorasTrabajo);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Controls->Add(this->txtGradosLibertad);
			this->grpBoxPrincipal->Controls->Add(this->cmbEstado);
			this->grpBoxPrincipal->Controls->Add(this->label2);
			this->grpBoxPrincipal->Controls->Add(this->txtUbicacion);
			this->grpBoxPrincipal->Controls->Add(this->txtAlias);
			this->grpBoxPrincipal->Controls->Add(this->txtSerialId);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(23, 24);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(619, 383);
			this->grpBoxPrincipal->TabIndex = 14;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Información general de la Unidad Robótica";
			// 
			// txtHorasTrabajo
			// 
			this->txtHorasTrabajo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtHorasTrabajo->Location = System::Drawing::Point(190, 306);
			this->txtHorasTrabajo->Margin = System::Windows::Forms::Padding(5);
			this->txtHorasTrabajo->Name = L"txtHorasTrabajo";
			this->txtHorasTrabajo->Size = System::Drawing::Size(126, 28);
			this->txtHorasTrabajo->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 306);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 24);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Horas de trabajo:";
			// 
			// txtGradosLibertad
			// 
			this->txtGradosLibertad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtGradosLibertad->Location = System::Drawing::Point(190, 257);
			this->txtGradosLibertad->Margin = System::Windows::Forms::Padding(5);
			this->txtGradosLibertad->Name = L"txtGradosLibertad";
			this->txtGradosLibertad->Size = System::Drawing::Size(126, 28);
			this->txtGradosLibertad->TabIndex = 5;
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
			this->label2->Location = System::Drawing::Point(13, 157);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 24);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Ubicación:";
			// 
			// txtUbicacion
			// 
			this->txtUbicacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtUbicacion->Location = System::Drawing::Point(190, 153);
			this->txtUbicacion->Margin = System::Windows::Forms::Padding(5);
			this->txtUbicacion->Name = L"txtUbicacion";
			this->txtUbicacion->Size = System::Drawing::Size(403, 28);
			this->txtUbicacion->TabIndex = 3;
			// 
			// txtAlias
			// 
			this->txtAlias->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtAlias->Location = System::Drawing::Point(190, 104);
			this->txtAlias->Margin = System::Windows::Forms::Padding(5);
			this->txtAlias->Name = L"txtAlias";
			this->txtAlias->Size = System::Drawing::Size(403, 28);
			this->txtAlias->TabIndex = 2;
			// 
			// txtSerialId
			// 
			this->txtSerialId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtSerialId->Location = System::Drawing::Point(190, 57);
			this->txtSerialId->Margin = System::Windows::Forms::Padding(5);
			this->txtSerialId->Name = L"txtSerialId";
			this->txtSerialId->Size = System::Drawing::Size(126, 28);
			this->txtSerialId->TabIndex = 1;
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
			this->label5->Location = System::Drawing::Point(13, 257);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(169, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Grados de libertad:";
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
			this->label1->Size = System::Drawing::Size(116, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Identificador:";
			// 
			// btnSPGrabar
			// 
			this->btnSPGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnSPGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSPGrabar->ForeColor = System::Drawing::Color::White;
			this->btnSPGrabar->Location = System::Drawing::Point(469, 428);
			this->btnSPGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnSPGrabar->Name = L"btnSPGrabar";
			this->btnSPGrabar->Size = System::Drawing::Size(173, 56);
			this->btnSPGrabar->TabIndex = 15;
			this->btnSPGrabar->Text = L"spGrabar";
			this->btnSPGrabar->UseVisualStyleBackColor = false;
			this->btnSPGrabar->Click += gcnew System::EventHandler(this, &frmNuevoUnidadRobotica::btnSPGrabar_Click);
			// 
			// frmNuevoUnidadRobotica
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(679, 511);
			this->Controls->Add(this->btnSPGrabar);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Name = L"frmNuevoUnidadRobotica";
			this->Text = L"Mantenimiento de Unidad Robotica - Nuevo registro";
			this->Load += gcnew System::EventHandler(this, &frmNuevoUnidadRobotica::frmNuevoUnidadRobotica_Load);
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		// Método para manejar el evento de carga del formulario, donde se pueden inicializar componentes o cargar datos necesarios para el registro de la nueva unidad robótica
	private: System::Void frmNuevoUnidadRobotica_Load(System::Object^ sender, System::EventArgs^ e) {
		// Aquí puedes agregar la lógica para inicializar componentes o cargar datos necesarios para el registro de la nueva unidad robótica
		
		// Por ejemplo, podrías cargar los posibles estados operativos en el ComboBox cmbEstado
		this->cmbEstado->Items->Add("Operativo");
		this->cmbEstado->Items->Add("En Mantenimiento");
		this->cmbEstado->Items->Add("Falla");
	}

		// Método para manejar el evento de clic del botón "Grabar", donde se validarán los datos ingresados y se registrará la nueva unidad robótica utilizando el controlador
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Aquí puedes agregar la lógica para grabar la nueva Unidad Robótica utilizando el controlador
		String^ serialId = txtSerialId->Text;
		String^ alias = txtAlias->Text;
		String^ ubicacion = txtUbicacion->Text;
		String^ estado = "";
		if (cmbEstado->SelectedIndex != -1) {
			// Si se ha seleccionado un estado en el ComboBox, se obtiene el valor seleccionado
			String^ idEstado = cmbEstado->SelectedItem->ToString(); // Obtener el Id del estado seleccionado
			estado = cmbEstado->Text; // Obtener el nombre del estado seleccionado
		}
		String^ gradosLibertad = txtGradosLibertad->Text;
		String^ horasTrabajo = txtHorasTrabajo->Text;
		// Validar los campos antes de guardar
		if (serialId->Equals("") || alias->Equals("") || ubicacion->Equals("") || estado->Equals("") || gradosLibertad->Equals("") || horasTrabajo->Equals("")) {
			MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Lógica para guardar la nueva unidad robótica
		// Variables para almacenar los valores convertidos
		int robotId;
		int grados;
		double horas;
		bool errorConversion = false;
		String^ mensajeError = "";

		// Validar y convertir RobotId
		if (!Int32::TryParse(serialId, robotId)) {
			errorConversion = true;
			mensajeError += "- RobotId debe ser un número entero válido.\n";
		}

		// Validar y convertir Grados de Libertad
		if (!Int32::TryParse(gradosLibertad, grados)) {
			errorConversion = true;
			mensajeError += "- Grados de Libertad debe ser un número entero válido.\n";
		}

		// Validar y convertir Horas de Trabajo
		if (!Double::TryParse(horasTrabajo, horas)) {
			errorConversion = true;
			mensajeError += "- Horas de Trabajo debe ser un número válido (ejemplo: 1250.5).\n";
		}

		// Verificar que el estado sea válido
		if (estado != "Operativo" && estado != "En Mantenimiento" && estado != "Falla") {
			errorConversion = true;
			mensajeError += "- Estado debe ser: Operativo, En Mantenimiento o Falla.\n";
		}

		// Si hubo errores de conversión, mostrar mensaje y salir
		if (errorConversion) {
			MessageBox::Show("Errores en los datos ingresados:\n" + mensajeError,
				"Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Convertir el estado ingresado a un valor del enum EstadoOperativo
		EstadoOperativo estadoOperativo = UnidadRobotica::ConvertirEstadoOperativo(estado);

		//Creando la nueva unidad robótica
		UnidadRobotica^ nuevaUnidadRobotica = gcnew UnidadRobotica(robotId, alias, ubicacion, estadoOperativo, grados, horas);
		bool resultado = this->robotController->AgregarRobot(nuevaUnidadRobotica);
		if (resultado) {
			MessageBox::Show("Unidad Robótica agregada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close(); // Cierra el formulario actual
		} else {
			MessageBox::Show("Error al agregar la unidad robótica.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}

		   // Método para manejar el evento de clic del botón "Cancelar", donde se cerrará el formulario sin guardar los cambios
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); // Cierra el formulario actual	
	}

private: System::Void btnSPGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Aquí puedes agregar la lógica para grabar la nueva Unidad Robótica utilizando el controlador
	String^ serialId = txtSerialId->Text;
	String^ alias = txtAlias->Text;
	String^ ubicacion = txtUbicacion->Text;
	String^ estado = "";
	if (cmbEstado->SelectedIndex != -1) {
		// Si se ha seleccionado un estado en el ComboBox, se obtiene el valor seleccionado
		String^ idEstado = cmbEstado->SelectedItem->ToString(); // Obtener el Id del estado seleccionado
		estado = cmbEstado->Text; // Obtener el nombre del estado seleccionado
	}
	String^ gradosLibertad = txtGradosLibertad->Text;
	String^ horasTrabajo = txtHorasTrabajo->Text;
	// Validar los campos antes de guardar
	if (serialId->Equals("") || alias->Equals("") || ubicacion->Equals("") || estado->Equals("") || gradosLibertad->Equals("") || horasTrabajo->Equals("")) {
		MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Lógica para guardar la nueva unidad robótica
	// Variables para almacenar los valores convertidos
	int robotId;
	int grados;
	double horas;
	bool errorConversion = false;
	String^ mensajeError = "";

	// Validar y convertir RobotId
	if (!Int32::TryParse(serialId, robotId)) {
		errorConversion = true;
		mensajeError += "- RobotId debe ser un número entero válido.\n";
	}

	// Validar y convertir Grados de Libertad
	if (!Int32::TryParse(gradosLibertad, grados)) {
		errorConversion = true;
		mensajeError += "- Grados de Libertad debe ser un número entero válido.\n";
	}

	// Validar y convertir Horas de Trabajo
	if (!Double::TryParse(horasTrabajo, horas)) {
		errorConversion = true;
		mensajeError += "- Horas de Trabajo debe ser un número válido (ejemplo: 1250.5).\n";
	}

	// Verificar que el estado sea válido
	if (estado != "Operativo" && estado != "En Mantenimiento" && estado != "Falla") {
		errorConversion = true;
		mensajeError += "- Estado debe ser: Operativo, En Mantenimiento o Falla.\n";
	}

	// Si hubo errores de conversión, mostrar mensaje y salir
	if (errorConversion) {
		MessageBox::Show("Errores en los datos ingresados:\n" + mensajeError,
			"Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Convertir el estado ingresado a un valor del enum EstadoOperativo
	EstadoOperativo estadoOperativo = UnidadRobotica::ConvertirEstadoOperativo(estado);

	//Creando la nueva unidad robótica
	UnidadRobotica^ nuevaUnidadRobotica = gcnew UnidadRobotica(robotId, alias, ubicacion, estadoOperativo, grados, horas);
	bool resultado = this->robotController->spAgregarRobot(nuevaUnidadRobotica);
	if (resultado) {
		MessageBox::Show("Unidad Robótica agregada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close(); // Cierra el formulario actual
	}
	else {
		MessageBox::Show("Error al agregar la unidad robótica.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}
};
}
