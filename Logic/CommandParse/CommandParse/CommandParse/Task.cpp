#include "Task.h"

Task::Task(){};

Task::Task(string commandType, string name, Date date, double startTime, double endTime, double serialID):
_commandType(commandType), _name(name), _date(date), _startTime(startTime), _endTime(endTime), _serialID(serialID){
	_isDone = false;
	_isFloat = false;
	_isDeadline = false;
}

Task::Task(string commandType, string name, Date date, double endTime, double serialID):
_commandType(commandType), _name(name), _date(date), _endTime(endTime), _serialID(serialID){
	_isDone = false;
	_isFloat = false;
	_isDeadline = true;
}

Task::Task(string commandType, string name, double serialID):
_commandType(commandType), _name(name), _serialID(serialID){
	_isDone = false;
	_isFloat = true;
	_isDeadline = false;
}

void Task::markDone(){
	_isDone = true;
}

string Task::getCommandType(){
	return _commandType;
}

Date Task::getDate(){
	return _date;
}

string Task::getName(){
	return _name;
}

double Task::getEndTime(){
	return _endTime;
}

double Task::getStartTime(){
	return _startTime;
}

bool Task::getDone(){
	return _isDone;
}

bool Task::getFloat(){
	return _isFloat;
}

bool Task::getDeadline(){
	return _isDeadline;
}

double Task::getSerialID(){
	return _serialID;
}





