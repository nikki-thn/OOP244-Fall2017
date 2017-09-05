// TODO: add header file guard here 
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

#define SIZE 32


// TODO: declare your namespace here
namespace sict {

	// TODO: define the Passenger class here
	class Passenger {

		char passengerName[SIZE + 1];
		char destination[SIZE + 1];
		int departYear;
		int departMonth;
		int departDay;

	public:

		Passenger(); //default constructor
		Passenger(const char* name_, const char* destination_); //constructor of 2 parameters
		Passenger(const char *name_, const char* destination_, int day, int month, int year); //constructor with 5 parameters

		bool isEmpty() const;
		void display() const;

		const Passenger& Passenger::name() const;
		bool canTravelWith(const Passenger&) const;


	};

}

#endif
