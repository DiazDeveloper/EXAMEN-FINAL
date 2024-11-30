#pragma once
#include "Juego.h"

namespace EXAMEN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		Graphics^ canvas; 
		BufferedGraphicsContext^ context; 
		BufferedGraphics^ buffer; 
	private: System::Windows::Forms::Timer^ timer2;
		   Juego* juego;


		   

	public:
		MyForm(void)
		{
			InitializeComponent();
		 	canvas = this->CreateGraphics();
		 	context = BufferedGraphicsManager::Current;
		 	buffer = context->Allocate(canvas, this->ClientRectangle);
		 	juego = new Juego(buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1890, 1021);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		if (e->KeyCode == Keys::A)
		{
			juego->moverTeclas(buffer->Graphics, Izquierda);
		}

		if (e->KeyCode == Keys::D)
		{
			juego->moverTeclas(buffer->Graphics, Derecha);
		}

		if (e->KeyCode == Keys::P)
		{
			juego->moverTeclas(buffer->Graphics, AtaquePunio);
		}

		if (e->KeyCode == Keys::K)
		{
			juego->moverTeclas(buffer->Graphics, AtaquePatada); 
		}
	}
	
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		
			buffer->Graphics->Clear(Color::White);
			juego->mostrar(buffer->Graphics);
			juego->mover(buffer->Graphics);
			buffer->Render(canvas);
		
	}
};
}
