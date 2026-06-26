#pragma once
#include "frmNuevoEstacionTrabajo.h"
#include "frmEditarEstacionTrabajo.h"

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; // Se agrega esta directiva para poder usar la clase Path y Directory para manejar las rutas de los archivos de datos de tipos de robots, esto se puede modificar según sea necesario
	using namespace SGELProdAutomModel;
	using namespace SGELProdAutomController;

	/// <summary>
	/// Resumen de frmMantEstacionTrabajo
	/// </summary>
	public ref class frmMantEstacionTrabajo : public System::Windows::Forms::Form
	{
	public:
		frmMantEstacionTrabajo(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			// Construye la ruta completa del directorio donde se almacenarán los archivos de datos, esto se puede modificar según sea necesario
			String^ pathArchivo = Path::Combine(Directory::GetParent(Directory::GetParent(Application::StartupPath)->FullName)->FullName, "BD\\BIN\\");
			this->tipoEstacionController = gcnew TipoEstacionController(pathArchivo);
			this->estacionController = gcnew EstacionController(pathArchivo);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantEstacionTrabajo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEliminar;
	protected:
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::DataGridView^ dgvLista;

	private: EstacionController^ estacionController; // Variable para almacenar la instancia del controlador y poder realizar las operaciones de consulta, edición y eliminación de unidades robóticas
	private: TipoEstacionController^ tipoEstacionController;	// Variable para almacenar la instancia del controlador de tipos de estaciones y poder cargar los tipos disponibles en el ComboBox cmbTipoEstacion



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ cmbTipoEstacion;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtId;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCapacidad;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCapacidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbTipoEstacion = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEliminar->Location = System::Drawing::Point(619, 475);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(4);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(98, 34);
			this->btnEliminar->TabIndex = 14;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantEstacionTrabajo::btnEliminar_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEditar->Location = System::Drawing::Point(424, 475);
			this->btnEditar->Margin = System::Windows::Forms::Padding(4);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(98, 34);
			this->btnEditar->TabIndex = 13;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantEstacionTrabajo::btnEditar_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::SystemColors::Control;
			this->btnNuevo->Location = System::Drawing::Point(212, 475);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(4);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(98, 34);
			this->btnNuevo->TabIndex = 12;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantEstacionTrabajo::btnNuevo_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLista->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colId, this->colNombre,
					this->colTipo, this->colEstado, this->colCapacidad
			});
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvLista->DefaultCellStyle = dataGridViewCellStyle8;
			this->dgvLista->Location = System::Drawing::Point(13, 127);
			this->dgvLista->Margin = System::Windows::Forms::Padding(4);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1041, 327);
			this->dgvLista->TabIndex = 16;
			// 
			// colId
			// 
			this->colId->HeaderText = L"Código";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre de Estación de Trabajo";
			this->colNombre->MinimumWidth = 6;
			this->colNombre->Name = L"colNombre";
			this->colNombre->Width = 320;
			// 
			// colTipo
			// 
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->MinimumWidth = 6;
			this->colTipo->Name = L"colTipo";
			this->colTipo->Width = 120;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->Width = 180;
			// 
			// colCapacidad
			// 
			this->colCapacidad->HeaderText = L"Capacidad Máxima";
			this->colCapacidad->Name = L"colCapacidad";
			this->colCapacidad->Width = 200;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->cmbTipoEstacion);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->btnLimpiar);
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtId);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(13, 13);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(1041, 94);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// cmbTipoEstacion
			// 
			this->cmbTipoEstacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbTipoEstacion->FormattingEnabled = true;
			this->cmbTipoEstacion->Location = System::Drawing::Point(544, 44);
			this->cmbTipoEstacion->Name = L"cmbTipoEstacion";
			this->cmbTipoEstacion->Size = System::Drawing::Size(201, 30);
			this->cmbTipoEstacion->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(377, 49);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Tipo de estación :";
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnLimpiar->Location = System::Drawing::Point(911, 43);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(4);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(98, 34);
			this->btnLimpiar->TabIndex = 3;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmMantEstacionTrabajo::btnLimpiar_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnBuscar->Location = System::Drawing::Point(792, 43);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(4);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(98, 34);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantEstacionTrabajo::btnBuscar_Click);
			// 
			// txtId
			// 
			this->txtId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtId->Location = System::Drawing::Point(98, 46);
			this->txtId->Margin = System::Windows::Forms::Padding(4);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(220, 28);
			this->txtId->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 49);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Codigo :";
			// 
			// frmMantEstacionTrabajo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1072, 536);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantEstacionTrabajo";
			this->Text = L"Mantenimiento de Estaciones de Trabajo";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMantEstacionTrabajo::frmMantEstacionTrabajo_FormClosing);
			this->Load += gcnew System::EventHandler(this, &frmMantEstacionTrabajo::frmMantEstacionTrabajo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantEstacionTrabajo_Load(System::Object^ sender, System::EventArgs^ e) {
		//Paso 1: Listamos los Tipos de Estación desde el archivo tipoEstacion.bin
		List<TipoEstacion^>^ listaTiposEstacion = this->tipoEstacionController->ListarTiposEstacion();
		//Paso 2: Cargamos los tipos de estación en el ComboBox cmbTipoEstacion, mostrando el nombre pero manteniendo el ID como valor
		List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();
		for each (TipoEstacion ^ obj in listaTiposEstacion) {
			//Paso 3: Agregamos cada tipo de estación a la lista de items para el ComboBox, utilizando el ID como clave y el nombre como valor
			int id = obj->getIdTipoEstacion();
			String^ nombre = obj->getTipoEstacion();
			// Agregar el tipo de estación a la lista de items para el ComboBox
			items->Add(KeyValuePair<String^, String^>(id.ToString(), nombre));
		}
		// Configurar el ComboBox para mostrar el nombre pero mantener el ID como valor
		cmbTipoEstacion->DataSource = items;
		cmbTipoEstacion->DisplayMember = "Value"; // muestra el nombre
		cmbTipoEstacion->ValueMember = "Key";     // mantiene el ID como valor
		cmbTipoEstacion->SelectedIndex = -1;      // opcional: sin selección inicial

		// Cargar las estaciones de trabajo en el DataGridView al iniciar el formulario
		// Aquí deberías llamar a tu controlador para obtener la lista de estaciones de trabajo y llenarla en el DataGridView
		List<EstacionTrabajo^>^ listaEstacionTrabajo = this->estacionController->ListarEstaciones();
		mostrarGrilla(listaEstacionTrabajo);
	}

	/*METODOSPERSONALES*/
	// Método para mostrar la lista de Estaciones en el DataGridView
	public:	void mostrarGrilla(List<EstacionTrabajo^>^ listaEstacionTrabajo)
	{
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaEstacionTrabajo->Count; i++)
		{
			// Obtener la estación de trabajo actual de la lista
			EstacionTrabajo^ estacionTrabajo = listaEstacionTrabajo[i];
			// Crear un arreglo de strings para representar la fila del DataGridView
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			// Asignar los valores de las propiedades de la estación de trabajo a cada columna de la fila
			filaGrilla[0] = Convert::ToString(estacionTrabajo->getId());
			filaGrilla[1] = estacionTrabajo->getNombre();
			filaGrilla[2] = estacionTrabajo->getTipo();
			filaGrilla[3] = estacionTrabajo->ObtenerEstadoString();
			filaGrilla[4] = estacionTrabajo->getCapacidadMaxima().ToString();
			// Agregar la fila al DataGridView
			this->dgvLista->Rows->Add(filaGrilla);
		}
		this->dgvLista->AutoGenerateColumns = false; // Desactivar la generaci�n autom�tica de columnas
		this->dgvLista->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		this->dgvLista->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells); // Ajustar el ancho de las columnas al contenido
	}
private: System::Void frmMantEstacionTrabajo_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->estacionController->LiberarMemoria();
}
private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
	frmNuevoEstacionTrabajo^ nuevoEstacionTrabajoForm = gcnew frmNuevoEstacionTrabajo(this->estacionController, this->tipoEstacionController);
	nuevoEstacionTrabajoForm->ShowDialog(this);
	List<EstacionTrabajo^>^ listaEstacionTrabajo = this->estacionController->ListarEstaciones();
	mostrarGrilla(listaEstacionTrabajo);
}
private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Verificar si se ha seleccionado una fila en el DataGridView
	if (this->dgvLista->SelectedRows->Count > 0)
	{
		int filaSeleccionada = this->dgvLista->SelectedRows[0]->Index;
		String^ sId = this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value->ToString();

		EstacionTrabajo^ estacionSeleccionada = this->estacionController->ConsultarEstacion(sId);
		if (estacionSeleccionada == nullptr)
		{
			MessageBox::Show("No se encontró la estación de trabajo seleccionada.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Crear una nueva instancia del formulario de nuevo Estacion
		// y mostrarlo como un formulario hijo dentro del contenedor MDI
		frmEditarEstacionTrabajo^ editarEstacionTrabajoForm = gcnew frmEditarEstacionTrabajo(this->estacionController, this->tipoEstacionController, estacionSeleccionada);
		editarEstacionTrabajoForm->ShowDialog();
		// Llamar al m�todo para cargar la lista de Estaciones nuevamente
		List<EstacionTrabajo^>^ listaEstacionTrabajo = this->estacionController->ListarEstaciones();
		mostrarGrilla(listaEstacionTrabajo);
	}
	else
	{
		MessageBox::Show("Por favor, seleccione una Estacion para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Verificar si se ha seleccionado una fila en el DataGridView
	if (this->dgvLista->SelectedRows->Count > 0)
	{

		// Preguntar al usuario si est� seguro de eliminar el registro
		System::Windows::Forms::DialogResult respuesta = MessageBox::Show("¿Está seguro de que desea eliminar el registro seleccionado?",
			"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		// Si el usuario selecciona "No", cancelar la operaci�n
		if (respuesta == System::Windows::Forms::DialogResult::No)
		{
			return; // Salir del evento si el usuario cancela
		}

		int selectedRowIndex = this->dgvLista->SelectedRows[0]->Index;
		String^ sId = this->dgvLista->Rows[selectedRowIndex]->Cells[0]->Value->ToString();
		// Crear una instancia del controlador y eliminar el Estacion
		bool resultado = this->estacionController->EliminarEstacion(sId);
		if (resultado) {
			MessageBox::Show("Estación de trabajo eliminada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show("Error al eliminar la estación de trabajo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// Actualizar la lista de estaciones de trabajo en el DataGridView
		List<EstacionTrabajo^>^ listaEstacionTrabajo = this->estacionController->ListarEstaciones();
		mostrarGrilla(listaEstacionTrabajo);
	}
	else
	{
		MessageBox::Show("Por favor, seleccione una Estacion para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Obtener el idStatus del Estacion a buscar
	String^ sId = txtId->Text;
	String^ selectedId = "";
	String^ selectedName = "";
	// Obtener el id del tipo de estación de trabajo seleccionado en el ComboBox cmbTipoEstacion, si se ha seleccionado alguno
	if (cmbTipoEstacion->SelectedIndex >= 0) {
		// Obtener el ID del tipo de estación de trabajo seleccionado en el ComboBox
		selectedId = cmbTipoEstacion->SelectedValue->ToString();
		selectedName = cmbTipoEstacion->Text; // Obtener el nombre del tipo de estación de trabajo seleccionado
	}

	List<EstacionTrabajo^>^ listaFiltrada = this->estacionController->ConsultarIdTipo(sId, selectedName);
	// Crear una lista para mostrar el resultado en el DataGridView
	List<EstacionTrabajo^>^ listaEstacionTrabajo = gcnew List<EstacionTrabajo^>();
	if (listaFiltrada != nullptr) {
		// Mostrar los resultados en el DataGridView
		mostrarGrilla(listaFiltrada);
	}
	else
	{	// Si no se encuentra unidad robótica, mostrar un mensaje de error
		MessageBox::Show("Por favor, ingrese un serialId.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Limpiar el campo de búsqueda
	List<EstacionTrabajo^>^ listaEstacionTrabajo = this->estacionController->ListarEstaciones();
	// Mostrar todos los Estaciones en el DataGridView
	mostrarGrilla(listaEstacionTrabajo);
}
};
}
