//@author A0115131B
#include "Tracker.h"

Tracker::Tracker(void) { }
Tracker::~Tracker(void) { }

void Tracker::addRecord(Record newRecord) {
	_recordTracker.push(newRecord);
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
	_recordTracker.pop();
}