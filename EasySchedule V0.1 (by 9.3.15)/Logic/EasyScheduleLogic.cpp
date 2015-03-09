#include "EasyScheduleLogic.h"

Storage* EasyScheduleLogic::storage;
Task* EasyScheduleLogic::task;

void EasyScheduleLogic::main(string userInput) {
//	floating task
//	string userInput = "add cs2103 meeting";


/*********Parse command and create task*********/
	CommandParser* cp;
	cp = new CommandParser;

	cp->identifyTask(userInput);
	string commandType = cp->commandType;
//	cout << "Command Type: "<< commandType<< endl;
	string taskType = cp->taskType;
//	cout << "Task Type: "<< taskType<< endl;
	string description = cp->description;
//	cout << "Description: "<< description<< endl;

	if(taskType=="FloatingTask") {
		task = new Task(commandType, description);
	} else {
		int year = cp->year;
		int month = cp->month;
		int day = cp->day;
		double endTime =cp->endTime;

		if (taskType=="DeadlineTask") {
			task = new Task(commandType, description, year, month, day, endTime);
		} else {
			double startTime = cp->startTime;
			task = new Task(commandType, description, year, month, day, startTime, endTime);
		}
	}


/*********Store task*********/

	storage = new Storage;
	storeTask();
	/*

	enter code here


	*/

	return;
}

//identify commandType and required parameters and call storeFloat(string taskName)
void EasyScheduleLogic::storeTask() {
	if (task->isFloat()) {
		storage->storeFloat(task->getName());
	} else if(task->isDeadline) {
		storage->storeDeadline(task->getName(), task->getDate(), task->getEndTime());
	} else {
		storage->storeTimed(task->getName(), task->getDate(), task->getStartTime(), task->getEndTime());
	}
}

//receive bool from storeFloat and create output message
string EasyScheduleLogic::tellUI() {
	ostringstream os;
	if (!isDuplicate()) {
		os << "\"" << task->getName() << "\" has been stored successfully.";
	} else {
		os << "Sorry, the task is already in the schedule.";
	}
	
	return os.str();
	// this should call a function in the UI to show output message
}


bool EasyScheduleLogic::isDuplicate() {
	if (storage->isFloatDuplicate(task->getName()) || 
		storage->isTimedDuplicate(task->getName()) || 
		storage->isDeadlineDuplicate(task->getName())) {
		return true;
	} else {
		return false;
	}
}

EasyScheduleLogic::EasyScheduleLogic(void) { }

EasyScheduleLogic::~EasyScheduleLogic(void) { }
