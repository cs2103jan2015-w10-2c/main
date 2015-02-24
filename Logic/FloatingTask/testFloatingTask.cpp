#include "FloatingTask.h"
#include<vector>

void printTaskDetail(vector <FloatingTask> taskVector){
	vector <FloatingTask>:: iterator iter;

	for( iter = taskVector.begin(); iter != taskVector.end(); iter++){
		cout << (*iter).FloatingTask::toStringTaskDetail() << endl;
	}
}

void printTaskSerialID(vector <FloatingTask> taskVector){
	vector <FloatingTask>:: iterator iter;

	for( iter = taskVector.begin(); iter != taskVector.end(); iter++){
		cout << (*iter).FloatingTask::getTaskSerialID() << endl;;
	}
}

int main(){
	vector <FloatingTask> taskVector;
	
	FloatingTask task1(16, 2, 2015, "CCA outing");
	FloatingTask task2(25, 2, 2015, "CS2103 meeting");
	taskVector.push_back(task1);
	taskVector.push_back(task2);
	
	printTaskDetail(taskVector); // check what has been added

	cout << "Task Serial ID: "<< endl;
	printTaskSerialID(taskVector);

	cout << "Press any key to exit" << endl;
	cin.ignore();

	return 0;
}