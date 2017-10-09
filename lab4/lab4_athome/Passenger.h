/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 4 - At_home
*/

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

		int m_departYear;
		int m_departMonth;
		int m_departDay;

	public:

		Passenger(); //default constructor
		Passenger(const char *, const char*); //overload constructor with 2 parameters
		Passenger(const char *, const char*, int , int , int ); //constructor with 5 parameters

		bool isEmpty() const; //to check if object is empty
		void display() const; //display

		const char* name() const; //return address of name or empty address if object is empty
		bool canTravelWith(const Passenger&) const; //to check is a passenger can travel with another

	};

}

#endif
