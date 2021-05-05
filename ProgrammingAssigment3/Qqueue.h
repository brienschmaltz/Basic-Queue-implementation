/**
	CS 3100
	Data Structures and Algorithms
	Dr. Meilin Liu
    Spring 2021
**/


#ifndef _QueueClass_
#define  _QueueClass_

#include <cstdlib>
#include <string>

class Qqueue
{
        public:
                // Constructor
                Qqueue( int cap);

                // Copy Constructor
                Qqueue( const Qqueue& s );

                ~Qqueue( ); //destructor
				
		// The member function enqueue: Precondition:  the queue is not full.  If the queue is full, this function signals an error.
                //add value to the end of the queue
		void enqueue ( const std::string&  s); 

				
		// The member function dequeue: Precondition:  the queue is not empty. If the queue is empty, this function signals an error.
		// Removes and returns the first item in the queue.
                std::string dequeue ();

                void Save(std::ofstream& out);

           		// The member function front: Precondition: the queue is not empty.
                std::string&  getfront () const;
				
		// The member function back: Precondition: the queue is not empty.
                std::string&  getback () const;

                bool IsEmpty () const;
                bool IsFull() const;
		//printing all the elements in the queue
				void print() const;

                int size() const;

		int getCapacity() const;

		//Returns true if the two queues contain exactly the same element values in the same order. Identical in behavior to the == operator.
		bool equals(const Qqueue& q) const;  
		// Usage: if (q.equals(q2)) ...

        private:
                int Capacity; // Capacity is the maximum number of items that a queue can hold
                std::string* DynamicQueue; 
                int num; // How many items are stored in the queue
                int front;
                int back;
};


		
#endif
