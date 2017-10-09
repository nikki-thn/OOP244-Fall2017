/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 4 - At home
*/


// TODO: add your headers here 
#include<iostream>
#include<cstring>
#include"Passenger.h"

// TODO: continue your namespace here
using namespace std;

namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {

		m_name[0] = '\0';
		m_destination[0] = '\0';

		m_departDay = 0;
		m_departMonth = 0;
		m_departYear = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {

		if (name != nullptr && destination != nullptr && strlen(name) < SIZE && strlen(destination) < SIZE) {

			strncpy(m_name, name, SIZE);
			strncpy(m_destination, destination, SIZE);
		}
		else {
			*this = Passenger();
		}
	}

	//Constructor with 5 parameters here
	Passenger::Passenger(const char *name, const char* destination, int year, int month, int day) {

		//call 2 parameters constructors to set name and destination
		*this = Passenger(name, destination);
		
		//check for validity of year, month and day
		if (name != nullptr && destination != nullptr &&
			day <= 31 && day >= 1 &&
			month <= 12 && month >= 1 &&
			year <= 2020 && year >= 2017) {

			m_departMonth = month;
			m_departYear = year;
			m_departDay = day;
		}
		else {
			*this = Passenger();
		}
	}
	
	const char* Passenger::name() const{
	
		return m_name;
	}


	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {

		bool isEmpty = true;

		if (m_name[0] != '\0' && m_destination[0] != '\0') {
			isEmpty = false;
		}
		return isEmpty;
	}

	// TODO: implement display query here
	void Passenger::display() const {

		bool empty = isEmpty();

		if (empty == false) {

			cout << m_name << " - " << m_destination;
			cout << " on " << m_departYear << "/";
			cout.fill('0');
			cout.width(2);
			cout << m_departMonth << "/" << m_departDay << endl;
		}
		else {

			cout << "No passenger!" << endl;
		}
	}

	bool Passenger::canTravelWith(const Passenger& b) const {

		Passenger a = *this;
		bool isTravelWith = false;

		if (!(strcmp(b.m_destination, a.m_destination)) &&
			b.m_departDay == a.m_departDay &&
			b.m_departMonth == a.m_departMonth &&
			b.m_departYear == a.m_departYear) {

			isTravelWith = true;
		}
		return isTravelWith;
	}

}
