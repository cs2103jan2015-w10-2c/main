#include "EasyScheduleLogic.h"


CommandParser EasyScheduleLogic::_cp;
Storage EasyScheduleLogic::_storage;
Task EasyScheduleLogic::_task;
string EasyScheduleLogic::_commandType;
string EasyScheduleLogic::_taskType;
string EasyScheduleLogic::_name;

void EasyScheduleLogic::main(string userInput) {
//	floating task
//	string userInput = "add cs2103 meeting";


	parsingCommand(userInput); //parse userInput
	creatingTask(); //create a task
	storingTask(); //store the task
	return;
}

void EasyScheduleLogic::parsingCommand(string userInput) {
	
	_cp.identifyTask(userInput);
	_commandType = _cp.commandType;
//	cout << "Command Type: "<< commandType<< endl;
	_taskType = _cp.taskType;
//	cout << "Task Type: "<< taskType<< endl;
	_name = _cp.description;
//	cout << "Description: "<< description<< endl;


}

void EasyScheduleLogic::creatingTask() {
	if(_taskType=="FloatingTask") {
		_task = Task(_commandType, _name);
	} else {
		int year = _cp.year;
		int month = _cp.month;
		int day = _cp.day;
		double endTime = _cp.endTime;

		if (_taskType=="DeadlineTask") {
			_task = Task(_commandType, _name, year, month, day, endTime);
		} else {
			double startTime = _cp.startTime;
			_task = Task(_commandType, _name, year, month, day, startTime, endTime);
		}
	}
}

//identify commandType and required parameters and call storeFloat(string taskName)
void EasyScheduleLogic::storingTask() {
	_storage.storeTask(_task);
}

//receive bool from storeFloat and create output message
string EasyScheduleLogic::tellUI() {
	ostringstream os;
	if (!isDuplicate()) {
		os << "\"" << _task.getName() << "\" has been stored successfully.";
	} else {
		os << "Sorry, the task is already in the schedule.";
	}
	
	return os.str();
	// this should call a function in the UI to show output message
}


bool EasyScheduleLogic::isDuplicate() {
	return _storage.isTaskDuplicate(_task);
}

EasyScheduleLogic::EasyScheduleLogic(void) { }

EasyScheduleLogic::~EasyScheduleLogic(void) { }
