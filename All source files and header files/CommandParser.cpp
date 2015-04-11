//@author A0114255N
#include "CommandParser.h"

#include <atltime.h>
#include <math.h>
#include <locale>
#include <ctime>

using namespace std;

const string CommandParser::FILEPATH = "filepath";
const string CommandParser::FILENAME = "filename";
const string CommandParser::FLOATING_TASK = "FloatingTask";
const string CommandParser::DEADLINE_TASK = "DeadlineTask";
const string CommandParser::TIMED_TASK = "TimedTask";

const string CommandParser::ADD = "add";
const string CommandParser::COMMAND_DELETE = "delete";
const string CommandParser::DISPLAY = "display";
const string CommandParser::DONE = "done";
const string CommandParser::EDIT = "edit";
const string CommandParser::EXIT = "exit";
const string CommandParser::NOT_DONE = "notdone";
const string CommandParser::SEARCH = "search";
const string CommandParser::SORT = "sort";
const string CommandParser::UNDO = "undo";
const string CommandParser::VIEW = "view";

const string CommandParser::DATE = "date";
const string CommandParser::NAME = "name";
const string CommandParser::TIME = "time";

string CommandParser::taskType="";
string CommandParser::commandType="";
string CommandParser::name="";
int CommandParser::year=-1;
int CommandParser::month=-1;
int CommandParser::day=-1;
int CommandParser::startTimeHour=-1;
int CommandParser::startTimeMin=-1;
int CommandParser::endTimeHour=-1;
int CommandParser::endTimeMin=-1;
string CommandParser::dayOfWeek;
int CommandParser::dayOfWeekNo;
int CommandParser::number=-1;
string CommandParser::attribute="";
string devider = "/";
size_t pos1;
size_t pos2;
size_t pos3;
size_t pos4;
size_t posD1;
size_t posD2;
size_t posD3;
size_t posD4;
size_t posD5;
size_t posD6;
size_t posD7;
int dayToAdd;


void CommandParser::addTimeDeadline(string userInput){
	taskType = DEADLINE_TASK;
	startTimeHour = 0;
	startTimeMin = 0;
	endTimeHour = stoi(userInput.substr(posD1+1, (posD2-posD1)));
	endTimeMin = stoi(userInput.substr(posD2+1, (posD3-posD2)));
}

void CommandParser::addTimeTimedTask(string userInput){
	taskType = TIMED_TASK;
	startTimeHour = stoi(userInput.substr(posD1+1, (posD2-posD1)));
	startTimeMin = stoi(userInput.substr(posD2+1, (posD3-posD2)));
	endTimeHour = stoi(userInput.substr(posD3+1, (posD4-posD3)));
	endTimeMin = stoi(userInput.substr(posD4+1, (posD5-posD4)));
}

void CommandParser::normalAddDate(string userInput){
	year = stoi(userInput.substr(pos1+1, (posD1-pos1)));
	month = stoi(userInput.substr(posD1+1, (posD2-posD1)));
	day =  stoi(userInput.substr(posD2+1, (posD3-posD2)));
}

void CommandParser::getDayOfWeekNo(string dayOfWeek){
	transform(dayOfWeek.begin(), dayOfWeek.end(), dayOfWeek.begin(), ::tolower);
	if (dayOfWeek == "monday" || dayOfWeek == "mon"){
		dayOfWeekNo = 1;
	} else if (dayOfWeek == "tuesday" || dayOfWeek == "tue"){
		dayOfWeekNo = 2;
	} else if (dayOfWeek == "wednesday" || dayOfWeek =="wed"){
		dayOfWeekNo = 3;
	} else if (dayOfWeek == "thursday" || dayOfWeek =="thu"){
		dayOfWeekNo = 4;
	} else if (dayOfWeek == "friday" || dayOfWeek =="fri"){
		dayOfWeekNo = 5;
	} else if (dayOfWeek == "saturday" || dayOfWeek =="sat"){
		dayOfWeekNo = 6;
	} else if (dayOfWeek == "sunday" || dayOfWeek =="sun"){
		dayOfWeekNo = 0;
	}
}

void CommandParser::getDayToAdd(int localWeekday){
	if (localWeekday > dayOfWeekNo){
		dayToAdd = 7 - abs(dayOfWeekNo - localWeekday);
	} else {
		dayToAdd = dayOfWeekNo - localWeekday;
	}
}

void CommandParser::setTodayDate(){
	time_t now = time(0);	
	struct tm time;
	localtime_s(&time, &now);
	day =  time.tm_mday;
	month = time.tm_mon + 1;
	year = time.tm_year + 1900;
}

void CommandParser::setTomorrowDate(){
	time_t now = time(0);	
	struct tm time;
	localtime_s(&time, &now);
	time.tm_mday += 1;
	mktime(&time);
	day =  time.tm_mday;
	month = time.tm_mon + 1;
	year = time.tm_year + 1900;
}

void CommandParser::setDayDate(){
	dayOfWeekNo = 0;
	getDayOfWeekNo(dayOfWeek);

	time_t now = time(0);	
	dayToAdd = 0;
	struct tm time;
	localtime_s(&time, &now);
	getDayToAdd(time.tm_wday);
	time.tm_mday =  time.tm_mday + dayToAdd;

	mktime(&time);
	day = time.tm_mday;
	month = time.tm_mon + 1;
	year = time.tm_year + 1900;
}

void CommandParser::easyAddDate(string userInput){
	string todayOrTomorrow = userInput.substr(pos1+1, (posD1-pos1-1));
	transform(todayOrTomorrow.begin(), todayOrTomorrow.end(), todayOrTomorrow.begin(), ::tolower);
	
	if (todayOrTomorrow == "today"){
		setTodayDate();
	} else if (todayOrTomorrow == "tomorrow"){
		setTomorrowDate();	
	} else {
		dayOfWeek = userInput.substr(pos1+1, (posD1-pos1-1));
		setDayDate();
	}
}

void CommandParser::setDevider(string userInput){
	devider = ' ';
	pos1 = userInput.find(devider);
	pos2 = userInput.find(devider, pos1+1);
	pos3 = userInput.find(devider, pos2+1);
	pos4 = userInput.find(devider, pos3+1);

	devider = '/';
	posD1 = userInput.find(devider);
	posD2 = userInput.find(devider, posD1+1);
	posD3 = userInput.find(devider, posD2+1);
	posD4 = userInput.find(devider, posD3+1);
	posD5 = userInput.find(devider, posD4+1);
	posD6 = userInput.find(devider, posD5+1);
	posD7 = userInput.find(devider, posD6+1);
}

void CommandParser::extractCommandType(string userInput){
	setDevider(userInput);
	commandType = userInput.substr(0, pos1);
	transform(commandType.begin(), commandType.end(), commandType.begin(), ::tolower);
}

bool isFloating(){
	if(posD1 == string::npos){
		return true;
	} else {
		return false;
	}
}

bool isUsingEasyAdd(string userInput){
	if(isalpha(userInput.at(pos1+1))){
		return true;
	} else {
		return false;
	}
}

bool isAddingDeadlineTask(){
	if (posD4 == string::npos){
		return true;
	} else {
		return false;
	}
}

void CommandParser::easyAdd(string userInput){
	easyAddDate(userInput);

	if(isAddingDeadlineTask()) {
		addTimeDeadline(userInput);
		name = userInput.substr(posD3+1);
	} else {
		addTimeTimedTask(userInput);
		name = userInput.substr(posD5+1);
	}	
}

void CommandParser::normalAdd(string userInput){
	normalAddDate(userInput);
	string cutInput = userInput.substr(posD3);
	setDevider(cutInput);
	if(isAddingDeadlineTask()) {
		addTimeDeadline(cutInput);
		name = cutInput.substr(posD3+1);
	} else {
		addTimeTimedTask(cutInput);
		name = cutInput.substr(posD5+1);
	}	
}

bool isByName(string userInput){
	if(isalpha(userInput.at(pos1+1))){
		return true;
	} else {
		return false;
	}
}

void CommandParser::addingTask(string userInput){
	if(isFloating()) {
		taskType = FLOATING_TASK;
		name = userInput.substr(3);
		return;
	} else {
		if (isUsingEasyAdd(userInput)){
			easyAdd(userInput);
		} else {
			normalAdd(userInput);
		}	
	}
}

void CommandParser::executeByNumberOrName(string userInput){
	if (isByName(userInput)) {
		name = userInput.substr(pos1+1);
		number = -1;
	} else {
		number = stoi(userInput.substr(pos1+1));
	}
}

void CommandParser::editName(string userInput){
	name = userInput.substr(pos3+1);
}

void CommandParser::editDate(string userInput){
	//userInput == edit 3 date ......
	string cutInput = userInput.substr(pos2+1);
	//cutInput == date .....
	setDevider(cutInput);
	
	if ((isUsingEasyAdd(cutInput) && posD1==string::npos) || (!isUsingEasyAdd(cutInput) && posD3==string::npos)){
		if(isUsingEasyAdd(cutInput)){
				easyAddDate(cutInput);
			} else{
				normalAddDate(cutInput);
			}
	} else {
		editFloatDateTime(cutInput);
	}
}

void CommandParser::editFloatDateTime(string cutInput){
	if(isUsingEasyAdd(cutInput)){
		easyAddDate(cutInput);
		if(posD3 == string::npos) {
			addTimeDeadline(cutInput);
			taskType = FLOATING_TASK;
			return;
		} else {
			addTimeTimedTask(cutInput);
			taskType = FLOATING_TASK;
			return;
		}	

	} else{
		normalAddDate(cutInput);
		string cutInput2 = cutInput.substr(posD3);
		setDevider(cutInput2);
		if(posD3 == string::npos) {
			addTimeDeadline(cutInput2);
			taskType = FLOATING_TASK;
		} else {
			addTimeTimedTask(cutInput2);
			taskType = FLOATING_TASK;
		}	
	}
}

void CommandParser::editTime(string userInput){
	string cutInput = userInput.substr(pos2+1);
	//cutInput == time ....
	setDevider(cutInput);

	if (!isUsingEasyAdd(cutInput) && posD4==string::npos){
		string cutInput2 = cutInput.substr(pos1+1);
		cutInput2 = '/' + cutInput2; // so we can use the addTimeDeadline or addTimeTimedTask
		setDevider(cutInput2);
		if(posD3 == string::npos){
			addTimeDeadline(cutInput2);
		} else {
			addTimeTimedTask(cutInput2);
		}
	} else {
		editFloatDateTime(cutInput);
	} 
}

void CommandParser::editingTask(string userInput){
	setDevider(userInput);
	number = stoi(userInput.substr(pos1+1, pos2-pos1-1));
	attribute = userInput.substr(pos2+1, pos3-pos2-1);
	transform(attribute.begin(), attribute.end(), attribute.begin(), ::tolower);
		
	if (attribute == NAME){
		editName(userInput);
	} else if (attribute == DATE){
		editDate(userInput);
	} else if (attribute == TIME){
		editTime(userInput);	
	}
}

void CommandParser::identifyTask(string userInput) {
	
	extractCommandType(userInput);
	
		if(commandType == FILEPATH){
			name = userInput.substr(pos1+1);
		} else if(commandType == FILENAME){
			name = userInput.substr(pos1+1);
		} else if(commandType == ADD){
			addingTask(userInput);
		} else if (commandType == COMMAND_DELETE || commandType == DONE || commandType == NOT_DONE || commandType == SEARCH) {
			executeByNumberOrName(userInput);
		} else if (commandType == SORT || commandType == DISPLAY || commandType == UNDO) {
			return;
		} else if (commandType == EDIT){
			editingTask(userInput);
		} else if (commandType == VIEW){
			viewTask(userInput);
		} else if (commandType == EXIT) {
			return;
		} 
	
}

void CommandParser::viewTask(string userInput){
	name = userInput.substr(pos1+1);
	transform(name.begin(), name.end(), name.begin(), ::tolower);
}

string CommandParser::getCommandType() {
	return commandType;
}

string CommandParser::getTaskType() {
	return taskType;
}

string CommandParser::getDate() {
	stringstream s;
	s << year << "/" << month << "/" << day;
	return s.str();
}

string CommandParser::getName() {
	return  name;
}

int CommandParser::getEndTimeHour() {
	return endTimeHour;
}

int CommandParser::getEndTimeMin() {
	return endTimeMin;
}

int CommandParser::getStartTimeHour() {
	return startTimeHour;
}

int CommandParser::getStartTimeMin() {
	return startTimeMin;
}

int CommandParser::getYear(){
	return year;
}

CommandParser::CommandParser(void) { }

CommandParser::~CommandParser(void) { }
