#pragma once
//#include "CommandParser.h"
#include "EasyScheduleLogic.h"
#include <string>
#include <cliext/vector>
#include <assert.h>
#include <msclr\marshal_cppstd.h>
#using <mscorlib.dll>
#include <algorithm>


//change to exception: because it is user's fault.
void checkUserInput (string userInput) {
	
	assert(isalpha(userInput[0]));
}

namespace UI {

	using namespace System;
	using namespace std;
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

	private: System::Windows::Forms::ListView^  listOutput;
	private: System::Windows::Forms::ColumnHeader^  Marked;
	private: System::Windows::Forms::ColumnHeader^  Index;
	private: System::Windows::Forms::ColumnHeader^  Task;
	private: System::Windows::Forms::ColumnHeader^  Date;
	private: System::Windows::Forms::ColumnHeader^  StartTime;
	private: System::Windows::Forms::ColumnHeader^  EndTime;
	private: System::Windows::Forms::ColumnHeader^  TaskType;

	private: System::ComponentModel::IContainer^  components;

	protected: System::Windows::Forms::ListViewItem^ listViewItems;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			this->enterButton = (gcnew System::Windows::Forms::Button());
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->listOutput = (gcnew System::Windows::Forms::ListView());
			this->Index = (gcnew System::Windows::Forms::ColumnHeader());
			this->Marked = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskType = (gcnew System::Windows::Forms::ColumnHeader());
			this->Task = (gcnew System::Windows::Forms::ColumnHeader());
			this->Date = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->EndTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// enterButton
			// 
			this->enterButton->Location = System::Drawing::Point(569, 367);
			this->enterButton->Name = L"enterButton";
			this->enterButton->Size = System::Drawing::Size(88, 25);
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
			this->inputBox->Location = System::Drawing::Point(6, 368);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(547, 24);
			this->inputBox->TabIndex = 1;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::inputBox_TextChanged);
			// 
			// outputBox
			// 
			this->outputBox->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->outputBox->Location = System::Drawing::Point(6, 12);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(651, 65);
			this->outputBox->TabIndex = 2;
			this->outputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::outputBox_TextChanged);
			// 
			// listOutput
			// 
			this->listOutput->AllowColumnReorder = true;
			this->listOutput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->Index, this->Marked, 
				this->TaskType, this->Task, this->Date, this->StartTime, this->EndTime});
			this->listOutput->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listOutput->Location = System::Drawing::Point(6, 83);
			this->listOutput->Name = L"listOutput";
			this->listOutput->Size = System::Drawing::Size(651, 278);
			this->listOutput->TabIndex = 3;
			this->listOutput->UseCompatibleStateImageBehavior = false;
			this->listOutput->View = System::Windows::Forms::View::Details;
			this->listOutput->SelectedIndexChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::listView1_SelectedIndexChanged);
			// 
			// Index
			// 
			this->Index->Text = L"Index";
			this->Index->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Index->Width = 50;
			// 
			// Marked
			// 
			this->Marked->Text = L"Done\?";
			this->Marked->Width = 50;
			// 
			// TaskType
			// 
			this->TaskType->Text = L"Type";
			this->TaskType->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TaskType->Width = 80;
			// 
			// Task
			// 
			this->Task->Text = L"Task";
			this->Task->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Task->Width = 229;
			// 
			// Date
			// 
			this->Date->Text = L"Date";
			this->Date->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Date->Width = 80;
			// 
			// StartTime
			// 
			this->StartTime->Text = L"Start at";
			this->StartTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StartTime->Width = 80;
			// 
			// EndTime
			// 
			this->EndTime->Text = L"End at";
			this->EndTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->EndTime->Width = 80;
			// 
			// EasyScheduleGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(664, 403);
			this->Controls->Add(this->listOutput);
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
				//clear the previous output for future uses.
				listOutput->Items->Clear();
				//allUserInputs.push_back(this->inputBox->Text);
				userInput = this->inputBox->Text;

				//convert from System::String to std::string and pass to logic
				msclr::interop::marshal_context context;
				std::string userInputString = context.marshal_as<std::string>(userInput);
				
			//	checkUserInput(userInputString); //assertion

				EasyScheduleLogic::executeLogic(userInputString);
				this->inputBox->Clear(); //clear userinput in the inputBox
				string returnInfo = EasyScheduleLogic::tellUI();

				String^ tempString = gcnew String(returnInfo.c_str());
				this->outputBox->Text = tempString;		

				if(isalpha(returnInfo[0])) {
					String^ feedback = gcnew String(returnInfo.c_str()); //convert from std::string to System::String to print as feedback.
				//	Console::WriteLine(tempString);
					System::Windows::Forms::MessageBox::Show(feedback); //"failed" feedback message
				} else {
					string componentInfo;
					String^ temp;
					size_t tempStart;
					size_t tempEnd=-1;
					int count = 0;
					for(int i=0; i<int(returnInfo.size());i++) {
						if (returnInfo.at(i) == ']') {
							count++;
						}
					}
					while(count > 0) {
						/****Index****/		//BUG: why index all 1 on display
						tempStart = tempEnd+1;
						tempEnd = returnInfo.find_first_of("]", tempStart);
						componentInfo = returnInfo.substr(0, tempEnd-tempStart);
						temp = gcnew String(componentInfo.c_str());
						listViewItems = gcnew Windows::Forms::ListViewItem(temp);
						/****Mark****/
						tempStart = tempEnd+1;
						tempEnd = returnInfo.find_first_of("]", tempStart);
						componentInfo = returnInfo.substr(tempStart, tempEnd-tempStart);
						temp = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(temp); 
						/****Task type****/
						tempStart = tempEnd+1;
						tempEnd = returnInfo.find_first_of("]", tempStart);
						componentInfo = returnInfo.substr(tempStart, tempEnd-tempStart);
						temp = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(temp); 
						/****Task name****/
						tempStart = tempEnd+1;
						tempEnd = returnInfo.find_first_of("]", tempStart);
						componentInfo = returnInfo.substr(tempStart, tempEnd-tempStart);
						temp = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(temp); 
						/****Date****/
						tempStart = tempEnd+1;
						tempEnd = returnInfo.find_first_of("]", tempStart);
						componentInfo = returnInfo.substr(tempStart, tempEnd-tempStart);
						temp = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(temp); 
						/****Start time****/
						tempStart = tempEnd+1;
						tempEnd = returnInfo.find_first_of("]", tempStart);
						componentInfo = returnInfo.substr(tempStart, tempEnd-tempStart);
						temp = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(temp); 
						/****End time****/
						tempStart = tempEnd+1;
						tempEnd = returnInfo.find_first_of("]", tempStart);
						componentInfo = returnInfo.substr(tempStart, tempEnd-tempStart);
						temp = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(temp); 
					
						listOutput->Items->Add(this->listViewItems);
						count -= 7; //each task has seven dividers "]"
					}
				}
		 }

	private: System::Void inputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void outputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
