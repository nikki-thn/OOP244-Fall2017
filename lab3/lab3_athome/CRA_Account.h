#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999
#define MAX_YRS 4

namespace sict {

	class CRA_Account {

		char lastName[MAX_NAME_LENGTH + 1];
		char firstName[MAX_NAME_LENGTH + 1];
		int sinNum;
		int m_year[MAX_YRS];
		double m_balance[MAX_YRS];
		int m_years;


	public:

		void set(const char* familyName, const char* givenName, int sin);
		bool isValid() const;
		void display() const;

		void set(int year, double balance);

	};



}


#endif
