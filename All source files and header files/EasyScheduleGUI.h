#pragma once
#include "EasyScheduleLogic.h"
#include <string>
#include <cliext/vector>
//#include <assert.h>
#include <msclr\marshal_cppstd.h>
#using <mscorlib.dll>

//change to exception: because it is user's fault.
//void checkUserInput (string userInput) {
//	
//	assert(isalpha(userInput[0]));
//}

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
	private: System::Windows::Forms::TextBox^  feedbackBox;


	private: System::Windows::Forms::ListView^  listOutput;
	private: System::Windows::Forms::ColumnHeader^  Marked;
	private: System::Windows::Forms::ColumnHeader^  Index;
	private: System::Windows::Forms::ColumnHeader^  Task;
	private: System::Windows::Forms::ColumnHeader^  Date;
	private: System::Windows::Forms::ColumnHeader^  StartTime;
	private: System::Windows::Forms::ColumnHeader^  EndTime;
	private: System::Windows::Forms::ColumnHeader^  TaskType;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  feedbackLabel;

	private: System::Windows::Forms::TextBox^  previousCommandBox;
	private: System::Windows::Forms::Label^  previousCommandLabel;



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
			this->feedbackBox = (gcnew System::Windows::Forms::TextBox());
			this->listOutput = (gcnew System::Windows::Forms::ListView());
			this->Index = (gcnew System::Windows::Forms::ColumnHeader());
			this->Marked = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskType = (gcnew System::Windows::Forms::ColumnHeader());
			this->Task = (gcnew System::Windows::Forms::ColumnHeader());
			this->Date = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->EndTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->feedbackLabel = (gcnew System::Windows::Forms::Label());
			this->previousCommandBox = (gcnew System::Windows::Forms::TextBox());
			this->previousCommandLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// enterButton
			// 
			this->enterButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->enterButton->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->enterButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->enterButton->Location = System::Drawing::Point(570, 368);
			this->enterButton->Name = L"enterButton";
			this->enterButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->enterButton->Size = System::Drawing::Size(87, 25);
			this->enterButton->TabIndex = 0;
			this->enterButton->Text = L"Enter";
			this->enterButton->UseVisualStyleBackColor = true;
			this->enterButton->Click += gcnew System::EventHandler(this, &EasyScheduleGUI::enterButton_Click);
			// 
			// inputBox
			// 
			this->inputBox->BackColor = System::Drawing::SystemColors::Window;
			this->inputBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(5, 368);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(550, 24);
			this->inputBox->TabIndex = 1;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::inputBox_TextChanged);
			// 
			// feedbackBox
			// 
			this->feedbackBox->BackColor = System::Drawing::SystemColors::Info;
			this->feedbackBox->Font = (gcnew System::Drawing::Font(L"Arial", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackBox->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->feedbackBox->Location = System::Drawing::Point(5, 323);
			this->feedbackBox->Multiline = true;
			this->feedbackBox->Name = L"feedbackBox";
			this->feedbackBox->Size = System::Drawing::Size(319, 32);
			this->feedbackBox->TabIndex = 2;
			this->feedbackBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->feedbackBox->UseWaitCursor = true;
			this->feedbackBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::feedbackBox_TextChanged);
			// 
			// listOutput
			// 
			this->listOutput->AllowColumnReorder = true;
			this->listOutput->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->listOutput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listOutput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->Index, this->Marked, 
				this->TaskType, this->Task, this->Date, this->StartTime, this->EndTime});
			this->listOutput->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listOutput->ForeColor = System::Drawing::SystemColors::WindowText;
			this->listOutput->FullRowSelect = true;
			this->listOutput->GridLines = true;
			this->listOutput->Location = System::Drawing::Point(5, 9);
			this->listOutput->Name = L"listOutput";
			this->listOutput->Size = System::Drawing::Size(652, 289);
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
			// feedbackLabel
			// 
			this->feedbackLabel->AutoSize = true;
			this->feedbackLabel->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->feedbackLabel->Font = (gcnew System::Drawing::Font(L"Arial", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->feedbackLabel->Location = System::Drawing::Point(2, 305);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(71, 16);
			this->feedbackLabel->TabIndex = 4;
			this->feedbackLabel->Text = L"Feedback";
			this->feedbackLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->feedbackLabel->Click += gcnew System::EventHandler(this, &EasyScheduleGUI::label1_Click);
			// 
			// previousCommandBox
			// 
			this->previousCommandBox->BackColor = System::Drawing::SystemColors::Info;
			this->previousCommandBox->Font = (gcnew System::Drawing::Font(L"Arial", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->previousCommandBox->Location = System::Drawing::Point(339, 323);
			this->previousCommandBox->Multiline = true;
			this->previousCommandBox->Name = L"previousCommandBox";
			this->previousCommandBox->Size = System::Drawing::Size(318, 32);
			this->previousCommandBox->TabIndex = 5;
			// 
			// previousCommandLabel
			// 
			this->previousCommandLabel->AutoSize = true;
			this->previousCommandLabel->Font = (gcnew System::Drawing::Font(L"Arial", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->previousCommandLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->previousCommandLabel->Location = System::Drawing::Point(336, 305);
			this->previousCommandLabel->Name = L"previousCommandLabel";
			this->previousCommandLabel->Size = System::Drawing::Size(128, 16);
			this->previousCommandLabel->TabIndex = 6;
			this->previousCommandLabel->Text = L"Previous command";
			// 
			// EasyScheduleGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(664, 403);
			this->Controls->Add(this->previousCommandLabel);
			this->Controls->Add(this->previousCommandBox);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->listOutput);
			this->Controls->Add(this->feedbackBox);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->enterButton);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"EasyScheduleGUI";
			this->Text = L"EasyScheduleGUI";
			this->Load += gcnew System::EventHandler(this, &EasyScheduleGUI::EasyScheduleGUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//When users loads (opens) the programme
	private: System::Void EasyScheduleGUI_Load(System::Object^  sender, System::EventArgs^  e) {
				this->feedbackBox->Text = "Hello Jim. Welcome to EasySchedule!\r\n\r\nWhat would you like to do?";
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
				this->previousCommandBox->Text = userInput;
				//convert from System::String to std::string and pass to logic
				msclr::interop::marshal_context context;
				std::string userInputString = context.marshal_as<std::string>(userInput);
				
				//clear the previous input and output for future uses.
				listOutput->Items->Clear();
				this->inputBox->Clear();
				
			//	checkUserInput(userInputString); //assertion

				EasyScheduleLogic::executeLogic(userInputString);
				string returnInfo = EasyScheduleLogic::tellUI();
				String^ tempString = gcnew String(returnInfo.c_str());
				this->feedbackBox->Text = tempString;		

				if(isalpha(returnInfo[0])) {
					String^ feedback = gcnew String(returnInfo.c_str()); //convert from std::string to System::String to print as feedback.
				//	Console::WriteLine(tempString);
				//	System::Windows::Forms::MessageBox::Show(feedback); //"failed" feedback message
					this->feedbackBox->Text = feedback;
				} else {
					string componentInfo;
					String^ temp;
					size_t tempStart;
					size_t tempEnd=-1;

					//why algorithm count() doesn't work
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
	private: System::Void feedbackBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
