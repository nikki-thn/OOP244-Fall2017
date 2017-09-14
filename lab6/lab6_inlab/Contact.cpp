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

		if (sourceName != nullptr && sourcePhone != nullptr && size != 0) {

		phoneNum = new long long[size];
		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;
		long double temp;


				int count = 0;
			for (int i = 0; i < size; i++) {

				//phone number with 1 digits country code
				if (sourcePhone[i] >= 10000000000 && sourcePhone[i] <= 99999999999) {

		

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


					countryCode = sourcePhone[i] / 10000000000;
					temp = (long double)sourcePhone[i] / 10000000000;

					areaCode = (temp - countryCode) * 1000;
					temp = (temp - (double)countryCode) * 1000;

					last3Digits = (temp - areaCode) * 1000;
					temp = (temp - (double)areaCode) * 1000;
					//	cout << "temp " << temp;

					last4Digits = (temp - last3Digits) * 10000;



				}
				//cout << "country " << countryCode << " area " << areaCode << " lastdigit " << last3Digits
					//<< "last4Di " << last4Digits << endl;


				bool valid = areaCode > 100 && countryCode > 1 && last3Digits > 100;

				if (valid == true) {

					strcpy(name, sourceName);
					phoneNum[count] = sourcePhone[i];
					cout << sourcePhone[i] << "-----" << phoneNum[count] << endl;
					count++;

					numOfPhones++;

				}


			}
		}

		if (sourceName == nullptr || sourcePhone == nullptr || size == 0) {

			//*this = Contact();

			name[0] = '\0';
			numOfPhones = 0;
			long long *phoneNum = nullptr;
		}


		cout << numOfPhones;
	}


	Contact::~Contact() {

		//delete [] phoneNum;

	}


	bool Contact::isEmpty() const {

		bool isEmpty = false;

		if (name[0] == '\0') {

			isEmpty = true;

			long long *phoneNum = nullptr;

		}

		return isEmpty;

	}


	void Contact::display() const {

		bool empty = isEmpty();

		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;
		long double temp = 0.0;


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
