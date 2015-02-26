#include "FloatTask.h"

FloatTask::FloatTask() {}

FloatTask::FloatTask(string name) {
   _name = name;
   _isDone = false;
}

FloatTask::~FloatTask() {}

string FloatTask::getName() {
	return _name;
}
