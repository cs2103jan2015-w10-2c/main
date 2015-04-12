#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchUnitTest {

	//@author A0116707H Dong Peisen
	TEST_CLASS(SearchUnitTest) {
	public:
		
		TEST_METHOD(SearchTest) {

			EasyScheduleLogic logic;
			string addTaskCommand = "add lunch with friends";
			logic.executeLogic(addTaskCommand);
			addTaskCommand = "add 2015/4/16/12/00/14/00/lunch outing";
			logic.executeLogic(addTaskCommand);
			
			string searchTask = "search lunch";
			logic.executeLogic(searchTask);
			string actualDisplay = logic.searchingTask();
			string expectedDisplay = "1]Not Done]Timed]lunch outing]16 Apr 2015]12:00]14:00]2]Not Done]Float] lunch with friends]N.A.]N.A.]N.A.]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			searchTask = "search lunch with";
			logic.executeLogic(searchTask);
			actualDisplay = logic.searchingTask();
			expectedDisplay = "1]Not Done]Float] lunch with friends]N.A.]N.A.]N.A.]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			searchTask = "search dinner";
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