#include "Record.h"

Record::Record(void) { }

Record(string commandType, Task task) {
	_commandType = commandType;
	//How about task?
}

<<<<<<< HEAD
Record::Record(string newCommand, list<Task> newTaskList){
	_commandType = newCommand;
	_taskRecord.clear();
	_taskRecord = newTaskList;
}

Record::~Record(void) {}
=======
Record::~Record(void) { }
>>>>>>> 73322872014d207b8ed221362092bdc40965d8cf

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