#include "Storage.h"
#include "dirent.h"
#include <algorithm>
#include <sstream>

#include <atltime.h>
#include <math.h>
#include <locale>
#include <ctime>

using namespace std;

const int Storage::MIN_MONTHS_IN_A_YEAR = 1;
const int Storage::MAX_MONTHS_IN_A_YEAR = 12;
const int Storage::MIN_DAY_IN_A_MONTH = 1;
const int Storage::MAX_DAYS_IN_A_MONTH[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int Storage::MIN_HOURS_IN_A_DAY = 0;
const int Storage::MAX_HOURS_IN_A_DAY = 23;
const int Storage::MIN_MINUTES_IN_AN_HOUR = 0;
const int Storage::MAX_MINUTES_IN_AN_HOUR = 59;

const int Storage::SHIFT_BY_ONE = 1;

const string Storage::FLOATING_TASK = "FloatingTask";
const string Storage::DEADLINE_TASK = "DeadlineTask";
const string Storage::TIMED_TASK = "TimedTask";

const string Storage::LINE_BUFFER = "%s/%s/%s/%s/%s/%s/%s/%s/%s/%s/%s";
const string Storage::COMMANDLIST = "List of commands:\n1. add\n2. display\n3. delete\n4. search\n5. done\n6. undone";
const string Storage::PATH_NAME_BUFFER ="%s";

char Storage::buffer[1000];
list<Task> Storage::_taskList;
list<Task> Storage::_searchResultList;
list<Task> Storage::_previousTaskList;
list<Task>::iterator Storage::_taskIt;
ofstream Storage::_fWrite;
ifstream Storage::_fRead;
string Storage::_fileName;
string Storage::_pathName;
bool Storage::isSuccess;
bool Storage::isSearched;
bool Storage::isDateValid;
bool Storage::isTimeValid;
Record Storage::_record;
Tracker Storage::_tracker;
int Storage::_index;

DIR *dir = NULL;
struct dirent *ent;


//@author A0111446R
Storage::Storage() {
isSearched = false;
isSuccess = false;
}

void Storage::setFileName(string name) {
	_fileName = name;
	string fileType = ".txt";
	size_t findPos = name.find(fileType);
	if (findPos==std::string::npos) {
	_fileName += fileType;
	} 
}

void Storage::setPathName(string name) {
	_pathName =name;
}

bool Storage::isValidDirectory() {
	return (((dir = opendir (_pathName.c_str())) != NULL));
}

void Storage::openFile() {
	string pathName = _pathName;
	string combined = pathName + "/" + _fileName;
	_fWrite.open(combined);
}

void Storage::writeToFile() {
	_taskIt = _taskList.begin();
	for (int i=1;i<=_taskList.size();i++) {
		sprintf_s(buffer, LINE_BUFFER.c_str(), ((_taskIt->getCommandType()).c_str())
			, (_taskIt->getTaskType()).c_str(), (_taskIt->getName()).c_str()
			, to_string(_taskIt->getYear()).c_str(), to_string((_taskIt->getMonth())).c_str()
			, to_string(_taskIt->getDay()).c_str(), to_string(_taskIt->getStartTimeHour()).c_str()
			, to_string(_taskIt->getStartTimeMin()).c_str(), to_string(_taskIt->getEndTimeHour()).c_str()
			, to_string(_taskIt->getEndTimeMin()).c_str(), to_string(_taskIt->getIsDone()).c_str());
		_fWrite << buffer << "\r\n";
		_taskIt++;
	}
	_fWrite.close();
}

//this is extremely inefficient but sigh
void Storage::readFile() {

	string pathName = _pathName;
	string combined = pathName + "/" + _fileName;
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
	int startTimeHour;
	int startTimeMin;
	int endTimeHour;
	int endTimeMin;
	bool isDone;

	string devider = "/";
	Task* inputTask;

	while (getline(_fRead,input)) {
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
		startTimeHour = stoi(input.substr((posD6+1), (posD7-posD6)));
		startTimeMin = stoi(input.substr((posD7+1), (posD8-posD7)));
		endTimeHour = stoi(input.substr((posD8+1), (posD9-posD8)));
		endTimeMin = stoi(input.substr((posD9+1), (posD10-posD9)));
		isDone = stoi(input.substr(posD10+1));
		
		inputTask = new Task(commandType,taskType,name,year,month,day,startTimeHour,startTimeMin,endTimeHour,endTimeMin,isDone);
		_taskList.push_back(*inputTask);
		delete inputTask;
	}
	_fRead.close();
		
}

void Storage::storeTask(Task task) {
	if (isValidDate(task)&&isValidTime(task)&&!isExistingTask(task)) {
		_taskList.push_back(task);
		creatRecordAdd(task);
		sortList();
		getTaskIt(task);
		isDateValid = true;
		isTimeValid = true;
		isSuccess = true;
	} else {
		isSuccess = false;
	}
	if (!isValidDate(task)) {
		isDateValid = false;
	} 
	if (!isValidTime(task)){
		isTimeValid = false;
	} 
}

bool Storage::isExistingTask(Task task) {
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
			&& (i->getIsDone() == task.getIsDone())) {
				_taskIt = i;
				return true;
		} 
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

//@author A0111446R
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

int Storage::getIndex() {
	return(distance(_taskList.begin(), _taskIt)+1);
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

bool Storage::isValidIndex(int i, list<Task> &taskList) {
	return (i<=taskList.size()&&i>0);
}

void Storage::getTaskItFromIndex(int i, list<Task> &taskList) {
	_taskIt = taskList.begin();
	while (i>1) {
		_taskIt++;
		i--;
	}
}

void Storage::getTaskItFromIndex(int i) {
	_taskIt = _taskList.begin();
	while (i>1) {
		_taskIt++;
		i--;
	}
}

void Storage::getTaskIt(Task task) {
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
		}
	}
}

string Storage::executeIndexCommand(int i, string commandType) {
	if (isSearched) {
		if (isValidIndex(i, _searchResultList)) {
			getTaskItFromIndex(i, _searchResultList);
			if (isExistingTask(*_taskIt)) {
				isSuccess = true;
				executeTaskCommand(commandType);
			}  
		} else {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		}
	} else {
		if (isValidIndex(i, _taskList)) {
			getTaskItFromIndex(i);
			isSuccess = true;
			executeTaskCommand(commandType);
		} else {
			isSuccess = false;
		}
	}
	return toStringTaskDetail(_taskList);
}

void Storage::executeTaskCommand(string commandType) {
	storePreviousTask(commandType);
	if (commandType == "done") {
		_taskIt->markDone();
	}
	if (commandType == "notdone") {
		_taskIt->markNotDone();
	}
	if (commandType == "delete") {
		_taskList.erase(_taskIt);
	}
}
	
string Storage::markDone(int i) {
	string commandType = "done";
	return executeIndexCommand(i, commandType);
}

string Storage::markNotDone(int i) {
	string commandType = "notdone";
	return executeIndexCommand(i, commandType);
}

string Storage::deleteByNumber(int i) {
	string commandType = "delete";
	return executeIndexCommand(i, commandType);
}

void Storage::executeEditName(string commandType, string s) {
	_previousTaskList.clear();
	_previousTaskList.push_back(*(_taskIt));
	_taskIt->setName(s);
	_previousTaskList.push_back(*(_taskIt));
	_record = Record(commandType, _previousTaskList);
	addToTracker();
}

void Storage::executeEditTime(string commandType, int sth, int stm, int eth, int etm) {
	_previousTaskList.clear();
	_previousTaskList.push_back(*(_taskIt));
	setTime(sth, stm, eth, etm);
	_previousTaskList.push_back(*(_taskIt));
	_record = Record(commandType, _previousTaskList);
	addToTracker();
}

void Storage::setTime(int sth, int stm, int eth, int etm) {
	_taskIt->setStartTimeHour(sth);
	_taskIt->setStartTimeMin(stm);
	_taskIt->setEndTimeHour(eth);
	_taskIt->setEndTimeMin(etm);
	if (sth==0&&stm==0) {
		_taskIt->setTaskType("DeadlineTask");
	} else {
		_taskIt->setTaskType("TimedTask");
	}
}

void Storage::executeEditDate(string commandType, int year, int month, int day) {
	_previousTaskList.clear();
	_previousTaskList.push_back(*(_taskIt));
	setDate(year, month, day);
	_previousTaskList.push_back(*(_taskIt));
	_record = Record(commandType, _previousTaskList);
	addToTracker();
}

void Storage::setDate(int year, int month, int day) {
	_taskIt->setYear(year);
	_taskIt->setMonth(month);
	_taskIt->setDay(day);
}

string Storage::editTaskName(int i, string s) {
	string commandType = "edit";
	if (isSearched) {
		if (isValidIndex(i, _searchResultList)) {
			getTaskItFromIndex(i, _searchResultList);
			if (isExistingTask(*_taskIt)) {
				isSuccess = true;
				executeEditName(commandType, s);
			}  
		} else {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		}
	} else {
		if (isValidIndex(i, _taskList)) {
			getTaskItFromIndex(i, _taskList);
			isSuccess = true;
			executeEditName(commandType, s);
		} else {
			isSuccess = false;
		}
	}
	sortList();
	getTaskIt(*_taskIt);
	return toStringTaskDetail(_taskList);
}

string Storage::editTaskTime(int i, int sth, int stm, int eth, int etm) {
	string commandType = "edit";
	if (isSearched) {
		if (isValidIndex(i, _searchResultList)) {
			getTaskItFromIndex(i, _searchResultList);
			if (isExistingTask(*_taskIt)) {
				isSuccess = true;
				executeEditTime(commandType, sth, stm, eth, etm);
			}  
		} else {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		}
	} else {
		if (isValidIndex(i, _taskList)) {
			getTaskItFromIndex(i, _taskList);
			isSuccess = true;
			executeEditTime(commandType, sth, stm, eth, etm);
		} else {
			isSuccess = false;
		}
	}
	sortList();
	getTaskIt(*_taskIt);
	return toStringTaskDetail(_taskList);
}


string Storage::editTaskDate(int i, int year, int month, int day) {
	string commandType = "edit";
	if (isSearched) {
		if (isValidIndex(i, _searchResultList)) {
			getTaskItFromIndex(i, _searchResultList);
			if (isExistingTask(*_taskIt)) {
				isSuccess = true;
				executeEditDate(commandType, year, month, day);
			}  
		} else {
			isSuccess = false;
			return toStringTaskDetail(_searchResultList);
		}
	} else {
		if (isValidIndex(i, _taskList)) {
			getTaskItFromIndex(i, _taskList);
			isSuccess = true;
			executeEditDate(commandType, year, month, day);
		} else {
			isSuccess = false;
		}
	}
	sortList();
	getTaskIt(*_taskIt);
	return toStringTaskDetail(_taskList);
}
	
//@author A0115131B
void Storage::creatRecordAdd(Task task) {
	_record = Record( "add", task);
	addToTracker();
}

void Storage::addToTracker() {
		_tracker.addRecord(_record);
		_record.clear();
}


//@author A0115131B    
//record edited task item for undo function
void Storage::storePreviousTask(string commandType) {
	//creat a list storing tasks being editted
	_previousTaskList.clear();
	_previousTaskList.push_back(*_taskIt);

	//create a record to store commandType and the list of tasks
	//add the record to tracker
	_record = Record(commandType, _previousTaskList);
	addToTracker();
}

list<Task> Storage::getPreviousTaskList(){
	return _previousTaskList;
}

list<Task> Storage::allDeadline(){
	_searchResultList.clear();

	for(_taskIt = _taskList.begin(); _taskIt != _taskList.end(); _taskIt++){
		if( (*_taskIt).getTaskType() == "DeadlineTask"){
				_searchResultList.push_back(*_taskIt);
		}
	}

	if(!_searchResultList.empty()){
		isSearched = true;
	}
	
	return _searchResultList;
}
	
list<Task> Storage::allFloating(){
	_searchResultList.clear();

	for(_taskIt = _taskList.begin(); _taskIt != _taskList.end(); _taskIt++){
		if( (*_taskIt).getTaskType() == "FloatingTask"){
				_searchResultList.push_back(*_taskIt);
		}
	}

	if(!_searchResultList.empty()){
		isSearched = true;
	}
	
	return _searchResultList;
}

list<Task> Storage::allTimed(){
	_searchResultList.clear();

	for(_taskIt = _taskList.begin(); _taskIt != _taskList.end(); _taskIt++){
		if( (*_taskIt).getTaskType() == "TimedTask"){
				_searchResultList.push_back(*_taskIt);
		}
	}

	if(!_searchResultList.empty()){
		isSearched = true;
	}
	
	return _searchResultList;
}

list<Task> Storage::allToday(){
	//set year, month, day as today
	time_t now = time(0);	
	struct tm time;
	localtime_s(&time, &now);
	int day =  time.tm_mday;
	int month = time.tm_mon + 1;
	int year = time.tm_year + 1900;

	searchTodayTask(day, month, year);

	return _searchResultList;
}

list<Task> Storage::allTomorrow(){
	//set year, month, day as tomorrow
	time_t now = time(0);	
	struct tm time;
	localtime_s(&time, &now);
	time.tm_mday += 1;
	mktime(&time);
	int day =  time.tm_mday;
	int month = time.tm_mon + 1;
	int year = time.tm_year + 1900;

	searchTodayTask(day, month, year);

	return _searchResultList;
}

list<Task> Storage::allYesterday(){
	//set year, month, day as yesterday
	time_t now = time(0);	
	struct tm time;
	localtime_s(&time, &now);
	time.tm_mday -= 1;
	mktime(&time);
	int day =  time.tm_mday;
	int month = time.tm_mon + 1;
	int year = time.tm_year + 1900;

	searchTodayTask(day, month, year);

	return _searchResultList;
}

list<Task> Storage::autoInitialDisplay(){
	//set year, month, day as system's today time
	time_t now = time(0);	
	struct tm time;
	localtime_s(&time, &now);
	int day =  time.tm_mday;
	int month = time.tm_mon + 1;
	int year = time.tm_year + 1900;

	//search for all tasks happening in today
	//store today's tasks in a list
	searchTodayTask(day, month, year);
	searchUpcomingDeadline(day, month, year);
	return _searchResultList;
}

//return tasks happening in today into _searchResultList
void Storage::searchTodayTask(int day, int month, int year){
	_searchResultList.clear();

	for(_taskIt = _taskList.begin(); _taskIt != _taskList.end(); _taskIt++){
		if( (*_taskIt).getYear() == year 
			&& (*_taskIt).getMonth() == month 
			&& (*_taskIt).getDay() == day){
				_searchResultList.push_back(*_taskIt);
		}
	}
	if(!_searchResultList.empty()){
		isSearched = true;
	}
}

void Storage::searchUpcomingDeadline(int day, int month, int year){
	for(_taskIt = _taskList.begin(); _taskIt != _taskList.end(); _taskIt++){
		if( (*_taskIt).getTaskType() == "DeadlineTask"
			&& ((*_taskIt).getYear() > year || (*_taskIt).getYear() == year)
			&& ((*_taskIt).getMonth() > month || (*_taskIt).getMonth() == month)
			&& ((*_taskIt).getDay() > day)){
				_searchResultList.push_back(*_taskIt);
		}
	}

	if(!_searchResultList.empty()){
		isSearched = true;
	}
}

string Storage::toStringTaskDetail(list <Task> &listToFormat){
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
			if(iter->getIsDone()) {
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

string Storage::getCommandList(){
	return COMMANDLIST;
}

//@author A0115131B
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

void Storage::undoingReverseEdit(list<Task> listToUndo){
	//undo the edit action
	list<Task>::iterator it;
	list<Task> newTaskList;

	Task taskAfterEdit = listToUndo.back();
	if(compareTask(taskAfterEdit)){
		//delete the editted copy
		for (it = _taskList.begin(); it != _taskList.end(); it++){
			if(it != _taskIt){
				newTaskList.push_back(*it);
			}
		}
		//add the before edit copy back
		newTaskList.push_back(*(listToUndo.begin()));
		_taskList = newTaskList;
	}
}

bool Storage::isValidDate(Task task){
	if (task.getTaskType() == FLOATING_TASK){
		return true;
	}
	else if(task.getMonth() < MIN_MONTHS_IN_A_YEAR || task.getMonth() > MAX_MONTHS_IN_A_YEAR){
			return false;	
		} 
}

bool Storage::isValidTime(Task task){
	if (task.getTaskType() == FLOATING_TASK){
		return true;
	} else if(task.getDay() < MIN_DAY_IN_A_MONTH || task.getDay() > MAX_DAYS_IN_A_MONTH[task.getMonth() - SHIFT_BY_ONE]){
		return false;
	} else if(task.getStartTimeHour() < MIN_HOURS_IN_A_DAY || task.getStartTimeHour() > MAX_HOURS_IN_A_DAY){
		return false;
	} else if(task.getStartTimeMin() < MIN_MINUTES_IN_AN_HOUR || task.getStartTimeMin() > MAX_MINUTES_IN_AN_HOUR){
		return false;
	} else if(task.getEndTimeHour() < MIN_HOURS_IN_A_DAY || task.getEndTimeHour() > MAX_HOURS_IN_A_DAY){
		return false;
	} else if(task.getEndTimeMin() < MIN_MINUTES_IN_AN_HOUR || task.getEndTimeMin() > MAX_MINUTES_IN_AN_HOUR){
		return false;
	} else if(task.getStartTimeHour() == task.getEndTimeHour() && task.getStartTimeMin() > task.getEndTimeMin()){
		return false;
	} else if(task.getStartTimeHour() > task.getEndTimeHour()){
		return false;
	} else {
		return true;
	}
}


