#include "FloatingTask.h"

FloatingTask::FloatingTask(){}

FloatingTask:: FloatingTask(string taskDescription):
_taskDescription(taskDescription){
	_taskStatus		= "Not done yet";
	_taskSerialID	= 0;
	//_taskSerialID is made to be 0 so that it would float at the top when sorted
}

string FloatingTask::toStringTaskDetail(){
		ostringstream oss;
		oss << _taskDescription << " added" ;
		oss << _taskStatus << endl;
		return oss.str();
}

int FloatingTask::getTaskSerialID(){
	return _taskSerialID;
}

FloatingTask::~FloatingTask(){}
