#pragma once
#include "Trial.h"
#include "TrialVector.h"

const int TrialTimesMultiplier = 1000;

namespace MyForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
				trial1->~Trial();
			}
		}
	private: System::Windows::Forms::TextBox^  InputTextBox;
	protected: 

   protected: 
   private: System::Windows::Forms::Button^  addTextBtn;
   private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  StringListBox;

	private: System::Windows::Forms::ComboBox^  ContainerListSelect;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  TrialTimeLabel;
	private: System::Windows::Forms::NumericUpDown^  iterations;
	private: System::Windows::Forms::ComboBox^  TrialTypeSelect;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: Trial *trial1;

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
			this->InputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->addTextBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->StringListBox = (gcnew System::Windows::Forms::ListBox());
			this->ContainerListSelect = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TrialTimeLabel = (gcnew System::Windows::Forms::Label());
			this->iterations = (gcnew System::Windows::Forms::NumericUpDown());
			this->TrialTypeSelect = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->iterations))->BeginInit();
			this->SuspendLayout();
			// 
			// InputTextBox
			// 
			this->InputTextBox->Location = System::Drawing::Point(16, 11);
			this->InputTextBox->Name = L"InputTextBox";
			this->InputTextBox->Size = System::Drawing::Size(116, 20);
			this->InputTextBox->TabIndex = 1;
			// 
			// addTextBtn
			// 
			this->addTextBtn->Location = System::Drawing::Point(138, 12);
			this->addTextBtn->Name = L"addTextBtn";
			this->addTextBtn->Size = System::Drawing::Size(75, 23);
			this->addTextBtn->TabIndex = 2;
			this->addTextBtn->Text = L"Add text";
			this->addTextBtn->UseVisualStyleBackColor = true;
			this->addTextBtn->Click += gcnew System::EventHandler(this, &Form1::addTextBtn_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(219, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 24);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Remove Selected";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// StringListBox
			// 
			this->StringListBox->FormattingEnabled = true;
			this->StringListBox->Location = System::Drawing::Point(12, 37);
			this->StringListBox->Name = L"StringListBox";
			this->StringListBox->Size = System::Drawing::Size(120, 212);
			this->StringListBox->Sorted = true;
			this->StringListBox->TabIndex = 4;
			// 
			// ContainerListSelect
			// 
			this->ContainerListSelect->FormattingEnabled = true;
			this->ContainerListSelect->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Vector", L"List", L"Deque", L"Multiset", 
				L"Multimap"});
			this->ContainerListSelect->Location = System::Drawing::Point(151, 72);
			this->ContainerListSelect->Name = L"ContainerListSelect";
			this->ContainerListSelect->Size = System::Drawing::Size(121, 21);
			this->ContainerListSelect->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(33, 276);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Trial Time:";
			// 
			// TrialTimeLabel
			// 
			this->TrialTimeLabel->AutoSize = true;
			this->TrialTimeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TrialTimeLabel->Location = System::Drawing::Point(119, 276);
			this->TrialTimeLabel->Name = L"TrialTimeLabel";
			this->TrialTimeLabel->Size = System::Drawing::Size(132, 20);
			this->TrialTimeLabel->TabIndex = 7;
			this->TrialTimeLabel->Text = L"*3 Microseconds*";
			// 
			// iterations
			// 
			this->iterations->Location = System::Drawing::Point(311, 134);
			this->iterations->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->iterations->Name = L"iterations";
			this->iterations->Size = System::Drawing::Size(120, 20);
			this->iterations->TabIndex = 8;
			this->iterations->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// TrialTypeSelect
			// 
			this->TrialTypeSelect->FormattingEnabled = true;
			this->TrialTypeSelect->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"FRONT FRONT", L"FRONT REAR", L"REAR FRONT", 
				L"REAR REAR", L"SORTED"});
			this->TrialTypeSelect->Location = System::Drawing::Point(311, 72);
			this->TrialTypeSelect->Name = L"TrialTypeSelect";
			this->TrialTypeSelect->Size = System::Drawing::Size(121, 21);
			this->TrialTypeSelect->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(174, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Container List";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(341, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Trial Type";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(321, 109);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Iterations (x1000)";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(311, 246);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 50);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Start Trial";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 327);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->TrialTypeSelect);
			this->Controls->Add(this->iterations);
			this->Controls->Add(this->TrialTimeLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ContainerListSelect);
			this->Controls->Add(this->StringListBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->addTextBtn);
			this->Controls->Add(this->InputTextBox);
			this->Name = L"Form1";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->iterations))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
   
   private: System::Void addTextBtn_Click(System::Object^  sender, System::EventArgs^  e) 
            {
               if ( InputTextBox->Text != "" )
                  StringListBox->Items->Add( InputTextBox->Text );
			   InputTextBox->Text = "";

            }
   private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
            {
				if ( StringListBox->SelectedIndex != -1 )
					StringListBox->Items->Remove(StringListBox->SelectedItem);
            }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 vector<string> happy;
			 happy.push_back(static_cast<string>(StringListBox->Items[0]->ToString()));

			 trial1 = new TrialVector ( happy, Convert::ToInt32(iterations->Value) * 1000, TrialTypeSelect->SelectedIndex);
			 TrialTimeLabel->Text = StringListBox->Text;
		 }
};
}

