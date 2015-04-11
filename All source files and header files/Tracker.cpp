//@author A0115131B
#include "Tracker.h"
#include <assert.h>

Tracker::Tracker(void) { }
Tracker::~Tracker(void) { }

void Tracker::addRecord(Record newRecord) {
	int a = _recordTracker.size();

	_recordTracker.push(newRecord);

	int b = _recordTracker.size();
	assert(a+1 == b);
}

bool Tracker:: isEmptyTracker() {
	if(_recordTracker.size() == 0) {
		return true;
	} else {
		return false;
	}
}

Record Tracker::getNewestRecord() {
	Record record = _recordTracker.top();
	return record;
}

void Tracker::deleteLastTrackerEntry(){
	int a = _recordTracker.size();

	_recordTracker.pop();
	
	int b =_recordTracker.size();
	assert(b == a-1);
}