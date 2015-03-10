#include "EasyScheduleLogic.h"


CommandParser EasyScheduleLogic::_cp;
Storage EasyScheduleLogic::_storage;
Task EasyScheduleLogic::_task;
string EasyScheduleLogic::_commandType;
string EasyScheduleLogic::_taskType;
string EasyScheduleLogic:: _name;
int EasyScheduleLogic::_year;
int EasyScheduleLogic::_month;
int EasyScheduleLogic::_day;
int EasyScheduleLogic::_startTimeHour;
int EasyScheduleLogic::_startTimeMin;
int EasyScheduleLogic::_endTimeHour;
int EasyScheduleLogic::_endTimeMin;

void EasyScheduleLogic::main(string userInput) {
//	floating task
//	string userInput = "add cs2103 meeting";


	parsingCommand(userInput);
	if(_commandType == "add") {
		creatingTask(); 
		storingTask(); 
	} else if (_commandType == "delete") {
	} else if (_commandType == "display") {
	} else if (_commandType == "search") {
	} else if (_commandType == "sort") {
	}

	return;
}

void EasyScheduleLogic::parsingCommand(string userInput) {
	
	_cp.identifyTask(userInput);
	_commandType = _cp.commandType;
//	cout << "Command Type: "<< commandType<< endl;
	_taskType = _cp.taskType;
//	cout << "Task Type: "<< taskType<< endl;
	_name = _cp.name;
//	cout << "name: "<< name<< endl;
	_year = _cp.year;
	_month = _cp.month;
	_day = _cp.day;

}

void EasyScheduleLogic::creatingTask() {
	if(_cp.taskType=="FloatingTask") {
		_task = Task(_cp.commandType,  _cp.name);
	} else {
		
		_endTimeHour = _cp.endTimeHour;
		_endTimeMin = _cp.endTimeMin;

		if (_cp.taskType=="DeadlineTask") {
			_task = Task(_cp.commandType,  _cp.name, _year, _month, _day, _endTimeHour, _endTimeMin);
		} else {
			_startTimeHour = _cp.startTimeHour;
			_startTimeMin = _cp.startTimeMin;
			_task = Task(_cp.commandType,  _cp.name, _year, _month, _day, _startTimeHour, _startTimeMin, _endTimeHour, _endTimeMin);
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
