#include "Record.h"

Record::Record(void) {}

Record::Record(string newCommand, Task newTask){
	_commandType = newCommand;
	_taskRecord.clear();
	_taskRecord.push_back(newTask);
}

Record::Record(string newCommand, list<Task> newTaskList){
	_commandType = newCommand;
	_taskRecord.clear();
	_taskRecord = newTaskList;
}

Record::~Record(void) {}

void Record::setCommandTypeRecord(string commandTypeRecord){
	_commandType = commandTypeRecord;
}

void Record::setlistTaskRecord(Task taskRecord){
	_taskRecord.push_back(taskRecord);
}

string Record::getCommandType(){
	return _commandType;
}

list<Task> Record::getTaskRecord(){
	return _taskRecord;
}

void Record::clear(){
	_commandType = "";
	_taskRecord.clear();
}