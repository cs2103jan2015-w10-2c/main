#pragma once
#include "EasyScheduleLogic.h"
#include <string>
#include <cliext/vector>
//#include <assert.h>
#include <msclr\marshal_cppstd.h>
#using <mscorlib.dll>

//change to exception: because it is user's fault.

namespace UI {

	using namespace System;
	using namespace std;
	using namespace cliext;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int widthToCharacterDisplayRatio = 10; //taskheader->width = 200. so 20 char each line
	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class EasyScheduleGUI : public System::Windows::Forms::Form {
	
	private: 
	public:
	//	cliext::vector<String^> allUserInputs; //a vector to store all user inputs


	public: 

		
	public:
		EasyScheduleGUI(void) {
			InitializeComponent();
			void decomposeTaskString(ListView^ listOutput, string feedbackTasks, int feedbackIndex);
			bool determineMultilineNeeded(string taskInfo);
			void displayMultilineTask(string remainingPieces);
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
	private: System::Windows::Forms::ListView^  listOutputTimed;
	private: System::Windows::Forms::ColumnHeader^  StatusHeaderT;
	private: System::Windows::Forms::ColumnHeader^  IndexHeaderT;
	private: System::Windows::Forms::ColumnHeader^  TaskHeaderT;
	private: System::Windows::Forms::ColumnHeader^  DateHeaderT;
	private: System::Windows::Forms::ColumnHeader^  StartTimeHeaderT;
	private: System::Windows::Forms::ColumnHeader^  EndTimeHeaderT;
	private: System::Windows::Forms::ColumnHeader^  TypeHeaderT;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  feedbackLabel;
	private: System::Windows::Forms::TextBox^  previousCommandBox;
	private: System::Windows::Forms::Label^  previousCommandLabel;
	private: System::Windows::Forms::ListView^  listOutputDeadline;
	private: System::Windows::Forms::ColumnHeader^  IndexHeaderD;
	private: System::Windows::Forms::ColumnHeader^  StatusHeaderD;
	private: System::Windows::Forms::ColumnHeader^  TypeHeaderD;
	private: System::Windows::Forms::ColumnHeader^  TaskHeaderD;
	private: System::Windows::Forms::ColumnHeader^  DateHeaderD;
	private: System::Windows::Forms::ColumnHeader^  StartTimeHeaderD;
	private: System::Windows::Forms::ColumnHeader^  DueTimeHeaderD;
	private: System::Windows::Forms::ListView^  listOutputFloat;
	private: System::Windows::Forms::ColumnHeader^  IndexHeaderF;
	private: System::Windows::Forms::ColumnHeader^  StatusHeaderF;
	private: System::Windows::Forms::ColumnHeader^  TypeHeaderF;
	private: System::Windows::Forms::ColumnHeader^  TaskHeaderF;
	private: System::Windows::Forms::ColumnHeader^  DateHeaderF;
	private: System::Windows::Forms::ColumnHeader^  StartTimeHeaderF;
	private: System::Windows::Forms::ColumnHeader^  EndTimeHeaderF;
	private: System::Windows::Forms::Label^  FloatTaskLabel;
	private: System::Windows::Forms::Label^  DeadlineTaskLabel;
	private: System::Windows::Forms::Label^  TimedTaskLabel;
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
			this->listOutputTimed = (gcnew System::Windows::Forms::ListView());
			this->IndexHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->StatusHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->TypeHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->DateHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartTimeHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->EndTimeHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->feedbackLabel = (gcnew System::Windows::Forms::Label());
			this->previousCommandBox = (gcnew System::Windows::Forms::TextBox());
			this->previousCommandLabel = (gcnew System::Windows::Forms::Label());
			this->listOutputDeadline = (gcnew System::Windows::Forms::ListView());
			this->IndexHeaderD = (gcnew System::Windows::Forms::ColumnHeader());
			this->StatusHeaderD = (gcnew System::Windows::Forms::ColumnHeader());
			this->TypeHeaderD = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskHeaderD = (gcnew System::Windows::Forms::ColumnHeader());
			this->DateHeaderD = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartTimeHeaderD = (gcnew System::Windows::Forms::ColumnHeader());
			this->DueTimeHeaderD = (gcnew System::Windows::Forms::ColumnHeader());
			this->listOutputFloat = (gcnew System::Windows::Forms::ListView());
			this->IndexHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->StatusHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->TypeHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->DateHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartTimeHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->EndTimeHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->FloatTaskLabel = (gcnew System::Windows::Forms::Label());
			this->DeadlineTaskLabel = (gcnew System::Windows::Forms::Label());
			this->TimedTaskLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// enterButton
			// 
			this->enterButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->enterButton->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->enterButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->enterButton->Location = System::Drawing::Point(565, 453);
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
			this->inputBox->Location = System::Drawing::Point(0, 453);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(550, 24);
			this->inputBox->TabIndex = 1;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::inputBox_TextChanged);
			// 
			// feedbackBox
			// 
			this->feedbackBox->BackColor = System::Drawing::SystemColors::Info;
			this->feedbackBox->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackBox->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->feedbackBox->Location = System::Drawing::Point(0, 414);
			this->feedbackBox->Multiline = true;
			this->feedbackBox->Name = L"feedbackBox";
			this->feedbackBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->feedbackBox->Size = System::Drawing::Size(319, 27);
			this->feedbackBox->TabIndex = 2;
			this->feedbackBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->feedbackBox->UseWaitCursor = true;
			this->feedbackBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::feedbackBox_TextChanged);
			// 
			// listOutputTimed
			// 
			this->listOutputTimed->AllowColumnReorder = true;
			this->listOutputTimed->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->listOutputTimed->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listOutputTimed->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->IndexHeaderT, 
				this->StatusHeaderT, this->TypeHeaderT, this->TaskHeaderT, this->DateHeaderT, this->StartTimeHeaderT, this->EndTimeHeaderT});
			this->listOutputTimed->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listOutputTimed->ForeColor = System::Drawing::SystemColors::WindowText;
			this->listOutputTimed->FullRowSelect = true;
			this->listOutputTimed->GridLines = true;
			this->listOutputTimed->Location = System::Drawing::Point(0, 158);
			this->listOutputTimed->Name = L"listOutputTimed";
			this->listOutputTimed->Size = System::Drawing::Size(652, 104);
			this->listOutputTimed->TabIndex = 3;
			this->listOutputTimed->UseCompatibleStateImageBehavior = false;
			this->listOutputTimed->View = System::Windows::Forms::View::Details;
			this->listOutputTimed->SelectedIndexChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::listView1_SelectedIndexChanged);
			// 
			// IndexHeaderT
			// 
			this->IndexHeaderT->Text = L"Index";
			this->IndexHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->IndexHeaderT->Width = 50;
			// 
			// StatusHeaderT
			// 
			this->StatusHeaderT->Text = L"Status";
			this->StatusHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StatusHeaderT->Width = 50;
			// 
			// TypeHeaderT
			// 
			this->TypeHeaderT->Text = L"Type";
			this->TypeHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TypeHeaderT->Width = 80;
			// 
			// TaskHeaderT
			// 
			this->TaskHeaderT->Text = L"Task";
			this->TaskHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TaskHeaderT->Width = 229;
			// 
			// DateHeaderT
			// 
			this->DateHeaderT->Text = L"Date";
			this->DateHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->DateHeaderT->Width = 80;
			// 
			// StartTimeHeaderT
			// 
			this->StartTimeHeaderT->Text = L"Start at";
			this->StartTimeHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StartTimeHeaderT->Width = 82;
			// 
			// EndTimeHeaderT
			// 
			this->EndTimeHeaderT->Text = L"End at";
			this->EndTimeHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->EndTimeHeaderT->Width = 80;
			// 
			// feedbackLabel
			// 
			this->feedbackLabel->AutoSize = true;
			this->feedbackLabel->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->feedbackLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->feedbackLabel->Location = System::Drawing::Point(-3, 395);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(65, 16);
			this->feedbackLabel->TabIndex = 4;
			this->feedbackLabel->Text = L"Feedback";
			this->feedbackLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// previousCommandBox
			// 
			this->previousCommandBox->BackColor = System::Drawing::SystemColors::Info;
			this->previousCommandBox->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->previousCommandBox->Location = System::Drawing::Point(334, 414);
			this->previousCommandBox->Multiline = true;
			this->previousCommandBox->Name = L"previousCommandBox";
			this->previousCommandBox->Size = System::Drawing::Size(318, 26);
			this->previousCommandBox->TabIndex = 5;
			this->previousCommandBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// previousCommandLabel
			// 
			this->previousCommandLabel->AutoSize = true;
			this->previousCommandLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->previousCommandLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->previousCommandLabel->Location = System::Drawing::Point(331, 396);
			this->previousCommandLabel->Name = L"previousCommandLabel";
			this->previousCommandLabel->Size = System::Drawing::Size(118, 16);
			this->previousCommandLabel->TabIndex = 6;
			this->previousCommandLabel->Text = L"Previous command";
			this->previousCommandLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// listOutputDeadline
			// 
			this->listOutputDeadline->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->IndexHeaderD, 
				this->StatusHeaderD, this->TypeHeaderD, this->TaskHeaderD, this->DateHeaderD, this->StartTimeHeaderD, this->DueTimeHeaderD});
			this->listOutputDeadline->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listOutputDeadline->GridLines = true;
			this->listOutputDeadline->Location = System::Drawing::Point(0, 28);
			this->listOutputDeadline->Name = L"listOutputDeadline";
			this->listOutputDeadline->Size = System::Drawing::Size(652, 109);
			this->listOutputDeadline->TabIndex = 7;
			this->listOutputDeadline->UseCompatibleStateImageBehavior = false;
			this->listOutputDeadline->View = System::Windows::Forms::View::Details;
			// 
			// IndexHeaderD
			// 
			this->IndexHeaderD->Text = L"Index";
			this->IndexHeaderD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->IndexHeaderD->Width = 50;
			// 
			// StatusHeaderD
			// 
			this->StatusHeaderD->Text = L"Status";
			this->StatusHeaderD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StatusHeaderD->Width = 51;
			// 
			// TypeHeaderD
			// 
			this->TypeHeaderD->Text = L"Type";
			this->TypeHeaderD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TypeHeaderD->Width = 78;
			// 
			// TaskHeaderD
			// 
			this->TaskHeaderD->Text = L"Task";
			this->TaskHeaderD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TaskHeaderD->Width = 230;
			// 
			// DateHeaderD
			// 
			this->DateHeaderD->Text = L"Due Date";
			this->DateHeaderD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->DateHeaderD->Width = 80;
			// 
			// StartTimeHeaderD
			// 
			this->StartTimeHeaderD->Text = L"Start at";
			this->StartTimeHeaderD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StartTimeHeaderD->Width = 82;
			// 
			// DueTimeHeaderD
			// 
			this->DueTimeHeaderD->Text = L"Due at";
			this->DueTimeHeaderD->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->DueTimeHeaderD->Width = 77;
			// 
			// listOutputFloat
			// 
			this->listOutputFloat->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->IndexHeaderF, 
				this->StatusHeaderF, this->TypeHeaderF, this->TaskHeaderF, this->DateHeaderF, this->StartTimeHeaderF, this->EndTimeHeaderF});
			this->listOutputFloat->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listOutputFloat->GridLines = true;
			this->listOutputFloat->Location = System::Drawing::Point(0, 282);
			this->listOutputFloat->Name = L"listOutputFloat";
			this->listOutputFloat->Size = System::Drawing::Size(652, 110);
			this->listOutputFloat->TabIndex = 8;
			this->listOutputFloat->UseCompatibleStateImageBehavior = false;
			this->listOutputFloat->View = System::Windows::Forms::View::Details;
			// 
			// IndexHeaderF
			// 
			this->IndexHeaderF->Text = L"Index";
			this->IndexHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->IndexHeaderF->Width = 50;
			// 
			// StatusHeaderF
			// 
			this->StatusHeaderF->Text = L"Status";
			this->StatusHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StatusHeaderF->Width = 51;
			// 
			// TypeHeaderF
			// 
			this->TypeHeaderF->Text = L"Type";
			this->TypeHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TypeHeaderF->Width = 79;
			// 
			// TaskHeaderF
			// 
			this->TaskHeaderF->Text = L"Task";
			this->TaskHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TaskHeaderF->Width = 230;
			// 
			// DateHeaderF
			// 
			this->DateHeaderF->Text = L"Date";
			this->DateHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->DateHeaderF->Width = 80;
			// 
			// StartTimeHeaderF
			// 
			this->StartTimeHeaderF->Text = L"Start at";
			this->StartTimeHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StartTimeHeaderF->Width = 84;
			// 
			// EndTimeHeaderF
			// 
			this->EndTimeHeaderF->Text = L"End at";
			this->EndTimeHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->EndTimeHeaderF->Width = 74;
			// 
			// FloatTaskLabel
			// 
			this->FloatTaskLabel->AutoSize = true;
			this->FloatTaskLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FloatTaskLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->FloatTaskLabel->Location = System::Drawing::Point(-3, 265);
			this->FloatTaskLabel->Name = L"FloatTaskLabel";
			this->FloatTaskLabel->Size = System::Drawing::Size(92, 16);
			this->FloatTaskLabel->TabIndex = 9;
			this->FloatTaskLabel->Text = L"Floating Tasks";
			// 
			// DeadlineTaskLabel
			// 
			this->DeadlineTaskLabel->AutoSize = true;
			this->DeadlineTaskLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->DeadlineTaskLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->DeadlineTaskLabel->Location = System::Drawing::Point(-3, 12);
			this->DeadlineTaskLabel->Name = L"DeadlineTaskLabel";
			this->DeadlineTaskLabel->Size = System::Drawing::Size(96, 16);
			this->DeadlineTaskLabel->TabIndex = 10;
			this->DeadlineTaskLabel->Text = L"Deadline Tasks";
			// 
			// TimedTaskLabel
			// 
			this->TimedTaskLabel->AutoSize = true;
			this->TimedTaskLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TimedTaskLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->TimedTaskLabel->Location = System::Drawing::Point(-3, 140);
			this->TimedTaskLabel->Name = L"TimedTaskLabel";
			this->TimedTaskLabel->Size = System::Drawing::Size(81, 16);
			this->TimedTaskLabel->TabIndex = 11;
			this->TimedTaskLabel->Text = L"Timed Tasks";
			// 
			// EasyScheduleGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(664, 485);
			this->Controls->Add(this->TimedTaskLabel);
			this->Controls->Add(this->DeadlineTaskLabel);
			this->Controls->Add(this->FloatTaskLabel);
			this->Controls->Add(this->listOutputFloat);
			this->Controls->Add(this->listOutputDeadline);
			this->Controls->Add(this->previousCommandLabel);
			this->Controls->Add(this->previousCommandBox);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->listOutputTimed);
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
				
				//show today's agenda and upcoming deadlines
				string allFeedbackTasks = EasyScheduleLogic::autoDisplay();
				//temporary: display in dealine listView box
				decomposeTaskString(listOutputDeadline, allFeedbackTasks, 0); 

				this->feedbackBox->Text = "Hello Jim. Welcome to EasySchedule!\r\nPlease enter the file name to open: ";
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
				
				String^ stringUserInput = this->inputBox->Text;
				this->inputBox->Clear();

				//convert from System::String to std::string and pass to logic
				msclr::interop::marshal_context context;
				string userInput = context.marshal_as<std::string>(stringUserInput);
				EasyScheduleLogic::executeLogic(userInput);

				string feedbackMessage = EasyScheduleLogic::tellUIReturnMessage();
				string allFeedbackTasks = EasyScheduleLogic::tellUIDisplay();
				int feedbackIndex = EasyScheduleLogic::tellUIReturnIndex();

				String^ stringFeedbackMessage = gcnew String(feedbackMessage.c_str());
			//	String^ stringFeedbackTasks = gcnew String(allFeedbackTasks.c_str());
				this->feedbackBox->Text = stringFeedbackMessage;
				if(userInput != "exit") {
					this->previousCommandBox->Text = stringUserInput;
				}

				/* //separate three types of tasks in three listView boxes
				string feedbackTasksDeadline, feedbackTasksTimed, feedbackTasksFloat;
				int feedbackIndexDeadline, feedbackIndexTimed, feedbackIndexFloat;
				

				decomposeTaskString(listOutputDeadline, feedbackTasksDeadline, feedbackIndexDeadline);
				decomposeTaskString(listOutputTimed, feedbackTasksTimed, feedbackIndexTimed);
				decomposeTaskString(listOutputFloat, feedbackTasksFloat, feedbackIndexFloat);
				*/

				//temporary: display everything in deadline listView box
				decomposeTaskString(listOutputDeadline, allFeedbackTasks, feedbackIndex);

		 }

	private: System::Void inputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void feedbackBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

	private: void decomposeTaskString(ListView^ listOutput, string feedbackTasks, int feedbackIndex) {
				//clear the previous input and output for future uses.
				listOutput->Items->Clear();
				string componentInfo;
				String^ stringComponentInfo;
				size_t tempStart;
				size_t tempEnd=-1;
				bool isMultilineNeeded = false;

				//why algorithm count() doesn't work
				int count = 0;
				for(int i=0; i<int(feedbackTasks.size());i++) {
					if (feedbackTasks.at(i) == ']') {
						count++;
					}
				}

				while(count > 0) {

					feedbackIndex--;

					/****Index****/
					tempStart = tempEnd+1;
					tempEnd = feedbackTasks.find_first_of("]", tempStart);
					componentInfo = feedbackTasks.substr(tempStart, tempEnd-tempStart);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems = gcnew Windows::Forms::ListViewItem(stringComponentInfo);

					/****Mark****/
					tempStart = tempEnd+1;
					tempEnd = feedbackTasks.find_first_of("]", tempStart);
					componentInfo = feedbackTasks.substr(tempStart, tempEnd-tempStart);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Task type****/
					tempStart = tempEnd+1;
					tempEnd = feedbackTasks.find_first_of("]", tempStart);
					componentInfo = feedbackTasks.substr(tempStart, tempEnd-tempStart);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Task name****/
					tempStart = tempEnd+1;
					tempEnd = feedbackTasks.find_first_of("]", tempStart);
					componentInfo = feedbackTasks.substr(tempStart, tempEnd-tempStart);
					isMultilineNeeded = determineMultilineNeeded(componentInfo);
					string remainingLongTask;
					if(isMultilineNeeded) {
						int remainingStartingPos = (TaskHeaderD/*temporary*/->Width / widthToCharacterDisplayRatio);
						string firstPiece = componentInfo.substr(0, remainingStartingPos);
						remainingLongTask = componentInfo.substr(remainingStartingPos);
						stringComponentInfo = gcnew String(firstPiece.c_str());
					} else {
						stringComponentInfo = gcnew String(componentInfo.c_str());
					}
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Date****/
					tempStart = tempEnd+1;
					tempEnd = feedbackTasks.find_first_of("]", tempStart);
					componentInfo = feedbackTasks.substr(tempStart, tempEnd-tempStart);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Start time****/
					tempStart = tempEnd+1;
					tempEnd = feedbackTasks.find_first_of("]", tempStart);
					componentInfo = feedbackTasks.substr(tempStart, tempEnd-tempStart);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****End time****/
					tempStart = tempEnd+1;
					tempEnd = feedbackTasks.find_first_of("]", tempStart);
					componentInfo = feedbackTasks.substr(tempStart, tempEnd-tempStart);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Long Task****/ //Bug: doesn't display now
					if(isMultilineNeeded) {
						displayMultilineTask(remainingLongTask);
					}

					//listViewItems change colour
				//	this->inputBox->Text = System::Convert::ToString(feedbackIndex);
					if(feedbackIndex == 0) {
						listViewItems->ForeColor = System::Drawing::SystemColors::HotTrack;
					}
					listOutput->Items->Add(this->listViewItems);
					count -= 7; //each task has seven dividers "]"
				}
		 }
	private: bool determineMultilineNeeded(string taskInfo) {
				 String^ stringTaskInfo = gcnew String(taskInfo.c_str());
				 if( stringTaskInfo->Length > TaskHeaderD/*temporary*/->Width / widthToCharacterDisplayRatio ) {
					 return true;
				 }
				 return false;
		 }
	private: void displayMultilineTask(string remainingPieces) {
				 String^ stringRemainingPieces = gcnew String(remainingPieces.c_str()); 
				 int lineLength = TaskHeaderD/*temporary*/->Width / widthToCharacterDisplayRatio;
				 int numberOfExtraLines = stringRemainingPieces->Length / lineLength;
				 int startingPos = 0;
				 
				 for(int i=0; i<numberOfExtraLines; i++) {
					 String^ stringEachLine = stringRemainingPieces->Substring(startingPos, lineLength);
					 listViewItems->SubItems->Add(""); //empty index
					 listViewItems->SubItems->Add(""); //empty mark
					 listViewItems->SubItems->Add(""); //empty task typw
					 listViewItems->SubItems->Add(stringEachLine);
					 listViewItems->SubItems->Add(""); //empty date
					 listViewItems->SubItems->Add(""); //empty start time
					 listViewItems->SubItems->Add(""); //empty end time
					 startingPos = startingPos + lineLength;
				 }
		 }
};
}
