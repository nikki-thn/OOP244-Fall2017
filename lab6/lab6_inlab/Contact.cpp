#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact() {

		name[0] = '\0';
		numOfPhones = 0;
		long long *phoneNum = nullptr;
	}

	Contact::Contact(const char* sourceName, const long long* sourcePhone, int size) {

		*this = Contact();
		phoneNum = new long long[size];
		bool valid;

		if (sourceName != nullptr) {
			strcpy(name, sourceName);
		}
		else if (sourceName == nullptr) {
			*this = Contact();
		}

		for (int i = 0; i < size; i++) {

			valid = validCheck(sourcePhone[i]);

			if (valid == true) {
				
				phoneNum[numOfPhones] = sourcePhone[i]; 
				numOfPhones++;
			}
		}
	}

	Contact::~Contact() {

		//default destructor will delete all dynamic allocated memory
	}

	bool Contact::validCheck(const long long toCheck) {

		bool isValid = NULL;

		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;

		extractNum(toCheck, countryCode, areaCode, last3Digits, last4Digits);
		isValid = areaCode >= 100 && countryCode >= 1 && countryCode <=99 && last3Digits >= 100;

		return isValid;
	}


	void Contact::extractNum(const long long phone, int& country, int& area, int& last3, int& last4) {

		//cout << "cout" << phone << endl;
		int temp = 0;

		last4 = phone % 10000;
		temp = (phone - last4) / 10000;
		last3 = temp % 1000;
		temp = (temp - last3) / 1000;
		area = temp % 1000;
		country = (temp - area) / 1000;
	}

	bool Contact::isEmpty() const {

		bool isEmpty = true;

		if (name[0] != '\0') {
			isEmpty = false;
		}

		return isEmpty;
	}


	void Contact::display() {

		bool empty = isEmpty();

		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;

		if (empty == false) {

			cout << name << endl;

			for (int i = 0; i < numOfPhones; i++) {
				extractNum(phoneNum[i], countryCode, areaCode, last3Digits, last4Digits);
				cout << "(" << countryCode << ") " << areaCode << " " << last3Digits << "-" << last4Digits << endl;
			}
		}

		else {
			cout << "Empty Contact!" << endl;
		}
	}

}