/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 4 - In_lab
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
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {

		if (name != nullptr && destination != nullptr) {
			strcpy(m_name, name);
			strcpy(m_destination, destination);
		}
		else {
			m_name[0] = '\0';
			m_destination[0] = '\0';
		}
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
			cout << m_name << " - " << m_destination << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}


}
