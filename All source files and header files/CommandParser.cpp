#include "CommandParser.h"

using namespace std;

//string CommandParser::userInput;
string CommandParser::taskType;
string CommandParser::commandType;
string CommandParser::name;
int CommandParser::year;
int CommandParser::month;
int CommandParser::day;
int CommandParser::startTimeHour;
int CommandParser::startTimeMin;
int CommandParser::endTimeHour;
int CommandParser::endTimeMin;

void CommandParser::identifyTask(string userInput) {

	//get the first word before the first white space
	size_t pos1 = userInput.find_first_of(' ');

	commandType = userInput.substr(0, pos1);
	//convert all letters in the commandType to lower case
	transform(commandType.begin(), commandType.end(), commandType.begin(), ::tolower);
	assert(commandType != "");
	
	if(commandType == "add"){
	//check the number of devider "//"
	//no devider -> floating: description
	//one devider -> deadline: endTime//description
	//two devider -> timed: startTime//endTime//description

	string devider = "/";
	size_t posD1 = userInput.find(devider);
	if(posD1 == string::npos) {
		taskType = "FloatingTask";
		name = userInput.substr(pos1+1);

	} else {
		//add 2015//01//02//8//0//meeting
		//add 2015//01//02//8//0//11//0//meeting
		//NOTE: doesn't cover the case where the task type is invalid.

		size_t posD2 = userInput.find(devider, posD1+1);
		size_t posD3 = userInput.find(devider, posD2+1);
		size_t posD4 = userInput.find(devider, posD3+1);
		size_t posD5 = userInput.find(devider, posD4+1);
		size_t posD6 = userInput.find(devider, posD5+1);

		year = stoi(userInput.substr(pos1+1, (posD1-pos1)));
		month =  stoi(userInput.substr(posD1+1, (posD2-posD1)));
		day =  stoi(userInput.substr(posD2+1, (posD3-posD2)));

		if(posD6 == string::npos) {
			taskType = "DeadlineTask";
			endTimeHour = stoi(userInput.substr(posD3+1, (posD4-posD3)));
			endTimeMin = stoi(userInput.substr(posD4+1, (posD5-posD4)));
			name = userInput.substr(posD5+1);

		} else {
			size_t posD7 = userInput.find(devider, posD6+1);

			taskType = "TimedTask";
			startTimeHour = stoi(userInput.substr(posD3+1, (posD4-posD3)));
			startTimeMin = stoi(userInput.substr(posD4+1, (posD5-posD4)));
			endTimeHour = stoi(userInput.substr(posD5+1, (posD6-posD5)));
			endTimeMin = stoi(userInput.substr(posD6+1, (posD7-posD6)));
			name = userInput.substr(posD7+1);
		}	
	}
	}else if(commandType == "delete" || commandType == "search" || commandType == "done" || commandType == "notdone" ){
		name = userInput.substr(pos1+1);
	}else if(commandType == "sort" || commandType == "display"){
		return;
	}else{
		cout << "invalid command" << endl;
	}
	return;

}

CommandParser::CommandParser(void) { }


CommandParser::~CommandParser(void) { }


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

