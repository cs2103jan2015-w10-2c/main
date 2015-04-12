#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchUnitTest {

	//@author A0116707H Dong Peisen
	TEST_CLASS(SearchUnitTest) {
	public:
		
		TEST_METHOD(SearchTest) {

			EasyScheduleLogic logic;
			string addTaskCommand = "add celebrate Chinese New Year";
			logic.executeLogic(addTaskCommand);
			addTaskCommand = "add 2015/4/16/12/00/14/00/celebrate birthday";
			logic.executeLogic(addTaskCommand);
			
			string searchTask = "search celebrate";
			logic.executeLogic(searchTask);
			string actualDisplay = logic.searchingTask();
			string expectedDisplay = "1]Not Done]Timed]celebrate birthday]16 Apr 2015]12:00]14:00]2]Not Done]Float] celebrate Chinese New Year]N.A.]N.A.]N.A.]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			searchTask = "search Chinese New Year";
			logic.executeLogic(searchTask);
			actualDisplay = logic.searchingTask();
			expectedDisplay = "1]Not Done]Float] celebrate Chinese New Year]N.A.]N.A.]N.A.]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			searchTask = "search happy";
			logic.executeLogic(searchTask);
			actualDisplay = logic.searchingTask();
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