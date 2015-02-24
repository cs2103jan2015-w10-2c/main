#include "DeadlineTask.h" 

DeadlineTask::DeadlineTask(){}

DeadlineTask:: DeadlineTask(int day, int month, int year, double deadline, string taskDescription):
_day(day), _month(month), _year(year), _deadline(deadline), _taskDescription(taskDescription){ 
	_taskStatus = "Not Done Yet";
}

string DeadlineTask::toStringTaskDetail(){
		ostringstream oss;
		oss << _taskDescription << " by ";
		oss << _day << "/" << _month << "/" << _year << " added " <<endl;
		oss << _taskStatus << endl;
		return oss.str();
}

int DeadlineTask::getTaskSerialID(){
	return _month*1000000 + _day*10000 + _deadline;
	//only based on month, day and time
}

int DeadlineTask::getYear(){
	return _year;
	//would be added to the front of getTaskSerialID() for sorting purposes
}

DeadlineTask::~DeadlineTask(){}


