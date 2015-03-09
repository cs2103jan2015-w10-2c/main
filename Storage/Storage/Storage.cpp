#include "Storage.h"
#include "dirent.h"

using namespace std;

const string Storage::LINE_BUFFER = "%s\\%s\\%s\\%s\\%s\\%s\\%s\\%s\\%s\\%s\\%s";

char Storage::buffer[255];
list<Task> Storage::_TaskList;
list<Task>::iterator Storage::_TaskIt;
ofstream Storage::_fWrite;
ifstream Storage::_fRead;
string Storage::_fileName;

bool Storage::_isDuplicate;
DIR *dir = NULL;
struct dirent *ent;

Storage::Storage() {}

void Storage::setFileName(string name) {
	_fileName = name;
}

void Storage::showDirectory() {
	if ((dir = opendir ("./Databank")) != NULL) {
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
	dir = opendir ("./Databank");
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
	cout << _TaskList.size();
	int i;
	_TaskIt = _TaskList.begin();
	for (i=1;i<=_TaskList.size();i++) {
		sprintf_s(buffer, LINE_BUFFER.c_str(), (to_string(_TaskIt->getSerialID()).c_str())
			, (_TaskIt->getCommandType()).c_str(), (_TaskIt->getName()).c_str()
			, to_string((_TaskIt->getDate()).year).c_str(), to_string((_TaskIt->getDate()).month).c_str()
			, to_string((_TaskIt->getDate()).day).c_str(), to_string(_TaskIt->getStartTime()).c_str()
			, to_string(_TaskIt->getEndTime()).c_str(), to_string(_TaskIt->getDone()).c_str()
			, to_string(_TaskIt->getFloat()).c_str(), to_string(_TaskIt->getDeadline()).c_str());
		cout << buffer;
		_fWrite << buffer << endl;
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

	double serialID;
	string commandType;
	string name;
	Date date;
	double startTime;
	double endTime;
	bool isDone;
	bool isFloat;
	bool isDeadline;

	string devider = "\\";
	Task* inputTask;

	while (!_fRead.eof()) {
		_fRead>>input;
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


		serialID = stod(input.substr(posStart, (posD1-posStart)));
		commandType = (input.substr(posD1+1, (posD2-posD1)));
		name = (input.substr(posD2+1, (posD3-posD2)));
		date.year = stoi(input.substr(posD3+1, (posD4-posD3)));
		date.month = stoi(input.substr(posD4+1, (posD5-posD4)));
		date.day = stoi(input.substr(posD5+1, (posD6-posD5)));
		startTime = stod(input.substr(posD6+1, (posD7-posD6)));
		endTime = stod(input.substr(posD7+1, (posD8-posD7)));
		isDone = stoi(input.substr(posD8+1, (posD9-posD8)));
		isFloat = stoi(input.substr(posD9+1, (posD10-posD9)));
		isDeadline = stoi(input.substr(posD10+1));

		inputTask = new Task(serialID,commandType,name,date,startTime,endTime,isDone,isFloat,isDeadline);
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
	_isDuplicate = false;
	_TaskIt = _TaskList.begin();
	for (int i=1;i<=_TaskList.size();i++) {
		if ((task.getName())==(_TaskIt->getName())) {
			if ((task.getStartTime())==(_TaskIt->getStartTime())) {
				_isDuplicate = true;
			}
		}
		_TaskIt++;
	}
	return _isDuplicate;
}

//comment the main function when integrating

int main () {
	Storage::showDirectory();
	string filename;
	cin >> filename;
	Storage::setFileName(filename);
	Storage::openFile();
	Task hello("add", "lol");
	Storage::storeTask(hello);
	Storage::storeTask(hello);
	Storage::writeToFile();
	cin >> filename;
	return 0;
}


