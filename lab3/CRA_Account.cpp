#include <iostream>
#include "CRA_Account.h"


using namespace std;

namespace sict {

	void CRA_Account::set (const char* familyName, const char* givenName, int sin) {
		
		bool valid = true;

		if (sin < MIN_SIN && sin > MAX_SIN)
			valid = false;

		if (valid) {

			SIN = sin;
			*lastName = *familyName;
			*firstName = *givenName;

		}
		else {
			SIN = 0;
		}


	}

	bool CRA_Account::isValid() const {
		bool isValid =  
		if (SIN != 0) {

		}
	}

	void CRA_Account::display() const {


	}


}
