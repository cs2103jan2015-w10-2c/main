#include "Task.h"
#include "CommandParser.h"
#include "Storage.h"


//call ParseCommand and receive task from ParseCommand
Task t;
Storage s;

//identify commandType and required parameters and call storeFloat(string taskName)
void callTask(){
	if (t.getTaskType() == "FloatingTask"){
		s.storeFloat(t.getName());
	}	else if(t.getTaskType() == "TimedTask"){
		s.storeTimed(t.getName(), t.getDate(), t.getStartTime(), t.getEndTime());
	}	else if (t.getTaskType() == "DeadlineTask"){
		s.storeDeadline(t.getName(), t.getDate(), t.getEndTime());
	}
}

bool isDuplicate(){
	if (s.isFloatDuplicate(t.getName()) || s.isTimedDuplicate() || s.isDeadlineDuplicate()){
		return true;
	}
		else return false;

}

//receive bool from storeFloat and create output message
void tellUI(){
	ostringstream os;
	if (!isDuplicate(t.getName())){
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
