#pragma once
#include "EasyScheduleLogic.h"
#include <string>
//#include <cliext/vector>
#include <msclr\marshal_cppstd.h>
#using <mscorlib.dll>
#include <ctype.h>

//change to exception: because it is user's fault.

namespace UI {

	using namespace System;
	using namespace std;
//	using namespace cliext;
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
		EasyScheduleGUI(void) {
			InitializeComponent();
			void displayTaskString(string feedbackTasks, int feedbackIndex);
			void displayInitial(string feedbackTasks);
			void decomposeInitial(string feedbackTasks);
			void decomposeTaskString(string feedbackTasks, int feedbackIndex);
			void changeDoneTaskColor(bool isDone);
			bool determineMultilineNeeded(string taskInfo);
			void displayMultilineTaskString(ListView^  listOutput, string remainingPieces, int feedbackIndex, bool isDone);
			void changeEditedRowColor(int feedbackIndex);
			void iterateTaskComponentInfo(string feedbackTasks, size_t start, size_t end, string componentInfo);
			void skipRow(string feedbackTasks, size_t start, size_t end, int NumberOfIter);
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
	private: System::Windows::Forms::ListView^  listOutputMain;
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
	private: System::Windows::Forms::ListView^  listOutputFloat;
	private: System::Windows::Forms::ColumnHeader^  IndexHeaderF;
	private: System::Windows::Forms::ColumnHeader^  StatusHeaderF;
	private: System::Windows::Forms::ColumnHeader^  TypeHeaderF;
	private: System::Windows::Forms::ColumnHeader^  TaskHeaderF;
	private: System::Windows::Forms::Label^  FloatTaskLabel;
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
			this->listOutputMain = (gcnew System::Windows::Forms::ListView());
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
			this->listOutputFloat = (gcnew System::Windows::Forms::ListView());
			this->IndexHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->StatusHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->TypeHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->FloatTaskLabel = (gcnew System::Windows::Forms::Label());
			this->TimedTaskLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// enterButton
			// 
			this->enterButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->enterButton->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->enterButton->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->enterButton->Location = System::Drawing::Point(591, 456);
			this->enterButton->Name = L"enterButton";
			this->enterButton->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->enterButton->Size = System::Drawing::Size(81, 25);
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
			this->inputBox->Location = System::Drawing::Point(6, 456);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(579, 24);
			this->inputBox->TabIndex = 1;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::inputBox_TextChanged);
			// 
			// feedbackBox
			// 
			this->feedbackBox->BackColor = System::Drawing::SystemColors::Info;
			this->feedbackBox->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackBox->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->feedbackBox->Location = System::Drawing::Point(390, 340);
			this->feedbackBox->Multiline = true;
			this->feedbackBox->Name = L"feedbackBox";
			this->feedbackBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->feedbackBox->Size = System::Drawing::Size(282, 36);
			this->feedbackBox->TabIndex = 2;
			this->feedbackBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->feedbackBox->UseWaitCursor = true;
			this->feedbackBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::feedbackBox_TextChanged);
			// 
			// listOutputMain
			// 
			this->listOutputMain->AllowColumnReorder = true;
			this->listOutputMain->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->listOutputMain->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listOutputMain->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->IndexHeaderT, 
				this->StatusHeaderT, this->TypeHeaderT, this->TaskHeaderT, this->DateHeaderT, this->StartTimeHeaderT, this->EndTimeHeaderT});
			this->listOutputMain->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listOutputMain->ForeColor = System::Drawing::SystemColors::WindowText;
			this->listOutputMain->FullRowSelect = true;
			this->listOutputMain->GridLines = true;
			this->listOutputMain->Location = System::Drawing::Point(6, 28);
			this->listOutputMain->Name = L"listOutputMain";
			this->listOutputMain->Size = System::Drawing::Size(666, 263);
			this->listOutputMain->TabIndex = 3;
			this->listOutputMain->UseCompatibleStateImageBehavior = false;
			this->listOutputMain->View = System::Windows::Forms::View::Details;
			// 
			// IndexHeaderT
			// 
			this->IndexHeaderT->Text = L"Index";
			this->IndexHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->IndexHeaderT->Width = 43;
			// 
			// StatusHeaderT
			// 
			this->StatusHeaderT->Text = L"Status";
			this->StatusHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StatusHeaderT->Width = 78;
			// 
			// TypeHeaderT
			// 
			this->TypeHeaderT->Text = L"Type";
			this->TypeHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TypeHeaderT->Width = 73;
			// 
			// TaskHeaderT
			// 
			this->TaskHeaderT->Text = L"Task";
			this->TaskHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TaskHeaderT->Width = 230;
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
			this->feedbackLabel->Location = System::Drawing::Point(387, 321);
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
			this->previousCommandBox->Location = System::Drawing::Point(390, 409);
			this->previousCommandBox->Multiline = true;
			this->previousCommandBox->Name = L"previousCommandBox";
			this->previousCommandBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->previousCommandBox->Size = System::Drawing::Size(282, 36);
			this->previousCommandBox->TabIndex = 5;
			this->previousCommandBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// previousCommandLabel
			// 
			this->previousCommandLabel->AutoSize = true;
			this->previousCommandLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->previousCommandLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->previousCommandLabel->Location = System::Drawing::Point(387, 390);
			this->previousCommandLabel->Name = L"previousCommandLabel";
			this->previousCommandLabel->Size = System::Drawing::Size(118, 16);
			this->previousCommandLabel->TabIndex = 6;
			this->previousCommandLabel->Text = L"Previous command";
			this->previousCommandLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// listOutputFloat
			// 
			this->listOutputFloat->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->IndexHeaderF, 
				this->StatusHeaderF, this->TypeHeaderF, this->TaskHeaderF});
			this->listOutputFloat->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listOutputFloat->GridLines = true;
			this->listOutputFloat->Location = System::Drawing::Point(6, 321);
			this->listOutputFloat->Name = L"listOutputFloat";
			this->listOutputFloat->Size = System::Drawing::Size(378, 124);
			this->listOutputFloat->TabIndex = 8;
			this->listOutputFloat->UseCompatibleStateImageBehavior = false;
			this->listOutputFloat->View = System::Windows::Forms::View::Details;
			// 
			// IndexHeaderF
			// 
			this->IndexHeaderF->Text = L"Index";
			this->IndexHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->IndexHeaderF->Width = 43;
			// 
			// StatusHeaderF
			// 
			this->StatusHeaderF->Text = L"Status";
			this->StatusHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->StatusHeaderF->Width = 78;
			// 
			// TypeHeaderF
			// 
			this->TypeHeaderF->Text = L"Type";
			this->TypeHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TypeHeaderF->Width = 73;
			// 
			// TaskHeaderF
			// 
			this->TaskHeaderF->Text = L"Task";
			this->TaskHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TaskHeaderF->Width = 180;
			// 
			// FloatTaskLabel
			// 
			this->FloatTaskLabel->AutoSize = true;
			this->FloatTaskLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FloatTaskLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->FloatTaskLabel->Location = System::Drawing::Point(3, 302);
			this->FloatTaskLabel->Name = L"FloatTaskLabel";
			this->FloatTaskLabel->Size = System::Drawing::Size(92, 16);
			this->FloatTaskLabel->TabIndex = 9;
			this->FloatTaskLabel->Text = L"Floating Tasks";
			// 
			// TimedTaskLabel
			// 
			this->TimedTaskLabel->AutoSize = true;
			this->TimedTaskLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TimedTaskLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->TimedTaskLabel->Location = System::Drawing::Point(3, 9);
			this->TimedTaskLabel->Name = L"TimedTaskLabel";
			this->TimedTaskLabel->Size = System::Drawing::Size(89, 16);
			this->TimedTaskLabel->TabIndex = 11;
			this->TimedTaskLabel->Text = L"Tasks by date";
			this->TimedTaskLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// EasyScheduleGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(680, 490);
			this->Controls->Add(this->TimedTaskLabel);
			this->Controls->Add(this->FloatTaskLabel);
			this->Controls->Add(this->listOutputFloat);
			this->Controls->Add(this->previousCommandLabel);
			this->Controls->Add(this->previousCommandBox);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->listOutputMain);
			this->Controls->Add(this->feedbackBox);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->enterButton);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"EasyScheduleGUI";
			this->Text = L"Welcome to EasySchedule!";
			this->Load += gcnew System::EventHandler(this, &EasyScheduleGUI::EasyScheduleGUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	//When users loads (opens) the programme
	private: System::Void EasyScheduleGUI_Load(System::Object^  sender, System::EventArgs^  e) {
				/*string allFeedbackTasks = EasyScheduleLogic::autoDisplay();
				displayInitial(allFeedbackTasks); */
				this->feedbackBox->Text = 
					"Hello Jim. Welcome to EasySchedule!\r\nPlease enter the filepath or filename: ";
		}

	//User press "Enter" key after typing to replace clicking "Enter" button
	//Debug: Now it doesn't work. Why???
	private: System::Void inputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				if(e->KeyCode == Keys::Enter) {
					enterButton->PerformClick();
				}
		}

	//Actions happen after user clicks the "Enter" button 
	private: System::Void enterButton_Click(System::Object^  sender, System::EventArgs^  e) {
				
				String^ stringUserInput = this->inputBox->Text;
				this->inputBox->Clear();
				/****convert from System::String to std::string and pass to logic****/
				msclr::interop::marshal_context context;
				string userInput = context.marshal_as<std::string>(stringUserInput);

				/****Execute user's input****/
				EasyScheduleLogic::executeLogic(userInput);
				string feedbackMessage = EasyScheduleLogic::tellUIReturnMessage();
				string allFeedbackTasks = EasyScheduleLogic::tellUIDisplay();
				int feedbackIndex = EasyScheduleLogic::tellUIReturnIndex();
				
				/****Return feedbacks to user****/
				String^ stringFeedbackMessage = gcnew String(feedbackMessage.c_str());
				this->previousCommandBox->Text = stringUserInput;
				this->feedbackBox->Text = stringFeedbackMessage;
				/****Initially show today's agenda and upcoming deadlines****/
				transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
				if (userInput.substr(0, 8) == "filename") {
					displayInitial(allFeedbackTasks); 
				} else {
					displayTaskString(allFeedbackTasks, feedbackIndex);
				}
		}

	private: System::Void inputBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		}
	private: System::Void feedbackBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		}

	private: void displayTaskString(string feedbackTasks, int feedbackIndex) {
				//clear the previous input and output for future uses.
				listOutputMain->Items->Clear();
				listOutputFloat->Items->Clear();

				decomposeTaskString(feedbackTasks, feedbackIndex);
		}
	private: void displayInitial(string feedbackTasks) {
				listOutputMain->Items->Clear();
				listOutputFloat->Items->Clear();

				decomposeInitial(feedbackTasks);
		}

	private: void decomposeInitial(string feedbackTasks) {
				
				string componentInfo;
				String^ stringComponentInfo;
				string nextTaskDate;
				size_t start;
				size_t end=-1;
				bool isMultilineNeeded = false;
				int differentDate = 0;

				string emptyToken = " ";
				string MESSAGE_TODAY_AGENDA = "Today's Agenda:";
				String^ stringEmptyToken = gcnew String(emptyToken.c_str());
				String^ STRING_MESSAGE_TODAY_AGENDA = gcnew String(MESSAGE_TODAY_AGENDA.c_str());

				/****Adding a message line before today's agenda****/
				listViewItems = gcnew Windows::Forms::ListViewItem(stringEmptyToken); //empty index
				listViewItems->SubItems->Add(stringEmptyToken); //empty mark
				listViewItems->SubItems->Add(stringEmptyToken); //empty task typw
				listViewItems->SubItems->Add(STRING_MESSAGE_TODAY_AGENDA);
				listViewItems->SubItems->Add(stringEmptyToken); //empty date
				listViewItems->SubItems->Add(stringEmptyToken); //empty start time
				listViewItems->SubItems->Add(stringEmptyToken); //empty end time
				listViewItems->ForeColor = System::Drawing::SystemColors::HotTrack;
				listOutputMain->Items->Add(this->listViewItems);

				int count = 0;
				for(int i=0; i<int(feedbackTasks.size());i++) {
					if (feedbackTasks.at(i) == ']') {
						count++;
					}
				}

				while(count > 0) {
					
					/****Index****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems = gcnew Windows::Forms::ListViewItem(stringComponentInfo);

					/****Mark****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Task type****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Task name****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					/****Multiline for long task name****/
					isMultilineNeeded = determineMultilineNeeded(componentInfo);
					string remainingLongTask;
					if(isMultilineNeeded) {
						int remainingStartingPos = (TaskHeaderT->Width / widthToCharacterDisplayRatio);
						string firstPiece = componentInfo.substr(0, remainingStartingPos);
						remainingLongTask = componentInfo.substr(remainingStartingPos);
						stringComponentInfo = gcnew String(firstPiece.c_str());
					} else {
						stringComponentInfo = gcnew String(componentInfo.c_str());
					}
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Date****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****check for date of the next task****/
					size_t tempStart = start;
					size_t tempEnd = end;
				//	skipRow(feedbackTasks, tempStart, tempEnd, 7);
					for(int i=0; i<7; i++) {
						tempStart = tempEnd + 1;
						tempEnd = feedbackTasks.find_first_of("]", start);
					}
					nextTaskDate = feedbackTasks.substr(tempStart, tempEnd-tempStart);
					if(componentInfo != nextTaskDate) {
						differentDate++;
					} 

					/****Start time****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****End time****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 
	
					listOutputMain->Items->Add(this->listViewItems);

					/****Check for multiline non-floating task****/
					if(isMultilineNeeded) {
						displayMultilineTaskString(listOutputMain, remainingLongTask, 0, false);
					}

					/****Adding a message line before upcoming deadline tasks****/
					if(differentDate == 1) {

						differentDate++;

						string MESSAGE_UPCOMING_DEADLINES = "Upcoming Deadlines:";
						String^ STRING_MESSAGE_UPCOMING_DEADLINES = gcnew String(MESSAGE_UPCOMING_DEADLINES.c_str());
						
						listViewItems = gcnew Windows::Forms::ListViewItem(stringEmptyToken); //empty index
						listViewItems->SubItems->Add(stringEmptyToken); //empty mark
						listViewItems->SubItems->Add(stringEmptyToken); //empty task typw
						listViewItems->SubItems->Add(STRING_MESSAGE_UPCOMING_DEADLINES);
						listViewItems->SubItems->Add(stringEmptyToken); //empty date
						listViewItems->SubItems->Add(stringEmptyToken); //empty start time
						listViewItems->SubItems->Add(stringEmptyToken); //empty end time
						listViewItems->ForeColor = System::Drawing::SystemColors::HotTrack;
						listOutputMain->Items->Add(this->listViewItems);
					}

					count -= 7; //each task has seven dividers "]"
				}
		}

	private: void decomposeTaskString(string feedbackTasks, int feedbackIndex) {

				string componentInfo;
				String^ stringComponentInfo;
				string taskType; //to distinguish a floating task
				string nextTaskDate;
				size_t start;
				size_t end=-1;
				bool isMultilineNeeded = false;
				bool isDifferentDate = false;
				bool isDone = false;

				int count = 0;
				for(int i=0; i<int(feedbackTasks.size());i++) {
					if (feedbackTasks.at(i) == ']') {
						count++;
					}
				}

				while(count > 0) {

					feedbackIndex--;
					/****Index****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems = gcnew Windows::Forms::ListViewItem(stringComponentInfo);

					/****Mark****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 
					if(componentInfo == "Done") {
						isDone = true;
					}

					/****Task type****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 
					taskType = componentInfo;

					/****Task name****/
					start = end+1;
					end = feedbackTasks.find_first_of("]", start);
					componentInfo = feedbackTasks.substr(start, end-start);
					/****Multiline for long task name****/
					isMultilineNeeded = determineMultilineNeeded(componentInfo);
					string remainingLongTask;
					if(isMultilineNeeded) {
						int remainingStartingPos = (TaskHeaderT->Width / widthToCharacterDisplayRatio);
						string firstPiece = componentInfo.substr(0, remainingStartingPos);
						remainingLongTask = componentInfo.substr(remainingStartingPos);
						stringComponentInfo = gcnew String(firstPiece.c_str());
					} else {
						stringComponentInfo = gcnew String(componentInfo.c_str());
					}
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Adding time info for non floating tasks****/
					if(taskType != "Float") {
						/****Date****/
						start = end+1;
						end = feedbackTasks.find_first_of("]", start);
						componentInfo = feedbackTasks.substr(start, end-start);
						stringComponentInfo = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(stringComponentInfo); 

						/****check for date of the next task****/
						size_t tempStart = start;
						size_t tempEnd = end;
					//	skipRow(feedbackTasks, tempStart, tempEnd, 7);
						for(int i=0; i<7; i++) {
							tempStart = tempEnd + 1;
							tempEnd = feedbackTasks.find_first_of("]", tempStart);
						}
						nextTaskDate = feedbackTasks.substr(tempStart, tempEnd-tempStart);
						if(componentInfo != nextTaskDate) {
							isDifferentDate = true;
						} 

						/****Start time****/
						start = end+1;
						end = feedbackTasks.find_first_of("]", start);
						componentInfo = feedbackTasks.substr(start, end-start);
						stringComponentInfo = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(stringComponentInfo); 

						/****End time****/
						start = end+1;
						end = feedbackTasks.find_first_of("]", start);
						componentInfo = feedbackTasks.substr(start, end-start);
						stringComponentInfo = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(stringComponentInfo); 
					}					

					/****Change colour for done tasks****/
					//changeDoneTaskColor(isDone);
					if(isDone) {
						listViewItems->ForeColor = System::Drawing::SystemColors::GrayText;
						isDone = false;
					}

					/****Change colour for edited row****/
					//changeEditedRowColor(feedbackIndex, listViewItems);
					if(feedbackIndex == 0) {
						listViewItems->BackColor = System::Drawing::SystemColors::Highlight;
						listViewItems->ForeColor = System::Drawing::SystemColors::HighlightText;
					}

					if(taskType == "Float") {
						listOutputFloat->Items->Add(this->listViewItems);
						/****Check for multiline floating task****/
						if(isMultilineNeeded) {
							displayMultilineTaskString(listOutputFloat, remainingLongTask, -1, isDone);
						}
					//	skipRow(feedbackTasks, start, end, 3);
						for(int i=0; i<3; i++) {
							start = end + 1;
							end = feedbackTasks.find_first_of("]", start);
						}
					} else {			
						listOutputMain->Items->Add(this->listViewItems);
						/****Check for multiline non-floating task****/
						if(isMultilineNeeded) {
							displayMultilineTaskString(listOutputMain, remainingLongTask, feedbackIndex, isDone);
						}
						/****Adding a blank line between tasks with different dates****/
						if(isDifferentDate) {
							string emptyToken = " ";
							String^ stringEmptyToken = gcnew String(emptyToken.c_str());
							listViewItems = gcnew Windows::Forms::ListViewItem(stringEmptyToken);
							for(int i=0; i<6; i++) {
								listViewItems->SubItems->Add(stringEmptyToken);
							}
							listOutputMain->Items->Add(this->listViewItems);
							isDifferentDate = false; //for future use
						}
					}

					count -= 7; //each task has seven dividers "]"
				}
		}

	//can't work
	private: void iterateTaskComponentInfo(string feedbackTasks, size_t start, size_t end, string componentInfo) {
				start = end + 1;
				end = feedbackTasks.find_first_of("]", start);
				componentInfo = feedbackTasks.substr(start, end-start);
		}
	//can't work
	private: void changeDoneTaskColor(bool isDone) {
				if(isDone) {
					listViewItems->ForeColor = System::Drawing::SystemColors::GrayText;
					isDone = false;
				}
		}
	//can't work
	private: void changeEditedRowColor(int feedbackIndex) {
				if(feedbackIndex == 0) {
					listViewItems->BackColor = System::Drawing::SystemColors::Highlight;
					listViewItems->ForeColor = System::Drawing::SystemColors::HighlightText;
				}
		}

	private: bool determineMultilineNeeded(string taskInfo) {
				String^ stringTaskInfo = gcnew String(taskInfo.c_str());
				if( stringTaskInfo->Length > TaskHeaderT->Width / widthToCharacterDisplayRatio ) {
					return true;
				}
				return false;
		}

	private: void displayMultilineTaskString(ListView^  listOutput, string remainingPieces, int feedbackIndex, bool isDone) {
				String^ stringRemainingPieces = gcnew String(remainingPieces.c_str()); 
				int lineLength = TaskHeaderT->Width / widthToCharacterDisplayRatio;
				int numberOfExtraLines = stringRemainingPieces->Length / lineLength + 1;
				String^ stringEachLine;
				int startingPos = 0;
				 
				for(int i=0; i<numberOfExtraLines; i++) {
					if(stringRemainingPieces->Length > lineLength) {
						stringEachLine = stringRemainingPieces->Substring(startingPos, lineLength);
						stringRemainingPieces = stringRemainingPieces->Substring(startingPos+lineLength);
					} else {
						stringEachLine = stringRemainingPieces;
					}
					string emptyToken = " ";
					String^ stringEmptyToken = gcnew String(emptyToken.c_str());
					listViewItems = gcnew Windows::Forms::ListViewItem(stringEmptyToken); //empty index
					listViewItems->SubItems->Add(stringEmptyToken); //empty mark
					listViewItems->SubItems->Add(stringEmptyToken); //empty task typw
					listViewItems->SubItems->Add(stringEachLine);
					listViewItems->SubItems->Add(stringEmptyToken); //empty date
					listViewItems->SubItems->Add(stringEmptyToken); //empty start time
					listViewItems->SubItems->Add(stringEmptyToken); //empty end time

					if(isDone) {
						listViewItems->ForeColor = System::Drawing::SystemColors::GrayText;
						isDone = false;
					}
					if(feedbackIndex == 0) {
						listViewItems->BackColor = System::Drawing::SystemColors::Highlight;
						listViewItems->ForeColor = System::Drawing::SystemColors::HighlightText;
					}
					listOutput->Items->Add(this->listViewItems);
			//		startingPos = startingPos + lineLength;
				}
		}

	//can't work. same problem as iterateTaskComponentInfo
	private: void skipRow(string feedbackTasks, size_t start, size_t end, int NumberOfIter) {
				for(int i=0; i<NumberOfIter; i++) {
					start = end + 1;
					end = feedbackTasks.find_first_of("]", start);
				}
		}
};

}
