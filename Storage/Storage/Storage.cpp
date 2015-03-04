#include "Storage.h"

using namespace std;

list<FloatTask> Storage::_FloatList;
list<FloatTask>::iterator Storage::_FloatIt;
bool Storage::_isDuplicate;

Storage::Storage() {}

void Storage::storeFloat(string name) {
	if (!isFloatDuplicate(name)) {
		FloatTask task(name);
		_FloatList.push_back(task);
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


