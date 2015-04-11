#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Jingyi
{
	//@author A0115131B
	TEST_CLASS(RecordTest)
	{
	public:

		TEST_METHOD(RecordConstructorTest){
			// TODO: Your test code here
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			list<Task> record1List, record2List;
			record1List = record1.getTaskRecord();
			record2List = record2.getTaskRecord();

			Assert::AreEqual(record1.getCommandType(), commandType1);
			Assert::AreEqual(record2.getCommandType(), commandType2);
			
			list<Task>::iterator it;
			it = record1List.begin();
			string name = it->getName();
			Assert::AreEqual(name, name1);

			it = record2List.begin();
			name = it->getName();
			Assert::AreEqual(name, name1);
			it++;
			name = it->getName();
			Assert::AreEqual(name, name2);
		}

		TEST_METHOD(RecordSetCommandTypeTest){
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			string command3, command4;
			command3 = "done";
			command4 = "edit";
			record1.setCommandTypeRecord(command3);
			record2.setCommandTypeRecord(command4);

			Assert::AreEqual(record1.getCommandType(), command3);
			Assert::AreEqual(record2.getCommandType(), command4);
		}

		TEST_METHOD(RecordsetlistTaskTest){
			string name1, name2, name3, command1, command2, command3;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			name3 = "Presentation";
			command1 = "add";
			command2 = "add";
			command3 = "add";
			Task task1 = Task(command1,name1);
			Task task2 = Task(command2,name2);
			Task task3 = Task(command3,name3);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);
			
			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			record1.setlistTaskRecord(task3);
			record2.setlistTaskRecord(task3);

			int record1Size = record1.getTaskRecord().size();
			int record2Size = record2.getTaskRecord().size();

			Assert::AreEqual(record1Size, 2);
			Assert::AreEqual(record2Size, 3);
		}
	};
	
	//@author A0115131B
	TEST_CLASS(TrackerTest)
	{
	public:
		
		TEST_METHOD(TrackerIsEmptyTest)
		{
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			Tracker tracker1;
			Assert::IsTrue(tracker1.isEmptyTracker());

			tracker1.addRecord(record1);
			Assert::IsFalse(tracker1.isEmptyTracker());
			tracker1.addRecord(record2);
			Assert::IsFalse(tracker1.isEmptyTracker());
		}

		TEST_METHOD(TrackerGetNewestRecordTest){
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			Tracker tracker1;
			tracker1.addRecord(record1);
			Record record3 = tracker1.getNewestRecord();
			string name3, name4, name5, commandType3, commandType4;
			name3 = record3.getTaskRecord().begin()->getName();
			commandType3 = record3.getCommandType();
			Assert::AreEqual(name3, name1);
			Assert::AreEqual(commandType3, commandType1);


			tracker1.addRecord(record2);
			Record record4 = tracker1.getNewestRecord();
			name4 = record4.getTaskRecord().begin()->getName();
			Assert::AreEqual(name4, name1);
			name5 = record4.getTaskRecord().back().getName();
			Assert::AreEqual(name5, name2);
			commandType4 = record4.getCommandType();
			Assert::AreEqual(commandType4, commandType2);
		}

		TEST_METHOD(deleteLastTrackerEntryTest){
			string name1, name2, command1, command2;
			name1 = "CS meeting";
			name2 = "Cs lecture";
			command1 = "add";
			command2 = "add";
			Task task1 = Task(command1, name1);
			Task task2 = Task(command2, name2);

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);
			
			string commandType1, commandType2;
			commandType1 = "add";
			commandType2 = "delete";

			Record record1 = Record(commandType1, task1);
			Record record2 = Record(commandType2, taskList2);

			Tracker tracker1;
			tracker1.addRecord(record1);
			tracker1.addRecord(record2);
			
			tracker1.deleteLastTrackerEntry();
			Record record3 = tracker1.getNewestRecord();
			string name3, name4, commandType3;
			name3 = record3.getTaskRecord().begin()->getName();
			commandType3 = record3.getCommandType();
			Assert::AreEqual(name3, name1);
			Assert::AreEqual(commandType3, commandType1);
		}

	};
}
	