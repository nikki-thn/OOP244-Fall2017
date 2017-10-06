// TODO: add your headers here 
#include<iostream>
#include<cstring>
#include"Passenger.h"


// TODO: continue your namespace here
using namespace std;
using namespace sict;


// TODO: implement the default constructor here
Passenger::Passenger() {

	m_name[0] = '\0';
	m_destination[0] = '\0';
}

// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char* name, const char* destination) {

	if (m_name != nullptr && destination != nullptr) {
		strcpy(m_name, name);
		strcpy(m_destination, destination);
	}
	else {
		m_name[0] = '\0';
	        m_destination[0] = '\0'
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
	
	bool notEmpty = isEmpty();
	if (notEmpty == true){
	cout << m_name << " - " << m_destination << endl;
	}
	else {
	cout << "No Passengers!" << endl;
	}
}
}
