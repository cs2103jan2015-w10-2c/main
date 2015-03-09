#pragma once
#include <string>
#include "CommandParser.h"
#include "Logic.cpp"
#include <iostream>
#include <cliext/vector>

namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TryGUI
	/// </summary>
	public ref class TryGUI : public System::Windows::Forms::Form {

	private: 
		String^ userInput;
		
	public:
		cliext::vector<String^> allUserInputs; //a vector to store all user inputs
		CommandParser cp;
		Logic logic;

		TryGUI(void) {
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TryGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(675, 281);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Enter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TryGUI::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(29, 278);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(615, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &TryGUI::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(29, 24);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(720, 231);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &TryGUI::textBox2_TextChanged);
			// 
			// TryGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 316);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"TryGUI";
			this->Text = L"TryGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 //enter code here
				 if(this->button1->Click) {
					 this->textBox2->Text = logic.tellUI;
				 }
			 }

	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 
				 //enter code here
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				 if(this->textBox2->Text!="") //in case user accidentally click on the button without any content in the text box
				 {
					 allUserInputs.push_back(this->textBox2->Text);
					 userInput = this->textBox2->Text;
					 cp.userInput = userInput;
				 //enter code here
				 }
			 }
	};
}
