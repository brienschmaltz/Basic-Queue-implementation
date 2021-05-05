// Project_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Course Number: 3100
// Course Title: Data Struc & Algorithms
// Name: Brien Schmaltz
// Email: schmaltz.6@wright.edu
// Prof Name: Professor Liu
// Date: 3/21/2021
// Project Name: Programming Assignment #3


#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <istream>
#include <string>
#include "Qqueue.h"
#include <cassert>

int main() {
	
	//My tests ///////////////////////////////////
	std::cout << "Initializing first test.\nTesting everything hard coded, (cap = 101).\nAfter this will be user test.\n";
	int testCap = 101;
	std::string testlastName;
	std::ifstream in;
	Qqueue testQueue(testCap);

	in.open("all.last.txt");
	assert(!in.fail()); //If file doesn't open, throw error. 

	for (int k = 0; k < testCap; k++) {
		std::getline(in, testlastName);
		testQueue.enqueue(testlastName);
	}
	testQueue.print();
	in.close();
	
	//User input tests ////////////////////////////////
	std::cout << "\nEnter in a capacity 10-90: ";
	int userCap;

	//Invalid input checking
	while (!(std::cin >> userCap) || userCap < 10 || userCap > 90) 
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Invalid Input.\n" << "Please enter another, 10-90 : ";
	}
	
	std::string lastName;
	Qqueue userQueue(userCap);
	
	in.open("all.last.txt");
	assert(!in.fail()); //If file doesn't open, throw error. 

	userCap = userCap - 1; 
	//Loop will go into all.last.txt and grab as many last names as the user wants. 
	for (int i = 0; i < userCap; i++) {
		std::getline(in, lastName);
		userQueue.enqueue(lastName);
	} 
	// (6)
	userQueue.print();
	// (3) (4)
	std::cout << "\nTesting Front: " << userQueue.getfront() << " and Back: " << userQueue.getback();


	//Testing other member functions 1-2////////////////////////////////// 
	std::cout << "\n\nTesting member functions on the queue you entered the capacity for.\nCapacity is 2 less than what you entered for testing purposes.\n";
	std::cout << "Testing enqueue.\n";

	//User queue (1)
	std::cout << "Enter in a lastname you would like to add the to the queue:"; 
	std::string q1input;
	std::cin >> q1input;
	userQueue.enqueue(q1input);
	std::cout << "\nPrint again to see if it added.\n";
	userQueue.print();

	//User dequeue (2)
	std::cout << "\nTesting dequeue\n";
	userQueue.dequeue();
	userQueue.print();
	std::cout << "\nYour input is no longer in the queue.\n";

	//Testing (5)
	std::cout << "\nTesting copy constructor and equals\n";
	//Qqueue copy(10);
	Qqueue copy(testQueue);
	std::cout << "\nTestQueue and a copy of test Queue are: 1=true 0 =false: " << copy.equals(testQueue);
	std::cout << "\nTestQueue and userQueue are: 1=true 0 =false: " << copy.equals(userQueue);

	//Testing (7)
	std::cout << "\nTesting save\n";
	//in stream called in.
	std::ofstream out;
	out.open("test.txt");
	testQueue.Save(out);
}
