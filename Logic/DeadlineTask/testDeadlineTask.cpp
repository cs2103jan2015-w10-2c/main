#include "DeadlineTask.h"
#include <vector>

void printTaskDetail(vector <DeadlineTask> taskVector){
	vector <DeadlineTask>:: iterator iter;

	for( iter = taskVector.begin(); iter != taskVector.end(); iter++){
		cout << (*iter).DeadlineTask::toStringTaskDetail() << endl;
	}
}

void printTaskSerialID(vector <DeadlineTask> taskVector){
	vector <DeadlineTask>:: iterator iter;

	for( iter = taskVector.begin(); iter != taskVector.end(); iter++){
		cout << (*iter).DeadlineTask::getYear() << (*iter).DeadlineTask::getTaskSerialID() <<endl;
	}
}

int main(){
	vector <DeadlineTask> taskVector;

	DeadlineTask task1(5, 2, 2015, 1159, "CS assignment");
	DeadlineTask task2(25, 2, 2015, 1330, "CS homework");

	taskVector.push_back(task1);
	taskVector.push_back(task2);
	
	printTaskDetail(taskVector);

	cout << "Task Serial ID: "<< endl;
	printTaskSerialID(taskVector);

	cout << "Press any key to exit" << endl;
	cin.ignore();

	return 0;
}