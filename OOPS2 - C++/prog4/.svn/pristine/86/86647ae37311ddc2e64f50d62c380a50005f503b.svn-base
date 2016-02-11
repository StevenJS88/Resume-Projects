#pragma once
#include "Maze.h"
#include "HelpForm.h"

namespace Prog4 {

   using namespace System;
   using namespace System::ComponentModel;
   using namespace System::Collections;
   using namespace System::Windows::Forms;
   using namespace System::Data;
   using namespace System::Drawing;


   /// <summary>
   /// Summary for MainForm
   /// </summary>
   public ref class MainForm : public System::Windows::Forms::Form
   {
   public:
      MainForm(void)
      {
         InitializeComponent();
		 FreedLabel->Hide();
      }

   protected:
      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      ~MainForm()
      {
         if (components)
         {
            delete components;
         }
		 if (maze != NULL)
            delete maze;
      }
   private: System::Windows::Forms::MenuStrip^  menuStrip1;
   protected: 
   private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
   private: System::Windows::Forms::ToolStripMenuItem^  MenuOpenFile;

   private: System::Windows::Forms::ToolStripMenuItem^  MenuExit;


   private: System::Windows::Forms::ToolStripMenuItem^  MenuHelp;


   private: System::Windows::Forms::Panel^  panel1;
   private: System::Windows::Forms::OpenFileDialog^  FileDialog;



   private:
      /// <summary>
      /// Required designer variable.
      /// </summary>
      System::ComponentModel::Container ^components;
   private: System::Windows::Forms::Label^  freeLabel;
   private: System::Windows::Forms::Button^  button1;

   private: System::Windows::Forms::Label^  FreedLabel;
			Maze *maze;


#pragma region Windows Form Designer generated code
            /// <summary>
            /// Required method for Designer support - do not modify
            /// the contents of this method with the code editor.
            /// </summary>
            void InitializeComponent(void)
            {
				this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->MenuOpenFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->MenuExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->MenuHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->FileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				this->freeLabel = (gcnew System::Windows::Forms::Label());
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->FreedLabel = (gcnew System::Windows::Forms::Label());
				this->menuStrip1->SuspendLayout();
				this->SuspendLayout();
				// 
				// menuStrip1
				// 
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem1, 
					this->MenuHelp});
				this->menuStrip1->Location = System::Drawing::Point(0, 0);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->Padding = System::Windows::Forms::Padding(3, 1, 0, 1);
				this->menuStrip1->Size = System::Drawing::Size(496, 24);
				this->menuStrip1->TabIndex = 0;
				this->menuStrip1->Text = L"menuStrip1";
				// 
				// toolStripMenuItem1
				// 
				this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->MenuOpenFile, 
					this->MenuExit});
				this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
				this->toolStripMenuItem1->Size = System::Drawing::Size(37, 22);
				this->toolStripMenuItem1->Text = L"File";
				// 
				// MenuOpenFile
				// 
				this->MenuOpenFile->Name = L"MenuOpenFile";
				this->MenuOpenFile->Size = System::Drawing::Size(124, 22);
				this->MenuOpenFile->Text = L"Open File";
				this->MenuOpenFile->Click += gcnew System::EventHandler(this, &MainForm::MenuOpenFile_Click);
				// 
				// MenuExit
				// 
				this->MenuExit->Name = L"MenuExit";
				this->MenuExit->Size = System::Drawing::Size(124, 22);
				this->MenuExit->Text = L"Exit";
				this->MenuExit->Click += gcnew System::EventHandler(this, &MainForm::MenuExit_Click);
				// 
				// MenuHelp
				// 
				this->MenuHelp->Name = L"MenuHelp";
				this->MenuHelp->Size = System::Drawing::Size(44, 22);
				this->MenuHelp->Text = L"Help";
				this->MenuHelp->Click += gcnew System::EventHandler(this, &MainForm::MenuHelp_Click);
				// 
				// panel1
				// 
				this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
				this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				this->panel1->Location = System::Drawing::Point(11, 57);
				this->panel1->Margin = System::Windows::Forms::Padding(2);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(474, 311);
				this->panel1->TabIndex = 1;
				this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel1_MouseDown);
				// 
				// freeLabel
				// 
				this->freeLabel->AutoSize = true;
				this->freeLabel->Location = System::Drawing::Point(73, 24);
				this->freeLabel->Name = L"freeLabel";
				this->freeLabel->Size = System::Drawing::Size(60, 13);
				this->freeLabel->TabIndex = 2;
				this->freeLabel->Text = L"Not Solved";
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(173, 24);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(111, 23);
				this->button1->TabIndex = 3;
				this->button1->Text = L"Show Original";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
				// 
				// FreedLabel
				// 
				this->FreedLabel->AutoSize = true;
				this->FreedLabel->Location = System::Drawing::Point(323, 24);
				this->FreedLabel->Name = L"FreedLabel";
				this->FreedLabel->Size = System::Drawing::Size(112, 13);
				this->FreedLabel->TabIndex = 5;
				this->FreedLabel->Text = L"You\'re Free! Congrats!";
				// 
				// MainForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(496, 463);
				this->Controls->Add(this->FreedLabel);
				this->Controls->Add(this->button1);
				this->Controls->Add(this->freeLabel);
				this->Controls->Add(this->panel1);
				this->Controls->Add(this->menuStrip1);
				this->MainMenuStrip = this->menuStrip1;
				this->Margin = System::Windows::Forms::Padding(2);
				this->Name = L"MainForm";
				this->Text = L"MainForm";
				this->menuStrip1->ResumeLayout(false);
				this->menuStrip1->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion

   private: System::Void MenuExit_Click(System::Object^  sender, System::EventArgs^  e)
            {
               this->~MainForm();
            }

   private: System::Void MenuHelp_Click(System::Object^  sender, System::EventArgs^  e)
            {
               Prog4::HelpForm form;
               form.ShowDialog();
            }

   private: System::Void MenuOpenFile_Click(System::Object^  sender, System::EventArgs^  e)
            {
               char filename[1024];
               ifstream ifs;
               if ( FileDialog->ShowDialog() == ::DialogResult::OK )
               {
                  for (int i = 0; i < FileDialog->FileName->Length; i++)
                     filename[i] = FileDialog->FileName[i];
                  filename[FileDialog->FileName->Length] = NULL;
				  ifs.open(filename);
                  if( maze != NULL )
                     delete maze;
                  maze = new Maze( panel1, ifs );
                  ifs.close();
                  if( maze->IsValid() )
                     maze->ShowOriginal();
                  else
                     MessageBox::Show("You selected a bad .Dat maze file.  Select a valid .Dat maze file.");
                  freeLabel->Text = "Not Solved";
               }
               else
               {
                  MessageBox::Show("You selected a bad .Dat maze file.  Select a valid .Dat maze file.");
               }
            }

   private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
            {
               int cellX = e->X/16;
               int cellY = e->Y/16;
               maze->ShowOriginal();
               freeLabel->Text = "Not Solved";
			   FreedLabel->Hide();
               if ( !maze->IsFree() )
               {
                  maze->Solve(cellY, cellX);
                  maze->ShowSolved();
                  if(maze->IsFree())
				  {
                     freeLabel->Text = "Solved!!!";
					 FreedLabel->Show();
				  }
               }
            }

   private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
			{
				 freeLabel->Text = "Not Solved";
				 FreedLabel->Hide();
				 maze->ShowOriginal();
			}
};
}