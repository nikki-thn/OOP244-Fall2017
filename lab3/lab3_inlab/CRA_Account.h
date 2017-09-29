/*
Nikki Truong - 112 214 174
OOP244 - Section B
Workshop 3 - in lab
*/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

	
const int max_name_length = 40;
const int min_sin = 100000000;
const int min_sin = 999999999;

namespace sict {

	class CRA_Account {

		char m_lastName [max_name_length + 1];
		char m_firstName [max_name_length + 1];
		int m_sin;

	public:

		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;

	};
}


#endif
