#include "CommandParser.h"

using namespace std;

int main(){
	//floating task
	string userInput = "add cs2103 meeting";
	CommandParser cd;
	Task t1 = cd.createTask(userInput);

	string commandType = t1.getCommandType();
	cout << "Command Type: "<< commandType<< endl;
	string taskType = t1.getTaskType();
	cout << "Task Type: "<< taskType<< endl;
	string description = t1.getName();
	cout << "Description: "<< description<< endl;

	getchar();
	return 0;
}

Task CommandParser::createTask(string input){
	string command;
	string commandType;
	string taskType;
	Date date;
	
	//get the first word before the first white space
	size_t pos1 = input.find_first_of(' ');
	commandType = input.substr(0, pos1);

	//check the number of devider "//"
	//no devider -> floating: description
	//one devider -> deadline: endTime//description
	//two devider -> timed: startTime//endTime//description


	string devider = "//";
	size_t posD1 = input.find(devider);
	if(posD1 == string::npos){
		taskType = "FloatingTask";
		string description = input.substr(pos1+1);
		Task t1(commandType, description);
		return t1;
	}else{
		//add 2015//01//02//8//meeting
		//add 2015//01//02//8//11//meeting
		
		size_t posD2 = input.find(devider, posD1+1);
		size_t posD3 = input.find(devider, posD2+1);
		size_t posD4 = input.find(devider, posD3+1);
		size_t posD5 = input.find(devider, posD4+1);

		//construct structure Date
		date.year = stoi(input.substr(pos1+1, (posD1-pos1)));
		date.month =  stoi(input.substr(posD1+1, (posD2-posD1)));
		date.month =  stoi(input.substr(posD2+1, (posD3-posD2)));

		if(posD5 == string::npos){
			taskType = "DeadlineTask";
			double endTime = stod(input.substr(posD3+1, (posD4-posD3)));
			string description = input.substr(posD4+1);
			Task t2(commandType, description, date, endTime);
			return t2;
		}else{
			taskType = "TimedTask";
			double startTime = stod(input.substr(posD3+1, (posD4-posD3)));
			double endTime = stod(input.substr(posD4+1, (posD5-posD4)));
			string description = input.substr(posD5+1);
			Task t3(commandType, description, date, startTime,endTime);
			return t3;
		}	
	}

	
}

CommandParser::CommandParser(void){}


CommandParser::~CommandParser(void){}
