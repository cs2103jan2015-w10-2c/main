#include "EasyScheduleLogic.h"
#include "Storage.h"
#include <sys/stat.h>
#include <assert.h>


const int EasyScheduleLogic::MIN_MONTHS_IN_A_YEAR = 1;
const int EasyScheduleLogic::MAX_MONTHS_IN_A_YEAR = 12;
const int EasyScheduleLogic::MIN_DAY_IN_A_MONTH = 1;
const int EasyScheduleLogic::MAX_DAYS_IN_A_MONTH[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int EasyScheduleLogic::MIN_HOURS_IN_A_DAY = 0;
const int EasyScheduleLogic::MAX_HOURS_IN_A_DAY = 23;
const int EasyScheduleLogic::MIN_MINUTES_IN_AN_HOUR = 0;
const int EasyScheduleLogic::MAX_MINUTES_IN_AN_HOUR = 59;

const int EasyScheduleLogic::SHIFT_BY_ONE = 1;

const string EasyScheduleLogic::FLOATING_TASK = "FloatingTask";
const string EasyScheduleLogic::DEADLINE_TASK = "DeadlineTask";
const string EasyScheduleLogic::TIMED_TASK = "TimedTask";

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
const string EasyScheduleLogic::MESSAGE_INVALID_DATE = "Invalid date.";

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
	} else if (parser.commandType == "mark") {
		//does nothing here. mark being called in tellUI function.
	}else if (parser.commandType == "sort") {
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
	if(taskType == FLOATING_TASK) {
		task = Task(commandType, name);	
	} else {
		
		endTimeHour = parser.endTimeHour;
		endTimeMin = parser.endTimeMin;

		if (taskType == DEADLINE_TASK) {
			
			task = Task(commandType,  name, year, month, day, endTimeHour, endTimeMin);
		} else if (taskType == TIMED_TASK){
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

string EasyScheduleLogic::deletingTask() {
	name = parser.name;
	return storage.deleteByName(name);
}

string EasyScheduleLogic::searchingTask() {
	name = parser.name;
	return storage.searchByName(name);
	
}

string EasyScheduleLogic::markDone() {
	name = parser.name;
	return storage.markDone(name);
}

string EasyScheduleLogic::markNotDone() {
	name = parser.name;
	return storage.markNotDone(name);
}

string EasyScheduleLogic::displayingTask() {
	return storage.toStringTaskDetail();
}

void EasyScheduleLogic::sortingTask() {
	storage.sortList();
}

//receive bool from storeFloat and create output message
string EasyScheduleLogic::tellUI() {
if(isInvalidCommandType) {
		isInvalidCommandType = false; //for future uses
		sprintf_s(buffer, MESSAGE_INVALID_INPUT_COMMAND.c_str());
		return buffer;
	}
	else if(isInvalidTaskType) {
		isInvalidTaskType = false; //for future uses
		sprintf_s(buffer, MESSAGE_INVALID_INPUT_NAME.c_str());
		return buffer;
	}
	else if(commandType=="add") {
		if (!isDuplicate() && isValidDate()) {	
			storingTask(); 
			return displayingTask();
		}
		else if(isDuplicate()) {
			sprintf_s(buffer, MESSAGE_ADD_FAIL.c_str());
			return buffer;
		}
		else if(!isValidDate()) {
			sprintf_s(buffer, MESSAGE_INVALID_DATE.c_str());
			return buffer;
		}
	} else if(commandType == "delete") {
		return deletingTask();
	} else if(commandType == "display") {
		return displayingTask();
	} else if(commandType == "sort") {
		return displayingTask();
	} else if (commandType == "search") {
		return searchingTask();
	} else if (commandType == "done") { //mark done? mark not done?
		return markNotDone();
	} else if (commandType == "notdone") { //mark notdone? mark done?
		return markDone();
	} else {
		return "";
	}
}


bool EasyScheduleLogic::isDuplicate() {
	return storage.isTaskDuplicate(task);
}

bool EasyScheduleLogic::isValidDate(){
	if (taskType == FLOATING_TASK){
		return true;
	}
	else if(taskType == TIMED_TASK){
		if(month < MIN_MONTHS_IN_A_YEAR || month > MAX_MONTHS_IN_A_YEAR){
			return false;	
		}
		else if(day < MIN_DAY_IN_A_MONTH || day > MAX_DAYS_IN_A_MONTH[month - SHIFT_BY_ONE]){
			return false;
		}
		else if(startTimeHour < MIN_HOURS_IN_A_DAY || startTimeHour > MAX_HOURS_IN_A_DAY){
			return false;
		}
		else if(startTimeMin < MIN_MINUTES_IN_AN_HOUR || startTimeMin > MAX_MINUTES_IN_AN_HOUR){
			return false;
		}
		else if(endTimeHour < MIN_HOURS_IN_A_DAY || endTimeHour > MAX_HOURS_IN_A_DAY){
			return false;
		}
		else if(endTimeMin < MIN_MINUTES_IN_AN_HOUR || endTimeMin > MAX_MINUTES_IN_AN_HOUR){
			return false;
		}
	}
	else if(taskType == DEADLINE_TASK){
		if(month < MIN_MONTHS_IN_A_YEAR || month > MAX_MONTHS_IN_A_YEAR){
			return false;	
		}
		else if(day < MIN_DAY_IN_A_MONTH || day > MAX_DAYS_IN_A_MONTH[month - SHIFT_BY_ONE]){
			return false;
		}
		else if(endTimeHour < MIN_HOURS_IN_A_DAY || endTimeHour > MAX_HOURS_IN_A_DAY){
			return false;
		}
		else if(endTimeMin < MIN_MINUTES_IN_AN_HOUR || endTimeMin > MAX_MINUTES_IN_AN_HOUR){
			return false;
		}
	}
}

EasyScheduleLogic::EasyScheduleLogic(void) { }

EasyScheduleLogic::~EasyScheduleLogic(void) { }
