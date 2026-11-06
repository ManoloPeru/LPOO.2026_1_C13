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
	/// Resumen de frmNuevaInspeccion
	/// </summary>
	public ref class frmNuevaInspeccion : public System::Windows::Forms::Form
	{
	public:
		frmNuevaInspeccion(void)
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
		~frmNuevaInspeccion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cmbUnidadRobotica;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dgvInspectionDetail;





	private: System::Windows::Forms::TextBox^ txtResultadoGeneral;

	private: System::Windows::Forms::TextBox^ txtInspector;
	private: System::Windows::Forms::TextBox^ txtCodigoLote;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnRegistrar;
	private: System::Windows::Forms::DateTimePicker^ dtpFechaInspeccion;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ colParametro;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colResultadoParametro;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNotas;
	private: System::Windows::Forms::DataGridView^ dgvLista;





	private: System::Windows::Forms::Timer^ timInspeccion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colInspeccionId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Unidad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCodigoLote;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colInspector;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFechaInspeccion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colResultadoGeneral;
	private: System::ComponentModel::IContainer^ components;











	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->cmbUnidadRobotica = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvInspectionDetail = (gcnew System::Windows::Forms::DataGridView());
			this->colParametro = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->colResultadoParametro = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNotas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtResultadoGeneral = (gcnew System::Windows::Forms::TextBox());
			this->txtInspector = (gcnew System::Windows::Forms::TextBox());
			this->txtCodigoLote = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->dtpFechaInspeccion = (gcnew System::Windows::Forms::DateTimePicker());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colInspeccionId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Unidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCodigoLote = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colInspector = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFechaInspeccion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colResultadoGeneral = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timInspeccion = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInspectionDetail))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->SuspendLayout();
			// 
			// cmbUnidadRobotica
			// 
			this->cmbUnidadRobotica->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbUnidadRobotica->FormattingEnabled = true;
			this->cmbUnidadRobotica->Location = System::Drawing::Point(245, 37);
			this->cmbUnidadRobotica->Margin = System::Windows::Forms::Padding(6);
			this->cmbUnidadRobotica->Name = L"cmbUnidadRobotica";
			this->cmbUnidadRobotica->Size = System::Drawing::Size(504, 32);
			this->cmbUnidadRobotica->TabIndex = 11;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 40);
			this->label1->Margin = System::Windows::Forms::Padding(13, 0, 13, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 24);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Unidad robótica:";
			// 
			// dgvInspectionDetail
			// 
			this->dgvInspectionDetail->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dgvInspectionDetail->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvInspectionDetail->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->colParametro,
					this->colResultadoParametro, this->colNotas
			});
			this->dgvInspectionDetail->Location = System::Drawing::Point(26, 289);
			this->dgvInspectionDetail->Margin = System::Windows::Forms::Padding(4);
			this->dgvInspectionDetail->Name = L"dgvInspectionDetail";
			this->dgvInspectionDetail->RowHeadersVisible = false;
			this->dgvInspectionDetail->RowHeadersWidth = 82;
			this->dgvInspectionDetail->RowTemplate->Height = 28;
			this->dgvInspectionDetail->Size = System::Drawing::Size(766, 237);
			this->dgvInspectionDetail->TabIndex = 21;
			// 
			// colParametro
			// 
			this->colParametro->HeaderText = L"Parámetro evaluado";
			this->colParametro->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Tolerancia Dimensional", L"Nivel de Vibración",
					L"Temperatura Operativa", L"Presión de Trabajo", L"Calidad de Soldadura", L"Alineación", L"Acabado Superficial", L"Funcionalidad Eléctrica"
			});
			this->colParametro->MinimumWidth = 10;
			this->colParametro->Name = L"colParametro";
			this->colParametro->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->colParametro->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->colParametro->Width = 250;
			// 
			// colResultadoParametro
			// 
			this->colResultadoParametro->HeaderText = L"Resultado del parámetro";
			this->colResultadoParametro->MaxInputLength = 10;
			this->colResultadoParametro->MinimumWidth = 10;
			this->colResultadoParametro->Name = L"colResultadoParametro";
			this->colResultadoParametro->Width = 250;
			// 
			// colNotas
			// 
			this->colNotas->HeaderText = L"Observaciones";
			this->colNotas->MaxInputLength = 200;
			this->colNotas->MinimumWidth = 10;
			this->colNotas->Name = L"colNotas";
			this->colNotas->Width = 250;
			// 
			// txtResultadoGeneral
			// 
			this->txtResultadoGeneral->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtResultadoGeneral->Location = System::Drawing::Point(245, 241);
			this->txtResultadoGeneral->Margin = System::Windows::Forms::Padding(4);
			this->txtResultadoGeneral->MaxLength = 20;
			this->txtResultadoGeneral->Name = L"txtResultadoGeneral";
			this->txtResultadoGeneral->Size = System::Drawing::Size(262, 29);
			this->txtResultadoGeneral->TabIndex = 20;
			// 
			// txtInspector
			// 
			this->txtInspector->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtInspector->Location = System::Drawing::Point(245, 142);
			this->txtInspector->Margin = System::Windows::Forms::Padding(4);
			this->txtInspector->MaxLength = 100;
			this->txtInspector->Name = L"txtInspector";
			this->txtInspector->Size = System::Drawing::Size(369, 29);
			this->txtInspector->TabIndex = 18;
			// 
			// txtCodigoLote
			// 
			this->txtCodigoLote->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCodigoLote->Location = System::Drawing::Point(245, 91);
			this->txtCodigoLote->Margin = System::Windows::Forms::Padding(4);
			this->txtCodigoLote->MaxLength = 50;
			this->txtCodigoLote->Name = L"txtCodigoLote";
			this->txtCodigoLote->Size = System::Drawing::Size(262, 29);
			this->txtCodigoLote->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 244);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(163, 24);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Resultado general";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 196);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(188, 24);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Fecha de inspección";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 147);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 24);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Inspector responsable";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(22, 94);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(175, 24);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Lote inspeccionado";
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnRegistrar->ForeColor = System::Drawing::Color::White;
			this->btnRegistrar->Location = System::Drawing::Point(225, 551);
			this->btnRegistrar->Margin = System::Windows::Forms::Padding(7);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(292, 61);
			this->btnRegistrar->TabIndex = 22;
			this->btnRegistrar->Text = L"Registrar inspección";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &frmNuevaInspeccion::btnRegistrar_Click);
			// 
			// dtpFechaInspeccion
			// 
			this->dtpFechaInspeccion->CalendarMonthBackground = System::Drawing::SystemColors::Info;
			this->dtpFechaInspeccion->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaInspeccion->Location = System::Drawing::Point(245, 192);
			this->dtpFechaInspeccion->Margin = System::Windows::Forms::Padding(5);
			this->dtpFechaInspeccion->MinDate = System::DateTime(2026, 1, 1, 0, 0, 0, 0);
			this->dtpFechaInspeccion->Name = L"dtpFechaInspeccion";
			this->dtpFechaInspeccion->Size = System::Drawing::Size(140, 29);
			this->dtpFechaInspeccion->TabIndex = 23;
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLista->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colInspeccionId,
					this->Unidad, this->colCodigoLote, this->colInspector, this->colFechaInspeccion, this->colResultadoGeneral
			});
			this->dgvLista->Location = System::Drawing::Point(800, 37);
			this->dgvLista->Margin = System::Windows::Forms::Padding(4);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(972, 489);
			this->dgvLista->TabIndex = 24;
			// 
			// colInspeccionId
			// 
			this->colInspeccionId->HeaderText = L"Id";
			this->colInspeccionId->MinimumWidth = 6;
			this->colInspeccionId->Name = L"colInspeccionId";
			this->colInspeccionId->Width = 70;
			// 
			// Unidad
			// 
			this->Unidad->HeaderText = L"colAlias";
			this->Unidad->Name = L"Unidad";
			// 
			// colCodigoLote
			// 
			this->colCodigoLote->HeaderText = L"CodigoLote";
			this->colCodigoLote->MinimumWidth = 6;
			this->colCodigoLote->Name = L"colCodigoLote";
			this->colCodigoLote->Width = 150;
			// 
			// colInspector
			// 
			this->colInspector->HeaderText = L"Inspector";
			this->colInspector->MinimumWidth = 6;
			this->colInspector->Name = L"colInspector";
			this->colInspector->Width = 250;
			// 
			// colFechaInspeccion
			// 
			this->colFechaInspeccion->HeaderText = L"Fec.Inspeccion";
			this->colFechaInspeccion->MinimumWidth = 6;
			this->colFechaInspeccion->Name = L"colFechaInspeccion";
			this->colFechaInspeccion->Width = 160;
			// 
			// colResultadoGeneral
			// 
			this->colResultadoGeneral->HeaderText = L"ResultadoGeneral";
			this->colResultadoGeneral->Name = L"colResultadoGeneral";
			this->colResultadoGeneral->Width = 180;
			// 
			// timInspeccion
			// 
			this->timInspeccion->Enabled = true;
			this->timInspeccion->Interval = 10000;
			this->timInspeccion->Tick += gcnew System::EventHandler(this, &frmNuevaInspeccion::timInspeccion_Tick);
			// 
			// frmNuevaInspeccion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1785, 628);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->dtpFechaInspeccion);
			this->Controls->Add(this->btnRegistrar);
			this->Controls->Add(this->dgvInspectionDetail);
			this->Controls->Add(this->txtResultadoGeneral);
			this->Controls->Add(this->txtInspector);
			this->Controls->Add(this->txtCodigoLote);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->cmbUnidadRobotica);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmNuevaInspeccion";
			this->Text = L"Registro de una nueva Inspección";
			this->Load += gcnew System::EventHandler(this, &frmNuevaInspeccion::frmNuevaInspeccion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvInspectionDetail))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void frmNuevaInspeccion_Load(System::Object^ sender, System::EventArgs^ e) {
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

	this->dtpFechaInspeccion->Value = DateTime::Now;
}
private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Agregamos la logica para agregar la inspección
	String^ sRobotId = cmbUnidadRobotica->SelectedValue->ToString();
	String^ sCodigoLote = this->txtCodigoLote->Text;
	String^ sInspector = this->txtInspector->Text;
	DateTime dFechaInspeccion = this->dtpFechaInspeccion->Value; //formato dd/mm/yyyy
	String^ sResultadoGeneral = this->txtResultadoGeneral->Text;
	String^ sFechaInspeccion = dFechaInspeccion.ToString();
	// Validar los campos antes de guardar
	if (sCodigoLote->Equals("") || sInspector->Equals("") || sFechaInspeccion->Equals("") || sResultadoGeneral->Equals("")) {
		MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	
	int robotId = Convert::ToInt32(sRobotId);

	//Recorremos el DataGridView para obtener los detalles
	List<InspeccionDetalle^>^ inspeccionDetalle = gcnew List<InspeccionDetalle^>();
	for each (DataGridViewRow ^ row in this->dgvInspectionDetail->Rows)
	{
		if (row->IsNewRow) continue; // Saltar la fila nueva
		String^ parametro = Convert::ToString(row->Cells["colParametro"]->Value);
		String^ resultadoParametro = Convert::ToString(row->Cells["colResultadoParametro"]->Value);
		String^ notas = Convert::ToString(row->Cells["colNotas"]->Value);
		// Validar que los campos no estén vacíos
		if (parametro->Equals("") || resultadoParametro->Equals("") || notas->Equals(""))
		{
			MessageBox::Show("Por favor, debe ingresar todos los datos del detalle.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Crear el objeto InspeccionDetalle y agregarlo a la lista
		InspeccionDetalle^ detalle = gcnew InspeccionDetalle();
		detalle->setParametro(parametro);
		detalle->setResultadoParametro(resultadoParametro);
		detalle->setNotas(notas);
		inspeccionDetalle->Add(detalle);
	}
	// Crear el objeto Inspeccion
	Inspeccion^ newInspeccion = gcnew Inspeccion();
	newInspeccion->setRobotId(robotId);
	newInspeccion->setCodigoLote(sCodigoLote);
	newInspeccion->setInspector(sInspector);
	newInspeccion->setFechaInspeccion(dFechaInspeccion);
	newInspeccion->setResultadoGeneral(sResultadoGeneral);
	newInspeccion->setListaInspeccionesDetalle(inspeccionDetalle);

	// Registramos el inspeccion usando el controlador
	InspeccionController^ inspeccionController = gcnew  InspeccionController();
	bool success = inspeccionController->RegistrarInspeccionTransaccional(newInspeccion);
	if (success) {
		MessageBox::Show("Inspeccion registrado con éxito.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		// Limpiar el formulario después de registrar
		cmbUnidadRobotica->SelectedIndex = -1;
		this->txtCodigoLote->Clear();
		this->txtInspector->Clear();
		this->txtResultadoGeneral->Clear();
		this->dgvInspectionDetail->Rows->Clear();
	}
	else {
		MessageBox::Show("Error al registrar el inspeccion.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void timInspeccion_Tick(System::Object^ sender, System::EventArgs^ e) {
	InspeccionController^ inspeccionController = gcnew  InspeccionController();
	List<Inspeccion^>^ listaInspeccion = inspeccionController->ListarTodos();
	mostrarGrilla(listaInspeccion);
}

	   public:	void mostrarGrilla(List<Inspeccion^>^ listaInspeccion)
	   {
		   this->dgvLista->Rows->Clear();
		   for (int i = 0; i < listaInspeccion->Count; i++)
		   {
			   // Obtener la estación de trabajo actual de la lista
			   Inspeccion^ inspeccion = listaInspeccion[i];
			   // Crear un arreglo de strings para representar la fila del DataGridView
			   array<String^>^ filaGrilla = gcnew array<String^>(7);
			   // Asignar los valores de las propiedades de la estación de trabajo a cada columna de la fila
			   filaGrilla[0] = Convert::ToString(inspeccion->getInspeccionId());
			   int RobotId = inspeccion->getRobotId();
			   RobotController^ robotController = gcnew  RobotController();
			   UnidadRobotica^ robot = robotController->ConsultarRobotPorId(RobotId);
			   filaGrilla[1] = robot->getAlias();
			   filaGrilla[2] = inspeccion->getCodigoLote();
			   filaGrilla[3] = inspeccion->getInspector();
			   filaGrilla[4] = inspeccion->getFechaInspeccion().ToString();
			   filaGrilla[5] = inspeccion->getResultadoGeneral();
			   // Agregar la fila al DataGridView
			   this->dgvLista->Rows->Add(filaGrilla);
		   }
		   this->dgvLista->AutoGenerateColumns = false; // Desactivar la generaci�n autom�tica de columnas
		   this->dgvLista->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		   this->dgvLista->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells); // Ajustar el ancho de las columnas al contenido
	   }
};
}
