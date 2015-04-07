#include "Storage.h"
#include "dirent.h"
#include <algorithm>
#include <sstream>
#include <assert.h>

using namespace std;

const string Storage::LINE_BUFFER = "%s/%s/%s/%s/%s/%s/%s/%s/%s/%s/%s";
const string Storage::COMMANDLIST = "List of commands:\n1. add\n2. display\n3. delete\n4. search\n5. done\n6. undone";

char Storage::buffer[1000];
list<Task> Storage::_taskList;
list<Task> Storage::_searchResultList;
list<Task> Storage::_previousTaskList;
list<Task>::iterator Storage::_taskIt;
ofstream Storage::_fWrite;
ifstream Storage::_fRead;
string Storage::_fileName;
bool Storage::isSuccess;
bool Storage::isSearched;
Record Storage::_record;
Tracker Storage::_tracker;

DIR *dir = NULL;
struct dirent *ent;

Storage::Storage() {
isSearched = false;
isSuccess = false;
}

void Storage::setFileName(string name) {
	string fileType = ".txt";
	size_t findPos = name.find(fileType);
	if (findPos==std::string::npos) {
	_fileName = name+fileType;
	} else {
		_fileName = name;
	}
}

void Storage::showDirectory() {
	if ((dir = opendir ("./")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			printf ("%s\r\n", ent->d_name);
		}
		closedir (dir);
		cout << "Type in name of file to open existing files" << "\n";
		cout << "Enter a new name to create a new file" << "\n";
	} else {
		cout << "Could not find directory" << "\r\n";
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
	string pathName = "./Databank/";
	string combined = pathName + _fileName;
	_fWrite.open(combined);
}

void Storage::writeToFile() {
	int i;
	_taskIt = _taskList.begin();
	for (i=1;i<=_taskList.size();i++) {
		sprintf_s(buffer, LINE_BUFFER.c_str(), ((_taskIt->getCommandType()).c_str())
			, (_taskIt->getTaskType()).c_str(), (_taskIt->getName()).c_str()
			, to_string(_taskIt->getYear()).c_str(), to_string((_taskIt->getMonth())).c_str()
			, to_string(_taskIt->getDay()).c_str(), to_string(_taskIt->getStartTimeHour()).c_str()
			, to_string(_taskIt->getStartTimeMin()).c_str(), to_string(_taskIt->getEndTimeHour()).c_str()
			, to_string(_taskIt->getEndTimeMin()).c_str(), to_string(_taskIt->isDone()).c_str());
		_fWrite << buffer << "\r\n";
		_taskIt++;
	}
	_fWrite.close();
}

//this is extremely inefficient but sigh
void Storage::readFile() {
	
	string pathName = "./Databank/";
	string combined = pathName + _fileName;
	_fRead.open(combined);

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

	string devider = "/";
	Task* inputTask;

	while (getline(_fRead,input)) {
		//assert(getDeviderNum(input) == 10);
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
		_taskList.push_back(*inputTask);
		delete inputTask;
	}
	_fRead.close();
		
}

int Storage::getIndex() {
	int index=1;
	list<Task>::iterator i = _taskList.begin();
	while (i!=_taskIt) {
		index++;
		i++;
	}
	return index;
}

void Storage::storeTask(Task task) {
	if (!isTaskDuplicate(task)) {
		_taskList.push_back(task);
		creatRecordAdd(task);
		getTask(task);
		sortList();
		isSuccess = true;
	} else {
		isSuccess = false;
	}
}

string Storage::editTask(int i, string s) {
	string commandType = "edit";

	if (isSearched) {
		_taskIt= _searchResultList.begin();
		if (i>_searchResultList.size()||i<=0) {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		} else {
			getPosition(i);
			isSuccess = compareTask(*(_taskIt));
			if (!isSuccess) {
				return toStringTaskDetail(_searchResultList);
			}
		}
	} else {
		if (i>_taskList.size()||i<=0) {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		} else {
			_taskIt= _taskList.begin();
			getPosition(i);
		}
	}
	_previousTaskList.clear();
	_previousTaskList.push_back(*(_taskIt));
	_taskIt->setName(s);
	_previousTaskList.push_back(*(_taskIt));
	_record = Record(commandType, _previousTaskList);
	addToTracker();
	_record.clear();
	isSuccess = true;
	return toStringTaskDetail();
	
}
	

void Storage::creatRecordAdd(Task task) {
	_record = Record( "add", task);
	addToTracker();
	_record.clear();
}

void Storage::addToTracker() {
		_tracker.addRecord(_record);
}

bool Storage::isTaskDuplicate(Task task) {
	_taskIt = _taskList.begin();
	if (task.getTaskType() == "FloatingTask") {
		return isFloatDuplicate(task);
	} else if (task.getTaskType() == "TimedTask") {
		return isTimedDuplicate(task);
	} else if (task.getTaskType() == "DeadlineTask") {
		return isDeadlineDuplicate(task);
	} else {
		return false;
	}
}

//bug
bool Storage::isFloatDuplicate(Task task) {

	for (_taskIt = _taskList.begin(); _taskIt != _taskList.end(); _taskIt++) {
		if ((task.getName())==(_taskIt->getName())
			&& !(_taskIt->isDone())) {
			return true;
		}
	}
	return false;
}

//bug
bool Storage::isTimedDuplicate(Task task) {
	for (int i=1;i<=_taskList.size();i++) {
		if ((task.getName())==(_taskIt->getName())) {
			if ((task.getStartTimeHour())==(_taskIt->getStartTimeHour())
				&& (task.getStartTimeMin())==(_taskIt->getStartTimeMin())
				&& (task.getYear())==(_taskIt->getYear())
				&& (task.getMonth())==(_taskIt->getMonth())
				&& (task.getDay())==(_taskIt->getDay())
				&& !(_taskIt->isDone())) 
				return true;
			}
		_taskIt++;
	}
	return false;
}

//bug
bool Storage::isDeadlineDuplicate(Task task) {
		for (int i=1;i<=_taskList.size();i++) {
		if ((task.getName())==(_taskIt->getName())) {
			if ((task.getEndTimeHour())==(_taskIt->getEndTimeHour())
				&& (task.getEndTimeMin())==(_taskIt->getEndTimeMin())
				&& !(_taskIt->isDone())) 
				return true;
			}
		_taskIt++;
	}
	return false;
}

bool cmpTime(Task a, Task b){
	string s1, s2;

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

	s1 = Storage::toLower(a.getName());
	s2 = Storage::toLower(b.getName());

	if (s1 < s2) {
		return true;
	} else {return false;}
}


bool sortTime(Task a, Task b){
	return (cmpTime(a,b));
}

void Storage::sortList(){
	_taskList.sort(sortTime);
	return;
}

//store all searched tasks into list <Task> _searchResultList 
//bool isSearched = true
void Storage::findTaskInList(string searchKeyWord) {
	string text;
	_searchResultList.clear();
	searchKeyWord = toLower(searchKeyWord);
	for (_taskIt = _taskList.begin(); _taskIt!= _taskList.end(); _taskIt++) {
		text = toLower(_taskIt->getName());
		if (text.find(searchKeyWord) != std::string::npos) {
			_searchResultList.push_back(*_taskIt);
		}
	}
	if (!(_searchResultList.empty())) {
		isSearched=true;
	}
}

//return and dispay all task items containing the searchKeyWord
string Storage::searchByName(string searchKeyWord){
	findTaskInList(searchKeyWord);
	return toStringTaskDetail(_searchResultList);
}


string Storage::toLower(string text) {
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	return text;
}

void Storage::getTask(Task task) {
	list<Task>::iterator i;
	for (i=_taskList.begin();i!=_taskList.end();i++) {
		
		if ((i->getCommandType() == task.getCommandType()) 
			&& (i->getTaskType() == task.getTaskType()) 
			&& (i->getName() == task.getName())
			&& (i->getYear() == task.getYear())
			&& (i->getMonth() == task.getMonth())
			&& (i->getDay() == task.getDay())
			&& (i->getStartTimeHour() == task.getStartTimeHour())
			&& (i->getStartTimeMin() == task.getStartTimeMin())
			&& (i->getEndTimeHour() == task.getEndTimeHour())
			&& (i->getEndTimeMin() == task.getEndTimeMin())
			&& (!task.isDone())) {
				_taskIt = i;
				return;
		}
	}
	return;
}


//search task in the _taskList for exact matches
bool Storage::compareTask(Task task) {
	list<Task>::iterator i;
	for (i=_taskList.begin();i!=_taskList.end();i++) {
		
		if ((i->getCommandType() == task.getCommandType()) 
			&& (i->getTaskType() == task.getTaskType()) 
			&& (i->getName() == task.getName())
			&& (i->getYear() == task.getYear())
			&& (i->getMonth() == task.getMonth())
			&& (i->getDay() == task.getDay())
			&& (i->getStartTimeHour() == task.getStartTimeHour())
			&& (i->getStartTimeMin() == task.getStartTimeMin())
			&& (i->getEndTimeHour() == task.getEndTimeHour())
			&& (i->getEndTimeMin() == task.getEndTimeMin())) {
				_taskIt = i;
				return true;
		}
	}
	return false;
}


void Storage::getPosition(int i) {
			while (i>1) {
				_taskIt++;
				i--;
			}
}

string Storage::markDone(int i) {
	string commandType = "done";

	if (isSearched) {
		_taskIt= _searchResultList.begin();
		if (i>_searchResultList.size()||i<=0) {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		} else {
			getPosition(i);
			isSuccess = compareTask(*(_taskIt));
			if (!isSuccess) {
				return toStringTaskDetail(_searchResultList);
			}
		}
	} else {
		if (i>_taskList.size()||i<=0) {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		} else {
			_taskIt= _taskList.begin();
			getPosition(i);
		}
	}
	//pointer to task in _taskList before mark done
	storePreviousTask(commandType);
	_taskIt->markDone();
	isSuccess = true;
	return toStringTaskDetail();
	
}

string Storage::markNotDone(int i) {
	string commandType = "notdone";

	if (isSearched) {
		_taskIt= _searchResultList.begin();
		if (i>_searchResultList.size()||i<=0) {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		} else {
			getPosition(i);
			if (!compareTask(*(_taskIt))) {
				isSuccess = false;
				return toStringTaskDetail(_searchResultList);
			}
		}
	} else {
		if (i>_taskList.size()||i<=0) {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		} else {
			_taskIt= _taskList.begin();
			getPosition(i);
		}
	}
	//pointer to task in _taskList before mark not done
	storePreviousTask(commandType);
	_taskIt->markNotDone();
	isSuccess = true;
	return toStringTaskDetail();	
}

string Storage::deleteByNumber(int i) {
	string commandType = "delete";

	if (isSearched) {
		_taskIt= _searchResultList.begin();
		if (i>_searchResultList.size()||i<=0) {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		} else {
			getPosition(i);
			if (!compareTask(*(_taskIt))) {
				isSuccess = false;
				return toStringTaskDetail(_searchResultList);
			}
		}
	} else {
		if (i>_taskList.size()||i<=0) {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		} else {
			_taskIt= _taskList.begin();
			getPosition(i);
		}
	}

	storePreviousTask(commandType);
	_taskList.erase(_taskIt);
	isSuccess = true;
	return toStringTaskDetail();
}



//record edited task item for undo function
void Storage::storePreviousTask(string commandType) {
	//creat a list storing tasks being editted
	_previousTaskList.clear();
	_previousTaskList.push_back(*(_taskIt));

	//create a record to store commandType and the list of tasks
	_record = Record(commandType, _previousTaskList);
	//add the record to the tracker
	addToTracker();
	//clear the _record
	_record.clear();
}

list<Task> Storage::getPreviousTaskList(){
	return _previousTaskList;
}

string Storage::toStringTaskDetail(list <Task> listToFormat){
	ostringstream s;
	if(listToFormat.empty()) {
		s << "The schedule is empty.";
		return s.str();
	} else {
		list <Task>::iterator iter;
		int index = 0;
		for (iter = listToFormat.begin(); iter != listToFormat.end(); iter++) {
			/****Index****/
			index++;
			s << index << "]"; // "]" as a divider to divide each component
			/****check if Mark as Done****/
			if(iter->isDone()) {
				s << "Yes" << "]";
			} else {
				s << "No" << "]";
			}
			/****For floating task****/
			if (iter->getTaskType() == "FloatingTask") {
				s << "Float]" << iter->getName() << "]N.A.]N.A.]N.A.]";
			} else { //for other 2 types of tasks
				/****Task Type****/
				if (iter->getTaskType() == "TimedTask") {
					s << "Timed]";
				} else {
					s << "Deadline]";
				}
				/****Task name and date****/
				s << iter->getName() << "]" << iter->getAlphabetDate() << "]";
				/****start and end time****/
				if (iter->getTaskType() == "TimedTask") {
					if(iter->getStartTimeHour() < 10) {
						s << "0" << iter->getStartTimeHour() <<":";
					} else {
						s << iter->getStartTimeHour() << ":";
					}
					if(iter->getStartTimeMin() < 10) {
						s << "0" << iter->getStartTimeMin() << "]";
					} else {
						s << iter->getStartTimeMin() << "]";
					}
				} else {
					s << "N.A.]"; //start time Non Applicable
				}

				if(iter->getEndTimeHour() < 10) {
					s << "0" << iter->getEndTimeHour() <<":";
				} else {
					s << iter->getEndTimeHour() << ":";
				}
				if(iter->getEndTimeMin() < 10){
					s << "0" << iter->getEndTimeMin() <<"]";
				} else {
					s << iter->getEndTimeMin() << "]";
				}
			}
		}
		return s.str();
	}
}

string Storage::toStringTaskDetail() {
	isSearched = false;
	stringstream s;
	if(_taskList.empty()) {
		s << "The schedule is empty.";
		return s.str();
	} else {
		int index = 1;
		for (_taskIt = _taskList.begin(); _taskIt != _taskList.end(); _taskIt++) {
			/****Index****/
			s << index << "]"; // "]" as a divider to divide each component
			/****check if Mark as Done****/
			if(_taskIt->isDone()) {
				s << "Yes" << "]";
			} else {
				s << "No" << "]";
			}
			/****For floating task****/
			if (_taskIt->getTaskType() == "FloatingTask") {
				s << "Float]" << _taskIt->getName() << "]N.A.]N.A.]N.A.]";
			} else { //for other 2 types of tasks
				/****Task Type****/
				if (_taskIt->getTaskType() == "TimedTask"){
					s << "Timed]";
				} else {
					s << "Deadline]";
				}
				/****Task name and date****/
				s << _taskIt->getName() << "]" << _taskIt->getAlphabetDate() << "]";
				/****start and end time****/
				if (_taskIt->getTaskType() == "TimedTask") {
					if(_taskIt->getStartTimeHour() < 10) {
						s << "0" << _taskIt->getStartTimeHour() <<":";
					} else {
						s << _taskIt->getStartTimeHour() << ":";
					}
					if(_taskIt->getStartTimeMin() < 10) {
						s << "0" << _taskIt->getStartTimeMin() << "]";
					} else {
						s << _taskIt->getStartTimeMin() << "]";
					}
				} else {
					s << "N.A.]"; //start time Non Applicable
				}

				if(_taskIt->getEndTimeHour() < 10){
					s << "0" << _taskIt->getEndTimeHour() <<":";
				} else {
					s << _taskIt->getEndTimeHour() << ":";
				}
				if(_taskIt->getEndTimeMin() < 10){
					s << "0" << _taskIt->getEndTimeMin() <<"]";
				} else {
					s << _taskIt->getEndTimeMin() << "]";
				}
			}
			index++;
		}
	}
	return s.str();
}

string Storage::getCommandList(){
	return COMMANDLIST;
}

Tracker Storage::getTracker(){
	return _tracker;
}

void Storage::deleteLastTrackerEntry(){
	_tracker.deleteLastTrackerEntry();
}

void Storage::undoingReverseAdd(list<Task> listToUndo){
	//delete the task in the list
	list<Task>::iterator it1, it2;
	list<Task> newTaskList;

	for(it1 = listToUndo.begin(); it1 != listToUndo.end(); it1++ ){
		//compare the tasks in the listToUndo with tasks inside _taskList for exact match
		if(compareTask(*it1)){
			//if there is exact match
			//delete the exact matched task from _taskList
			for(it2 = _taskList.begin(); it2 != _taskList.end(); it2++){
				if(it2 != _taskIt){
					newTaskList.push_back(*it2);
				}
			}
			_taskList = newTaskList;
		}
	}
	
}


void Storage::undoingReverseDelete(list<Task> listToUndo){
	//add the tasks back into the _taskList
	list<Task>::iterator it;
	for(it = listToUndo.begin(); it != listToUndo.end(); it++ ){
		_taskList.push_back(*it);
	}
}

void Storage::undoingReverseDone(list<Task> listToUndo){
	//mark the task as not done
	list<Task>::iterator it;
	for(it = listToUndo.begin(); it != listToUndo.end(); it++ ){
		if(compareTask(*it)){
			_taskIt->markNotDone();
		}
	}
}

void Storage::undoingReverseNotDone(list<Task> listToUndo){
	//mark the task as done
	list<Task>::iterator it;
	for(it = listToUndo.begin(); it != listToUndo.end(); it++ ){
		if(compareTask(*it)){
			_taskIt->markDone();
		}
	}
}


