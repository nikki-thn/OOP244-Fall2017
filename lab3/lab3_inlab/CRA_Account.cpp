/*
Nikki Truong - 112 214 174
OOP244 - Section B
Workshop 2 - in lab
*/

#include <iostream>
#include <cstring>
#include "CRA_Account.h"


using namespace std;

namespace sict {

	//mutator to set value for object
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		bool valid = true;

		if (sin < min_sin || sin > max_sin) {

			valid = false;
			cout << "Invalid Input! Try again." << endl;
		}

		if (valid == true) {

			strcpy(m_firstName, givenName);
			strcpy(m_lastName, familyName);
			m_sin = sin;
		}

		else {

			m_sin = 0;
		}
	}
        
	//check if object is empty
	bool CRA_Account::isEmpty() const {

		bool isValid = false;

		if (m_sin != 0) {

			isValid = true;
		}

		return isValid;
	}

	//query
	void CRA_Account::display() const {

		bool valid;

		valid = isEmpty();

		if (valid == false) {

			cout << "Account object is empty!" << endl;
		}

		if (valid == true) {

			cout << "Family Name: " << m_lastName << endl;
			cout << "Given Name: " << m_firstName << endl;
			cout << "CRA Account: " << m_sin << endl;
		}
	}

}
