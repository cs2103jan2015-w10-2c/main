#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{	
	//@author A0116707H
	TEST_CLASS(EasyScheduleLogicTest) {
	public:

		TEST_METHOD(FailUndoTest) {
			EasyScheduleLogic logic;

			/*string displayTaskCommand = "display";
			logic.executeLogic(displayTaskCommand);*/
			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo fail. End of command history reached.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}
		

		TEST_METHOD(UndoDeleteTest) {

			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add keep calm";
			string addDeadlineTaskCommand = "add 2015/4/13/23/59/back from the zoo";
			logic.executeLogic(addFloatTaskCommand);
			logic.executeLogic(addDeadlineTaskCommand);
			string deleteCommand = "delete 2";
			logic.executeLogic(deleteCommand);

			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(UndoStatusChangeTest) {

			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add keep an eye on him";
			logic.executeLogic(addFloatTaskCommand);
			
			string doneCommand = "done 1";
			logic.executeLogic(doneCommand);
			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			string notdoneCommand = "notdone 1";
			logic.executeLogic(notdoneCommand);
			undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			actualMessage = logic.undoingTask();
			expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(UndoEditTest) {

			EasyScheduleLogic logic;

			string addTaskCommand = "add get enough sleep";
			logic.executeLogic(addTaskCommand);
			string editCommand = "edit 1 name get much sleep";
			logic.executeLogic(editCommand);
			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(EditTaskNameTest) {

			EasyScheduleLogic Nlogic;

			string addFloatTaskCommand = "add lunch with family";
			Nlogic.executeLogic(addFloatTaskCommand);
			
			string editFloatTaskName = "edit 1 name dinner with family";
			Nlogic.executeLogic(editFloatTaskName);
			string actualDisplay = Nlogic.editingTask();
			string expectedDisplay = "1]Not Done]Float]dinner with family]N.A.]N.A.]N.A.]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			editFloatTaskName = "edit 2 name lunch with family";
			Nlogic.executeLogic(editFloatTaskName);
			actualDisplay = Nlogic.editingTask();
			expectedDisplay = "1]Not Done]Float]dinner with family]N.A.]N.A.]N.A.]";
			Assert::AreEqual(expectedDisplay, actualDisplay);
			
			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(Nlogic.displayingTask() != "") {
				Nlogic.executeLogic(deleteTaskCommand);
			}
			

		}

		TEST_METHOD(EditTaskDateTest) {

			EasyScheduleLogic Dlogic;

			string addDeadlineTaskCommand = "add 2015/4/13/23/59/CS homework";
			Dlogic.executeLogic(addDeadlineTaskCommand);
			
			string editDeadlineTaskName = "edit 1 date 2015/4/11";
			Dlogic.executeLogic(editDeadlineTaskName);
			string actualDisplay = Dlogic.editingTask();
			string expectedDisplay = "1]Not Done]Deadline]CS homework]11 Apr 2015]N.A.]23:59]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			editDeadlineTaskName = "edit 1 date Monday";
			Dlogic.executeLogic(editDeadlineTaskName);
			actualDisplay = Dlogic.editingTask();
			expectedDisplay = "1]Not Done]Deadline]CS homework]13 Apr 2015]N.A.]23:59]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(Dlogic.displayingTask() != "") {
				Dlogic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(EditTaskTimeTest) {
			
			EasyScheduleLogic Tlogic;

			string addTimedTaskCommand = "add 2015/4/5/7/30/9/30/watch drama show";
			Tlogic.executeLogic(addTimedTaskCommand);
			
			string editTimedTaskTime = "edit 1 time 8/00/10/00";
			Tlogic.executeLogic(editTimedTaskTime);
			string actualDisplay = Tlogic.editingTask();
			string expectedDisplay = "1]Not Done]Timed]watch drama show]5 Apr 2015]08:00]10:00]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			editTimedTaskTime = "edit 1 time 11/00/10/00";
			Tlogic.executeLogic(editTimedTaskTime);
			actualDisplay = Tlogic.editingTask();
			expectedDisplay = "1]Not Done]Timed]watch drama show]5 Apr 2015]08:00]10:00]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(Tlogic.displayingTask() != "") {
				Tlogic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(EditTaskTypeTest) {

			EasyScheduleLogic Ylogic;

			//float to timed
			string addFloatTaskCommand = "add blind date";
			Ylogic.executeLogic(addFloatTaskCommand);
			
			string editTaskTime = "edit 1 time 2015/4/5/12/00/13/00";
			Ylogic.executeLogic(editTaskTime);
			string actualDisplay = Ylogic.editingTask();
			string expectedDisplay = "1]Not Done]Timed] blind date]5 Apr 2015]12:00]13:00]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			editTaskTime = "edit 1 date 2015/4/5/12/00/13/00";
			Ylogic.executeLogic(editTaskTime);
			actualDisplay = Ylogic.editingTask();
			Assert::AreEqual(expectedDisplay, actualDisplay);

			//timed to deadline
			editTaskTime = "edit 1 time 13/00";
			Ylogic.executeLogic(editTaskTime);
			actualDisplay = Ylogic.editingTask();
			expectedDisplay = "1]Not Done]Deadline] blind date]5 Apr 2015]N.A.]13:00]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(Ylogic.displayingTask() != "") {
				Ylogic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(DisplayTest) {
			EasyScheduleLogic logic;
			string addTaskCommand = "add 2015/4/13/23/59/CS submission";
			logic.executeLogic(addTaskCommand);
			addTaskCommand = "add 2015/4/6/10/00/11/00/CS tutorial";
			logic.executeLogic(addTaskCommand);
			
			/****display by task type****/
			string viewTaskCommand = "view floating";
			logic.executeLogic(viewTaskCommand);
			string actualDisplay = logic.displayAllFloating();
			string expectedDisplay = "";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			viewTaskCommand = "view timed";
			logic.executeLogic(viewTaskCommand);
			actualDisplay = logic.displayAllTimed();
			expectedDisplay = "1]Not Done]Timed]CS tutorial]6 Apr 2015]10:00]11:00]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			viewTaskCommand = "view deadline";
			logic.executeLogic(viewTaskCommand);
			actualDisplay = logic.displayAllDeadline();
			expectedDisplay = "1]Not Done]Deadline]CS submission]13 Apr 2015]N.A.]23:59]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		//@author A0114255N
		TEST_METHOD(parsingCommandTest){
			string userInput = "add 2015/3/25/14/30/submit CS Homework";
			EasyScheduleLogic es;
			es.parsingCommand(userInput);
			string COMMAND_TYPE = "add";
			string TASK_TYPE = "DeadlineTask";
			int YEAR = 2015;
			int MONTH = 3;
			int DAY = 25;
			
			Assert::AreEqual(COMMAND_TYPE, es.getCommandType()); 
			Assert::AreEqual(TASK_TYPE, es.getTaskType());
			Assert::AreEqual(YEAR, es.getYear());
			Assert::AreEqual(MONTH, es.getMonth());
			Assert::AreEqual(DAY, es.getDay());
			
		}

		TEST_METHOD(creatingTaskTest){
			string userInput = "add today/14/30/16/30/CS Homework";
			EasyScheduleLogic es;
			es.parsingCommand(userInput);
			es.creatingTask();

			time_t now = time(0);	
			struct tm time;
			localtime_s(&time, &now);
			int DAY =  time.tm_mday;
			int MONTH = time.tm_mon + 1;
			int YEAR = time.tm_year + 1900;	

			string COMMAND_TYPE = "add";
			string TASK_TYPE = "TimedTask";
			
			int START_TIME_HOUR = 14;
			int START_TIME_MIN = 30;
			int END_TIME_HOUR = 16;
			int END_TIME_MIN = 30;
		
			Assert::AreEqual(COMMAND_TYPE, es.getCommandType());
			Assert::AreEqual(TASK_TYPE, es.getTaskType());
			Assert::AreEqual(YEAR, es.getYear());
			Assert::AreEqual(MONTH, es.getMonth());
			Assert::AreEqual(DAY, es.getDay());
			Assert::AreEqual(START_TIME_HOUR, es.getStartTimeHour());
			Assert::AreEqual(START_TIME_MIN, es.getStartTimeMin());
			Assert::AreEqual(END_TIME_HOUR, es.getEndTimeHour());
			Assert::AreEqual(END_TIME_MIN, es.getEndTimeMin());
		}

		TEST_METHOD(addingTaskTest){
			EasyScheduleLogic es;

			string userInput1 = "add 2015/3/25/14/30/CS Homework";
			es.parsingCommand(userInput1);
			string MESSAGE_ADD = "The task has been stored successfully.";
			Assert::AreEqual(MESSAGE_ADD, es.addingTask());
	
			string MESSAGE_ADD_FAIL = "Sorry, the task is already in the schedule.";
			es.addingTask();
			Assert::AreEqual(MESSAGE_ADD_FAIL, es.addingTask());

			string userInput2 = "add tomorrow/14/30/10/15/swim in the sea";
			es.parsingCommand(userInput2);
			string MESSAGE_INVALID_TIME = "Invalid time.";
			Assert::AreEqual(MESSAGE_INVALID_TIME, es.addingTask());

			string userInput3 = "add 2015/13/31/14/30/CS Homework";
			es.parsingCommand(userInput3);
			string MESSAGE_INVALID_DATE = "Invalid date.";
			Assert::AreEqual(MESSAGE_INVALID_DATE, es.addingTask());

			string userInput4 = "add";
			es.parsingCommand(userInput4);
			string MESSAGE_INVALID_INPUT_NAME = "Invalid task.";
			Assert::AreEqual(MESSAGE_INVALID_INPUT_NAME, es.addingTask());
		}
	};	


	//@author A0114255N
	TEST_CLASS(TaskTest){
	public:

		TEST_METHOD(ConstructorTest){
			Task task("add", "TimedTask", "CS Homework", 2015, 3, 25, 6, 30, 7, 30, false);
			string COMMAND_TYPE = "add";
			string TASK_TYPE = "TimedTask";
			int YEAR = 2015;
			int MONTH = 3;
			int DAY = 25;
			int START_TIME_HOUR = 6;
			int START_TIME_MIN = 30;
			int END_TIME_HOUR = 7;
			int END_TIME_MIN = 30;
		
			Assert::AreEqual(COMMAND_TYPE, task.getCommandType());
			Assert::AreEqual(TASK_TYPE, task.getTaskType());
			Assert::AreEqual(YEAR, task.getYear());
			Assert::AreEqual(MONTH, task.getMonth());
			Assert::AreEqual(DAY, task.getDay());
			Assert::AreEqual(START_TIME_HOUR, task.getStartTimeHour());
			Assert::AreEqual(START_TIME_MIN, task.getStartTimeMin());
			Assert::AreEqual(END_TIME_HOUR, task.getEndTimeHour());
			Assert::AreEqual(END_TIME_MIN, task.getEndTimeMin());
			Assert::IsFalse(task.getIsDone());
		}

	};

	//@author A0115131B
	TEST_CLASS(RecordTest)
	{
	public:

		TEST_METHOD(RecordConstructorTest){
			// TODO: Your test code here
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			list<Task> record1List, record2List;
			record1List = record1.getTaskRecord();
			record2List = record2.getTaskRecord();

			Assert::AreEqual(record1.getCommandType(), commandType1);
			Assert::AreEqual(record2.getCommandType(), commandType2);
			
			list<Task>::iterator it;
			it = record1List.begin();
			string name = it->getName();
			Assert::AreEqual(name, name1);

			it = record2List.begin();
			name = it->getName();
			Assert::AreEqual(name, name1);
			it++;
			name = it->getName();
			Assert::AreEqual(name, name2);
		}

		TEST_METHOD(RecordSetCommandTypeTest){
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			string command3, command4;
			command3 = "done";
			command4 = "edit";
			record1.setCommandTypeRecord(command3);
			record2.setCommandTypeRecord(command4);

			Assert::AreEqual(record1.getCommandType(), command3);
			Assert::AreEqual(record2.getCommandType(), command4);
		}

		TEST_METHOD(RecordsetlistTaskTest){
			string name1, name2, name3, command1, command2, command3;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			name3 = "Presentation";
			command1 = "add";
			command2 = "add";
			command3 = "add";
			Task task1 = Task(command1,name1);
			Task task2 = Task(command2,name2);
			Task task3 = Task(command3,name3);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);
			
			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			record1.setlistTaskRecord(task3);
			record2.setlistTaskRecord(task3);

			int record1Size = record1.getTaskRecord().size();
			int record2Size = record2.getTaskRecord().size();

			Assert::AreEqual(record1Size, 2);
			Assert::AreEqual(record2Size, 3);
		}
	};
	
	//@author A0115131B
	TEST_CLASS(TrackerTest)
	{
	public:
		
		TEST_METHOD(TrackerIsEmptyTest)
		{
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			Tracker tracker1;
			Assert::IsTrue(tracker1.isEmptyTracker());

			tracker1.addRecord(record1);
			Assert::IsFalse(tracker1.isEmptyTracker());
			tracker1.addRecord(record2);
			Assert::IsFalse(tracker1.isEmptyTracker());
		}

		TEST_METHOD(TrackerGetNewestRecordTest){
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			Tracker tracker1;
			tracker1.addRecord(record1);
			Record record3 = tracker1.getNewestRecord();
			string name3, name4, name5, commandType3, commandType4;
			name3 = record3.getTaskRecord().begin()->getName();
			commandType3 = record3.getCommandType();
			Assert::AreEqual(name3, name1);
			Assert::AreEqual(commandType3, commandType1);


			tracker1.addRecord(record2);
			Record record4 = tracker1.getNewestRecord();
			name4 = record4.getTaskRecord().begin()->getName();
			Assert::AreEqual(name4, name1);
			name5 = record4.getTaskRecord().back().getName();
			Assert::AreEqual(name5, name2);
			commandType4 = record4.getCommandType();
			Assert::AreEqual(commandType4, commandType2);
		}

		TEST_METHOD(deleteLastTrackerEntryTest){
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);
			
			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			Tracker tracker1;
			tracker1.addRecord(record1);
			tracker1.addRecord(record2);
			
			tracker1.deleteLastTrackerEntry();
			Record record3 = tracker1.getNewestRecord();
			string name3, name4, commandType3;
			name3 = record3.getTaskRecord().begin()->getName();
			commandType3 = record3.getCommandType();
			Assert::AreEqual(name3, name1);
			Assert::AreEqual(commandType3, commandType1);
		}

	};

	
	//@author A0111446R
	TEST_CLASS(StorageTest)
	{
		
	public:
		
		
		TEST_METHOD(Readfile)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;

			expected.clear();
			(store._searchResultList).clear();
			(store._taskList).clear();

			//Checks if file reads properly
			store.setPathName("./");
			store.setFileName("mytestfile");
			store.readFile();

			Task task3("add", "hello world");
			Task task1("add", "eat lunch at home", 2015 ,03 ,11 , 13, 00, 14, 30);
			Task task2("add", "eat breakfast at home", 2015 ,03 ,11 , 14, 30);


			expected.push_back(task1);
			expected.push_back(task2);
			expected.push_back(task3);

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it1->getName(),it2->getName());
				it1++;
		}
			expected.clear();
			(store._searchResultList).clear();
			(store._taskList).clear();
		}


		TEST_METHOD(Sort_TaskType)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;
			
			//Order of importance: Deadline > Timed > Float

			Task task3("add", "hello world");
			Task task2("add", "eat dinner at home", 2015, 03, 11, 18, 00, 19, 00);
			Task task1("add", "eat lunch at home", 2015 ,03 ,11 ,13 ,00);

			store.storeTask(task3);
			store.storeTask(task2);
			store.storeTask(task1);

			expected.push_back(task1);
			expected.push_back(task2);
			expected.push_back(task3);
			store.sortList();

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it2->getName(),it1->getName());
				it1++;
		}
			expected.clear();
			(store._taskList).clear();
		}

		TEST_METHOD(Sort_TimedTask)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;
			
			//Sorts timed task in order of date then time

			Task task1("add", "eat at home", 2014, 03, 11, 18, 00, 19, 00);
			Task task2("add", "eat dinner at home", 2015, 03, 11, 18, 00, 19, 00);
			Task task3("add", "eat lunch at home", 2015 ,03 ,11 ,13 ,00, 14, 30);

			store.storeTask(task3);
			store.storeTask(task1);
			store.storeTask(task2);

			expected.push_back(task1);
			expected.push_back(task3);
			expected.push_back(task2);
			store.sortList();

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it2->getName(),it1->getName());
				it1++;
		}
			expected.clear();
			(store._taskList).clear();
		}

		TEST_METHOD(Sort_Deadline)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;
			
			//Sorts Deadline task in order of date then time

			Task task1("add", "eat at home", 2014, 03, 11, 19, 00);
			Task task2("add", "eat dinner at home", 2015, 03, 11, 19, 00);
			Task task3("add", "eat lunch at home", 2015 ,03 ,11 , 14, 30);

			store.storeTask(task3);
			store.storeTask(task1);
			store.storeTask(task2);

			expected.push_back(task1);
			expected.push_back(task3);
			expected.push_back(task2);
			store.sortList();

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it2->getName(),it1->getName());
				it1++;
		}
			expected.clear();
			(store._taskList).clear();
		}

		TEST_METHOD(Sort_By_Name)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;
			
			//Sorts similar timings based on name of task in alphabetical order

			Task task1("add", "dat lunch at home", 2015 ,03 ,11 , 14, 30);
			Task task2("add", "eat lunch at home", 2015 ,03 ,11 , 14, 30);
			Task task3("add", "eat breakfast at home", 2015 ,03 ,11 , 14, 30);

			store.storeTask(task3);
			store.storeTask(task1);
			store.storeTask(task2);

			expected.push_back(task1);
			expected.push_back(task3);
			expected.push_back(task2);
			store.sortList();

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it2->getName(),it1->getName());
				it1++;
		}
			expected.clear();
			(store._taskList).clear();
		}

		TEST_METHOD(Delete_By_Number)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;

			Task task1("add", "dat lunch at home", 2015 ,03 ,11 , 14, 30);
			Task task2("add", "eat lunch at home", 2015 ,03 ,11 , 14, 30);
			Task task3("add", "fat breakfast at home", 2015 ,03 ,11 , 14, 30);

			store.storeTask(task1);
			store.storeTask(task2);
			store.storeTask(task3);

			expected.push_back(task1);
			expected.push_back(task3);
			store.deleteByNumber(2);

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it2->getName(),it1->getName());
				it1++;
			}
			expected.clear();
			(store._taskList).clear();
		}

		TEST_METHOD(Done_By_Number)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;
			
			Task task1("add", "dat lunch at home", 2015 ,03 ,11 , 14, 30);
			Task task2("add", "eat lunch at home", 2015 ,03 ,11 , 14, 30, 14, 45);
			Task task3("add", "eat breakfast at home", 2015 ,03 ,11 , 14, 30);
			Task task4("add" , "TimedTask" , "eat lunch at home", 2015 ,03 ,11 , 14, 30, 14, 45, 1);

			store.storeTask(task1);
			store.storeTask(task2);
			store.storeTask(task3);

			expected.push_back(task1);
			expected.push_back(task4);
			expected.push_back(task3);


			store.markDone(2);

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it2->getIsDone(),it1->getIsDone());
				it1++;
			}
			expected.clear();
			(store._taskList).clear();
		}

		TEST_METHOD(Done_By_Name_Number)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;
			
			Task task("add", "aat at home");
			Task task0("add", "eat lunch at home");
			Task task1("add", "cat lunch at home", 2015 ,03 ,11 , 14, 30);
			Task task2("add", "eat lunch at home", 2015 ,03 ,11 , 14, 30, 14, 45);
			Task task3("add", "fat breakfast at home", 2015 ,03 ,11 , 14, 30);
			Task task4("add" , "TimedTask" , "eat lunch at home", 2015 ,03 ,11 , 14, 30, 14, 45, 1);

			store.storeTask(task);
			store.storeTask(task0);
			store.storeTask(task1);
			store.storeTask(task3);
			store.storeTask(task2);

			expected.push_back(task);
			expected.push_back(task0);
			expected.push_back(task1);
			expected.push_back(task3);
			expected.push_back(task4);


			store.searchByName("eat lunch");
			store.markDone(2);

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it2->getIsDone(),it1->getIsDone());
				it1++;
			}
			expected.clear();
			(store._searchResultList).clear();
			(store._taskList).clear();
		}
		
		
		TEST_METHOD(Search_Name)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;
			
			Task task1("add", "dat lunch at home", 2015 ,03 ,11 , 14, 30);
			Task task2("add", "eat break at home", 2015 ,05 ,11 , 14, 30);
			Task task4("add", "eat breakfast at home", 2015 ,03 ,11 , 14, 30);
			Task task3("add", "i eat breakfast home", 2015 ,02 ,11 , 14, 30);

			store.storeTask(task1);
			store.storeTask(task2);
			store.storeTask(task3);
			store.storeTask(task4);

			expected.push_back(task3);
			expected.push_back(task4);
			string s;
			s = store.searchByName("eat breakfast");

			it1 = expected.begin();

			for (it2 = (store._searchResultList).begin() ; it2!=(store._searchResultList).end() ;it2++) {
				Assert::AreEqual(it2->getName(),it1->getName());
				it1++;
			}
			expected.clear();
			(store._taskList).clear();
			(store._searchResultList).clear();
		}

		TEST_METHOD(Delete_By_Name_Number)
		{
			Storage store;
			list <Task> expected;
			list<Task>::iterator it1;
			list<Task>::iterator it2;
			
			Task task1("add", "dat lunch at home", 2015 ,03 ,11 , 14, 30);
			Task task2("add", "eat break at home", 2015 ,03 ,11 , 14, 30);
			Task task3("add", "eat dreakfast at home", 2015 ,03 ,11 , 14, 30);

			store.storeTask(task1);
			store.storeTask(task2);
			store.storeTask(task3);

			expected.push_back(task1);
			expected.push_back(task3);
			string s;
			s = store.searchByName("eat");
			s = store.deleteByNumber(1);

			it1 = expected.begin();

			for (it2 = (store._taskList).begin() ; it2!=(store._taskList).end() ;it2++) {
				Assert::AreEqual(it2->getName(),it1->getName());
				it1++;
			}
			expected.clear();
			(store._taskList).clear();
		}


	};
}
