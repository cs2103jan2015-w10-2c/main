#pragma once
#include "EasyScheduleLogic.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#using <mscorlib.dll>
#include <ctype.h>

//add exception: because it is user's fault.

//@author A0116707H
namespace UI {

	using namespace System;
	using namespace std;
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
		
	public:
		EasyScheduleGUI(void) {
			InitializeComponent();
			void displayInitial(string feedbackTasks);
			void displayTaskString(string feedbackTasks, int feedbackIndex);
			void decomposeInitial(string feedbackTasks);
			void decomposeTaskString(string feedbackTasks, int feedbackIndex);		
			void displayMultilineTaskString(ListView^  listOutput, string remainingPieces, int feedbackIndex, bool isDone);
			bool determineMultilineNeeded(string taskInfo);
			void identifyFirstPiece(bool isMultilineNeeded, string& remainingLongTask, string componentInfo, string& firstPiece);
			void separateFirstPiece(string& remainingLongTask, string componentInfo, string& firstPiece);
			void checkNextDateInitial(int& differentDate, size_t start, size_t end, string feedbackTasks, string componentInfo);
			void checkNextDate(bool& isDifferentDate, size_t start, size_t end, string feedbackTasks, string componentInfo);
			void changeDoneTaskColor(bool& isDone);
			void changeEditedLineColor(int& feedbackIndex);
			void iterateTaskComponentInfo(string& feedbackTasks, size_t& start, size_t& end, string& componentInfo);
			void skipLine(string& feedbackTasks, size_t& start, size_t& end, int NumberOfIter);
			void countDivider(int& count, string& feedbackTasks);
			void addBlankLine(bool& isDifferentDate);
			void addMessageLine(string message, ListView^ listOutput, string typeLocation, bool& isDone, int& feedbackIndex);
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
	private: System::Windows::Forms::ColumnHeader^  statusHeaderT;

	private: System::Windows::Forms::ColumnHeader^  indexHeaderT;
	private: System::Windows::Forms::ColumnHeader^  taskHeaderT;
	private: System::Windows::Forms::ColumnHeader^  dateHeaderT;
	private: System::Windows::Forms::ColumnHeader^  startTimeHeaderT;
	private: System::Windows::Forms::ColumnHeader^  endTimeHeaderT;





	private: System::Windows::Forms::ColumnHeader^  typeHeaderT;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  feedbackLabel;
	private: System::Windows::Forms::TextBox^  previousCommandBox;
	private: System::Windows::Forms::Label^  previousCommandLabel;
	private: System::Windows::Forms::ListView^  listOutputFloat;
	private: System::Windows::Forms::ColumnHeader^  indexHeaderF;
	private: System::Windows::Forms::ColumnHeader^  statusHeaderF;
	private: System::Windows::Forms::ColumnHeader^  typeHeaderF;
	private: System::Windows::Forms::ColumnHeader^  taskHeaderF;




	private: System::Windows::Forms::Label^  floatTaskLabel;
	private: System::Windows::Forms::Label^  timedTaskLabel;


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
			this->indexHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->statusHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->typeHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->taskHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->dateHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->startTimeHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->endTimeHeaderT = (gcnew System::Windows::Forms::ColumnHeader());
			this->feedbackLabel = (gcnew System::Windows::Forms::Label());
			this->previousCommandBox = (gcnew System::Windows::Forms::TextBox());
			this->previousCommandLabel = (gcnew System::Windows::Forms::Label());
			this->listOutputFloat = (gcnew System::Windows::Forms::ListView());
			this->indexHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->statusHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->typeHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->taskHeaderF = (gcnew System::Windows::Forms::ColumnHeader());
			this->floatTaskLabel = (gcnew System::Windows::Forms::Label());
			this->timedTaskLabel = (gcnew System::Windows::Forms::Label());
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
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(579, 25);
			this->inputBox->TabIndex = 1;
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &EasyScheduleGUI::inputBox_TextChanged);
			this->inputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &EasyScheduleGUI::inputBox_KeyDown);
			// 
			// feedbackBox
			// 
			this->feedbackBox->BackColor = System::Drawing::SystemColors::Info;
			this->feedbackBox->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackBox->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->feedbackBox->Location = System::Drawing::Point(393, 409);
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
			this->listOutputMain->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {this->indexHeaderT, 
				this->statusHeaderT, this->typeHeaderT, this->taskHeaderT, this->dateHeaderT, this->startTimeHeaderT, this->endTimeHeaderT});
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
			// indexHeaderT
			// 
			this->indexHeaderT->Text = L"Index";
			this->indexHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->indexHeaderT->Width = 43;
			// 
			// statusHeaderT
			// 
			this->statusHeaderT->Text = L"Status";
			this->statusHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->statusHeaderT->Width = 78;
			// 
			// typeHeaderT
			// 
			this->typeHeaderT->Text = L"Type";
			this->typeHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->typeHeaderT->Width = 73;
			// 
			// taskHeaderT
			// 
			this->taskHeaderT->Text = L"Task";
			this->taskHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->taskHeaderT->Width = 230;
			// 
			// dateHeaderT
			// 
			this->dateHeaderT->Text = L"Date";
			this->dateHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->dateHeaderT->Width = 80;
			// 
			// startTimeHeaderT
			// 
			this->startTimeHeaderT->Text = L"Start at";
			this->startTimeHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->startTimeHeaderT->Width = 82;
			// 
			// endTimeHeaderT
			// 
			this->endTimeHeaderT->Text = L"End at";
			this->endTimeHeaderT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->endTimeHeaderT->Width = 80;
			// 
			// feedbackLabel
			// 
			this->feedbackLabel->AutoSize = true;
			this->feedbackLabel->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->feedbackLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->feedbackLabel->Location = System::Drawing::Point(390, 390);
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
			this->previousCommandBox->Location = System::Drawing::Point(393, 340);
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
			this->previousCommandLabel->Location = System::Drawing::Point(390, 321);
			this->previousCommandLabel->Name = L"previousCommandLabel";
			this->previousCommandLabel->Size = System::Drawing::Size(118, 16);
			this->previousCommandLabel->TabIndex = 6;
			this->previousCommandLabel->Text = L"Previous command";
			this->previousCommandLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// listOutputFloat
			// 
			this->listOutputFloat->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->indexHeaderF, 
				this->statusHeaderF, this->typeHeaderF, this->taskHeaderF});
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
			// indexHeaderF
			// 
			this->indexHeaderF->Text = L"Index";
			this->indexHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->indexHeaderF->Width = 43;
			// 
			// statusHeaderF
			// 
			this->statusHeaderF->Text = L"Status";
			this->statusHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->statusHeaderF->Width = 78;
			// 
			// typeHeaderF
			// 
			this->typeHeaderF->Text = L"Type";
			this->typeHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->typeHeaderF->Width = 73;
			// 
			// taskHeaderF
			// 
			this->taskHeaderF->Text = L"Task";
			this->taskHeaderF->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->taskHeaderF->Width = 180;
			// 
			// floatTaskLabel
			// 
			this->floatTaskLabel->AutoSize = true;
			this->floatTaskLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->floatTaskLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->floatTaskLabel->Location = System::Drawing::Point(3, 302);
			this->floatTaskLabel->Name = L"floatTaskLabel";
			this->floatTaskLabel->Size = System::Drawing::Size(92, 16);
			this->floatTaskLabel->TabIndex = 9;
			this->floatTaskLabel->Text = L"Floating Tasks";
			// 
			// timedTaskLabel
			// 
			this->timedTaskLabel->AutoSize = true;
			this->timedTaskLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->timedTaskLabel->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->timedTaskLabel->Location = System::Drawing::Point(3, 9);
			this->timedTaskLabel->Name = L"timedTaskLabel";
			this->timedTaskLabel->Size = System::Drawing::Size(89, 16);
			this->timedTaskLabel->TabIndex = 11;
			this->timedTaskLabel->Text = L"Tasks by date";
			this->timedTaskLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// EasyScheduleGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(680, 490);
			this->Controls->Add(this->timedTaskLabel);
			this->Controls->Add(this->floatTaskLabel);
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
					"Hello Jim. Welcome to EasySchedule!\r\nPlease enter the filepath or filename";
		}

	//User press "Enter" key after typing to replace clicking "Enter" button
	private: System::Void inputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				
				if(e->KeyCode == Keys::Enter) {
					enterButton->PerformClick();
					this->inputBox->Clear();
				}
		}

	//Actions happen after user clicks the "Enter" button 
	private: System::Void enterButton_Click(System::Object^  sender, System::EventArgs^  e) {
				
				String^ stringUserInput = this->inputBox->Text;
				this->inputBox->Clear();
				/****convert from System::String to std::string****/
				msclr::interop::marshal_context context;
				string userInput = context.marshal_as<std::string>(stringUserInput);

				/****Execute user's input in logic****/
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

	private: void displayInitial(string feedbackTasks) {
				//clear the previous output for future uses.
				listOutputMain->Items->Clear();
				listOutputFloat->Items->Clear();

				decomposeInitial(feedbackTasks);
		}

	private: void displayTaskString(string feedbackTasks, int feedbackIndex) {
				//clear the previous output for future uses.
				listOutputMain->Items->Clear();
				listOutputFloat->Items->Clear();

				decomposeTaskString(feedbackTasks, feedbackIndex);
		}

	private: void decomposeInitial(string feedbackTasks) {
				
				string MESSAGE_TODAY_AGENDA = "Today's Agenda:";
				string MESSAGE_UPCOMING_DEADLINES = "Upcoming Deadlines:";
				string componentInfo;
				String^ stringComponentInfo;
				string nextTaskDate;
				string remainingLongTask;
				string firstPiece;
				size_t start;
				size_t end=-1;
				int differentDate = 0;
				bool isMultilineNeeded = false;

				/****Adding a message line before today's agenda****/
				string typeLocation = "Message";
				bool tempIsDone = false;
				int tempFeedbackIndex = 0;
				addMessageLine(MESSAGE_TODAY_AGENDA, listOutputMain, typeLocation, tempIsDone, tempFeedbackIndex);

				int count = 0;
				countDivider(count, feedbackTasks);

				while(count > 0) {
					
					/****Index****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems = gcnew System::Windows::Forms::ListViewItem(stringComponentInfo);

					/****Mark****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Task type****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Task name****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					/****Multiline for long task name****/
					isMultilineNeeded = determineMultilineNeeded(componentInfo);
					identifyFirstPiece(isMultilineNeeded, remainingLongTask, componentInfo, firstPiece);
					stringComponentInfo = gcnew String(firstPiece.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Date****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****check for date of the next task****/
					checkNextDateInitial(differentDate, start, end, feedbackTasks, componentInfo); 

					/****Start time****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****End time****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 
	
					listOutputMain->Items->Add(this->listViewItems);

					/****Check for multiline non-floating task****/
					if(isMultilineNeeded) {
						displayMultilineTaskString(listOutputMain, remainingLongTask, 0, false);
					}

					/****Adding a message line before upcoming deadline tasks****/
					if(differentDate == 1) {
						addMessageLine(MESSAGE_UPCOMING_DEADLINES, listOutputMain, typeLocation, tempIsDone, tempFeedbackIndex);
						differentDate++;
					}

					count -= 7; //each task has seven dividers "]"
				}
		}

	private: void decomposeTaskString(string feedbackTasks, int feedbackIndex) {

				string componentInfo;
				String^ stringComponentInfo;
				string taskType; //to distinguish a floating task
				string nextTaskDate;
				string remainingLongTask;
				string firstPiece;
				size_t start;
				size_t end=-1;
				bool isMultilineNeeded = false;
				bool isDifferentDate = false;
				bool isDone = false;
				int count = 0;

				countDivider(count, feedbackTasks);
				while(count > 0) {

					feedbackIndex--;

					/****Index****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems = gcnew System::Windows::Forms::ListViewItem(stringComponentInfo);

					/****Mark****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 
					if(componentInfo == "Done") {
						isDone = true;
					}

					/****Task type****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					stringComponentInfo = gcnew String(componentInfo.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 
					taskType = componentInfo;

					/****Task name****/
					iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
					/****Multiline for long task name****/
					isMultilineNeeded = determineMultilineNeeded(componentInfo);
					identifyFirstPiece(isMultilineNeeded, remainingLongTask, componentInfo, firstPiece);
					stringComponentInfo = gcnew String(firstPiece.c_str());
					listViewItems->SubItems->Add(stringComponentInfo); 

					/****Adding time info for non floating tasks****/
					if(taskType != "Float") {
						/****Date****/
						iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
						stringComponentInfo = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(stringComponentInfo); 

						/****check for date of the next task****/
						checkNextDate(isDifferentDate, start, end, feedbackTasks, componentInfo);  

						/****Start time****/
						iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
						stringComponentInfo = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(stringComponentInfo); 

						/****End time****/
						iterateTaskComponentInfo(feedbackTasks, start, end, componentInfo);
						stringComponentInfo = gcnew String(componentInfo.c_str());
						listViewItems->SubItems->Add(stringComponentInfo); 
					}					

					/****Change colour for done tasks****/
					changeDoneTaskColor(isDone);
					 
					/****Change colour for edited Line****/
					changeEditedLineColor(feedbackIndex);
					
					/****Display three types of tasks differently****/
					if(taskType == "Float") {
						listOutputFloat->Items->Add(this->listViewItems);
						/****Check for multiline floating task****/
						if(isMultilineNeeded) {
							displayMultilineTaskString(listOutputFloat, remainingLongTask, feedbackIndex, isDone);
						}
						skipLine(feedbackTasks, start, end, 3);
					} else {			
						listOutputMain->Items->Add(this->listViewItems);
						/****Check for multiline non-floating task****/
						if(isMultilineNeeded) {
							displayMultilineTaskString(listOutputMain, remainingLongTask, feedbackIndex, isDone);
						}
						/****Adding a blank line between non-floating tasks with different dates****/
						addBlankLine(isDifferentDate);
					}

					isDone = false;
					count -= 7; //each task has seven dividers "]"
				}
		}

	private: void displayMultilineTaskString(ListView^  listOutput, string remainingPieces, int feedbackIndex, bool isDone) {

				int lineLength = taskHeaderT->Width / widthToCharacterDisplayRatio;
				int numberOfExtraLines = remainingPieces.size() / lineLength + 1;
				string eachLine;
				 
				for(int i=0; i<numberOfExtraLines; i++) {
					if(remainingPieces.size() > lineLength) {
						eachLine = remainingPieces.substr(0, lineLength);
						remainingPieces = remainingPieces.substr(lineLength);
					} else {
						eachLine = remainingPieces;
					}
					string typeLocation = "";
					addMessageLine(eachLine, listOutput, typeLocation, isDone, feedbackIndex);
				}
		}

	private: bool determineMultilineNeeded(string taskInfo) {
				String^ stringTaskInfo = gcnew String(taskInfo.c_str());
				if( stringTaskInfo->Length > taskHeaderT->Width / widthToCharacterDisplayRatio ) {
					return true;
				}
				return false;
		}

	private: void separateFirstPiece(string& remainingLongTask, string componentInfo, string& firstPiece) {
				int remainingStartingPos = (taskHeaderT->Width / widthToCharacterDisplayRatio);
				firstPiece = componentInfo.substr(0, remainingStartingPos);
				remainingLongTask = componentInfo.substr(remainingStartingPos);
		}

	private: void identifyFirstPiece(bool isMultilineNeeded, string& remainingLongTask, string componentInfo, string& firstPiece) {
				if(isMultilineNeeded) {
					separateFirstPiece(remainingLongTask, componentInfo, firstPiece);
				} else {
					firstPiece = componentInfo;
				}
		}

	private: void checkNextDateInitial(int& differentDate, size_t start, size_t end, string feedbackTasks, string componentInfo) {
				
				size_t tempStart = start;
				size_t tempEnd = end;
				skipLine(feedbackTasks, tempStart, tempEnd, 7);

				string nextTaskDate = feedbackTasks.substr(tempStart, tempEnd-tempStart);
				if(componentInfo != nextTaskDate) {
					differentDate++;
				} 
		}

	private: void checkNextDate(bool& isDifferentDate, size_t start, size_t end, string feedbackTasks, string componentInfo) {
				
				size_t tempStart = start;
				size_t tempEnd = end;
				skipLine(feedbackTasks, tempStart, tempEnd, 7);
				
				string nextTaskDate = feedbackTasks.substr(tempStart, tempEnd-tempStart);
				if(componentInfo != nextTaskDate) {
					isDifferentDate = true;
				} 
		}

	private: void changeDoneTaskColor(bool& isDone) {
				if(isDone) {
					listViewItems->ForeColor = System::Drawing::SystemColors::GrayText;
				}
		}

	private: void changeEditedLineColor(int& feedbackIndex) {
				if(feedbackIndex == 0) {
					listViewItems->BackColor = System::Drawing::SystemColors::Highlight;
					listViewItems->ForeColor = System::Drawing::SystemColors::HighlightText;
				}
		}

	private: void iterateTaskComponentInfo(string& feedbackTasks, size_t& start, size_t& end, string& componentInfo) {
				start = end + 1;
				end = feedbackTasks.find_first_of("]", start);
				componentInfo = feedbackTasks.substr(start, end-start);
		}

	private: void skipLine(string& feedbackTasks, size_t& start, size_t& end, int NumberOfIter) {
				for(int i=0; i<NumberOfIter; i++) {
					start = end + 1;
					end = feedbackTasks.find_first_of("]", start);
				}
		}

	private: void countDivider(int& count, string& feedbackTasks) {
				for(int i=0; i<int(feedbackTasks.size());i++) {
					if (feedbackTasks.at(i) == ']') {
						count++;
					}
				}
		}

	private: void addBlankLine(bool& isDifferentDate) {
				if(isDifferentDate) {
					string emptyToken = " ";
					String^ stringEmptyToken = gcnew String(emptyToken.c_str());
					listViewItems = gcnew System::Windows::Forms::ListViewItem(stringEmptyToken);
					for(int i=0; i<6; i++) {
						listViewItems->SubItems->Add(stringEmptyToken);
					}
					listOutputMain->Items->Add(this->listViewItems);
					isDifferentDate = false; //for future use
				}
		}

	private: void addMessageLine(string message, ListView^ listOutput, string typeLocation, bool& isDone, int& feedbackIndex) {
		
					string emptyToken = " ";
					String^ stringMessage = gcnew String(message.c_str());
					String^ stringEmptyToken = gcnew String(emptyToken.c_str());	
					listViewItems = gcnew System::Windows::Forms::ListViewItem(stringEmptyToken); //empty index
					listViewItems->SubItems->Add(stringEmptyToken); //empty mark
					listViewItems->SubItems->Add(stringEmptyToken); //empty task type
					listViewItems->SubItems->Add(stringMessage);
					listViewItems->SubItems->Add(stringEmptyToken); //empty date
					listViewItems->SubItems->Add(stringEmptyToken); //empty start time
					listViewItems->SubItems->Add(stringEmptyToken); //empty end time

					if (typeLocation == "Message") {
						listViewItems->ForeColor = System::Drawing::SystemColors::HotTrack;
					} else {
						changeDoneTaskColor(isDone);
						changeEditedLineColor(feedbackIndex);						
					}
					listOutput->Items->Add(this->listViewItems);
		}
};

}
