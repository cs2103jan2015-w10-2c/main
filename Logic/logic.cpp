#include "Task.h"
#include "CommandParser.h"


//call ParseCommand and receive task from ParseCommand
Task t;
CommandParser cp;
t = CommandParser::cp.createTask(input);

//identify commandType and required parameters and call storeFloat(string taskName)
if (t.getTaskType() == "FloatingTask"){
	storeFloat(getTaskName());
}	else if(t.getTaskType() == "TimedTask"){
	storeTimed(getTaskName(), getDate(), getStartTime(), getEndTime());
}	else if (t.getTaskType() == "DeadlineTask"){
	storeDeadline(getTaskName(), getDate(), getEndTime());
}

//receive bool from storeFloat and create output message
if (isStored()){
	ostringstream os;
	os << t.getTaskName() << "has been stored successfully";
}
	else {
		os << "Sorry, the task has not been stored successfully";
	} 

	showToUser(os.str());

