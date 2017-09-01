#include <iostream>
#include "CRA_Account.h"


using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

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

			m_years = 0;

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

		cout << "Value " << valid << endl;

		if (valid == false) {

			cout << "Account object is empty!" << endl;

		}

		if (valid == true) {

			cout << "Family Name: " << lastName << endl;
			cout << "Given Name: " << firstName << endl;
			cout << "CRA Account: " << sinNum << endl;

			for (int i = 0; i < MAX_YRS; i++) {

				if (m_balance[i] > 2.0 ) {

					cout << "Year" << m_year[i] << "balance owing: " << m_balance[i] << endl;
				}

				else if (m_balance[i] < 2.0 ) {

					cout << "Year" << m_year[i] << "refund due: " << m_balance[i] << endl;
				}

				else {

					cout << "Year" << m_year[i] << "No balance owing or refund due!" << endl;
				}
			}
		}


	}

	void CRA_Account::set(int year, double balance) {

		bool valid;
		int count = 0;

		valid = isValid();

		m_year[MAX_YRS] = 0;
		m_balance[MAX_YRS] = 0;

		if (valid == true) {

			if (count < MAX_YRS) {
				
				m_year[count] = year;
				m_balance[count] = balance;

				count++;

			
			}

		}


	}


}
