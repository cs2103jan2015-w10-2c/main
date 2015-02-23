#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TaskNode
{
 public:
   // Constructors
   TaskNode();
   TaskNode(const string name, const string date);
   TaskNode(const TaskNode &node);
   ~TaskNode();

   // Methods
   bool readData();
   void setNext(TaskNode* next);
   void print() const;

 private:
   string Name;
   string Date;

   TaskNode *Next;
};

//----------------------------------------------
// Constructor method
//----------------------------------------------
TaskNode::TaskNode()
{
   Name = "";
   Date = "";

   Next = NULL;
}

//----------------------------------------------
// Constructor method with parameters
//----------------------------------------------
TaskNode::TaskNode(const string name, const string date) 
{
   Name = name;
   Date = date;
   Next = NULL;
}

//----------------------------------------------
// Copy constructor method
//----------------------------------------------
TaskNode::TaskNode(const TaskNode &node)
{
   Name = node.Name;
   Date = node.Date;
 
   Next = NULL;
}

//----------------------------------------------
// Destructor method
//----------------------------------------------
TaskNode::~TaskNode()
{
}

//----------------------------------------------
// Method:   readData
// Purpose:  Read data from file into linked list, and print contents of the list.
//----------------------------------------------
bool TaskNode::readData()
{
   // Declare local variables
   string name, date;
      name = date = "";

   // Get file name
   string filename = "";
   cout << "Enter file name: ";
   cin >> filename;

   // Open input file
   ifstream din;
   din.open(filename.c_str());
   if (din.fail())
   {
      cerr << "Could not open file: " << filename << endl;
      return false;
   }

   // Read data
   TaskNode *head = NULL;
   while (!din.eof())
   {
      din >> name >> date;

      TaskNode *temp = new TaskNode(name, date);
      temp->setNext(head);
      head = temp;
   }

   din.close();
   head->print();
   return true;
}

//----------------------------------------------
// setNext method
//----------------------------------------------
void TaskNode::setNext(TaskNode* next)
{
   Next = next;
}

//----------------------------------------------
// Print method
// This basically prints everything without discretion -.-
//----------------------------------------------
void TaskNode::print() const
{
   cout << Name << "    " << Date << endl;
   if (Next != NULL)
      Next->print();
}

//----------------------------------------------
// Main program
//----------------------------------------------

int main()
{
   TaskNode list;
   if (list.readData())
      cout << "Success" << endl;
   else
      cout << "Fail" << endl;

   return 0;
}