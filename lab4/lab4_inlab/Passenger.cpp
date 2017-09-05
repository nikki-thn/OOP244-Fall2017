// TODO: add your headers here 
#include<iostream>
#include"Passenger.h"


// TODO: continue your namespace here
using namespace std;
using namespace sict;


// TODO: implement the default constructor here
Passenger::Passenger() {



}

// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char* name_, const char* destination_) {

	bool valid = name_ != "";
	//&& name_ != nullptr && destination_ != "" && destination_ != nullptr;

		cout << valid << endl;
		if (valid == true) {

			cout << name_ << endl;
		//	strcpy(name, name_);
		//	strcpy(destination, destination_);

		}

		else {

			strcpy(name, nullptr);
			strcpy(destination, nullptr);

		}

		cout << "n" << name << destination << endl;

}


// TODO: implement isEmpty query here
bool Passenger::isEmpty() const {
	bool isEmpty = false;

	if (name != nullptr && destination != nullptr) {

		isEmpty = true;

	}

	return isEmpty;
}


// TODO: implement display query here
void Passenger::display() const {

	cout << name << "-" << destination;

}

