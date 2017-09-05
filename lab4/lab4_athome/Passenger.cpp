// TODO: add your headers here 
#include<iostream>
#include"Passenger.h"

// TODO: continue your namespace here
using namespace std;

namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {

		passengerName[0] = '\0';
		destination[0] = '\0';
		
		departDay = 0;
		departMonth = 0;
		departYear = 0;

	}     

	//Constructor with 5 parameters here
	Passenger::Passenger(const char *name_, const char* destination_, int year, int month, int day) {

		if (name_ != nullptr && destination_ != nullptr &&
			name_ != "" && destination_ != "" &&
			day <= 31 && day >= 1 && 
			month <= 12 && month >= 1 &&
			year <= 2020 && year >= 2017){

			strcpy(passengerName, name_);
			strcpy(destination, destination_);
			departMonth = month;
			departYear = year;
			departDay = day;
		}

		else {

			passengerName[0] = '\0';
		}

	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name_, const char* destination_) {
	
		if (name_ != nullptr && destination_ != nullptr) {

			departDay = 1;
			departMonth = 7;
			departYear = 2017;
		}

		else {
			passengerName[0] = '\0';
		}

	}


	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {

		bool isEmpty = true;
		
		if (passengerName[0] != '\0') {
			isEmpty = false;
		}

		return isEmpty;
	}


	// TODO: implement display query here
	void Passenger::display() const {

		cout << passengerName << " - " << destination;
		cout << " on " << departYear << "/";
		cout.fill('0');
		cout.width(2);
		cout << departMonth << "/" << departDay << endl;

	}

	const Passenger& Passenger::name() const {

		return *this;

	}


	bool Passenger::canTravelWith(const Passenger& b) const {

		Passenger a = *this;
		bool isTravelWith = false;

		if (a.destination == b.destination) {
			isTravelWith = true;
		}

		cout << isTravelWith << endl;

		return isTravelWith;
		
	}

}
