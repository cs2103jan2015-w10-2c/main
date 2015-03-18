#pragma once
//#include "CommandParser.h"
#include "EasyScheduleLogic.h"
#include <string>
//#include <cliext/vector>
#include <assert.h>
#include <msclr\marshal_cppstd.h>
#using <mscorlib.dll>


//change to exception: because it is user's fault.
void checkUserInput (string userInput) {
	
	assert(isalpha(userInput[0]));
}

namespace UI {

	using namespace System;
	using namespace std;
//	using namespace cliext;
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
	//	cliext::vector<String^> allUserInputs; //a vector to store all user inputs


	public: 

		
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
			this->SuspendLayout();
			// 
			// enterButton
			// 
			this->enterButton->Location = System::Drawing::Point(463, 284);
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
			this->inputBox->Size = System::Drawing::Size(394, 45);
			this->inputBox->TabIndex = 1;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::inputBox_TextChanged);
			// 
			// outputBox
			// 
			this->outputBox->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->outputBox->Location = System::Drawing::Point(34, 27);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(504, 240);
			this->outputBox->TabIndex = 2;
			this->outputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::outputBox_TextChanged);
			// 
			// EasyScheduleGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 350);
			this->Controls->Add(this->outputBox);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->enterButton);
			this->Name = L"EasyScheduleGUI";
			this->Text = L"EasyScheduleGUI";
			this->Load += gcnew System::EventHandler(this, &EasyScheduleGUI::EasyScheduleGUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//When users loads (opens) the programme
	private: System::Void EasyScheduleGUI_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->outputBox->Text = "Hello Jim. Welcome to EasySchedule!\r\n\r\nWhat would you like to do?";
				 /*
				 other welcome messages such as show all the command types, show today's tasks, etc 
				 */
		 }

	//User press "Enter" key after typing to replace clicking "Enter" button
	//Debug: Now it doesn't work. Why???
	private: System::Void inputBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				if(e->KeyCode == Keys::Enter) {
					enterButton->PerformClick();
				}
		 }

	//Actions happen after user clicks the "Enter" button 
	private: System::Void enterButton_Click(System::Object^  sender, System::EventArgs^  e) {
				//allUserInputs.push_back(this->inputBox->Text);
				userInput = this->inputBox->Text;

				//convert from System::String to std::string and pass to logic
				msclr::interop::marshal_context context;
				std::string userInputString = context.marshal_as<std::string>(userInput);
				
				checkUserInput(userInputString); //assertion


				EasyScheduleLogic::executeLogic(userInputString);
				this->inputBox->Text = ""; //clear userinput in the inputBox

				//convert from std::string to System::String to print as feedback.
				String^ tempString = gcnew String((EasyScheduleLogic::tellUI()).c_str());
				//Console::WriteLine(tempString);
				this->outputBox->Text = tempString;				 
		 }

	private: System::Void inputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void outputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

};
}
