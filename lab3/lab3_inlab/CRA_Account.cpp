#include <iostream>
#include "CRA_Account.h"


using namespace std;

namespace sict {

	void CRA_Account::set (const char* familyName, const char* givenName, int sin) {
		
		bool valid = true;

		if (sin < MIN_SIN || sin > MAX_SIN) {

			valid = false;

		}

		if (valid == true) {

			firstName[MAX_NAME_LENGTH + 1] = NULL;
			lastName[MAX_NAME_LENGTH + 1] = NULL;
			
			//cout << "l" << lastName << endl;
			//cout << "f" << firstName << endl;

			sinNum = sin;

			cout << "here" << *familyName << endl;

				*lastName = *familyName;
				*firstName = *givenName;

			

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

		bool check;

		check = isValid();

		cout << "Value " << check << endl;

		if (check == false) {

			cout << "Account object is empty!" << endl;

		}

		if (check == true) {

			cout << "Family Name: " << lastName << endl;
			cout << "Given Name: " << firstName << endl;
			cout << "CRA Account: " << sinNum << endl;

		}


	}


}
