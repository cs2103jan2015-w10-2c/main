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
			double START_TIME_HOUR = 6;
			double START_TIME_MIN = 30;
			double END_TIME_HOUR = 7;
			double END_TIME_MIN = 30;
		
			Assert::AreEqual(COMMAND_TYPE, task.getCommandType());
			Assert::AreEqual(TASK_TYPE, task.getTaskType());
			Assert::AreEqual(YEAR, task.getYear());
			Assert::AreEqual(MONTH, task.getMonth());
			Assert::AreEqual(DAY, task.getDay());
			Assert::AreEqual(START_TIME_HOUR, task.getStartTimeHour());
			Assert::AreEqual(START_TIME_MIN, task.getStartTimeMin());
			Assert::AreEqual(END_TIME_HOUR, task.getEndTimeHour());
			Assert::AreEqual(END_TIME_MIN, task.getEndTimeMin());
			Assert::IsFalse(task.isDone());
		}

	};
	
	TEST_CLASS(EasyScheduleLogicTest){

	public:

		TEST_METHOD(parsingCommandTest){
			string userInput = "add 2015/3/25/14/30/submit CS Homework";
			EasyScheduleLogic es;
			es.parsingCommand(userInput);
			string COMMAND_TYPE = "add";
			Assert::AreEqual(COMMAND_TYPE, es.getCommandType()); 
		}

		TEST_METHOD(creatingTaskTest){
			string userInput = "add 2015/3/25/14/30/CS Homework";
			EasyScheduleLogic es;
			es.parsingCommand(userInput);
			es.creatingTask();

			string COMMAND_TYPE = "add";
			string TASK_TYPE = "DeadlineTask";
			int YEAR = 2015;
			int MONTH = 3;
			int DAY = 25;
			int START_TIME_HOUR = 0;
			int START_TIME_MIN = 0;
			int END_TIME_HOUR = 14;
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
		
		
		}
	};

	
}

