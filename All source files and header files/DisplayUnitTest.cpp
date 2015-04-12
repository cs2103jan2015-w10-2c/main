#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DisplayUnitTest {
	TEST_CLASS(DisplayUnitTest) {
	public:
		
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

			/****display by date****/ //Incomplete
			viewTaskCommand = "view deadline";
			logic.executeLogic(viewTaskCommand);
			actualDisplay = logic.displayAllDeadline();
			expectedDisplay = "1]Not Done]Deadline]CS submission]13 Apr 2015]N.A.]23:59]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			viewTaskCommand = "view deadline";
			logic.executeLogic(viewTaskCommand);
			actualDisplay = logic.displayAllDeadline();
			expectedDisplay = "";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}
	};
}