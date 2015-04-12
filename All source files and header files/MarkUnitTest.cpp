#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarkUnitTest {

	//@author A0116707H Dong Peisen
	TEST_CLASS(MarkUnitTest) {
	public:
		
		TEST_METHOD(MarkStatusTest) {
			EasyScheduleLogic logic;
			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			
			string doneTask = "done 1";
			logic.executeLogic(doneTask);
			string actualDisplay = logic.markDone();
			string expectedDisplay = "1]Done]Float] lunch with friends]N.A.]N.A.]N.A.]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			string notdoneTask = "notdone 1";
			logic.executeLogic(notdoneTask);
			actualDisplay = logic.markNotDone();
			expectedDisplay = "1]Not Done]Float] lunch with friends]N.A.]N.A.]N.A.]";
			Assert::AreEqual(expectedDisplay, actualDisplay);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}
	};
}