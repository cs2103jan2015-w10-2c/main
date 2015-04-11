#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
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
	
	TEST_CLASS(EasyScheduleLogicTest){

	public:

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

	//@author A0111446R
	TEST_CLASS(UnitTest_teckkian)
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