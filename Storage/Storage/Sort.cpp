#include "Task.h"
#include "CommandParser.h"
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;


bool sortSerialID(Task a, Task b){
	return a.getSerialID() < b.getSerialID();
}

void sortList(list <Task> list){
	sort(list.begin(), list.end(), sortSerialID);
	return;
}

int main(){

	list <Task> testList;
	string userInput1 = "add cs2103 meeting";
	string userInput2 = "add lunch";

	CommandParser cd;
	Task t1 = cd.createTask(userInput1);
	Task t2 = cd.createTask(userInput2);

	testList.push_back(t1);
	testList.push_back(t2);

	string commandType = t1.getCommandType();
	cout << "Command Type: "<< commandType<< endl;
	string description = t1.getName();
	cout << "Description: "<< description<< endl;

	if (commandType == "sort"){
		sortList(testList);
	}

	getchar();
	return 0;
}

