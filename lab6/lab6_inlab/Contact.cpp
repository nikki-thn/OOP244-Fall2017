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
		if (sourceName != nullptr && sourcePhone != nullptr && size != 0) {


			int count = 0;

			for (int i = 0; i < size; i++) {

				int countryCode = 0;
				int areaCode = 0;
				int last3Digits = 0;
				int last4Digits = 0;
				int temp;


				if (sourcePhone[i] >= 10000000000 && sourcePhone[i] <= 999999999999) {

					last4Digits = sourcePhone[i] % 10000;
					temp = (sourcePhone[i] - last4Digits) / 10000;
					last3Digits = temp % 1000;
					temp = (temp - last3Digits) / 1000;
					areaCode = temp % 1000;
					countryCode = (temp - areaCode) / 1000;

				}

				bool valid = areaCode >= 100 && countryCode >= 1 && last3Digits >= 100;

				if (valid == true) {

					//****problem, can't copy oversize character
					strcpy_s(name, sourceName);
					phoneNum[count] = sourcePhone[i];

					count++;
					numOfPhones = count;
				}
			}
		}

		if (sourceName == nullptr || sourcePhone == nullptr || size == 0) {

			*this = Contact();
		}
	}


	Contact::~Contact() {

		//delete [] phoneNum;
	}


	bool Contact::isEmpty() const {

		bool isEmpty;

		if (name[0] == '\0' || phoneNum == nullptr || numOfPhones == 0) {

			isEmpty = true;
		}

		else {

			isEmpty = false;
		}

		return isEmpty;
	}


	void Contact::display() const {

		bool empty = isEmpty();

		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;
		int temp = 0;

		if (empty == false) {

			cout << name << endl;

			for (int i = 0; i < numOfPhones; i++) {

				last4Digits = phoneNum[i] % 10000;
				temp = (phoneNum[i] - last4Digits) / 10000;
				last3Digits = temp % 1000;
				temp = (temp - last3Digits) / 1000;
				areaCode = temp % 1000;
				countryCode = (temp - areaCode) / 1000;

				cout << "(+" << countryCode << ") " << areaCode << " " << last3Digits << "-" << last4Digits << endl;
			}
		}

		else if (empty == true) {

			cout << "Empty contact!" << endl;
		}

	}

}
