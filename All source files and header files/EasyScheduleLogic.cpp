#include "EasyScheduleLogic.h"


CommandParser EasyScheduleLogic::cp;
Storage EasyScheduleLogic::storage;
Task EasyScheduleLogic::task;
string EasyScheduleLogic::commandType;
string EasyScheduleLogic::taskType;
string EasyScheduleLogic::name;
int EasyScheduleLogic::year;
int EasyScheduleLogic::month;
int EasyScheduleLogic::day;
int EasyScheduleLogic::startTimeHour;
int EasyScheduleLogic::startTimeMin;
int EasyScheduleLogic::endTimeHour;
int EasyScheduleLogic::endTimeMin;

void EasyScheduleLogic::main(string userInput) {
//	floating task
//	string userInput = "add cs2103 meeting";


	parsingCommand(userInput);
	if(cp.commandType == "add") {
		creatingTask(); 
		storingTask(); 
	} else if (cp.commandType == "delete") {
	} else if (cp.commandType == "display") {
	} else if (cp.commandType == "search") {
	} else if (cp.commandType == "sort") {
	}

	return;
}

void EasyScheduleLogic::parsingCommand(string userInput) {
	
	cp.identifyTask(userInput);
	commandType = cp.commandType;
//	cout << "Command Type: "<< commandType<< endl;
	taskType = cp.taskType;
//	cout << "Task Type: "<< taskType<< endl;
	name = cp.name;
//	cout << "name: "<< name<< endl;
	year = cp.year;
	month = cp.month;
	day = cp.day;

}

void EasyScheduleLogic::creatingTask() {
	if(taskType=="FloatingTask") {
		task = Task(commandType,  name);
	} else {
		
		endTimeHour = cp.endTimeHour;
		endTimeMin = cp.endTimeMin;

		if (taskType=="DeadlineTask") {
			task = Task(commandType,  name, year, month, day, endTimeHour, endTimeMin);
		} else {
			startTimeHour = cp.startTimeHour;
			startTimeMin = cp.startTimeMin;
			task = Task(commandType,  name, year, month, day, startTimeHour, startTimeMin, endTimeHour, endTimeMin);
		}
	}
}

//identify commandType and required parameters and call storeFloat(string taskName)
void EasyScheduleLogic::storingTask() {
	storage.storeTask(task);
}

//receive bool from storeFloat and create output message
string EasyScheduleLogic::tellUI() {
	ostringstream os;
	if (!isDuplicate()) {
		os << "\"" << task.getName() << "\" has been stored successfully.";
	} else {
		os << "Sorry, the task is already in the schedule.";
	}
	
	return os.str();
	// this should call a function in the UI to show output message
}


bool EasyScheduleLogic::isDuplicate() {
	return storage.isTaskDuplicate(task);
}

EasyScheduleLogic::EasyScheduleLogic(void) { }

EasyScheduleLogic::~EasyScheduleLogic(void) { }
