#include <iostream>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact() {

		name[0] = '\0';
		numOfPhones = 0;
		long long *phoneNum = nullptr;
	}

	Contact::Contact(const char* sourceName, const long long* sourcePhone, int size) {

		phoneNum = new long long[size];

		if (sourceName != nullptr && size != 0) {

			//****problem, can't copy oversize character
			strcpy_s(name, sourceName);

			int count = numOfPhones;

			for (int i = 0; i < size; i++) {
				bool isValid = validCheck(sourcePhone[i]);

				if (isValid == true) {
					phoneNum[count] = sourcePhone[i];
					count++;
					numOfPhones = count;
				}
			}
		}
	}

	Contact::~Contact() {

		//default destructor will delete all dynamic allocated memory
	}

/*	Contact::Contact(const Contact&) {

	}
	Contact& Contact::operator=(const Contact&) {
		return *this;
	}
	Contact& Contact::operator+=(const long long newPhone) {

		bool empty = isEmpty();
		bool valid = validCheck(newPhone);

		if (empty == false) {

			phoneNum[numOfPhones++] = newPhone;
		}

		return *this;
	}*/

	bool Contact::validCheck(const long long toCheck) {

		bool isValid = NULL;

		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;

		extractNum(toCheck, countryCode, areaCode, last3Digits, last4Digits);
		isValid = areaCode >= 100 && countryCode >= 1 && last3Digits >= 100;
		cout << "(+" << countryCode << ") " << areaCode << " " << last3Digits << "-" << last4Digits << endl;
		cout << "is valid" << isValid << endl;
		return isValid;
	}


	void Contact::extractNum (const long long phone, int& country, int& area, int& last3, int& last4) const {

		//cout << "cout" << phone << endl;
		int temp = 0;

		last4 = phone % 10000;
		temp = (phone - last4) / 10000;
		last3 = temp % 1000;
		temp = (temp - last3) / 1000;
		area = temp % 1000;
		country = (temp - area) / 1000;

		cout << "cout" << country << ") " << area << " " << last3 << "-" << last4 << endl;

	}

	bool Contact::isEmpty() const {

		bool isEmpty = true;

		if (name[0] != '\0' && numOfPhones != 0) {

			isEmpty = false;
		}

		return isEmpty;
	}


	void Contact::display() const {

		bool empty = isEmpty();

		if (empty == false) {

			int countryCode = 0;
			int areaCode = 0;
			int last3Digits = 0;
			int last4Digits = 0;

			cout << name << endl;

			for (int i = 0; i < numOfPhones; i++) {

				extractNum(phoneNum[i], countryCode, areaCode, last3Digits, last4Digits);
				cout << "(+" << countryCode << ") " << areaCode << " " << last3Digits << "-" << last4Digits << endl;
			}
		}

		else if (empty == true) {

			cout << "Empty contact!" << endl;
		}
	}

}
