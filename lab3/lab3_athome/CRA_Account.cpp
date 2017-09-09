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

			m_year[MAX_YRS] = 0;
			m_balance[MAX_YRS] = 0;
			m_years = 0;

		}

		else {

			sinNum = 0;
		
		}


	}

	bool CRA_Account::isValid() const {

		bool isValid = false;
		int digits[5] = { 0 };
		int alternate[4] = { 0 };
		int remain[7] = { 0 };
		int multiple = 0;
		int difference = 0;

		if (sinNum != 0) {

			//Extract numbers and assigns them into arrays
			remain[0] = sinNum % 100000000;
			digits[0] = (sinNum - remain[0]) / 100000000;

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

				//	cout << "alternates " << alternate[i] << endl;

				sum = alternate[i] * 2;
				secondDigit = (sum % 10);
				firstDigit = (sum - secondDigit) / 10;

				//	cout << "first " << firstDigit << "second " << secondDigit << endl;

				alternateSum = firstDigit + secondDigit;

				//	cout << "alternatesSum " << alternateSum << endl;

				total += alternateSum;

			}

			//	cout << "total1 " << total << endl;

			for (int i = 0; i < 4; i++) {

				bubbleSort(digits, 4);

				//	cout << "digits " << digits[i] << endl;

				total += digits[i];

			}

			//Take highest integer in the alternates set and multiply by 10
			multiple = digits[2] * 10;

			//Subtract multiple and total to get the difference
			difference = multiple - total;

			if (difference == digits[4]) {

				//		cout << "SIN is valid" << endl;

				isValid = true;
			}

			else {

				//		cout << "SIN is not valid" << endl;
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

		valid = isValid();

		if (valid == false) {

			cout << "Account object is empty!" << endl;
		}

		if (valid == true) {

			cout << "Family Name: " << lastName << endl;
			cout << "Given Name: " << firstName << endl;
			cout << "CRA Account: " << sinNum << endl;

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

		//CRA_Account temp;

			cout << "num years " << m_years << endl;
		//	cout << year << balance << endl;

		valid = isValid();

		if (valid == true) {

			if (m_years < MAX_YRS) {

				m_year[count] = year;
				m_balance[count] = balance;

				//cout << m_year[count] << m_balance[count] << endl;

				//cout << "m_years" << m_years << endl;

				count++; // **value doesn't change??

			}

			else {

				m_year[count] = 0;
			}

			//cout << "m_years" << m_years << endl;
		}

	//	cout << "balance " << m_balance[count] << endl;
		m_years = count;
	
		cout << "m_years" << m_years << endl;
		//m_years = m_years;
	}


}
