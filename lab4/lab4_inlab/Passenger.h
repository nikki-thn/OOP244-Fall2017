// TODO: add header file guard here 
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

#define SIZE 32


// TODO: declare your namespace here
namespace sict {

	// TODO: define the Passenger class here
	class Passenger {

		char name[SIZE + 1];
		char destination[SIZE + 1];

	public:

		Passenger(); //default constructor
		Passenger(const char *name_, const char* destination_); //overload constructor

		bool isEmpty() const;
		void display() const;

	};

}

#endif
