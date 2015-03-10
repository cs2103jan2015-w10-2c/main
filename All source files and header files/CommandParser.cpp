#include "CommandParser.h"

using namespace std;

//string CommandParser::userInput;
string CommandParser::taskType;
string CommandParser::commandType;
string CommandParser::description;
int CommandParser::year;
int CommandParser::month;
int CommandParser::day;
double CommandParser::startTime;
double CommandParser::endTime;

void CommandParser::identifyTask(string userInput) {
//	string command;
//	string commandType;
	
//	Date date;
	
	//get the first word before the first white space
	size_t pos1 = userInput.find_first_of(' ');
	commandType = userInput.substr(0, pos1);

	//check the number of devider "//"
	//no devider -> floating: description
	//one devider -> deadline: endTime//description
	//two devider -> timed: startTime//endTime//description

	string devider = "//";
	size_t posD1 = userInput.find(devider);
	if(posD1 == string::npos) {
		taskType = "FloatingTask";
		description = userInput.substr(pos1+1);
//		Task t1(commandType, description);
//		return t1;
	} else {
		//add 2015//01//02//8//meeting
		//add 2015//01//02//8//11//meeting
		
		size_t posD2 = userInput.find(devider, posD1+1);
		size_t posD3 = userInput.find(devider, posD2+1);
		size_t posD4 = userInput.find(devider, posD3+1);
		size_t posD5 = userInput.find(devider, posD4+1);

		//construct structure Date
		year = stoi(userInput.substr(pos1+1, (posD1-pos1)));
		month =  stoi(userInput.substr(posD1+1, (posD2-posD1)));
		day =  stoi(userInput.substr(posD2+1, (posD3-posD2)));

		if(posD5 == string::npos) {
			taskType = "DeadlineTask";
			endTime = stod(userInput.substr(posD3+1, (posD4-posD3)));
			description = userInput.substr(posD4+1);
//			Task t2(commandType, description, date, endTime);
//			return t2;
		} else {
		//	taskType = "TimedTask";
			startTime = stod(userInput.substr(posD3+1, (posD4-posD3)));
			endTime = stod(userInput.substr(posD4+1, (posD5-posD4)));
			description = userInput.substr(posD5+1);
//			Task t3(commandType, description, date, startTime,endTime);
//			return t3;
		}	
	}

	
}

CommandParser::CommandParser(void) { }


CommandParser::~CommandParser(void) { }