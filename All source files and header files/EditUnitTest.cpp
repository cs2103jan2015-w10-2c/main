#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace EditUnitTest {
	
	//@author A0116707H Dong Peisen
	TEST_CLASS(EditUnitTest) {
	public:
		
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

	};
}