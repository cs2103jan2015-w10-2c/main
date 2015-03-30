#include "Record.h"

Record::Record(void) { }
Record::~Record(void) { }

Record::Record(string commandType, Task newTask) {
	_commandType = commandType;
	_taskRecord.clear();
	_taskRecord.push_back(newTask);
}

Record::Record(string newCommand, list<Task> newTaskList){
	_commandType = newCommand;
	_taskRecord.clear();
	_taskRecord = newTaskList;
}

void Record::setCommandTypeRecord(string commandTypeRecord){
	_commandType = commandTypeRecord;
}

void Record::setlistTaskRecord(Task taskRecord){
	_taskRecord.push_back(taskRecord);
}

string Record::getCommandType(){
	return _commandType;
}

void Record::clear(){
	_commandType = "";
	_taskRecord.clear();
}

list<Task> Record::getTaskRecord(){
	return _taskRecord;
}
