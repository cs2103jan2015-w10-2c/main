#include "Task.h"
#include "TaskStorage.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string userInput = "add CS2103 Meeting at COM1";
	TaskStorage ts1;

	ts1.parseInput(userInput);
	cout << "command type is " << ts1.getCommandType() << endl;
	cout << "task type is " << ts1.getTaskType() << endl;
	cout << "task description is " << (ts1.getFTask()).FloatingTask::toStringTaskDetail()<< endl;

	cout << "press any key to exit" << endl;
	getchar();
	return 0;
}
