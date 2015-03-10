#include "EasyScheduleLogic.h"
#include "Storage.h"

const string EasyScheduleLogic::MESSAGE_WELCOME = "Welcome to EasySchedule!";
const string EasyScheduleLogic::MESSAGE_ADD = "%s has been stored successfully.";
const string EasyScheduleLogic::MESSAGE_ADD_FAIL = "Sorry, the task is already in the schedule.";
const string EasyScheduleLogic::MESSAGE_DELETE = "";
const string EasyScheduleLogic::MESSAGE_DELETE_FAIL = "";
const string EasyScheduleLogic::MESSAGE_CLEAR = "";
const string EasyScheduleLogic::MESSAGE_SEARCH_FAIL = "";
const string EasyScheduleLogic::MESSAGE_SORT = "";
const string EasyScheduleLogic::MESSAGE_EMPTY = "";
const string EasyScheduleLogic::MESSAGE_INVALID_INPUT_COMMAND = "";
const string EasyScheduleLogic::MESSAGE_INVALID_INPUT_NAME = "";

char EasyScheduleLogic::buffer[1000];

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
	storage.openFile();
	storage.readFile();
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
		storingTask(); 
	} else if (parser.commandType == "delete") {
		deletingTask();
	} else if (parser.commandType == "display") {
		displayingTask();
	} else if (parser.commandType == "search") {
		searchingTask();
	} else if (parser.commandType == "sort") {
		sortingTask();
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
		} else {
			startTimeHour = parser.startTimeHour;
			startTimeMin = parser.startTimeMin;
			task = Task(commandType,  name, year, month, day, startTimeHour, startTimeMin, endTimeHour, endTimeMin);
		}
	}
}

//identify commandType and required parameters
void EasyScheduleLogic::storingTask() {
	storage.storeTask(task);
}

void EasyScheduleLogic::deletingTask(){
	name = parser.name;
	storage.deleteByName(name);
}

void EasyScheduleLogic::searchingTask(){
	name = parser.name;
	storage.searchByName(name);
}

string EasyScheduleLogic::displayingTask(){
	return storage.toStringTaskDetail();
}

void EasyScheduleLogic::sortingTask(){
	storage.sortList();
}

//receive bool from storeFloat and create output message
string EasyScheduleLogic::tellUI() {
	if(commandType=="add") {
		if (!isDuplicate()) {
			sprintf_s(buffer, MESSAGE_ADD.c_str(), task.getName().c_str());
			return buffer;
		} else {
			sprintf_s(buffer, MESSAGE_ADD_FAIL.c_str());
			return buffer;
		}
	} else if(commandType == "delete") {

	} else if(commandType == "display") {

	} else if(commandType == "sort") {

	} else if (commandType == "search") {

	}
}


bool EasyScheduleLogic::isDuplicate() {
	return storage.isTaskDuplicate(task);
}

EasyScheduleLogic::EasyScheduleLogic(void) { }

EasyScheduleLogic::~EasyScheduleLogic(void) { }
