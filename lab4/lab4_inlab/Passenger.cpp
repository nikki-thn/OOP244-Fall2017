// TODO: add your headers here 
#include<iostream>
#include<cstring>
#include"Passenger.h"


// TODO: continue your namespace here
using namespace std;
using namespace sict;


// TODO: implement the default constructor here
Passenger::Passenger() {

	name[0] = '\0';
	destination[0] = '\0';
}

// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char* name, const char* destination) {

	if (name_ != nullptr && destination_ != nullptr) {
		strcpy(m_name, name);
		strcpy(m_destination, destination);
	}
	else {
		this* = Passenger();
	}
}


// TODO: implement isEmpty query here
bool Passenger::isEmpty() const {

	bool isEmpty = true;
	if (name[0] != '\0' && destination[0] != '\0') {
		isEmpty = false;
	}

	return isEmpty;
}


// TODO: implement display query here
void Passenger::display() const {
	
	bool notEmpty = isEmpty();
	if (notEmpty == true){
	cout << name << " - " << destination << endl;
	}
	else {
	cout << "No Passengers!" << endl;
}
