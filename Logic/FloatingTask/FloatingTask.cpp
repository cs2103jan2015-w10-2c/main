#include "FloatingTask.h"

FloatingTask::FloatingTask(){}

FloatingTask:: FloatingTask(int day, int month, int year, string taskDescription):
_day(day), _month(month), _year(year), _taskDescription(taskDescription){
	_taskStatus		= "Not done yet";
	_taskSerialID	= 0;
	//_taskSerialID is made to be 0 so that it would float at the top when sorted
}

string FloatingTask::toStringTaskDetail(){
		ostringstream oss;
		oss << _taskDescription << " added to " ;
		oss << _day << "/" << _month << "/" << _year << " whole day" << endl;
		oss << _taskStatus << endl;
		return oss.str();
}

int FloatingTask::getTaskSerialID(){
	return _taskSerialID;
}

FloatingTask::~FloatingTask(){}
