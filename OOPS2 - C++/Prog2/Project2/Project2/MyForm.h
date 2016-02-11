#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  Add;
	private: System::Windows::Forms::TrackBar^  Speed;
	private: System::Windows::Forms::NumericUpDown^  Starty;
	private: System::Windows::Forms::NumericUpDown^  Startx;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ListBox^  BotSelect;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->Speed = (gcnew System::Windows::Forms::TrackBar());
			this->Starty = (gcnew System::Windows::Forms::NumericUpDown());
			this->Startx = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->BotSelect = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Speed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Starty))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Startx))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Location = System::Drawing::Point(12, 95);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(810, 461);
			this->panel1->TabIndex = 0;
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(457, 42);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(75, 23);
			this->Add->TabIndex = 1;
			this->Add->Text = L"Add VBot";
			this->Add->UseVisualStyleBackColor = true;
			// 
			// Speed
			// 
			this->Speed->Location = System::Drawing::Point(589, 44);
			this->Speed->Name = L"Speed";
			this->Speed->Size = System::Drawing::Size(104, 45);
			this->Speed->TabIndex = 2;
			// 
			// Starty
			// 
			this->Starty->Location = System::Drawing::Point(343, 48);
			this->Starty->Name = L"Starty";
			this->Starty->Size = System::Drawing::Size(52, 20);
			this->Starty->TabIndex = 3;
			// 
			// Startx
			// 
			this->Startx->Location = System::Drawing::Point(268, 48);
			this->Startx->Name = L"Startx";
			this->Startx->Size = System::Drawing::Size(58, 20);
			this->Startx->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(287, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Start X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(356, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Start Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(619, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Speed";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(75, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Select VBot Type";
			// 
			// BotSelect
			// 
			this->BotSelect->FormattingEnabled = true;
			this->BotSelect->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Happy Bot", L"Weird Bot", L"Awesome Bot"});
			this->BotSelect->Location = System::Drawing::Point(63, 48);
			this->BotSelect->Name = L"BotSelect";
			this->BotSelect->Size = System::Drawing::Size(120, 17);
			this->BotSelect->TabIndex = 9;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(834, 568);
			this->Controls->Add(this->BotSelect);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Startx);
			this->Controls->Add(this->Starty);
			this->Controls->Add(this->Speed);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Speed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Starty))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Startx))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
};

STAThreadAttribute;
void main(){
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm());
}
}
