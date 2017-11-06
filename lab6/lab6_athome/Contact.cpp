/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 6 - At home
*/



#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {

	Contact::Contact() { //set object to safe empty state

		m_name[0] = '\0';
		m_numOfPhones = 0;
		m_phoneNum = nullptr;
	}

	Contact::Contact(const char* sourceName, const long long* sourcePhone, int size) {

		*this = Contact();

		int count = 0;

		//if not empty, copy value into data members accordingly
		if (sourceName != nullptr) {

			strncpy(m_name, sourceName, 19);
			m_name[19] = '\0';

			for (int i = 0; i < size; i++) {

				if (validCheck(sourcePhone[i])) { //call validCheck function to check phone	
					m_numOfPhones++; //count number of valid number for memory allocation
				}
			}

			m_phoneNum = new long long[m_numOfPhones]; //allocate memory for valid phone number

			for (int j = 0; j < size; j++) {

				if (validCheck(sourcePhone[j])) {

					//copy into array m_phoneNum
					m_phoneNum[count] = sourcePhone[j];
					count++;
				}
			}
		}
		//else *this = Contact(); // else set object to safety state

	}

	Contact::~Contact() {

		delete[] m_phoneNum;
	}

	//Copy constructor
	Contact::Contact(const Contact& newContact) {
	
		if (this != &newContact) {

			m_phoneNum = nullptr;
			*this = newContact;
		}
	}

	//copy operator
	Contact& Contact::operator= (const Contact& newContact) {

		if (this != &newContact) {

			strncpy(m_name, newContact.m_name, 19);
			m_name[19] = '\0';
			m_numOfPhones = newContact.m_numOfPhones;

			if (newContact.m_phoneNum != nullptr) {

				m_phoneNum = new long long[m_numOfPhones];

				for (int i = 0; i < m_numOfPhones; i++) {
					m_phoneNum[i] = newContact.m_phoneNum[i];
				}
			}
			else {
				m_phoneNum = nullptr;
			}
		}
		return *this;
	}

	//+= operator to add a new number into the existing array phoneNum
	Contact& Contact::operator+=(const long long newPhone) {

		Contact temp = *this;

		int count = m_numOfPhones;

		//if the newPhone is valid, accept it into array
		if (validCheck(newPhone)) {

			//increase the memory by one
			m_phoneNum = new long long[m_numOfPhones + 1];
			m_numOfPhones++;
			//copy all existing contact to the array of new size
			for (int i = 0; i < m_numOfPhones; i++) {
				m_phoneNum[i] = temp.m_phoneNum[i];
			}

			//assign newPhone to the last element of array
			m_phoneNum[count] = newPhone;
		}
		return *this;
	}

	//check for valid phone number
	bool Contact::validCheck(const long long toCheck) {

		bool isValid = false;
		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;

		extractNum(toCheck, countryCode, areaCode, last3Digits, last4Digits);
		isValid = areaCode >= 100 && countryCode >= 1 && countryCode <= 99 && last3Digits >= 100;

		return isValid;
	}

	//break down number 
	void Contact::extractNum(const long long phone, int& country, int& area, int& last3, int& last4) {

		int temp = 0;

		last4 = phone % 10000;
		temp = (phone - last4) / 10000;
		last3 = temp % 1000;
		temp = (temp - last3) / 1000;
		area = temp % 1000;
		country = (temp - area) / 1000;
	}

	//returns true if object is empty
	bool Contact::isEmpty() const {

		bool isEmpty = true;

		if (m_name[0] != '\0') {
			isEmpty = false;
		}

		return isEmpty;
	}

	//query
	void Contact::display() {

		bool empty = isEmpty();

		int countryCode = 0;
		int areaCode = 0;
		int last3Digits = 0;
		int last4Digits = 0;

		if (empty != true) {

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
