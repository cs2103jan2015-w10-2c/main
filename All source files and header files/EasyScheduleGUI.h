#pragma once
//#include "CommandParser.h"
#include "EasyScheduleLogic.h"
#include <string>
#include <cliext/vector>
#include <msclr\marshal_cppstd.h>
#using <mscorlib.dll>

namespace UI {

	using namespace System;
	using namespace cliext;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class EasyScheduleGUI : public System::Windows::Forms::Form {
	
	private: 
		String^ userInput;
	public:
		cliext::vector<String^> allUserInputs; //a vector to store all user inputs

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	public: 
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
		
	public:
		EasyScheduleGUI(void) {
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}
		


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EasyScheduleGUI() {
			if (components) {
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  enterButton;
	protected: 

	private: System::Windows::Forms::TextBox^  inputBox;
	private: System::Windows::Forms::TextBox^  outputBox;

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
		void InitializeComponent(void) {
			this->enterButton = (gcnew System::Windows::Forms::Button());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// enterButton
			// 
			this->enterButton->Location = System::Drawing::Point(638, 284);
			this->enterButton->Name = L"enterButton";
			this->enterButton->Size = System::Drawing::Size(75, 45);
			this->enterButton->TabIndex = 0;
			this->enterButton->Text = L"Enter";
			this->enterButton->UseVisualStyleBackColor = true;
			this->enterButton->Click += gcnew System::EventHandler(this, &EasyScheduleGUI::enterButton_Click);
			// 
			// inputBox
			// 
			this->inputBox->BackColor = System::Drawing::SystemColors::Window;
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(34, 284);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->inputBox->Size = System::Drawing::Size(570, 45);
			this->inputBox->TabIndex = 1;
	//		this->inputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::inputBox_TextChanged);
			// 
			// outputBox
			// 
			this->outputBox->Location = System::Drawing::Point(34, 27);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(679, 240);
			this->outputBox->TabIndex = 2;
//			this->outputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::outputBox_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(753, 25);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(40, 21);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &EasyScheduleGUI::exitToolStripMenuItem_Click);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(753, 350);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->enterButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"EasyScheduleGUI";
			this->Text = L"EasyScheduleGUI";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void enterButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 //in case user accidentally click on the button without any content in the text box
				 if(inputBox->Text->Substring(0, 3) == "add") {
					 allUserInputs.push_back(this->inputBox->Text);
					 userInput = this->inputBox->Text;

					 //convert from System::String to std::string and pass to command parser cp
					 msclr::interop::marshal_context context;
					 std::string userInputString = context.marshal_as<std::string>(userInput);
//					 cp->identifyTask(); //call Command Parser
					 
					 EasyScheduleLogic::main(userInputString);
					 this->inputBox->Text = ""; //clear userinput in the inputBox
					 this->outputBox->Text = EasyScheduleLogic::tellUI();
				 }
				 else if (inputBox->Text->Substring(0, 6) == "display") {

				 } 
		 }

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		//	 MessageBox::Show("Exit the programme?");
			 Close();
		 }
};
}
