// TODO: add header file guard here 
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

#define SIZE 32

// TODO: declare your namespace here
namespace sict {

	// TODO: define the Passenger class here
	class Passenger {

		char m_name[SIZE];
		char m_destination[SIZE];

	public:

		Passenger(); //default constructor
		Passenger(const char *name_, const char* destination_); //overload constructor
		
		bool isEmpty() const; //to check if object is empty
		void display() const; //display
	};
}

#endif
