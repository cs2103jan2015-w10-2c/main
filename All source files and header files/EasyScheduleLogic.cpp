#include "EasyScheduleLogic.h"
#include "Storage.h"
#include <sys/stat.h>

const string EasyScheduleLogic::MESSAGE_WELCOME = "Welcome to EasySchedule!";
const string EasyScheduleLogic::MESSAGE_ADD = "The task has been stored successfully.";
const string EasyScheduleLogic::MESSAGE_ADD_FAIL = "Sorry, the task is already in the schedule.";
const string EasyScheduleLogic::MESSAGE_DELETE = "The task %s has been deleted.";
const string EasyScheduleLogic::MESSAGE_DELETE_FAIL = "There is no task \"%s\" in the schedule.";
const string EasyScheduleLogic::MESSAGE_CLEAR = "All tasks have been deleted.";
//const string EasyScheduleLogic::MESSAGE_SEARCH_FAIL = "There is no task \"%s\" in the schedule.";
const string EasyScheduleLogic::MESSAGE_SORT = "All tasks have been sorted by time.";
const string EasyScheduleLogic::MESSAGE_EMPTY = "The schedule is empty.";
const string EasyScheduleLogic::MESSAGE_INVALID_INPUT_COMMAND = "Invalid command type.";
const string EasyScheduleLogic::MESSAGE_INVALID_INPUT_NAME = "Invalid task.";

char EasyScheduleLogic::buffer[1000];
bool EasyScheduleLogic::isInvalidCommandType = false;
bool EasyScheduleLogic::isInvalidTaskType = false;
CommandParser EasyScheduleLogic::parser;
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

int main () {
	EasyScheduleLogic::main();
}

void EasyScheduleLogic::main() {
	storage.showDirectory();
	string filename;
	cin >> filename;
	storage.setFileName(filename);
	storage.readFile();
	storage.openFile();
	string input;
	cin.ignore();
	getline(cin, input);

	while (input!="exit") {
		executeLogic(input);
		getline(cin, input);
	}
	
	storage.writeToFile();
	
}

void EasyScheduleLogic::executeLogic(string userInput) {
	parsingCommand(userInput);
	if(parser.commandType == "add") {
		creatingTask(); 
		//store task is done in tellUI function.
	} else if (parser.commandType == "delete") {
		//does nothing here. delete being called in tellUI function.
	} else if (parser.commandType == "display") {
		//does nothing here. display being called in tellUI function.
	} else if (parser.commandType == "search") {
		//does nothing here. search being called in tellUI function.
	} else if (parser.commandType == "sort") {
		sortingTask();
	} else if (parser.commandType == "exit") {
		exit(0);
	} else {
		isInvalidCommandType = true;
	}

}

void EasyScheduleLogic::parsingCommand(string userInput) {
	
	parser.identifyTask(userInput);
	commandType = parser.commandType;
	taskType = parser.taskType;
	name = parser.name;
	year = parser.year;
	month = parser.month;
	day = parser.day;
}

void EasyScheduleLogic::creatingTask() {
	if(taskType=="FloatingTask") {
		task = Task(commandType, name);
	} else {
		
		endTimeHour = parser.endTimeHour;
		endTimeMin = parser.endTimeMin;

		if (taskType=="DeadlineTask") {
			
			task = Task(commandType,  name, year, month, day, endTimeHour, endTimeMin);
		} else if (taskType=="TimedTask"){
			startTimeHour = parser.startTimeHour;
			startTimeMin = parser.startTimeMin;
			task = Task(commandType,  name, year, month, day, startTimeHour, startTimeMin, endTimeHour, endTimeMin);
		} else {
			isInvalidTaskType = true; 
		}
	}
}

//identify commandType and required parameters
void EasyScheduleLogic::storingTask() {
	storage.storeTask(task);
}

string EasyScheduleLogic::deletingTask(){
	name = parser.name;
	return storage.deleteByName(name);
}

string EasyScheduleLogic::searchingTask(){
	name = parser.name;
	return storage.searchByName(name);
	
}

string EasyScheduleLogic::displayingTask(){
	return storage.toStringTaskDetail();
}

void EasyScheduleLogic::sortingTask(){
	storage.sortList();
}

//receive bool from storeFloat and create output message
string EasyScheduleLogic::tellUI() {
	if(isInvalidCommandType) {
		isInvalidCommandType = false; //for future uses
		sprintf_s(buffer, MESSAGE_INVALID_INPUT_COMMAND.c_str());
		return buffer;
	}
	if(isInvalidTaskType) {
		isInvalidTaskType = false; //for future uses
		sprintf_s(buffer, MESSAGE_INVALID_INPUT_NAME.c_str());
		return buffer;
	}
	if(commandType=="add") {
		if (!isDuplicate()) {	//Bug: isDuplicate() always returns true regardless of actual situation.
			storingTask(); 
			sprintf_s(buffer, MESSAGE_ADD.c_str());
			return buffer;
		}
		sprintf_s(buffer, MESSAGE_ADD_FAIL.c_str());
		return buffer;
	} else if(commandType == "delete") {
		return deletingTask();
	} else if(commandType == "display") {
		return displayingTask();
	} else if(commandType == "sort") {
		sprintf_s(buffer, MESSAGE_SORT.c_str());
		return buffer;
	} else if (commandType == "search") {
		return searchingTask();
	} 
}


bool EasyScheduleLogic::isDuplicate() {
	return storage.isTaskDuplicate(task);
}

EasyScheduleLogic::EasyScheduleLogic(void) { }

EasyScheduleLogic::~EasyScheduleLogic(void) { }
