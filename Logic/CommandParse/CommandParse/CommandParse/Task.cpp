#include "Task.h"

Task::Task(){};

Task::Task(string commandType, string name, Date date, double startTime, double endTime):
_commandType(commandType), _name(name), _date(date), _startTime(startTime), _endTime(endTime){
	_taskType = "TimedTask";
	_isDone = false;
}

Task::Task(string commandType, string name, Date date, double endTime):
_commandType(commandType), _name(name), _date(date), _endTime(endTime){
	_taskType = "DeadLineTask";
	_isDone = false;
}

Task::Task(string commandType, string name):
_commandType(commandType), _name(name){
	_taskType = "FloatingTask";
	_isDone = false;
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

string Task::getTaskType(){
	return _taskType;
}





