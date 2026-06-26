#pragma once

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace SGELProdAutomModel;

	    //Creación de Alias
	    using ModelPoint = SGELProdAutomModel::Point;
	    using ModelPointF = SGELProdAutomModel::PointF;
	    using DrawingPoint = System::Drawing::Point;
	    using DrawingPointF = System::Drawing::PointF;

	/// <summary>
	/// Resumen de frmWorkspaceVisualizer
	/// </summary>
	public ref class frmWorkspaceVisualizer : public System::Windows::Forms::Form
	{
	public:
		frmWorkspaceVisualizer(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			InicializarWorkspace();
		}
		
		// Constructor que recibe parámetros específicos
        frmWorkspaceVisualizer(double a, double b) {
            InitializeComponent();
            txtParamA->Text = a.ToString();
            txtParamB->Text = b.ToString();
            InicializarWorkspace();
        }

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmWorkspaceVisualizer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ grpParametros;
	private: System::Windows::Forms::Label^ lblParamA;
	private: System::Windows::Forms::TextBox^ txtParamA;

	private: System::Windows::Forms::Label^ lblParamB;
	private: System::Windows::Forms::TextBox^ txtParamB;
	private: System::Windows::Forms::Label^ lblUnidadA;
	private: System::Windows::Forms::Label^ lblUnidadB;
	private: System::Windows::Forms::Button^ btnGraficar;
	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Button^ btnCerrar;
	private: System::Windows::Forms::GroupBox^ grpVisualizacion;
	private: System::Windows::Forms::PictureBox^ pbWorkspace;
	private: System::Windows::Forms::GroupBox^ grpInfo;
	private: System::Windows::Forms::RichTextBox^ rtbInfo;

	//Variables de trabajo
	WorkspaceCalculator^ calculator;
	float escala;           // Factor de conversión mm → píxeles
	int centroX;            // Centro del PictureBox en X
	int centroY;            // Centro del PictureBox en Y

	protected:

	protected:

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
			this->grpParametros = (gcnew System::Windows::Forms::GroupBox());
			this->btnCerrar = (gcnew System::Windows::Forms::Button());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnGraficar = (gcnew System::Windows::Forms::Button());
			this->lblUnidadB = (gcnew System::Windows::Forms::Label());
			this->lblUnidadA = (gcnew System::Windows::Forms::Label());
			this->txtParamB = (gcnew System::Windows::Forms::TextBox());
			this->lblParamB = (gcnew System::Windows::Forms::Label());
			this->txtParamA = (gcnew System::Windows::Forms::TextBox());
			this->lblParamA = (gcnew System::Windows::Forms::Label());
			this->grpVisualizacion = (gcnew System::Windows::Forms::GroupBox());
			this->pbWorkspace = (gcnew System::Windows::Forms::PictureBox());
			this->grpInfo = (gcnew System::Windows::Forms::GroupBox());
			this->rtbInfo = (gcnew System::Windows::Forms::RichTextBox());
			this->grpParametros->SuspendLayout();
			this->grpVisualizacion->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbWorkspace))->BeginInit();
			this->grpInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpParametros
			// 
			this->grpParametros->Controls->Add(this->btnCerrar);
			this->grpParametros->Controls->Add(this->btnLimpiar);
			this->grpParametros->Controls->Add(this->btnGraficar);
			this->grpParametros->Controls->Add(this->lblUnidadB);
			this->grpParametros->Controls->Add(this->lblUnidadA);
			this->grpParametros->Controls->Add(this->txtParamB);
			this->grpParametros->Controls->Add(this->lblParamB);
			this->grpParametros->Controls->Add(this->txtParamA);
			this->grpParametros->Controls->Add(this->lblParamA);
			this->grpParametros->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpParametros->Location = System::Drawing::Point(27, 22);
			this->grpParametros->Name = L"grpParametros";
			this->grpParametros->Size = System::Drawing::Size(480, 221);
			this->grpParametros->TabIndex = 0;
			this->grpParametros->TabStop = false;
			this->grpParametros->Text = L"Parámetros del Robot";
			// 
			// btnCerrar
			// 
			this->btnCerrar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCerrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCerrar->ForeColor = System::Drawing::Color::White;
			this->btnCerrar->Location = System::Drawing::Point(322, 146);
			this->btnCerrar->Margin = System::Windows::Forms::Padding(5);
			this->btnCerrar->Name = L"btnCerrar";
			this->btnCerrar->Size = System::Drawing::Size(145, 56);
			this->btnCerrar->TabIndex = 5;
			this->btnCerrar->Text = L"Cerrar";
			this->btnCerrar->UseVisualStyleBackColor = false;
			this->btnCerrar->Click += gcnew System::EventHandler(this, &frmWorkspaceVisualizer::btnCerrar_Click);
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::Color::White;
			this->btnLimpiar->Location = System::Drawing::Point(167, 146);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(5);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(145, 56);
			this->btnLimpiar->TabIndex = 4;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmWorkspaceVisualizer::btnLimpiar_Click);
			// 
			// btnGraficar
			// 
			this->btnGraficar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGraficar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGraficar->ForeColor = System::Drawing::Color::White;
			this->btnGraficar->Location = System::Drawing::Point(13, 146);
			this->btnGraficar->Margin = System::Windows::Forms::Padding(5);
			this->btnGraficar->Name = L"btnGraficar";
			this->btnGraficar->Size = System::Drawing::Size(145, 56);
			this->btnGraficar->TabIndex = 3;
			this->btnGraficar->Text = L"Graficar Límite";
			this->btnGraficar->UseVisualStyleBackColor = false;
			this->btnGraficar->Click += gcnew System::EventHandler(this, &frmWorkspaceVisualizer::btnGraficar_Click);
			// 
			// lblUnidadB
			// 
			this->lblUnidadB->AutoSize = true;
			this->lblUnidadB->Location = System::Drawing::Point(367, 94);
			this->lblUnidadB->Name = L"lblUnidadB";
			this->lblUnidadB->Size = System::Drawing::Size(42, 24);
			this->lblUnidadB->TabIndex = 5;
			this->lblUnidadB->Text = L"mm";
			// 
			// lblUnidadA
			// 
			this->lblUnidadA->AutoSize = true;
			this->lblUnidadA->Location = System::Drawing::Point(367, 41);
			this->lblUnidadA->Name = L"lblUnidadA";
			this->lblUnidadA->Size = System::Drawing::Size(42, 24);
			this->lblUnidadA->TabIndex = 4;
			this->lblUnidadA->Text = L"mm";
			// 
			// txtParamB
			// 
			this->txtParamB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtParamB->Location = System::Drawing::Point(259, 89);
			this->txtParamB->Margin = System::Windows::Forms::Padding(5);
			this->txtParamB->Name = L"txtParamB";
			this->txtParamB->Size = System::Drawing::Size(87, 29);
			this->txtParamB->TabIndex = 1;
			this->txtParamB->Text = L"80";
			this->txtParamB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lblParamB
			// 
			this->lblParamB->AutoSize = true;
			this->lblParamB->Location = System::Drawing::Point(20, 94);
			this->lblParamB->Name = L"lblParamB";
			this->lblParamB->Size = System::Drawing::Size(214, 24);
			this->lblParamB->TabIndex = 3;
			this->lblParamB->Text = L"Factor excentricidad (b):";
			// 
			// txtParamA
			// 
			this->txtParamA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtParamA->Location = System::Drawing::Point(265, 36);
			this->txtParamA->Margin = System::Windows::Forms::Padding(5);
			this->txtParamA->Name = L"txtParamA";
			this->txtParamA->Size = System::Drawing::Size(81, 29);
			this->txtParamA->TabIndex = 0;
			this->txtParamA->Text = L"100";
			this->txtParamA->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lblParamA
			// 
			this->lblParamA->AutoSize = true;
			this->lblParamA->Location = System::Drawing::Point(20, 41);
			this->lblParamA->Name = L"lblParamA";
			this->lblParamA->Size = System::Drawing::Size(187, 24);
			this->lblParamA->TabIndex = 0;
			this->lblParamA->Text = L"Eslabón principal (a):";
			// 
			// grpVisualizacion
			// 
			this->grpVisualizacion->Controls->Add(this->pbWorkspace);
			this->grpVisualizacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->grpVisualizacion->Location = System::Drawing::Point(513, 22);
			this->grpVisualizacion->Name = L"grpVisualizacion";
			this->grpVisualizacion->Size = System::Drawing::Size(725, 742);
			this->grpVisualizacion->TabIndex = 7;
			this->grpVisualizacion->TabStop = false;
			this->grpVisualizacion->Text = L"Plano de Trabajo (Vista Superior)";
			// 
			// pbWorkspace
			// 
			this->pbWorkspace->BackColor = System::Drawing::Color::White;
			this->pbWorkspace->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbWorkspace->Location = System::Drawing::Point(6, 28);
			this->pbWorkspace->Name = L"pbWorkspace";
			this->pbWorkspace->Size = System::Drawing::Size(700, 700);
			this->pbWorkspace->TabIndex = 3;
			this->pbWorkspace->TabStop = false;
			this->pbWorkspace->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmWorkspaceVisualizer::pbWorkspace_Paint);
			// 
			// grpInfo
			// 
			this->grpInfo->Controls->Add(this->rtbInfo);
			this->grpInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpInfo->Location = System::Drawing::Point(27, 249);
			this->grpInfo->Name = L"grpInfo";
			this->grpInfo->Size = System::Drawing::Size(480, 515);
			this->grpInfo->TabIndex = 8;
			this->grpInfo->TabStop = false;
			this->grpInfo->Text = L"Información Técnica";
			// 
			// rtbInfo
			// 
			this->rtbInfo->Location = System::Drawing::Point(13, 35);
			this->rtbInfo->Name = L"rtbInfo";
			this->rtbInfo->Size = System::Drawing::Size(454, 466);
			this->rtbInfo->TabIndex = 0;
			this->rtbInfo->Text = L"Ingrese los parámetros a y b\\nen milímetros y presione\\n\'Graficar Límite\' para ve"
				L"r\\nla zona de seguridad del robot.\\n\\nLa curva representa el\\nalcance máximo per"
				L"misible\\nen forma de cardioide.";
			// 
			// frmWorkspaceVisualizer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1253, 785);
			this->Controls->Add(this->grpInfo);
			this->Controls->Add(this->grpVisualizacion);
			this->Controls->Add(this->grpParametros);
			this->Name = L"frmWorkspaceVisualizer";
			this->Text = L"Visualizador de Zona Límite de Seguridad (Workspace)";
			this->grpParametros->ResumeLayout(false);
			this->grpParametros->PerformLayout();
			this->grpVisualizacion->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbWorkspace))->EndInit();
			this->grpInfo->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		
		void InicializarWorkspace() {
			// Configurar el centro del PictureBox (700x700 -> centro en 350,350)
			centroX = 350;
			centroY = 350;

			// Calcular escala automática basada en el radio máximo esperado
			// Por defecto: a=100, b=80 -> radio máximo = 180 mm
			// Para que quepa en 200 píxeles hacia cada lado, escala = 200/180 ≈ 1.11
			escala = 1.1f;

			calculator = gcnew WorkspaceCalculator();
		}

		void DibujarEjes(Graphics^ g) {
			// Dibujar ejes coordenados
			Pen^ ejePen = gcnew Pen(Color::LightGray, 1);
			ejePen->DashStyle = DashStyle::Dash;

			// Eje X (horizontal)
			g->DrawLine(ejePen, 0, centroY, 400, centroY);

			// Eje Y (vertical)
			g->DrawLine(ejePen, centroX, 0, centroX, 400);

			// Dibujar el punto de origen (centro)
			SolidBrush^ centerBrush = gcnew SolidBrush(Color::Red);
			g->FillEllipse(centerBrush, centroX - 3, centroY - 3, 6, 6);

			// Dibujar flechas en los ejes
			Pen^ flechaPen = gcnew Pen(Color::Gray, 1);
			// Flecha X positiva
			g->DrawLine(flechaPen, 390, centroY - 3, 400, centroY);
			g->DrawLine(flechaPen, 390, centroY + 3, 400, centroY);
			// Flecha Y positiva
			g->DrawLine(flechaPen, centroX - 3, 10, centroX, 0);
			g->DrawLine(flechaPen, centroX + 3, 10, centroX, 0);

			// Etiquetas de ejes
			System::Drawing::Font^ labelFont = gcnew System::Drawing::Font(L"Arial", 8);
			SolidBrush^ textBrush = gcnew SolidBrush(Color::DarkGray);
			g->DrawString("X", labelFont, textBrush, 395, centroY - 12);
			g->DrawString("Y", labelFont, textBrush, centroX + 5, 5);

			delete ejePen;
			delete flechaPen;
			delete centerBrush;
			delete labelFont;
			delete textBrush;
		}

		void DibujarGrilla(Graphics^ g) {
			Pen^ gridPen = gcnew Pen(Color::LightGray, 1);
			gridPen->DashStyle = DashStyle::Dot;

			// Dibujar círculos concéntricos de referencia
			for (int r = 50; r <= 200; r += 50) {
				g->DrawEllipse(gridPen, centroX - r, centroY - r, 2 * r, 2 * r);
			}

			// Dibujar líneas radiales cada 45 grados
			for (int ang = 0; ang < 360; ang += 45) {
				double rad = ang * Math::PI / 180.0;
				int x2 = centroX + (int)(200 * Math::Cos(rad));
				int y2 = centroY - (int)(200 * Math::Sin(rad));
				g->DrawLine(gridPen, centroX, centroY, x2, y2);
			}

			delete gridPen;
		}
	private: System::Void pbWorkspace_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->SmoothingMode = SmoothingMode::AntiAlias;

		g->Clear(Color::White);
		DibujarGrilla(g);
		DibujarEjes(g);

		if (calculator != nullptr && calculator->ObtenerPuntosPixeles()->Count > 0) {
			List<ModelPoint>^ puntos = calculator->ObtenerPuntosPixeles();

			// Convertir a DrawingPoint para DrawLines
			array<DrawingPoint>^ puntosArray = gcnew array<DrawingPoint>(puntos->Count);
			for (int i = 0; i < puntos->Count; i++) {
				puntosArray[i] = DrawingPoint(puntos[i].X, puntos[i].Y);
			}

			Pen^ curvePen = gcnew Pen(Color::Blue, 3);
			g->DrawLines(curvePen, puntosArray);

			// Relleno
			array<DrawingPointF>^ puntosArrayF = gcnew array<DrawingPointF>(puntos->Count);
			for (int i = 0; i < puntos->Count; i++) {
				puntosArrayF[i] = DrawingPointF((float)puntos[i].X, (float)puntos[i].Y);
			}

			SolidBrush^ fillBrush = gcnew SolidBrush(Color::FromArgb(50, 0, 0, 255));
			g->FillPolygon(fillBrush, puntosArrayF);

			delete curvePen;
			delete fillBrush;
		}
	}
private: System::Void btnGraficar_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Validar y obtener parámetros
		double a, b;

		if (!Double::TryParse(txtParamA->Text, a)) {
			MessageBox::Show("Ingrese un valor numérico válido para el eslabón principal (a).",
				"Error de parámetro", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			txtParamA->Focus();
			return;
		}

		if (!Double::TryParse(txtParamB->Text, b)) {
			MessageBox::Show("Ingrese un valor numérico válido para el factor de excentricidad (b).",
				"Error de parámetro", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			txtParamB->Focus();
			return;
		}

		// Validar rangos
		if (a <= 0) {
			MessageBox::Show("El eslabón principal (a) debe ser mayor que 0 mm.",
				"Error de parámetro", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			txtParamA->Focus();
			return;
		}

		if (b <= 0) {
			MessageBox::Show("El factor de excentricidad (b) debe ser mayor que 0 mm.",
				"Error de parámetro", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			txtParamB->Focus();
			return;
		}

		// Crear calculadora con los parámetros ingresados
		calculator = gcnew WorkspaceCalculator(a, b);
		calculator->setPasoAngulo(0.05); // Resolución alta

		// Calcular puntos
		calculator->CalcularPuntos();

		// Calcular escala automática basada en el radio máximo
		double radioMax = calculator->ObtenerRadioMaximo();
		if (radioMax > 0) {
			// Margen de seguridad: usar el 80% del área disponible
			escala = (float)(180.0 / radioMax);
			if (escala > 2.0) escala = 2.0f;
			if (escala < 0.5) escala = 0.5f;
		}

		// Convertir a píxeles
		calculator->ConvertirAPixeles(centroX, centroY, escala);

		// Actualizar información técnica
		rtbInfo->Text = calculator->ObtenerEstadisticas();

		// Agregar información de escala
		rtbInfo->Text += String::Format("\n\nEscala de visualización:\n  {0:F2} mm → 1 píxel\n  {1:F0} mm ≈ diámetro pantalla",
			(1.0 / escala), (400.0 / escala));

		// Forzar repintado del PictureBox
		pbWorkspace->Invalidate();

		MessageBox::Show(String::Format("Cardioide calculada exitosamente.\nRadio máximo: {0:F2} mm", radioMax),
			"Cálculo completado", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al graficar: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Limpiar puntos
	calculator = gcnew WorkspaceCalculator();
	pbWorkspace->Invalidate();
	rtbInfo->Text = L"Lienzo limpiado.\n\nIngrese nuevos parámetros y\npresione 'Graficar Límite'.";
}
private: System::Void btnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}