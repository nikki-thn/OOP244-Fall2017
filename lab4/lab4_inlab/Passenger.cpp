// TODO: add your headers here 
#include<iostream>
#include"Passenger.h"


// TODO: continue your namespace here
using namespace std;
using namespace sict;


// TODO: implement the default constructor here
Passenger::Passenger() {

	name[0] = '\0';
	destination[0] = '\0';
	cout << "name" << name << endl;

}

// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char* name_, const char* destination_) {

	if (name_ != nullptr && destination_ != nullptr) {
		
		strcpy(name, name_);
		strcpy(destination, destination_);

	}

	else {

		name[0] = '\0';
		destination[0] = '\0';
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

	cout << name << " - " << destination << endl;

}
