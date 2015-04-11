#include "EasyScheduleLogic.h"
#include "Storage.h"
#include <sys/stat.h>
#include <assert.h>
#include <ctime>

const string EasyScheduleLogic::FLOATING_TASK = "FloatingTask";
const string EasyScheduleLogic::DEADLINE_TASK = "DeadlineTask";
const string EasyScheduleLogic::TIMED_TASK = "TimedTask";

const string EasyScheduleLogic::MESSAGE_WELCOME = "Welcome to EasySchedule!";
const string EasyScheduleLogic::MESSAGE_DIRECTORY_OPENED = "Directory opened";
const string EasyScheduleLogic::MESSAGE_DIRECTORY_NOT_FOUND = "Directory is not found, please respecify file storage location";
const string EasyScheduleLogic::MESSAGE_PROGRAM_READY = "Program is now ready to be used";
const string EasyScheduleLogic::MESSAGE_FILE_ERROR = "Specified file is incompatible, please enter a new file name";
const string EasyScheduleLogic::MESSAGE_ADD = "The task has been stored successfully.";
const string EasyScheduleLogic::MESSAGE_ADD_FAIL = "Sorry, the task is already in the schedule.";
const string EasyScheduleLogic::MESSAGE_DELETE = "The task has been deleted.";
const string EasyScheduleLogic::MESSAGE_DELETE_FAIL = "There is no task \"%s\" in the schedule.";
const string EasyScheduleLogic::MESSAGE_DELETE_CHOOSE = "Please enter 'delete [index]' to delete the task.";
const string EasyScheduleLogic::MESSAGE_EDIT = "The task has been edited";
const string EasyScheduleLogic::MESSAGE_EDIT_FAIL = "There is no such task. Please check from display of all tasks.";
const string EasyScheduleLogic::MESSAGE_EDIT_INPUT_ERROR = "Invalid edit format.";
const string EasyScheduleLogic::MESSAGE_CLEAR = "All tasks have been deleted.";
const string EasyScheduleLogic::MESSAGE_SEARCH_FAIL = "There is no task containing the keyword. Please check from display of all tasks.";
const string EasyScheduleLogic::MESSAGE_SORT = "All tasks have been sorted by task type.";
const string EasyScheduleLogic::MESSAGE_MARK_FAIL = "There is no such task. Please check from display of all tasks.";
const string EasyScheduleLogic::MESSAGE_MARK_CHOOSE = "Please enter 'done/notdone [index]' to change the status of the task.";
const string EasyScheduleLogic::MESSAGE_EMPTY = "The schedule is empty.";
const string EasyScheduleLogic::MESSAGE_INVALID_INPUT_COMMAND = "Invalid command type.";
const string EasyScheduleLogic::MESSAGE_INVALID_INPUT_NAME = "Invalid task.";
const string EasyScheduleLogic::MESSAGE_INVALID_DATE = "Invalid date.";
const string EasyScheduleLogic::MESSAGE_INVALID_TIME = "Invalid time.";
const string EasyScheduleLogic::MESSAGE_INVALID_NUMBER = "Invalid number, please select from the display.";
const string EasyScheduleLogic::MESSAGE_EXIT = "Program exiting now.";
const string EasyScheduleLogic::MESSAGE_UNDO_FAIL = "Undo fail. End of command history reached.";
const string EasyScheduleLogic::MESSAGE_UNDO_SUCCESS = "Undo successfully.";
const string EasyScheduleLogic::MESSAGE_UNDO_ERROR = "Error occured within undo function.";
const string EasyScheduleLogic::MESSAGE_EMPTY_DEADLINE = "There is no deadline task stored";
const string EasyScheduleLogic::MESSAGE_EMPTY_FLOATING = "There is no floating task stored";
const string EasyScheduleLogic::MESSAGE_EMPTY_TIMED = "There is no deadline task stored";
const string EasyScheduleLogic::MESSAGE_EMPTY_TODAY = "There is no task stored for today";
const string EasyScheduleLogic::MESSAGE_EMPTY_TOMORROW = "There is no task stored for tomorrow";
const string EasyScheduleLogic::MESSAGE_EMPTY_YESTERDAY = "There is no task stored for yesterday";
const string EasyScheduleLogic::MESSAGE_VIEW_DEADLINE_ALL = "All deadline tasks";
const string EasyScheduleLogic::MESSAGE_VIEW_FLOATING_ALL = "All floating tasks";
const string EasyScheduleLogic::MESSAGE_VIEW_TIMED_ALL = "All timed tasks";
const string EasyScheduleLogic::MESSAGE_VIEW_TODAY_ALL = "All today's tasks";
const string EasyScheduleLogic::MESSAGE_VIEW_TOMORROW_ALL = "All tomorrow's tasks";
const string EasyScheduleLogic::MESSAGE_VIEW_YESTERDAY_ALL = "All yesterday's tasks";


string EasyScheduleLogic::returnMessage;
string EasyScheduleLogic::returnDisplay;
int EasyScheduleLogic::returnIndex;
char EasyScheduleLogic::buffer[1000];
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

//@author A0111446
void EasyScheduleLogic::commandFilePath(){
	storage.setPathName(parser.name);
		if (storage.isValidDirectory()) {
			returnMessage = MESSAGE_DIRECTORY_OPENED;
		} else {
			returnMessage = MESSAGE_DIRECTORY_NOT_FOUND;
		}
}

void EasyScheduleLogic::commandFileName(){
	if (storage._fileName!="") {
			storage.writeToFile();
		}
		storage.setFileName(parser.name);
		storage.readFile();
		if (storage.isSuccess) {
			storage.openFile();
			returnDisplay = autoDisplay();
			returnMessage = MESSAGE_PROGRAM_READY; 
		} else {
			returnMessage = MESSAGE_FILE_ERROR;
		}
		returnIndex = 0;
}

void EasyScheduleLogic::writeFile() {
	storage.openFile();
	storage.writeToFile();
}

//@author A0115131B
void EasyScheduleLogic::viewDeadline(){
	returnDisplay = displayAllDeadline();
	if(displayAllDeadline() == ""){
		returnMessage = MESSAGE_EMPTY_DEADLINE;
	}else {
		returnMessage = MESSAGE_VIEW_DEADLINE_ALL;
	}
}

void EasyScheduleLogic::viewFloating(){
		returnDisplay = displayAllFloating();
		if(displayAllFloating() == ""){
			returnMessage = MESSAGE_EMPTY_FLOATING;
		}else {
			returnMessage = MESSAGE_VIEW_FLOATING_ALL;
		}
}

void EasyScheduleLogic::viewTimed(){
		returnDisplay = displayAllTimed();
		if(displayAllTimed() == ""){
			returnMessage = MESSAGE_EMPTY_TIMED;			
		}else {
			returnMessage = MESSAGE_VIEW_TIMED_ALL;
		}
}

void EasyScheduleLogic::viewToday(){
		returnDisplay = displayAllToday();
		if(displayAllToday() == ""){
			returnMessage = MESSAGE_EMPTY_TODAY;
		}else {
			returnMessage = MESSAGE_VIEW_TODAY_ALL;
		}
}

void EasyScheduleLogic::viewTomorrow(){
		returnDisplay = displayAllTomorrow();
		if(displayAllTomorrow() == ""){
			returnMessage = MESSAGE_EMPTY_TOMORROW;
		}else {
			returnMessage = MESSAGE_VIEW_TOMORROW_ALL;
		}
}

void EasyScheduleLogic::viewYesterday(){
	returnDisplay = displayAllYesterday();
		if(displayAllYesterday() == ""){
			returnMessage = MESSAGE_EMPTY_YESTERDAY;
		}else {
			returnMessage = MESSAGE_VIEW_YESTERDAY_ALL;
		}
}

//@author A0115131B
void EasyScheduleLogic::commandView(){
	if(parser.name == "deadline"){
			viewDeadline();
		} else if(parser.name == "floating"){
			viewFloating();
		} else if(parser.name == "timed"){
			viewTimed();
		} else if(parser.name == "today"){
			viewToday();
		} else if(parser.name == "tomorrow"){
			viewTomorrow();
		} else if(parser.name == "yesterday"){
			viewYesterday();
		}
}

//peisen
void EasyScheduleLogic::commandAdd(){
	returnMessage = addingTask();
		returnDisplay = displayingTask();
		if (storage.isSuccess) {
			returnIndex = storage.getIndex();
		} else {
			returnIndex = 0;
		}
}


//@author Peisen?
void EasyScheduleLogic::commandDelete(){
	returnDisplay = deletingTask();
	returnIndex = 0;
}

void EasyScheduleLogic::commandDisplay(){
	if (displayingTask() != "") {
			returnMessage = "";
			returnDisplay = displayingTask();
		} else {
			returnMessage = MESSAGE_EMPTY;
			returnDisplay = "";
		}
		returnIndex = 0;
}

void EasyScheduleLogic::commandSearch(){
	if(searchingTask() == "") {
		returnMessage = MESSAGE_SEARCH_FAIL; //Bug: not shown in feedbackBox
		returnDisplay = displayingTask(); //display all the tasks 
	} else {
		returnMessage = "";
		returnDisplay = searchingTask();
	}
	returnIndex = 0;
}

void EasyScheduleLogic::commandSort(){
	returnMessage = sortingTask();
	returnDisplay = displayingTask();
	returnIndex = 0;
}

void EasyScheduleLogic::commandDone(){
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
		}
	} else {
		returnIndex = 0;
	}
}

void EasyScheduleLogic::commandNotDone(){
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
}

void EasyScheduleLogic::commandEdit(){
	returnDisplay = editingTask();
	returnIndex = storage.getIndex();
}

void EasyScheduleLogic::commandUndo(){
	returnMessage = undoingTask();
	returnDisplay = displayingTask();
}

void EasyScheduleLogic::commandExit(){
	returnMessage = MESSAGE_EXIT;
	returnDisplay = "";
	exit(0);
}
 void EasyScheduleLogic::commandInvalid(){
	 	returnMessage = MESSAGE_INVALID_INPUT_COMMAND;
		returnDisplay = displayingTask();
 }

 //@author A0115131B
void EasyScheduleLogic::executeLogic(string userInput) {
	parsingCommand(userInput);
	returnIndex = 0;
	if(parser.commandType == "filepath"){
		commandFilePath();
	} else if(parser.commandType == "filename"){
		commandFileName();
	} else if (parser.commandType == "add") {
		commandAdd();
	} else if (parser.commandType == "view"){
		commandView();
	} else if (parser.commandType == "delete") {
		commandDelete();
	} else if (parser.commandType == "display") {
		commandDisplay();
	} else if (parser.commandType == "search") {
		commandSearch();
	} else if (parser.commandType == "sort") {
		commandSort();
	} else if (parser.commandType == "done") {
		commandDone();
	} else if (commandType == "notdone") {
		commandNotDone();
	} else if(parser.commandType == "edit"){
		commandEdit();
	} else if (parser.commandType == "exit") {
		commandExit();
	} else if (parser.commandType == "undo") {  
		commandUndo();
	} else {
		commandInvalid();
	}
	if (storage.isSuccess) {
		writeFile();
	}
}

//@author A0114255N
void EasyScheduleLogic::parsingCommand(string userInput) {
	
	parser.identifyTask(userInput);
	commandType = parser.commandType;
	taskType = parser.taskType;
	name = parser.name;
	year = parser.year;
	month = parser.month;
	day = parser.day;
}

 //@author A0115131B
string EasyScheduleLogic::callUndoingAdd(Record recordToUndo){
		if(undoingAdd(recordToUndo)) {
			return MESSAGE_UNDO_SUCCESS;
		}else{
			return MESSAGE_UNDO_ERROR;
		}
}

string EasyScheduleLogic::callUndoingDelete(Record recordToUndo){
	if(undoingDelete(recordToUndo)) {
		return MESSAGE_UNDO_SUCCESS;
	}else{
			return MESSAGE_UNDO_ERROR;
	}
}

string EasyScheduleLogic::callUndoingDone(Record recordToUndo){
	if(undoingDone(recordToUndo)) {
		return MESSAGE_UNDO_SUCCESS;
	}else{
			return MESSAGE_UNDO_ERROR;
	}
}

string EasyScheduleLogic::callUndoingNotDone(Record recordToUndo){
	if(undoingNotDone(recordToUndo)) {
		return MESSAGE_UNDO_SUCCESS;
	}else{
		return MESSAGE_UNDO_ERROR;
	}
}

string EasyScheduleLogic::callUndoingEdit(Record recordToUndo){
	if(undoingEdit(recordToUndo)){
		return MESSAGE_UNDO_SUCCESS;
	}else{
		return MESSAGE_UNDO_ERROR;
	}
}

Record EasyScheduleLogic::getLastRecord(){
	Record recordToUndo;
	recordToUndo = storage.getTracker().getNewestRecord();
	storage.deleteLastTrackerEntry();

	return recordToUndo;
}

//@author A0115131B
string EasyScheduleLogic::undoingTask() {
	string message;

	try{
		if(storage.getTracker().isEmptyTracker()) {
			throw 0;
		}
	}
	catch(int& e){
		message = MESSAGE_UNDO_FAIL;
		return message;
	}

	Record recordToUndo;
	recordToUndo = getLastRecord();

	if(recordToUndo.getCommandType() == "add") {
		message = callUndoingAdd(recordToUndo);
	}else if(recordToUndo.getCommandType() == "delete") {
		message = callUndoingDelete(recordToUndo);
	}else if(recordToUndo.getCommandType() == "done") {
		message = callUndoingDone(recordToUndo);
	}else if(recordToUndo.getCommandType() == "notdone") {
		message = callUndoingNotDone(recordToUndo);
	}else if(recordToUndo.getCommandType() == "edit"){
		message = callUndoingEdit(recordToUndo);
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

bool EasyScheduleLogic::undoingEdit(Record recordToUndo){
	//undo the edit action
	list <Task> listToUndo;
	listToUndo = recordToUndo.getTaskRecord();
	storage.undoingReverseEdit(listToUndo);
	return true;
}

//@author A0114255N
void EasyScheduleLogic::creatingTask() {
	if(taskType == FLOATING_TASK) {
		task = Task(commandType, name);
		if((task.getName()).find_first_not_of(' ') != std::string::npos){
			isInvalidTaskType = false;
		} else {
			isInvalidTaskType = true;	
		}
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

string EasyScheduleLogic::addingTask(){
	creatingTask(); 
	if(isInvalidTaskType) {
		isInvalidTaskType = false; //for future uses
		return MESSAGE_INVALID_INPUT_NAME;
	} else {
		storingTask();
		if (!storage.isDateValid){
			return MESSAGE_INVALID_DATE;
		} else if(!storage.isTimeValid){
			return MESSAGE_INVALID_TIME;
		} else if (!storage.isSuccess){
			return MESSAGE_ADD_FAIL;
		} else {
			return MESSAGE_ADD;
		}
	}
}

//@author A0111446R
void EasyScheduleLogic::storingTask() {
	storage.storeTask(task);
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

//@author A0114255N
string EasyScheduleLogic::editingTask(){
	taskNumber = parser.number;
	string s;
	if (parser.attribute == "name"){
		s = storage.editTaskName(taskNumber, parser.name);
	} else if (parser.attribute == "date"){
		if(parser.taskType == FLOATING_TASK){
			s = storage.editTaskDateTime(taskNumber, parser.year, parser.month, parser.day,parser.startTimeHour, parser.startTimeMin, parser.endTimeHour, parser.endTimeMin);
		} else {
			s = storage.editTaskDate(taskNumber, parser.year, parser.month, parser.day);
		}
	} else if (parser.attribute == "time"){
		if(parser.taskType == FLOATING_TASK){
			s = storage.editTaskDateTime(taskNumber, parser.year, parser.month, parser.day,parser.startTimeHour, parser.startTimeMin, parser.endTimeHour, parser.endTimeMin);
		} else {
			s = storage.editTaskTime(taskNumber,parser.startTimeHour, parser.startTimeMin, parser.endTimeHour, parser.endTimeMin);
		}
	} else{
		returnMessage = MESSAGE_EDIT_INPUT_ERROR;
		return (s = displayingTask());
	}

	if (!storage.isDateValid){
			returnMessage = MESSAGE_INVALID_DATE;
		} else if(!storage.isTimeValid){
			returnMessage = MESSAGE_INVALID_TIME;
		} else if (!storage.isSuccess){
			returnMessage = MESSAGE_EDIT_FAIL;
		} else {
			returnMessage = MESSAGE_EDIT;
		}
	return s;
}


//@author A0115131B
string EasyScheduleLogic::displayAllDeadline(){
	return storage.toStringTaskDetail(storage.allDeadline());
}

string EasyScheduleLogic::displayAllFloating(){
	return storage.toStringTaskDetail(storage.allFloating());
}

string EasyScheduleLogic::displayAllTimed(){
	return storage.toStringTaskDetail(storage.allTimed());
}

string EasyScheduleLogic::displayAllToday(){
	return storage.toStringTaskDetail(storage.allToday());
}

string EasyScheduleLogic::displayAllTomorrow(){
	return storage.toStringTaskDetail(storage.allTomorrow());
}

string EasyScheduleLogic::displayAllYesterday(){
	return storage.toStringTaskDetail(storage.allYesterday());
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

//peisen
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
	return storage.isExistingTask(task);
}

//@author A0114255N
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
