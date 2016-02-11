#pragma once
#include "VBot.h"
#include "HappyBot.h"
#include "AwesomeBot.h"
#include "MegaTronBot.h"
#include "AutoBot.h"
#include "BotContainer.h"
namespace Program3 {

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
			bot_x = bot_y = 50;
			timer1->Start();
			VBOTVector = new vector<VBot*>;
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
			VBOTVector->clear();
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Button^  AddBot;
	private:
		int bot_x, bot_y;
	    static const int BOTSIZE = 40;
		vector< VBot*> *VBOTVector;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TrackBar^  Speed;

	private: System::Windows::Forms::NumericUpDown^  StartX;
	private: System::Windows::Forms::NumericUpDown^  StartY;
	private: System::Windows::Forms::ListBox^  BotSelect;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  RemoveDeadBtn;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->AddBot = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Speed = (gcnew System::Windows::Forms::TrackBar());
			this->StartX = (gcnew System::Windows::Forms::NumericUpDown());
			this->StartY = (gcnew System::Windows::Forms::NumericUpDown());
			this->BotSelect = (gcnew System::Windows::Forms::ListBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->RemoveDeadBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Speed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->StartX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->StartY))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Location = System::Drawing::Point(12, 81);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(660, 369);
			this->panel1->TabIndex = 0;
			// 
			// AddBot
			// 
			this->AddBot->Location = System::Drawing::Point(477, 24);
			this->AddBot->Name = L"AddBot";
			this->AddBot->Size = System::Drawing::Size(75, 23);
			this->AddBot->TabIndex = 1;
			this->AddBot->Text = L"Add Bot";
			this->AddBot->UseVisualStyleBackColor = true;
			this->AddBot->Click += gcnew System::EventHandler(this, &MyForm::AddBot_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(53, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Select a Bot";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(222, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Start X";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(342, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Start Y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(597, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Speed";
			// 
			// Speed
			// 
			this->Speed->LargeChange = 100;
			this->Speed->Location = System::Drawing::Point(568, 30);
			this->Speed->Maximum = 500;
			this->Speed->Minimum = 50;
			this->Speed->Name = L"Speed";
			this->Speed->Size = System::Drawing::Size(104, 45);
			this->Speed->SmallChange = 10;
			this->Speed->TabIndex = 7;
			this->Speed->TickFrequency = 100;
			this->Speed->Value = 250;
			this->Speed->ValueChanged += gcnew System::EventHandler(this, &MyForm::Speed_ValueChanged);
			// 
			// StartX
			// 
			this->StartX->AllowDrop = true;
			this->StartX->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->StartX->Location = System::Drawing::Point(176, 30);
			this->StartX->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {700, 0, 0, 0});
			this->StartX->Name = L"StartX";
			this->StartX->Size = System::Drawing::Size(120, 20);
			this->StartX->TabIndex = 8;
			this->StartX->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->StartX->ValueChanged += gcnew System::EventHandler(this, &MyForm::StartX_ValueChanged);
			// 
			// StartY
			// 
			this->StartY->AllowDrop = true;
			this->StartY->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->StartY->Location = System::Drawing::Point(327, 30);
			this->StartY->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {280, 0, 0, 0});
			this->StartY->Name = L"StartY";
			this->StartY->Size = System::Drawing::Size(120, 20);
			this->StartY->TabIndex = 9;
			this->StartY->ValueChanged += gcnew System::EventHandler(this, &MyForm::StartY_ValueChanged);
			// 
			// BotSelect
			// 
			this->BotSelect->FormattingEnabled = true;
			this->BotSelect->HorizontalExtent = 4;
			this->BotSelect->HorizontalScrollbar = true;
			this->BotSelect->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"HappyBot", L"AwesomeBot", L"MegaTronBot", L"AutoBot"});
			this->BotSelect->Location = System::Drawing::Point(37, 33);
			this->BotSelect->Name = L"BotSelect";
			this->BotSelect->Size = System::Drawing::Size(120, 17);
			this->BotSelect->TabIndex = 10;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// RemoveDeadBtn
			// 
			this->RemoveDeadBtn->Location = System::Drawing::Point(461, 53);
			this->RemoveDeadBtn->Name = L"RemoveDeadBtn";
			this->RemoveDeadBtn->Size = System::Drawing::Size(116, 23);
			this->RemoveDeadBtn->TabIndex = 11;
			this->RemoveDeadBtn->Text = L"Remove Dead Bots";
			this->RemoveDeadBtn->UseVisualStyleBackColor = true;
			this->RemoveDeadBtn->Click += gcnew System::EventHandler(this, &MyForm::RemoveDeadBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 462);
			this->Controls->Add(this->RemoveDeadBtn);
			this->Controls->Add(this->BotSelect);
			this->Controls->Add(this->StartY);
			this->Controls->Add(this->StartX);
			this->Controls->Add(this->Speed);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->AddBot);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Speed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->StartX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->StartY))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddBot_Click(System::Object^  sender, System::EventArgs^  e) {

				 if(BotSelect->SelectedItem->ToString() == "HappyBot")
				 {
					 HappyBot *g = new HappyBot( bot_x, bot_y, this->panel1);
					 g->Show();
					 VBOTVector->push_back( dynamic_cast<VBot*>(g));
				 } 
				 else if(BotSelect->SelectedItem->ToString() == "AwesomeBot")
				 {
					 AwesomeBot *x = new AwesomeBot( bot_x, bot_y, this->panel1);
					 x->Show();
					 VBOTVector->push_back( dynamic_cast<VBot*>(x));
				 } 
				 else if(BotSelect->SelectedItem->ToString() == "MegaTronBot")
				 {
					 MegaTronBot *y = new MegaTronBot( bot_x, bot_y, this->panel1);
					 y->Show();
					 VBOTVector->push_back( dynamic_cast<VBot*>(y));
				 }
				 else if (BotSelect->SelectedItem->ToString() == "AutoBot")
				 {
					 AutoBot *z = new AutoBot( bot_x, bot_y, this->panel1);
					 z->Show();
					 VBOTVector->push_back( dynamic_cast<VBot*>(z));
				 }
			 }

private: System::Void Speed_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 timer1->Interval = Speed->Value;
		 }

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		panel1->Refresh();// Cause a repaint.  Use this for painting bots.
		if(VBOTVector != NULL)
		{
			vector<VBot*>::iterator iter;
			vector<VBot*>::iterator iter2;
			for(iter = VBOTVector->begin(); iter != VBOTVector->end(); iter++)
			{
				for(iter2 = VBOTVector->begin(); iter2 != VBOTVector->end(); iter2++)
				{
				    if( iter != iter2 && iter.operator*()->CollidedWith( iter2.operator*() ) )
					{
						if ( !(iter.operator*()->IsDead()) && !(iter2.operator*()->IsDead()) )
						{
							 iter.operator*()->DoBattleWith(iter2.operator*());

							 if (iter.operator*()->IsDead())
								iter.operator*()->Dead();
							 if (iter2.operator*()->IsDead())
							    iter2.operator*()->Dead();
						}
					}
				}
			}
			iter = VBOTVector->begin();
			while(iter != VBOTVector->end())
			{
			   iter.operator*()->Move();
			   iter.operator*()->Show();
			   iter++;
			}
		}
}

private: System::Void StartX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 bot_x = Decimal::ToInt32(StartX->Value);
		 }

private: System::Void StartY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 bot_y = Decimal::ToInt32(StartY->Value);
		 }

private: System::Void RemoveDeadBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		    vector<VBot*>::iterator iter;
			if (VBOTVector != NULL)
			{
				for (iter = VBOTVector->begin(); iter != VBOTVector->end(); iter++)
				{
					if(iter.operator*()->IsDead())
					{
						VBOTVector->erase(iter);
						iter = VBOTVector->begin();
					}
				}
			}
		 }
private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		 {
			 this->~MyForm();
			 timer1->Enabled = false;
		 }
};
}
