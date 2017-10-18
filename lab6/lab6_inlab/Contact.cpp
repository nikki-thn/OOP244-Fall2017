/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 6 - In lab
*/
#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact() { //set object to safe empty state

		m_name[0] = '\0';
		m_numOfPhones = 0;
		long long *m_phoneNum = nullptr;
	}

	Contact::Contact(const char* sourceName, const long long* sourcePhone, int size) {

		*this = Contact();

		int count = 0;

		//if not empty, copy value into data members accordingly
		if (sourceName != nullptr || sourceName == "") {

			strncpy(m_name, sourceName, 19);
			m_name[19] = '\0';

			for (int i = 0; i < size; i++) {
	
				if (validCheck(sourcePhone[i])) { //call validCheck function to check phone	
					m_numOfPhones++; //count number of valid number for memory allocation
				}
			}


			m_phoneNum = new long long[m_numOfPhones];

			for (int j = 0; j < size; j++) {

				if (validCheck(sourcePhone[j])) {

					m_phoneNum[count] = sourcePhone[j];
					count++;
				}
			}

			cout << "m_numOfPhones" << m_numOfPhones << endl;
		}


		else {

			*this = Contact(); // else set object to safety state
		}
	}

	Contact::~Contact() {

			cout << "	Contact::~Contact() {" << endl;
		//delete [] m_phoneNum;
		
	}

	bool Contact::validCheck(const long long toCheck) {

		bool isValid = NULL;

		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;

		extractNum(toCheck, countryCode, areaCode, last3Digits, last4Digits);
		isValid = areaCode >= 100 && countryCode >= 1 && countryCode <= 99 && last3Digits >= 100;

		return isValid;
	}


	void Contact::extractNum(const long long phone, int& country, int& area, int& last3, int& last4) {

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

		if (m_name[0] != '\0') {
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

			cout << m_name << endl;

			for (int i = 0; i < m_numOfPhones; i++) {
				extractNum(m_phoneNum[i], countryCode, areaCode, last3Digits, last4Digits);
				cout << "(+" << countryCode << ") " << areaCode << " " << last3Digits << "-";
				cout.width(4);
				cout.fill('0');
				cout << last4Digits << endl;
			}
		}

		else {
			cout << "Empty Contact!" << endl;
		}
	}

}
