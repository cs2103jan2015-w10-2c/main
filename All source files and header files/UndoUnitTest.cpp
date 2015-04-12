#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UndoUnitTest {	

	//@author A0116707H Dong Peisen
	TEST_CLASS(UndoUnitTest) {
	public:
		
		TEST_METHOD(FailUndoTest) {
			EasyScheduleLogic logic;
			string displayTaskCommand = "display";
			logic.executeLogic(displayTaskCommand);
			logic.executeLogic(displayTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedFailMessage = "Undo fail. End of command history reached.";
			Assert::AreEqual(expectedFailMessage, actualMessage);
		}

		TEST_METHOD(UndoAddTest) {
			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			string addTimedTaskCommand = "add 2015/4/5/7/30/9/30/watch musical show.";
			logic.executeLogic(addTimedTaskCommand);
			actualMessage = logic.undoingTask();
			expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			string addDeadlineTaskCommand = "add 2015/4/13/23/59/CS submission";
			logic.executeLogic(addDeadlineTaskCommand);
			actualMessage = logic.undoingTask();
			expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);
		}

		TEST_METHOD(UndoDeleteTest) {
			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			string addDeadlineTaskCommand = "add 2015/4/13/23/59/CS submission";
			logic.executeLogic(addFloatTaskCommand);
			logic.executeLogic(addDeadlineTaskCommand);
			string deleteCommand = "delete 2";
			logic.executeLogic(deleteCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);
		}

		TEST_METHOD(UndoStatusChangeTest) {
			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			
			string doneCommand = "done 1";
			logic.executeLogic(doneCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			string undoneCommand = "notdone 1";
			logic.executeLogic(undoneCommand);
			actualMessage = logic.undoingTask();
			expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);
		}

		TEST_METHOD(UndoEditTest) {
			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			string editCommand = "edit 1 name dinner with friends";
			logic.executeLogic(editCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);
			
			string addTimedTaskCommand = "add 2015/2/13/12/00/13/00/CS homework";
			editCommand = "edit 2 time 14/00";
			logic.executeLogic(editCommand);
			actualMessage = logic.undoingTask();
			Assert::AreEqual(expectedMessage, actualMessage);
		}
	};
}