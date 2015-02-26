#pragma once
#ifndef FLOAT_TASK_H_
#define FLOAT_TASK_H_
#include<string>

using namespace std;

class FloatTask
{
 private:
   string _name;
   bool _isDone;

 public:
   // Constructors
   FloatTask();
   FloatTask(const string name);
   ~FloatTask();

   string getName();

};


#endif