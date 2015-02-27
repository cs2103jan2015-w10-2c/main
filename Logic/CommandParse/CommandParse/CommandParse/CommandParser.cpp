#include "CommandParser.h"

int main(){
	//floating task
	string userInput = "add cs2103 meeting";
	CommandParser cd;
	Task t1 = cd.getUserInput(userInput);

	return 0;
}

Task CommandParser::getUserInput(string input){
	string command;
	string commandType;
	string taskType;
	
	//get the first word before the first white space
	size_t pos1 = input.find_first_of(' ');
	commandType = input.substr(0, pos1);

	//check the number of devider "//"
	//no devider -> floating: description
	//one devider -> deadline: endTime//description
	//two devider -> timed: startTime//endTime//description
	string devider = "//";
	size_t pos2 = input.find_first_of(devider);
	if(pos2 == string::npos){
		taskType = "FloatingTask";
		string description = input.substr(pos1+1);
		Task t1(commandType, description);
		return t1;
	}else if(){
	}

	
}

CommandParser::CommandParser(void){}


CommandParser::~CommandParser(void){}
