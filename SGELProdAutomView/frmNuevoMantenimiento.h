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
	/// Resumen de frmNuevoMantenimiento
	/// </summary>
	public ref class frmNuevoMantenimiento : public System::Windows::Forms::Form
	{
	public:
		frmNuevoMantenimiento(void)
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
		~frmNuevoMantenimiento()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnRegistrar;
	private: System::Windows::Forms::DataGridView^ dgvLista;
	protected:

	protected:






	private: System::Windows::Forms::TextBox^ txtTipoMantenimiento;

	private: System::Windows::Forms::TextBox^ txtTecnico;




	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ colActividad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDuracionMinutos;
	private: System::Windows::Forms::ComboBox^ cmbUnidadRobotica;
	private: System::Windows::Forms::DateTimePicker^ dtpFechaMantenimiento;





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
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colActividad = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->colDuracionMinutos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtTipoMantenimiento = (gcnew System::Windows::Forms::TextBox());
			this->txtTecnico = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbUnidadRobotica = (gcnew System::Windows::Forms::ComboBox());
			this->dtpFechaMantenimiento = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->SuspendLayout();
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnRegistrar->ForeColor = System::Drawing::Color::White;
			this->btnRegistrar->Location = System::Drawing::Point(230, 652);
			this->btnRegistrar->Margin = System::Windows::Forms::Padding(7);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(292, 61);
			this->btnRegistrar->TabIndex = 5;
			this->btnRegistrar->Text = L"Registrar mantenimiento";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &frmNuevoMantenimiento::btnRegistrar_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->colActividad,
					this->colDuracionMinutos
			});
			this->dgvLista->Location = System::Drawing::Point(16, 282);
			this->dgvLista->Margin = System::Windows::Forms::Padding(7);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersVisible = false;
			this->dgvLista->RowHeadersWidth = 82;
			this->dgvLista->RowTemplate->Height = 28;
			this->dgvLista->Size = System::Drawing::Size(729, 334);
			this->dgvLista->TabIndex = 18;
			// 
			// colActividad
			// 
			this->colActividad->HeaderText = L"Actividad";
			this->colActividad->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Actualización del firmware del controlador",
					L"Calibración de home", L"Cambio de grasa", L"Lubricación de engranajes en eje base", L"Reajuste de sensores de proximidad"
			});
			this->colActividad->MinimumWidth = 10;
			this->colActividad->Name = L"colActividad";
			this->colActividad->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->colActividad->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->colActividad->Width = 400;
			// 
			// colDuracionMinutos
			// 
			this->colDuracionMinutos->HeaderText = L"Duracion minutos";
			this->colDuracionMinutos->MinimumWidth = 10;
			this->colDuracionMinutos->Name = L"colDuracionMinutos";
			this->colDuracionMinutos->Width = 300;
			// 
			// txtTipoMantenimiento
			// 
			this->txtTipoMantenimiento->BackColor = System::Drawing::SystemColors::Info;
			this->txtTipoMantenimiento->Location = System::Drawing::Point(239, 154);
			this->txtTipoMantenimiento->Margin = System::Windows::Forms::Padding(7);
			this->txtTipoMantenimiento->Name = L"txtTipoMantenimiento";
			this->txtTipoMantenimiento->Size = System::Drawing::Size(218, 29);
			this->txtTipoMantenimiento->TabIndex = 3;
			// 
			// txtTecnico
			// 
			this->txtTecnico->BackColor = System::Drawing::SystemColors::Info;
			this->txtTecnico->Location = System::Drawing::Point(239, 89);
			this->txtTecnico->Margin = System::Windows::Forms::Padding(7);
			this->txtTecnico->Name = L"txtTecnico";
			this->txtTecnico->Size = System::Drawing::Size(502, 29);
			this->txtTecnico->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 221);
			this->label4->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(198, 24);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Fecha mantenimiento:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 154);
			this->label3->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(182, 24);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Tipo mantenimiento:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 89);
			this->label2->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 24);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Técnico:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 29);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 24);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Unidad robótica:";
			// 
			// cmbUnidadRobotica
			// 
			this->cmbUnidadRobotica->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbUnidadRobotica->FormattingEnabled = true;
			this->cmbUnidadRobotica->Location = System::Drawing::Point(239, 21);
			this->cmbUnidadRobotica->Name = L"cmbUnidadRobotica";
			this->cmbUnidadRobotica->Size = System::Drawing::Size(502, 32);
			this->cmbUnidadRobotica->TabIndex = 1;
			// 
			// dtpFechaMantenimiento
			// 
			this->dtpFechaMantenimiento->CalendarMonthBackground = System::Drawing::SystemColors::Info;
			this->dtpFechaMantenimiento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaMantenimiento->Location = System::Drawing::Point(239, 217);
			this->dtpFechaMantenimiento->Margin = System::Windows::Forms::Padding(5);
			this->dtpFechaMantenimiento->MinDate = System::DateTime(2026, 1, 1, 0, 0, 0, 0);
			this->dtpFechaMantenimiento->Name = L"dtpFechaMantenimiento";
			this->dtpFechaMantenimiento->Size = System::Drawing::Size(140, 29);
			this->dtpFechaMantenimiento->TabIndex = 4;
			// 
			// frmNuevoMantenimiento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(757, 729);
			this->Controls->Add(this->dtpFechaMantenimiento);
			this->Controls->Add(this->cmbUnidadRobotica);
			this->Controls->Add(this->btnRegistrar);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->txtTipoMantenimiento);
			this->Controls->Add(this->txtTecnico);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmNuevoMantenimiento";
			this->Text = L"Registrar un Nuevo Mantenimiento";
			this->Load += gcnew System::EventHandler(this, &frmNuevoMantenimiento::frmNuevoMantenimiento_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmNuevoMantenimiento_Load(System::Object^ sender, System::EventArgs^ e) {
		//Paso 1: Listamos las Unidades Roboticas desde BD
		RobotController^ robotController = gcnew  RobotController();
		List<UnidadRobotica^>^ listaUnidadRobotica = robotController->ObtenerTodosRobots();
		//Paso 2: Cargamos los tipos de robot en el ComboBox cmbTipoRobot, mostrando el nombre pero manteniendo el ID como valor
		List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();
		for each (UnidadRobotica ^ obj in listaUnidadRobotica) {
			//Paso 3: Agregamos cada tipo de robot a la lista de items para el ComboBox, utilizando el ID como clave y el nombre como valor
			int robotId = obj->getRobotId();
			String^ alias = obj->getAlias();
			// Agregar el tipo de robot a la lista de items para el ComboBox
			items->Add(KeyValuePair<String^, String^>(robotId.ToString(), alias));
		}
		// Configurar el ComboBox para mostrar el nombre pero mantener el ID como valor
		cmbUnidadRobotica->DataSource = items;
		cmbUnidadRobotica->DisplayMember = "Value"; // muestra el nombre
		cmbUnidadRobotica->ValueMember = "Key";     // mantiene el ID como valor
		cmbUnidadRobotica->SelectedIndex = -1;      // opcional: sin selección inicial

		this->dtpFechaMantenimiento->Value = DateTime::Now;
	}
private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Agregamos la logica para agregar la inspección
	String^ sRobotId = cmbUnidadRobotica->SelectedValue->ToString();
	String^ sTecnico = this->txtTecnico->Text;
	String^ sTipoMantenimiento = this->txtTipoMantenimiento->Text;
	DateTime dFechaMantenimiento = this->dtpFechaMantenimiento->Value; //formato dd/mm/yyyy
	String^ sFechaMantenimiento = dFechaMantenimiento.ToString();
	// Validar los campos antes de guardar
	if (sRobotId->Equals("") || sTecnico->Equals("") || sTipoMantenimiento->Equals("") || sFechaMantenimiento->Equals("")) {
		MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	
	int robotId = Convert::ToInt32(sRobotId);
	
	//Recorremos el DataGridView para obtener los detalles
	List<MantenimientoDetalle^>^ mantenimientoDetalle = gcnew List<MantenimientoDetalle^>();
	for each (DataGridViewRow ^ row in this->dgvLista->Rows)
	{
		if (row->IsNewRow) continue; // Saltar la fila nueva
		String^ actividad = Convert::ToString(row->Cells["colActividad"]->Value);
		String^ duracionMinutos = Convert::ToString(row->Cells["colDuracionMinutos"]->Value);
		// Validar que los campos no estén vacíos
		if (actividad->Equals(""))
		{
			MessageBox::Show("Por favor, la actividad de mantenimiento.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Int32 iDuracionMinutos = 0;
		if (!Int32::TryParse(duracionMinutos, iDuracionMinutos)) {
			MessageBox::Show("Ingrese un valor numérico válido para la duración en minutos.",
				"Error de parámetro", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Crear el objeto MantenimientoDetalle y agregarlo a la lista
		MantenimientoDetalle^ detalle = gcnew MantenimientoDetalle();
		detalle->setActividad(actividad);
		detalle->setDuracionMinutos(iDuracionMinutos);
		mantenimientoDetalle->Add(detalle);
	}
	// Crear el objeto Mantenimiento
	Mantenimiento^ newMantenimiento = gcnew Mantenimiento();
	newMantenimiento->setRobotId(robotId);
	newMantenimiento->setTecnico(sTecnico);
	newMantenimiento->setTipoMantenimiento(sTipoMantenimiento);
	newMantenimiento->setFechaMantenimiento(dFechaMantenimiento);
	newMantenimiento->setListaMantenimientoDetalle(mantenimientoDetalle);

	// Registramos el mantenimiento usando el controlador
	MantenimientoController^ mantenimientoController = gcnew  MantenimientoController();
	bool success = mantenimientoController->RegistrarMantenimientoCompleto(newMantenimiento);
	if (success) {
		MessageBox::Show("Mantenimiento registrado con éxito.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		// Limpiar el formulario después de registrar
		cmbUnidadRobotica->SelectedIndex = -1;
		this->txtTecnico->Clear();
		this->txtTipoMantenimiento->Clear();
		this->dgvLista->Rows->Clear();
	}
	else {
		MessageBox::Show("Error al registrar el mantenimiento.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
