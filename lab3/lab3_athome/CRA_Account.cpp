#include <iostream>
#include <cstring>
#include "CRA_Account.h"



using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		bool valid = true;

		if (sin < min_sin || sin > max_sin) {

			valid = false;
		}

		if (valid == true) {

			strcpy(m_firstName, givenName);
			strcpy(m_lastName, familyName);
			m_sin = sin;

			m_year[max_yrs] = 0;
			m_balance[max_yrs] = 0;
			m_years = 0;

		}

		else {

			m_sin = 0;
		
		}


	}

	bool CRA_Account::isEmpty() const {

		bool isValid = false;
		int digits[5] = { 0 };
		int alternate[4] = { 0 };
		int remain[7] = { 0 };
		int multiple = 0;
		int difference = 0;

		if (m_sin != 0) {

			//Extract all numbers and assigns them into 2 arrays for validation
			remain[0] = m_sin % 100000000;
			digits[0] = (m_sin - remain[0]) / 100000000;

			remain[1] = remain[0] % 10000000;
			alternate[0] = (remain[0] - remain[1]) / 10000000;

			remain[2] = remain[1] % 1000000;
			digits[1] = (remain[1] - remain[2]) / 1000000;

			remain[3] = remain[2] % 100000;
			alternate[1] = (remain[2] - remain[3]) / 100000;

			remain[4] = remain[3] % 10000;
			digits[2] = (remain[3] - remain[4]) / 10000;

			remain[5] = remain[4] % 1000;
			alternate[2] = (remain[4] - remain[5]) / 1000;

			remain[6] = remain[5] % 100;
			digits[3] = (remain[5] - remain[6]) / 100;

			digits[4] = remain[6] % 10;
			alternate[3] = (remain[6] - digits[4]) / 10;

			int total = 0;

			for (int i = 0; i < 4; i++) {

				int alternateSum = 0;
				int sum = 0;
				int firstDigit = 0;
				int secondDigit = 0;

				sum = alternate[i] * 2;
				secondDigit = (sum % 10);
				firstDigit = (sum - secondDigit) / 10;

				alternateSum = firstDigit + secondDigit;

				total += alternateSum;
			}

			for (int i = 0; i < 4; i++) {

				bubbleSort(digits, 4);
				
				total += digits[i];

			}

			//Take highest integer in the alternates set and multiply by 10
			multiple = digits[2] * 10;

			//Subtract multiple and total to get the difference
			difference = multiple - total;

			if (difference == digits[4]) {

				isValid = true;
			}
		}

		return isValid;
	}

	// bubbleSort sorts the elements of a[n] in ascending order 
	// Code is copied from IPC144 - Algorithm chapter
	// Link : https://scs.senecac.on.ca/~ipc144/pages/content/sorts.html

	void bubbleSort(int a[], int n)
	{
		int i, j;
		int temp;

		for (i = n - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (a[j] > a[j + 1]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}


	void CRA_Account::display() const {

		bool valid;

		valid = isEmpty();

		if (valid == false) {

			cout << "Account object is empty!" << endl;
		}

		if (valid == true) {

			cout << "Family Name: " << m_lastName << endl;
			cout << "Given Name : " << m_firstName << endl;
			cout << "CRA Account: " << m_sin << endl;

			for (int i = 0; i < m_years; i++) {
				if (m_balance[i] > 2.0)  {

					cout << "Year " << m_year[i] << " owning: " << m_balance[i] << endl;
				}

				else if (m_balance[i] < -2.0) {

					cout << "Year " << m_year[i] << "refund due: " << m_balance[i] << endl;
				}

				else if (m_balance[i] <= 2.0 && m_balance[i] >= -2.0) {

					cout << "Year " << m_year[i] << " no balance owning or refund due!" << endl;
				}
			}

		}
	}

	void CRA_Account::set(int year, double balance) {

		bool valid;

		int count = m_years;

			cout << "num years " << m_years << endl;
	
		valid = isValid();

		if (valid == true) {

			if (m_years < MAX_YRS) {

				m_year[count] = year;
				m_balance[count] = balance;

				count++; 
			}

			else {

				m_year[count] = 0;
			}
		}

		m_years = count;
	
		cout << "m_years" << m_years << endl;

	}
}
