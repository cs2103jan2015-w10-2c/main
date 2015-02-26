#include "TaskStorage.h"


TaskStorage::TaskStorage(void){}

void TaskStorage::parseInput(string input){
	//get the first word before the first white space
	string command;
	size_t pos1 = input.find_first_of(' ');
	_commandType = input.substr(0, pos1);

	//check the number of devider "//"
	//no devider -> floating: description
	//one devider -> deadline: endTime//description
	//two devider -> timed: startTime//endTime//description
	string devider = "//";
	size_t pos2 = input.find_first_of(devider);
	if(pos2 == string::npos){
		_taskType = "FloatingTask";
		string description = input.substr(pos1+1);
		FloatingTask tempFTask(description);
		_fTask = tempFTask;
	}

	return;
}

string TaskStorage::getTaskType(){
	return _taskType;
}

string TaskStorage::getCommandType(){
	return _commandType;
}

FloatingTask TaskStorage::getFTask(){
	return _fTask;
}

TaskStorage::~TaskStorage(void){}
