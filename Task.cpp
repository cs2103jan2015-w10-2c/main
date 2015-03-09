#include "Task.h"
#include<sstream>

Task::Task(){};

Task::Task(string commandType, string name, int year, int month, int day, double startTime, double endTime):
_commandType(commandType), _name(name), _year(year), _month(month), _day(day), _startTime(startTime), _endTime(endTime){
	_isDone = false;
	_isFloat = false;
	_isDeadline = false;
}

Task::Task(string commandType, string name, int year, int month, int day, double endTime):
_commandType(commandType), _name(name), _year(year), _month(month), _day(day), _endTime(endTime){
	_isDone = false;
	_isFloat = false;
	_isDeadline = true;
}

Task::Task(string commandType, string name):
_commandType(commandType), _name(name){
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

string Task::getDate(){
	stringstream s;
	s << _year << "/" << _month << "/" << _day;
	return s.str();
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






