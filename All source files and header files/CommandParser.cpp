#include "CommandParser.h"

#include <atltime.h>
#include <math.h>
#include <locale>
#include <ctime>

using namespace std;

//string CommandParser::userInput;

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

void CommandParser::addTimeDeadline(string userInput){
	taskType = "DeadlineTask";
	endTimeHour = stoi(userInput.substr(posD1+1, (posD2-posD1)));
	endTimeMin = stoi(userInput.substr(posD2+1, (posD3-posD2)));
}

void CommandParser::addTimeTimedTask(string userInput){
	taskType = "TimedTask";
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

void CommandParser::easyAddDate(string userInput){
	if (userInput.substr(pos1+1, (posD1-pos1-1)) == "today"){

				time_t now = time(0);	
				struct tm time;
				localtime_s(&time, &now);
				day =  time.tm_mday;
				month = time.tm_mon + 1;
				year = time.tm_year + 1900;
			}	
			else if (userInput.substr(pos1+1, (posD1-pos1-1)) == "tomorrow"){
				time_t now = time(0);	
				struct tm time;
				localtime_s(&time, &now);
				time.tm_mday += 1;
				mktime(&time);
				day =  time.tm_mday;
				month = time.tm_mon + 1;
				year = time.tm_year + 1900;
			} else {
				dayOfWeek = userInput.substr(pos1+1, (posD1-pos1-1));
				int dayOfWeekNo = 0;
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

				time_t now = time(0);	
				int dayToAdd = 0;
				struct tm time;
				localtime_s(&time, &now);
			
				if (time.tm_wday > dayOfWeekNo){
					dayToAdd = 7 - abs(dayOfWeekNo - time.tm_wday);
				} else {
					dayToAdd = dayOfWeekNo - time.tm_wday;
				}
				
				time.tm_mday =  time.tm_mday + dayToAdd;
				
				mktime(&time);
				day = time.tm_mday;
				month = time.tm_mon + 1;
				year = time.tm_year + 1900;
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

void CommandParser::identifyTask(string userInput) {

	setDevider(userInput);

	commandType = userInput.substr(0, pos1);

	//convert all letters in the commandType to lower case
	transform(commandType.begin(), commandType.end(), commandType.begin(), ::tolower);
	assert(commandType != "");

	if(commandType == "filepath"){
		name = userInput.substr(pos1+1);
		return;
	}else if(commandType == "filename"){
		name = userInput.substr(pos1+1);
		return;
	}else if(commandType == "add"){

		if(posD1 == string::npos) {
			taskType = "FloatingTask";
			name = userInput.substr(pos1+1);
			return;

		} else {
			//add tomorrow/9/30/meeting
			//add Friday/19/0/21/30/CCA
			//NOTE: doesn't cover the case where the task type is invalid.
			if (isalpha(userInput.at(pos1+1))){
				easyAddDate(userInput);

				if(posD4 == string::npos) {
					addTimeDeadline(userInput);
					name = userInput.substr(posD3+1);
					return;
				} else {
					addTimeTimedTask(userInput);
					name = userInput.substr(posD5+1);
					return;
				}	
			} else {
				//add 2015/01/02/8/0/meeting
				//add 2015/01/02/8/0/11/0/meeting
				
				normalAddDate(userInput);
				string cutInput = userInput.substr(posD3);
				setDevider(cutInput);
				if(posD4 == string::npos) {
					addTimeDeadline(cutInput);
					name = cutInput.substr(posD3+1);
				} else {
					addTimeTimedTask(cutInput);
					name = cutInput.substr(posD5+1);
				}	
			}	
		}
	} else if (commandType == "delete" || commandType == "done" || commandType == "notdone" || commandType == "search") {
		if (isalpha(userInput.at(pos1+1))) {
			name = userInput.substr(pos1+1);
			number = -1;
		} else {
			number = stoi(userInput.substr(pos1+1));
		}

	} else if (commandType == "sort" || commandType == "display" || commandType == "undo") {
		return;
	} else if (commandType == "edit"){
		setDevider(userInput);
		number = stoi(userInput.substr(pos1+1, pos2-pos1-1));
		attribute = userInput.substr(pos2+1, pos3-pos2-1);
		cout << number;
		cout << attribute;
		
		if (attribute == "name"){
			//userInput == edit 4 name XXXXX
			name = userInput.substr(pos3+1);
		} else if (attribute == "date"){
			//userInpur == edit 3 date ......
			string cutInput = userInput.substr(pos2+1);
			//cutInput == date .....
			setDevider(cutInput);

			if (posD1 == string::npos){
				//FloatingTask, need to add both date and time
				if(isalpha(cutInput.at(pos1+1))){
					//cutInput == date today/9/30/eat
					easyAddDate(cutInput);
					if(posD4 == string::npos) {
						addTimeDeadline(cutInput);
						return;
					} else {
						addTimeTimedTask(cutInput);
						return;
					}	

				} else{
					normalAddDate(cutInput);
					string cutInput2 = cutInput.substr(posD3);
					//cutInput2 == /9/30/10/30/eat
					//cutInput2 == /9/30/eat
					setDevider(cutInput2);
					if(posD4 == string::npos) {
						addTimeDeadline(cutInput2);
					} else {
						addTimeTimedTask(cutInput2);
					}	
				}
				
			} else {
				//DeadlineTask or TimedTask
				if(isalpha(cutInput.at(pos1+1))){
					easyAddDate(cutInput);
				} else{
					normalAddDate(cutInput);
				}
			}

		} else if (attribute == "time"){
			string cutInput = userInput.substr(pos2+1);
			//cutInput == time .....
			setDevider(cutInput);

			if (posD1 == string::npos){
				//FloatingTask, need to add both date and time

				if(isalpha(cutInput.at(pos1+1))){
					//cutInput == date today/9/30/eat
					easyAddDate(cutInput);
					if(posD4 == string::npos) {
						addTimeDeadline(cutInput);
						return;
					} else {
						addTimeTimedTask(cutInput);
						return;
					}	

				} else{
					normalAddDate(cutInput);
					string cutInput2 = cutInput.substr(posD3);
					//cutInput2 == /9/30/10/30/eat
					//cutInput2 == /9/30/eat
					setDevider(cutInput2);
					if(posD4 == string::npos) {
						addTimeDeadline(cutInput2);
					} else {
						addTimeTimedTask(cutInput2);
					}	
				}
			}else{
				//DeadlineTask or TimedTask
				//cutInput == time 17/30 || cutInput == time 17/30/18/30
				string cutInput2 = cutInput.substr(pos1+1);
				cutInput2 = '/' + cutInput2; // so we can use the addTimeDeadline or addTimeTimedTask
				//cutInput2 == /17/30 || /17/30/18/30
				setDevider(cutInput2);
				if(posD3 == string::npos){
					addTimeDeadline(cutInput2);
				} else {
					addTimeTimedTask(cutInput2);
				}
			}	
		}
	} else if (commandType == "exit") {
		return;
	} else {
		cout << "invalid command" << endl;
	}
	return;
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
