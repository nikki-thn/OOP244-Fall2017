/*
Nikki Truong - 112 214 174
OOP244 - Section B
Workshop 3 - in lab
*/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999

namespace sict {

	class CRA_Account {

		char m_lastName [MAX_NAME_LENGTH + 1];
		char m_firstName [MAX_NAME_LENGTH + 1];
		int m_sin;

	public:

		void set(const char* familyName, const char* givenName, int sin);
		bool isValid() const;
		void display() const;

	};



}


#endif
