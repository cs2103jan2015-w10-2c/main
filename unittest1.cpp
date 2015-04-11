#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest{

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
}

