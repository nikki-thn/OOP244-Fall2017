#include <iostream>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact() {

		name[0] = '\0';
		numOfPhones = -1;
		phoneNum[numOfPhones] = { 0 };

	}
	

	Contact::Contact(const char* sourceName, const long long* sourcePhone, int size) {

		long long *phone = nullptr;

		phone = new long long[size];

		int countryCode;
		int areaCode;
		int last3Digits;
		int last4Digits = 0;
		long double temp;

		for (int i = 0; i < size; i++) {
		//phone number with 1 digits country code
		if (sourcePhone[i] >= 10000000000 && sourcePhone[i] <= 99999999999) {

			//cout.precision(15);

			countryCode = sourcePhone[i] / 10000000000;
			temp = (long double)sourcePhone[i] / 10000000000;

			areaCode = (temp - countryCode) * 1000;
			temp = (temp - (double)countryCode) * 1000;

			last3Digits = (temp - areaCode) * 1000;
			temp = (temp - (double)areaCode) * 1000;

			last4Digits = (temp - last3Digits) * 10000;

		}

		//phone number with 2 digits country code
		if (sourcePhone[i] >= 100000000000 && sourcePhone[i] <= 999999999999) {

			cout.precision(15);

			countryCode = sourcePhone[i] / 10000000000;
			temp = (long double)sourcePhone[i] / 10000000000;

			areaCode = (temp - countryCode) * 1000;
			temp = (temp - (double)countryCode) * 1000;

			last3Digits = (temp - areaCode) * 1000;
			temp = (temp - (double)areaCode) * 1000;
			//	cout << "temp " << temp;

			last4Digits = (temp - last3Digits) * 10000;


		//	cout << "country " << countryCode << " area " << areaCode << " lastdigit " << last3Digits
		//		<< "last4Di" << last4Digits << endl;
		
		}


		bool valid = areaCode > 100 && countryCode > 1 && last3Digits > 100;

		if (valid == true) {

			strcpy(name, sourceName);
			phone[i] = sourcePhone[i];
			phoneNum[i] = phone[i];

			cout << phone[i] << endl;
		}
		else {

			*this = Contact();
		}

		}


	}

	
	
	Contact::~Contact() {

		delete [] phoneNum;
	}


	bool Contact::isEmpty() const {

		bool isEmpty = false;

		if (name[0] == '\0') {

			isEmpty = true;

		} 

		return isEmpty;

	}
	
	
	void Contact::display() const {

		bool empty = isEmpty();
		int countryCode;
		int areaCode;
		int last3Digits;
		int last4Digits = 0;
		long double temp;


		if (empty == false) {

			cout << name << endl;
			for (int i = 0; i < numOfPhones; i++) {


				countryCode = phoneNum[i] / 10000000000;
				temp = (long double)phoneNum[i] / 10000000000;

				areaCode = (temp - countryCode) * 1000;
				temp = (temp - (double)countryCode) * 1000;

				last3Digits = (temp - areaCode) * 1000;
				temp = (temp - (double)areaCode) * 1000;
				//	cout << "temp " << temp;

				last4Digits = (temp - last3Digits) * 10000;

				cout << "(+" << countryCode << ") " << areaCode << " " << last3Digits << "-" << last4Digits << endl;

			}

		}
		else if (empty == true) {

			cout << "Empty contact!" << endl;
		}


	}






}
