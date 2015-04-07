#include "EasyScheduleLogic.h"
#include "Storage.h"
#include <sys/stat.h>
#include <assert.h>
#include <ctime>


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
const string EasyScheduleLogic::MESSAGE_DELETE = "The task has been deleted.";
const string EasyScheduleLogic::MESSAGE_DELETE_FAIL = "There is no task \"%s\" in the schedule.";
const string EasyScheduleLogic::MESSAGE_DELETE_CHOOSE = "Please type 'delete [number]' to delete the task.";
const string EasyScheduleLogic::MESSAGE_EDIT = "The task has been edited";
const string EasyScheduleLogic::MESSAGE_EDIT_FAIL = "There is no such task. Please check from display of all tasks.";
const string EasyScheduleLogic::MESSAGE_CLEAR = "All tasks have been deleted.";
const string EasyScheduleLogic::MESSAGE_SEARCH_FAIL = "There is no task containing the keyword. Please check from display of all tasks.";
const string EasyScheduleLogic::MESSAGE_SORT = "All tasks have been sorted by task type.";
const string EasyScheduleLogic::MESSAGE_MARK_FAIL = "There is no such task. Please check from display of all tasks.";
const string EasyScheduleLogic::MESSAGE_MARK_CHOOSE = "Please type 'done/undone [number]' to change the status of the task.";
const string EasyScheduleLogic::MESSAGE_EMPTY = "The schedule is empty.";
const string EasyScheduleLogic::MESSAGE_INVALID_INPUT_COMMAND = "Invalid command type.";
const string EasyScheduleLogic::MESSAGE_INVALID_INPUT_NAME = "Invalid task.";
const string EasyScheduleLogic::MESSAGE_INVALID_DATE = "Invalid date.";
const string EasyScheduleLogic::MESSAGE_INVALID_NUMBER = "Invalid number, please select from the display.";
const string EasyScheduleLogic::MESSAGE_EXIT = "Program exiting now.";
const string EasyScheduleLogic::MESSAGE_UNDO_FAIL = "Undo fail. End of command history reached.";
const string EasyScheduleLogic::MESSAGE_UNDO_SUCCESS = "Undo successfully.";
const string EasyScheduleLogic::MESSAGE_UNDO_ERROR = "Error occured within undo function.";

string EasyScheduleLogic::returnMessage;
string EasyScheduleLogic::returnDisplay;
int EasyScheduleLogic::returnIndex;
char EasyScheduleLogic::buffer[1000];
//bool EasyScheduleLogic::isInvalidCommandType = false;
bool EasyScheduleLogic::isInvalidTaskType = false;
CommandParser EasyScheduleLogic::parser;
Storage EasyScheduleLogic::storage;
Task EasyScheduleLogic::task;
string EasyScheduleLogic::commandType;
string EasyScheduleLogic::taskType;
string EasyScheduleLogic::name;
int EasyScheduleLogic::taskNumber;
int EasyScheduleLogic::year;
int EasyScheduleLogic::month;
int EasyScheduleLogic::day;
int EasyScheduleLogic::startTimeHour;
int EasyScheduleLogic::startTimeMin;
int EasyScheduleLogic::endTimeHour;
int EasyScheduleLogic::endTimeMin;

int EasyScheduleLogic::localYear;
int EasyScheduleLogic::localMonth;
int EasyScheduleLogic::localDay;
int EasyScheduleLogic::localHour;
int EasyScheduleLogic::localMin;


//
////here
//int main () {
//	EasyScheduleLogic::main();
//}
//
//void EasyScheduleLogic::main() {
//	string pathName;
//	cin >> pathName;
//	storage.setPathName(pathName);
//	string filename;
//	cin >> filename;
//	storage.setFileName(filename);
//	storage.readFile();
//	storage.openFile();
//	string input;
//	cin.ignore();
//	getline(cin, input);
//
//	while (input!="exit") {
//		executeLogic(input);
//		getline(cin, input);
//	}
//	
//	storage.writeToFile();
//	exit(0);
//	
//}
////here
//

void EasyScheduleLogic::executeLogic(string userInput) {
	parsingCommand(userInput);
	if(parser.commandType == "filepath"){
		storage.setPathName(parser.name);
		if (storage.showDirectory()) {
			returnMessage = "Directory opened";
		} else {
			returnMessage = "Directory is not found, please respecify file storage location";
		}
	} else if(parser.commandType == "filename"){
		if (storage._fileName!="") {
			storage.writeToFile();
		}
		storage.setFileName(parser.name);
		storage.readFile();
		storage.openFile();
		returnDisplay = autoDisplay();
		returnMessage = "Program is now ready to be used"; 
		returnIndex = 0;
	} else if (parser.commandType == "add") {
		returnMessage = addingTask();
		returnDisplay = displayingTask();
		if (storage.isSuccess) {
			returnIndex = storage.getIndex();
		} else {
			returnIndex = 0;
		}
	} else if (parser.commandType == "delete") {
		returnDisplay = deletingTask();
		returnIndex = 0;
	} else if (parser.commandType == "display") {
		if (displayingTask() != "") {
			returnMessage = "";
			returnDisplay = displayingTask();
		} else {
			returnMessage = MESSAGE_EMPTY;
			returnDisplay = "";
		}
		returnIndex = 0;
	} else if (parser.commandType == "search") {
		if(searchingTask() == "") {
			returnMessage = MESSAGE_SEARCH_FAIL; //Bug: not shown in feedbackBox
			returnDisplay = displayingTask(); //display all the tasks 
		} else {
			returnMessage = "";
			returnDisplay = searchingTask();
		}
		returnIndex = 0;
	} else if (parser.commandType == "sort") {
		returnMessage = sortingTask();
		returnDisplay = displayingTask();
		returnIndex = 0;
	} else if (parser.commandType == "done") { //mark done/notdone doesn't work.
		returnDisplay = markDone();
		if (storage.isSuccess) {
			returnIndex = storage.getIndex();
		}
		if (parser.name!="") {
			if ((storage._searchResultList).size()==0) {
				returnDisplay = displayingTask();
			}
			if ((storage._searchResultList).size()==1) {
				parser.number=1;
				returnDisplay = markDone();
				returnIndex = storage.getIndex();
			} else {
				returnIndex = 0;
			}
		}
		} else if (commandType == "notdone") {
		returnDisplay = markNotDone();
		if (storage.isSuccess) {
			returnIndex = storage.getIndex();
		}
		if (parser.name!="") {
			if ((storage._searchResultList).size()==0) {
				returnDisplay = displayingTask();
			}
			if ((storage._searchResultList).size()==1) {
				parser.number=1;
				returnDisplay = markNotDone();
				returnIndex = storage.getIndex();
			} else {
				returnIndex = 0;
			}
		} 
	} else if(parser.commandType == "edit"){
		returnDisplay = editingTask();
		returnIndex = 0;
	} else if (parser.commandType == "exit") {
			returnMessage = MESSAGE_EXIT;
			returnDisplay = "";
			storage.writeToFile();
			exit(0);
	} else if (parser.commandType == "undo") { //Bug: for example, undo delete by add: it'll keep adding if I keep calling undo 
		returnMessage = undoingTask();
		returnDisplay = displayingTask();
	} else {
		returnMessage = MESSAGE_INVALID_INPUT_COMMAND;
		returnDisplay = "";
	}
	returnIndex = 0;
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

string EasyScheduleLogic::undoingTask() {
	string message;
	if(storage.getTracker().isEmptyTracker()) {
		message = MESSAGE_UNDO_FAIL;
	}else{
		Record recordToUndo;
		recordToUndo = storage.getTracker().getNewestRecord();
		storage.deleteLastTrackerEntry();
		if(recordToUndo.getCommandType() == "add") {
			if(undoingAdd(recordToUndo)) {
				message = MESSAGE_UNDO_SUCCESS;
			}else{
				message = MESSAGE_UNDO_ERROR;
			}
		}else if(recordToUndo.getCommandType() == "delete") {
			if(undoingDelete(recordToUndo)) {
				message = MESSAGE_UNDO_SUCCESS;
			}else{
				message = MESSAGE_UNDO_ERROR;
			}
		}else if(recordToUndo.getCommandType() == "done") {
			if(undoingDone(recordToUndo)) {
				message = MESSAGE_UNDO_SUCCESS;
			}else{
				message = MESSAGE_UNDO_ERROR;
			}
		}else if(recordToUndo.getCommandType() == "notdone") {
			if(undoingNotDone(recordToUndo)) {
				message = MESSAGE_UNDO_SUCCESS;
			}else{
				message = MESSAGE_UNDO_ERROR;
			}
		}
	}
	return message;
}

//@author A0115131B
bool  EasyScheduleLogic::undoingDone(Record recordToUndo){
	list <Task> listToUndo;
	listToUndo = recordToUndo.getTaskRecord();
	storage.undoingReverseDone(listToUndo);
	return true;
}

bool  EasyScheduleLogic::undoingNotDone(Record recordToUndo){
	list <Task> listToUndo;
	listToUndo = recordToUndo.getTaskRecord();
	storage.undoingReverseNotDone(listToUndo);
	return true;
}

bool EasyScheduleLogic::undoingDelete(Record recordToUndo){
	list <Task> listToUndo;
	listToUndo = recordToUndo.getTaskRecord();
	storage.undoingReverseDelete(listToUndo);
	return true;
}

bool EasyScheduleLogic::undoingAdd(Record recordToUndo){
	//delete the added tasks
	list <Task> listToUndo;
	listToUndo = recordToUndo.getTaskRecord();
	storage.undoingReverseAdd(listToUndo);
	return true;
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
			task = Task(commandType, name, year, month, day, startTimeHour, startTimeMin, endTimeHour, endTimeMin);
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

string EasyScheduleLogic::addingTask(){
	creatingTask(); 
	if(isInvalidTaskType) {
		isInvalidTaskType = false; //for future uses
		return MESSAGE_INVALID_INPUT_NAME;
	} else {
		storingTask();
		if (storage.isSuccess) {
			return MESSAGE_ADD;
		} else { 
			return MESSAGE_ADD_FAIL;
		}
	}
}

string EasyScheduleLogic::deletingTask() {
	if(parser.number == -1) {
		name = parser.name;
		returnMessage = MESSAGE_DELETE_CHOOSE;
		return storage.searchByName(name);
	} else {
		taskNumber = parser.number;
		string s = storage.deleteByNumber(taskNumber);
		if (storage.isSuccess) {
			returnMessage = MESSAGE_DELETE;
		} else {
			returnMessage = MESSAGE_INVALID_NUMBER;
			}
		return s;
	}
}

string EasyScheduleLogic::searchingTask() {
	name = parser.name;
	return storage.searchByName(name);
}

string EasyScheduleLogic::markDone() {
	if (parser.number == -1) {
		name = parser.name;
		returnMessage = MESSAGE_MARK_CHOOSE;
		return storage.searchByName(name);
	} else {
		taskNumber = parser.number;
		string s = storage.markDone(taskNumber);
		if (storage.isSuccess) {
			returnMessage = "";
		} else {
			returnMessage = MESSAGE_INVALID_NUMBER;
			}
		return s;
	}
}

string EasyScheduleLogic::markNotDone() {
	if (parser.number == -1) {
		name = parser.name;
		returnMessage = MESSAGE_MARK_CHOOSE;
		return storage.searchByName(name);
	} else {
		taskNumber = parser.number;
		string s = storage.markNotDone(taskNumber);
		if (storage.isSuccess) {
			returnMessage = "";
		} else {
			returnMessage = MESSAGE_INVALID_NUMBER;
			}
		return s;
	}
}

string EasyScheduleLogic::editingTask(){
	taskNumber = parser.number;
	string s = storage.editTask(taskNumber, parser.name);
	if (storage.isSuccess){
		returnMessage = MESSAGE_EDIT;
	}else{
		returnMessage = MESSAGE_EDIT_FAIL;
	}
	return s;
}

string EasyScheduleLogic::autoDisplay(){
	return storage.toStringTaskDetail(storage.autoInitialDisplay());
}

string EasyScheduleLogic::displayingTask() {
	return storage.toStringTaskDetail();
}

string EasyScheduleLogic::sortingTask() {
	storage.sortList();
	return MESSAGE_SORT;
}

//receive bool from storeFloat and create output message
string EasyScheduleLogic::tellUIReturnMessage() {
	return returnMessage;
}

string EasyScheduleLogic::tellUIDisplay() {
	return returnDisplay;
}

int EasyScheduleLogic::tellUIReturnIndex() {
	return returnIndex;
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

void EasyScheduleLogic::getLocalDateTime(){
	time_t now = time(0);
	struct tm time;
	localtime_s(&time, &now);
	localDay = time.tm_mday;
	localMonth  = time.tm_mon + 1;
	localYear = time.tm_year + 1900;
	localHour = time.tm_hour;
	localMin  = time.tm_min;
}

#ifndef LOGICTEST
Task EasyScheduleLogic::getTask(){
	return task;
}

string EasyScheduleLogic::getCommandType(){
	return commandType;
}
string EasyScheduleLogic::getTaskType(){
	return taskType;
}

string EasyScheduleLogic::getName(){
	return name;
}

int EasyScheduleLogic::getYear(){
	return year;
}

int EasyScheduleLogic::getMonth(){
	return month;
}

int EasyScheduleLogic::getDay(){
	return day;
}

int EasyScheduleLogic::getStartTimeHour(){
	return startTimeHour;
}

int EasyScheduleLogic::getStartTimeMin(){
	return startTimeMin;
}

int EasyScheduleLogic::getEndTimeHour(){
	return endTimeHour;
}

int EasyScheduleLogic::getEndTimeMin(){
	return endTimeMin;
}

#endif

EasyScheduleLogic::EasyScheduleLogic(void) { }

EasyScheduleLogic::~EasyScheduleLogic(void) { }
