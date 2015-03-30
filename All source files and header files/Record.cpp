#include "Record.h"

Record::Record(void) { }

Record(string commandType, Task task) {
	_commandType = commandType;
	//How about task?
}

Record::~Record(void) { }

void Record::setCommandTypeRecord(string commandTypeRecord){
	_commandType = commandTypeRecord;
}

void Record::setlistTaskRecord(Task taskRecord){
	_taskRecord.push_back(taskRecord);
}

void Record::setIsPrevious(){
	_isPrevious = true;
}

void Record::setIsNotPrevious(){
	_isPrevious = false;
}

string Record::getCommandType(){
	return _commandType;
}

list<Task> Record::getTaskRecord(){
	return _taskRecord;
}

bool Record::getIsPrevious(){
	return (_isPrevious);
}