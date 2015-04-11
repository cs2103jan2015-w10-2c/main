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
			Task task1 = Task("add", "CS meeting");
			Task task2 = Task("add", "CS lecture");
			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			Record record1 = Record("add", task1);
			Record record2 = Record("delete", taskList2);

			list<Task> record1List, record2List;
			record1List = record1.getTaskRecord();
			record2List = record2.getTaskRecord();

			Assert::AreEqual(record1.getCommandType().c_str(), "add");
			Assert::AreEqual(record2.getCommandType().c_str(), "delete");
			Assert::AreEqual(record1List, taskList1);
			Assert::AreEqual(record2List, taskList2);
		}

		TEST_METHOD(RecordSetCommandTypeTest){
			Task task1 = Task("add", "CS meeting");
			Task task2 = Task("add", "CS lecture");
			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			Record record1 = Record("add", task1);
			Record record2 = Record("delete", taskList2);

			record1.setCommandTypeRecord("done");
			record2.setCommandTypeRecord("edit");

			Assert::AreEqual(record1.getCommandType().c_str(), "done");
			Assert::AreEqual(record2.getCommandType().c_str(), "edit");
		}

		TEST_METHOD(RecordsetlistTaskTest){
			Task task1 = Task("add", "CS meeting");
			Task task2 = Task("add", "CS lecture");
			Task task3 = Task("add", "Presentation");

			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			Record record1 = Record("add", task1);
			Record record2 = Record("delete", taskList2);

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
			// TODO: Your test code here
			Task task1 = Task("add", "CS meeting");
			Task task2 = Task("add", "CS lecture");
			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			Record record1 = Record("add", task1);
			Record record2 = Record("delete", taskList2);

			Tracker tracker1;
			Assert::IsTrue(tracker1.isEmptyTracker());

			tracker1.addRecord(record1);
			Assert::IsFalse(tracker1.isEmptyTracker());
			tracker1.addRecord(record2);
			Assert::IsFalse(tracker1.isEmptyTracker());
		}

		TEST_METHOD(TrackerGetNewestRecordTest){
			Task task1 = Task("add", "CS meeting");
			Task task2 = Task("add", "CS lecture");
			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			Record record1 = Record("add", task1);
			Record record2 = Record("delete", taskList2);

			Tracker tracker1;
			tracker1.addRecord(record1);
			Record record3 = tracker1.getNewestRecord();
			Assert::AreEqual(record3, record1);

			tracker1.addRecord(record2);
			Record record4 = tracker1.getNewestRecord();
			Assert::AreEqual(record4, record2);
		}

		TEST_METHOD(deleteLastTrackerEntryTest){
			Task task1 = Task("add", "CS meeting");
			Task task2 = Task("add", "CS lecture");
			list<Task> taskList1, taskList2;
			taskList1.push_back(task1);

			taskList2.push_back(task1);
			taskList2.push_back(task2);

			Record record1 = Record("add", task1);
			Record record2 = Record("delete", taskList2);

			Tracker tracker1;
			tracker1.addRecord(record1);
			tracker1.addRecord(record2);
			
			tracker1.deleteLastTrackerEntry();
			Record record3 = tracker1.getNewestRecord();
			Assert::AreEqual(record3, record1);
		}

	};
}
	