#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DeleteUnitTest {

	//@author A0116707H Dong Peisen
	TEST_CLASS(DeleteUnitTest) {
	public:
		
		TEST_METHOD(DeleteFailTest) {
			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			string deleteTaskCommand = "delete 2";
			logic.executeLogic(deleteTaskCommand);
			string expectedDisplay = "1]Not Done]Float] lunch with friends]N.A.]N.A.]N.A.]";
			string actualDisplay = logic.deletingTask();
			Assert::AreEqual(expectedDisplay, actualDisplay);

			/****Clear the data storage****/
			deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(DeleteTaskTest) {
			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			string deleteTaskCommand = "delete 1";
			logic.executeLogic(deleteTaskCommand);
			string expectedDisplay = "";
			string actualDisplay = logic.deletingTask();
			Assert::AreEqual(expectedDisplay, actualDisplay);

			/****Clear the data storage****/
			deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

	};
}