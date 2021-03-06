//@author A0114255N
#include "Task.h"
#include<sstream>

const string Task::NAME_OF_MONTH[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Task::Task() { };

Task::Task(string commandType, string taskType, string name, int year, int month, int day, int startTimeHour, int startTimeMin, int endTimeHour, int endTimeMin, bool isDone) {
	_commandType = commandType;
	_taskType = taskType;
	_name = name;
	_year = year;
	_month = month;
	_day = day;
	_startTimeHour = startTimeHour;
	_startTimeMin = startTimeMin;
	_endTimeHour = endTimeHour;
	_endTimeMin = endTimeMin;
	_isDone = isDone;
}


Task::Task(string commandType, string name, int year, int month, int day, int startTimeHour, int startTimeMin, int endTimeHour, int endTimeMin) {
	_isDone = false;
	_taskType = "TimedTask";
	_commandType = commandType;
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
	_commandType = commandType;
	_name = name;
	_year = year;
	_month = month;
	_day = day;
	_endTimeHour = endTimeHour;
	_endTimeMin = endTimeMin;
	_startTimeHour = endTimeHour;
	_startTimeMin = endTimeMin;
}

Task::Task(string commandType, string name):
_commandType(commandType),  _name(name) {
	_isDone = false;
	_taskType = "FloatingTask";
	_year = 99999;
	_month = 0;
	_day = 0;
	_startTimeHour=0;
	_startTimeMin=0;
	_endTimeHour=0;
	_endTimeMin=0;
}

void Task::markDone() {
	_isDone = true;
}

void Task::markNotDone(){
	_isDone = false;
}

void Task::setName(string newName) {
	_name = newName;
}

void Task::setTaskType(string taskType) {
	_taskType = taskType;
}

void Task::setYear(int newYear){
	_year = newYear;
}

void Task::setMonth(int newMonth){
	_month = newMonth;
}

void Task::setDay(int newDay){
	_day = newDay;
}

void Task::setStartTimeHour(int newStartTimeHour){
	_startTimeHour = newStartTimeHour;
}

void Task::setStartTimeMin(int newStartTimeMin){
	_startTimeMin = newStartTimeMin;
}

void Task::setEndTimeHour(int newEndTimeHour){
	_endTimeHour = newEndTimeHour;
}

void Task::setEndTimeMin(int newEndTimeMin){
	_endTimeMin = newEndTimeMin;
}

void Task::setCommandType(string commandType) {
	_commandType = commandType;
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

string Task::getAlphaMonth(int monthNumber){
	return NAME_OF_MONTH[monthNumber - 1];
}

string Task::getAlphabetDate(){
	stringstream s;
	s << _day << " " << getAlphaMonth(_month) << " " << _year;
	return s.str();
}

string Task::getName() {
	return _name;
}

int Task::getYear() {
	return _year;
}

int Task::getMonth() {
	return _month;
}

int Task::getDay() {
	return _day;
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

bool Task::getIsDone(){
	return _isDone;
}
