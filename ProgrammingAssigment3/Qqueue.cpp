// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 3/21/2021
// Project Name: Programming Assignment #3


#include "Qqueue.h"
#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <fstream>



std::string empty = "\nQueue is empty!!";


//Parameterized Constructor
Qqueue::Qqueue(int cap) 
{
	Capacity = cap;
	front = 0;
	back = 0;
	num = 0;
	DynamicQueue = new std::string[Capacity];
}
//Copy Constructor
Qqueue::Qqueue(const Qqueue& copy) 
{
	// 
	Capacity = copy.Capacity;
	DynamicQueue = new std::string[Capacity];
	front = copy.front;
	num = copy.num;
	for (int b = 0; b < num; b++) {
		DynamicQueue[b] = copy.DynamicQueue[(front + b) % Capacity];
	}

	back = copy.back;
	std::cout << " The Copy Constructor just ran\n";

}
//Deconstructor
Qqueue::~Qqueue() 
{
	delete[] DynamicQueue; 
	std::cout << "\nThe Destructor just ran. \n";
}
//Adds an element to the end of the queue.
void Qqueue::enqueue(const std::string& s) 
{
	if (size() == Capacity)
	{
		std::cout << "\nFull. Restart. ERRORRRRR\n";
	}
	else 
	{
		DynamicQueue[back] = s;
		back = (back + 1) % Capacity;
		num = num +1; //Increment number of elements in the array
	}
}
//Removes an element front he front of the queue
std::string Qqueue::dequeue() 
{
	//So if empty = true, set front and back to default values. (the start), return empty
	if (IsEmpty() == true) 
	{
		return empty;
	}
	// 
	else 
	{
		front = (front + 1) % Capacity;
		num = num - 1;
		std::string dQ = "\nDequeue just ran and removed whatever element that was at the front\n";
		return dQ;
	}
}
void Qqueue::Save(std::ofstream& out) {
	for (int i = 0; i < num; i++)
	{
		out << DynamicQueue[(front + i) % Capacity] << "\n";
	}
}
 std::string& Qqueue::getfront() const
 {
	 if (IsEmpty() == true) 
	 {
		 return empty;
	 } 
	 else 
	 {
		 return DynamicQueue[front];
	 }
  }

 std::string& Qqueue::getback() const 
 {

	 if (IsEmpty() == true) 
	 {
		 return empty;
	 }
	 else 
	 {
		 return DynamicQueue[(back - 1) % Capacity];
	 }
 }

 bool Qqueue::IsEmpty() const 
 {
	 if (num == 0)
	 {	
		 std::cout << empty;
		 return true;
	 }
	 else 
	 {
		 return false;
	 }
 }
 bool Qqueue::IsFull() const 
 {
	 if (num == Capacity)
	 {
		 std::cout << "\nQueue is full.\n";
		 return true;
	 }
	 else
	 {
		 return false;
	 }
 }
void Qqueue::print() const 
{
	for (int i = 0; i < num ; i++)
	{
		std::cout << DynamicQueue[i] << "\n";
	}
	std::cout << "\nNumber of elements printed out: " << num;
	std::cout << "\nPrint function just ran successfully\n";
	
}
int Qqueue::size() const 
{
		return num;
}
int Qqueue::getCapacity() const 
{
	return Capacity;
}
//Look through each element and if they are the same update the counter, else break. Once counter = capacity its good!
bool Qqueue::equals(const Qqueue& q) const 
{
	if (num == q.size()) {
		for (int j = 0; j < num; j++)
		{	//Compare elements
			if (DynamicQueue[(front + j) % Capacity] == q.DynamicQueue[(q.front + j) % q.getCapacity()])
			{
				break;
			}
			else
			{
				return true;
			}
		}
	} else {
		return false;
	}
	return true;
}


