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

			/*string displayTaskCommand = "display";
			logic.executeLogic(displayTaskCommand);*/
			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo fail. End of command history reached.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(UndoAddTest) {

			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			string addTimedTaskCommand = "add 2015/4/5/7/30/9/30/watch musical show.";
			logic.executeLogic(addTimedTaskCommand);
			logic.executeLogic(undoTaskCommand);
			actualMessage = logic.undoingTask();
			expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			string addDeadlineTaskCommand = "add 2015/4/13/23/59/CS submission";
			logic.executeLogic(addDeadlineTaskCommand);
			logic.executeLogic(undoTaskCommand);
			actualMessage = logic.undoingTask();
			expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(UndoDeleteTest) {

			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			string addDeadlineTaskCommand = "add 2015/4/13/23/59/CS submission";
			logic.executeLogic(addFloatTaskCommand);
			logic.executeLogic(addDeadlineTaskCommand);
			string deleteCommand = "delete 2";
			logic.executeLogic(deleteCommand);

			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(UndoStatusChangeTest) {

			EasyScheduleLogic logic;

			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			
			string doneCommand = "done 1";
			logic.executeLogic(doneCommand);
			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			string notdoneCommand = "notdone 1";
			logic.executeLogic(notdoneCommand);
			undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			actualMessage = logic.undoingTask();
			expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(UndoEditTest) {

			EasyScheduleLogic logic;

			string addTaskCommand = "add lunch with friends";
			logic.executeLogic(addTaskCommand);
			string editCommand = "edit 1 name dinner with friends";
			logic.executeLogic(editCommand);
			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedMessage = "Undo successfully.";
			Assert::AreEqual(expectedMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}

		TEST_METHOD(UndoSecondPreviousTest) {

			EasyScheduleLogic logic;
			string addFloatTaskCommand = "add lunch with friends";
			logic.executeLogic(addFloatTaskCommand);
			string displayTaskCommand = "display";
			logic.executeLogic(displayTaskCommand);
			string undoTaskCommand = "undo";
			logic.executeLogic(undoTaskCommand);
			string actualMessage = logic.undoingTask();
			string expectedFailMessage = "Undo successfully.";
			Assert::AreEqual(expectedFailMessage, actualMessage);

			/****Clear the data storage****/
			string deleteTaskCommand = "delete 1";
			while(logic.displayingTask() != "") {
				logic.executeLogic(deleteTaskCommand);
			}
		}
	};
}