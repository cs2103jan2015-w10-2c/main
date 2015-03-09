#include "Task.h"
#include "CommandParser.h"
#include "Storage.h"
#include "Sort and search.cpp"


//call ParseCommand and receive task from ParseCommand
Task t;
Storage s;

//identify commandType and required parameters and call storeFloat(string taskName)
void callTask(){
	/*if (t.getTaskType() == "FloatingTask"){
		s.storeFloat(t.getName());
	}	else if(t.getTaskType() == "TimedTask"){
		s.storeTimed(t.getName(), t.getDate(), t.getStartTime(), t.getEndTime());
	}	else if (t.getTaskType() == "DeadlineTask"){
		s.storeDeadline(t.getName(), t.getDate(), t.getEndTime());
	}*/

	if (t.getCommandType() == "add"){
		s.storeTask(t);
	}

	if (t.getCommandType() == "delete"){
		// call storage's delete function
	}

	if (t.getCommandType() == "search"){
		
	}

	if (t.getCommandType() == "sort"){

	}
}

//receive bool from storeFloat and create output message
void tellUI(){
	ostringstream os;
	if (!s.isTaskDuplicate(t)){
		os << t.getName() << "has been stored successfully";
	}
		else {
			os << "Sorry, the task has not been stored successfully";
		} 

		showToUser(os.str());
		// this should call a function in the UI to show output message
}

void showToUser(string outputMessage){
	cout << outputMessage;
}
