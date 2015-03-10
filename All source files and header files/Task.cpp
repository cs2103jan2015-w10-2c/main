#include "Task.h"
#include<sstream>

Task::Task() { };

Task::Task(string commandType, string name, int year, int month, int day, int startTimeHour, int startTimeMin, int endTimeHour, int endTimeMin) {
	_isDone = false;
	_taskType = "TimedTask";
	_commandType = commandType);
	_name = name;
	_year = year;
	_month = month;
	_day = day;
	_startTimeHour = startTimeHour;
	_startTimeMin = startTimeMin;
	_endTimeHour = endTimeHour;
	_endTimeMin = endTimeMin;
}

Task::Task(string commandType, string name, int year, int month, int day, int endTimeHour, int endTimeMin) {
	_isDone = false;
	_taskType = "DeadlineTask";
	_year = year;
	_month = month;
	_day = day;
	_endTimeHour = endTimeHour;
	_endTimeMin = endTimeMin;
}

Task::Task(string commandType, string name):
_commandType(commandType),  _name(name) {
	_isDone = false;
	_taskType = "FloatingTask";
}

void Task::markDone() {
	_isDone = true;
}

void Task::setName(string newName) {
	_name = newName;
}

string Task::getCommandType() {
	return _commandType;
}

string Task::getTaskType() {
	return _taskType;
}

string Task::getDate() {
	stringstream s;
	s << _year << "/" << _month << "/" << _day;
	return s.str();
}

string Task::getName() {
	return  _name;
}

int Task::getEndTimeHour() {
	return _endTimeHour;
}

int Task::getEndTimeMin() {
	return _endTimeMin;
}

int Task::getStartTimeHour() {
	return _startTimeHour;
}

int Task::getStartTimeMin() {
	return _startTimeMin;
}

bool Task::isDone(){
	return _isDone;
}