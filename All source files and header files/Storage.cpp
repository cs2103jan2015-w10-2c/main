#include "Storage.h"
#include "dirent.h"
#include<algorithm>
#include<sstream>

using namespace std;

const string Storage::LINE_BUFFER = "%s\\%s\\%s\\%s\\%s\\%s\\%s\\%s\\%s\\%s\\%s";

char Storage::buffer[500];
list<Task> Storage::_TaskList;
list<Task>::iterator Storage::_TaskIt;
ofstream Storage::_fWrite;
ifstream Storage::_fRead;
string Storage::_fileName;

DIR *dir = NULL;
struct dirent *ent;

Storage::Storage() {}

void Storage::setFileName(string name) {
	_fileName = name;
}

void Storage::showDirectory() {
	if ((dir = opendir ("./")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			printf ("%s\n", ent->d_name);
		}
		closedir (dir);
		cout << "Type in name of file to open existing files" << endl;
		cout << "Enter a new name to create a new file" << endl;
	} else {
		cout << "Could not find directory" << endl;
	}
}

bool Storage::isExistingFile() {
	dir = opendir ("./");
	while ((ent = readdir (dir)) != NULL) {
		if (_fileName==ent->d_name) {
			closedir (dir);
			return true;
		}
	}
	closedir (dir);
	return false;
}

//i have folder called databank which is where all text files will be saved into
//pathName can be respecified if you wish to save it in another EXISTING folder
void Storage::openFile() {
	string pathName = "./";
	string combined = pathName + _fileName;
	_fWrite.open(combined);
}

void Storage::writeToFile() {
	cout << _TaskList.size(); 
	int i;
	_TaskIt = _TaskList.begin();
	for (i=1;i<=_TaskList.size();i++) {
		sprintf_s(buffer, LINE_BUFFER.c_str(), ((_TaskIt->getCommandType()).c_str())
			, (_TaskIt->getTaskType()).c_str(), (_TaskIt->getName()).c_str()
			, to_string(_TaskIt->getYear()).c_str(), to_string((_TaskIt->getMonth())).c_str()
			, to_string(_TaskIt->getDay()).c_str(), to_string(_TaskIt->getStartTimeHour()).c_str()
			, to_string(_TaskIt->getStartTimeMin()).c_str(), to_string(_TaskIt->getEndTimeHour()).c_str()
			, to_string(_TaskIt->getEndTimeMin()).c_str(), to_string(_TaskIt->isDone()).c_str());
		cout << buffer;
		cout << _TaskIt->getName();
		_fWrite << buffer << endl;
		_TaskIt++;
	}
	_fWrite.close();
}

//this is extremely inefficient but sigh
void Storage::readFile() {
	
	string pathName = "./Databank/";
	string combined = pathName + _fileName;
	_fRead.open(combined, ios_base::in);

	size_t posStart;
	size_t posD1;
	size_t posD2;
	size_t posD3;
	size_t posD4;
	size_t posD5;
	size_t posD6;
	size_t posD7;
	size_t posD8;
	size_t posD9;
	size_t posD10;
	string input;

	string commandType;
	string taskType;
	string  name;
	int year;
	int month;
	int day;
	double startTimeHour;
	double startTimeMin;
	double endTimeHour;
	double endTimeMin;
	bool isDone;

	string devider = "\\";
	Task* inputTask;

	while (_fRead>>input) {
		posStart = 0;
		posD1 = input.find(devider);
		posD2 = input.find(devider, posD1+1);
		posD3 = input.find(devider, posD2+1);
		posD4 = input.find(devider, posD3+1);
		posD5 = input.find(devider, posD4+1);
		posD6 = input.find(devider, posD5+1);
		posD7 = input.find(devider, posD6+1);
		posD8 = input.find(devider, posD7+1);
		posD9 = input.find(devider, posD8+1);
		posD10 = input.find(devider, posD9+1);


		commandType = (input.substr(posStart, (posD1-posStart)));
		taskType = (input.substr((posD1+1), (posD2-posD1-1)));
		name = (input.substr((posD2+1), (posD3-posD2-1)));
		year = stoi(input.substr((posD3+1), (posD4-posD3)));
		month = stoi(input.substr((posD4+1), (posD5-posD4)));
		day = stoi(input.substr((posD5+1), (posD6-posD5)));
		startTimeHour = stod(input.substr((posD6+1), (posD7-posD6)));
		startTimeMin = stod(input.substr((posD7+1), (posD8-posD7)));
		endTimeHour = stod(input.substr((posD8+1), (posD9-posD8)));
		endTimeMin = stod(input.substr((posD9+1), (posD10-posD9)));
		isDone = stoi(input.substr(posD10+1));

		inputTask = new Task(commandType,taskType,name,year,month,day,startTimeHour,startTimeMin,endTimeHour,endTimeMin,isDone);
		_TaskList.push_back(*inputTask);
		delete inputTask;
	}
	_fRead.close();
		
}

void Storage::storeTask(Task task) {
	if (!isTaskDuplicate(task)) {
		_TaskList.push_back(task);
	}
}

bool Storage::isTaskDuplicate(Task task) {
	_TaskIt = _TaskList.begin();
	if (task.getTaskType() == "FloatingTask") {
		return isFloatDuplicate(task);
	} else {
		if (task.getTaskType() == "TimedTask") {
			return isTimedDuplicate(task);
		} else {
			if (task.getTaskType() == "DeadlineTask") {
				return isDeadlineDuplicate(task);
			} else {
				return false;
			}
		}
	}	

}

bool Storage::isFloatDuplicate(Task task) {
	for (int i=1;i<=_TaskList.size();i++) {
		if ((task.getName())==(_TaskIt->getName())) {
				return true;
			}
		_TaskIt++;
	}
	return false;
}

bool Storage::isTimedDuplicate(Task task) {
	for (int i=1;i<=_TaskList.size();i++) {
		if ((task.getName())==(_TaskIt->getName())) {
			if ((task.getStartTimeHour())==(_TaskIt->getStartTimeHour())
				&& (task.getStartTimeMin())==(_TaskIt->getStartTimeMin())) 
				return true;
			}
		_TaskIt++;
	}
	return false;
}

bool Storage::isDeadlineDuplicate(Task task) {
		for (int i=1;i<=_TaskList.size();i++) {
		if ((task.getName())==(_TaskIt->getName())) {
			if ((task.getEndTimeHour())==(_TaskIt->getEndTimeHour())
				&& (task.getEndTimeMin())==(_TaskIt->getEndTimeMin())) 
				return true;
			}
		_TaskIt++;
	}
	return false;
}

bool cmpTime(Task a, Task b){

	if(a.getYear() < b.getYear()){
		return true;
	} else if (a.getYear() > b.getYear()){
		return false;
	}

	if(a.getMonth() < b.getMonth()){
		return true;
	} else if(a.getMonth() > b.getMonth()){
		return false;
	}

	if(a.getDay() < b.getDay()){
		return true;
	} else if (a.getDay() > b.getDay()){
		return false;
	}

	if(a.getStartTimeHour() < b.getStartTimeHour()){
		return true;
	} else if (a.getStartTimeHour() > b.getStartTimeHour()){
		return false;
	}

	if(a.getStartTimeMin() < b.getStartTimeMin()){
		return true;
	} else if(a.getStartTimeMin() > b.getStartTimeMin()) {
		return false;
	}

	if (a.getName() < b.getName()){
		return true;
	} else {return false;}
}


bool sortTime(Task a, Task b){
	return (cmpTime(a,b));
}

void Storage::sortList(){
	_TaskList.sort(sortTime);
	return;
}

string Storage::searchByName(string searchKeyWord){
	list <Task> searchResultList;
	list <Task>::iterator i;
	for (i = _TaskList.begin(); i!= _TaskList.end(); i++){
		if ((i->getName()).find(searchKeyWord) != std::string::npos){
			searchResultList.push_back(*i);
		}
	}
	return toStringTaskDetail(searchResultList);
}

string Storage::deleteByName(string searchKeyWord){
	
    list <Task>::iterator i;
    list <Task> deleteResultList;
	int count=0;
    for (i = _TaskList.begin(); i!= _TaskList.end(); i++){

        if (i->getName() != searchKeyWord){
            deleteResultList.push_back(*i);
			count++;
        }
    }
	ostringstream s;
	if(count==_TaskList.size()) {
		s << "There is no such task in the schedule.\n";
		return s.str();
	}
    _TaskList.clear();
    _TaskList = deleteResultList;
	s << "Tasks containing the keyword have been deleted.\n";
	return s.str();

}

string Storage::toStringTaskDetail(list <Task> listToFormat){
	ostringstream s;
	if(listToFormat.empty()) {
		s << "There is no such task in the schedule.\n";
		return s.str();
	} else {
		list <Task>::iterator i;
		for ( i = listToFormat.begin(); i != listToFormat.end(); i++){
			if (i->getTaskType() == "FloatingTask"){
				s << i->getName() << endl;
			}
			else if (i->getTaskType() == "TimedTask"){
				s << "[" << i->getDate() << "][" <<i->getStartTimeHour() << ":";
				s << i->getStartTimeMin() << "-" << i->getEndTimeHour() << ":";
				s << i->getEndTimeMin() << "]" << i->getName() << endl;
			}
			else if (i->getTaskType() == "DeadlineTask"){
				s << "[" << i->getDate() << "][" <<i->getEndTimeHour() << ":";
				s << i->getEndTimeMin() << "]"<< i->getName() << endl;
			}
		}
		return s.str();
	}
}

string Storage::toStringTaskDetail(){
	stringstream s;
	if(_TaskList.empty()) {
		s << "There is no task in the schedule.\n";
		return s.str();
	} else {
		for (_TaskIt = _TaskList.begin(); _TaskIt != _TaskList.end(); _TaskIt++){
			if (_TaskIt->getTaskType() == "FloatingTask"){
				s << _TaskIt->getName() << endl;
			}
			else if (_TaskIt->getTaskType() == "TimedTask"){
				s << "[" << _TaskIt->getDate() << "][";

				if(_TaskIt->getStartTimeHour() < 10){
					s << "0" << _TaskIt->getStartTimeHour() <<":";
				} else s << _TaskIt->getStartTimeHour() << ":";
			
				if(_TaskIt->getStartTimeMin() < 10){
					s << "0" << _TaskIt->getStartTimeMin() <<"-";
				} else s << _TaskIt->getStartTimeMin() << "-";

				if(_TaskIt->getEndTimeHour() < 10){
					s << "0" << _TaskIt->getEndTimeHour() <<":";
				} else s << _TaskIt->getEndTimeHour() << ":";
			
				if(_TaskIt->getEndTimeMin() < 10){
					s << "0" << _TaskIt->getEndTimeMin() <<"]";
				} else s << _TaskIt->getEndTimeMin() << "]";

				s << _TaskIt->getName() << endl;
			}

			else if (_TaskIt->getTaskType() == "DeadlineTask"){
				s << "[" << _TaskIt->getDate() << "][";

				if(_TaskIt->getEndTimeHour() < 10){
					s << "0" << _TaskIt->getEndTimeHour() <<":";
				} else s << _TaskIt->getEndTimeHour() << ":";
			
				if(_TaskIt->getEndTimeMin() < 10){
					s << "0" << _TaskIt->getEndTimeMin() <<"]";
				} else s << _TaskIt->getEndTimeMin() << "]";
			
				s<< _TaskIt->getName() << endl;
			}
		}
	
	}
	
	return s.str();
}



