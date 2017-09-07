#include <iostream>
#include <cstring>
#include "CRA_Account.h"



using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		bool valid = true;

		if (sin < MIN_SIN || sin > MAX_SIN) {

			valid = false;
		}

		if (valid == true) {

			strcpy(firstName, givenName);
			strcpy(lastName, familyName);
			sinNum = sin;
		}

		else {

			sinNum = 0;
		}


	}

	bool CRA_Account::isValid() const {

		bool isValid = false;

		if (sinNum != 0) {

			isValid = true;
		}

		return isValid;

	}

	void CRA_Account::display() const {

		bool valid;

		valid = isValid();

		if (valid == false) {

			cout << "Account object is empty!" << endl;
		}

		if (valid == true) {

			cout << "Family Name: " << lastName << endl;
			cout << "Given Name: " << firstName << endl;
			cout << "CRA Account: " << sinNum << endl;
		}
	}


}
