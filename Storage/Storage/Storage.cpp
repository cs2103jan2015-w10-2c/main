#include "Storage.h"

using namespace std;

list<FloatTask> Storage::_FloatList;
list<FloatTask>::iterator Storage::_FloatIt;
bool Storage::_isDuplicate;

Storage::Storage() {}

bool Storage::storeFloat(string name) {
	if (isFloatDuplicate(name)) {
		return false;
	} else {
		FloatTask task(name);
		_FloatList.push_back(task);
		return true;
	}
}

bool Storage::isFloatDuplicate(string name) {
	_isDuplicate = false;
	_FloatIt = _FloatList.begin();
	for (int i=1;i<=_FloatList.size();i++) {
		if (name==(_FloatIt->getName()))
			_isDuplicate = true;
		_FloatIt++;
	}
	return _isDuplicate;
}

//i use this main function for testing my code o.o
//unitTesting too mafan T T
//Please delete away when integrating
int main() {
	string name;
	cout << "Enter float to store: ";
	cin >> name;
	bool isSuccess;
	while (name!="exit") {
	isSuccess = Storage::storeFloat(name);
	if (isSuccess) {
		cout << "Yes" << endl;
	} else {
		cout << "Duplicate" << endl;
	}
	cout << "Enter float to store: ";
	cin >> name;
	}
	return 0;
}