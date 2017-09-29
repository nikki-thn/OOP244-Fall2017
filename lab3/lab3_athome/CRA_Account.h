/*
Nikki Truong - 112 214 174
OOP244 - Section B
Workshop 3 - at home
*/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H


namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {

		char m_lastName[max_name_length + 1];
		char m_firstName[max_name_length + 1];
		int m_sin;
		int m_year[max_yrs];
		double m_balance[max_yrs];
		int m_years;

	public:

		void set(const char* familyName, const char* givenName, int sin); //to set values for an object or set empty state
		void set(int year, double balance); //to set values of newly added data members
		bool isEmpty() const; //check if the object is empty
		void display() const; //print out data members

	};

	//helper function to validate SIN
	void bubbleSort(int a[], int n);
	
}


#endif
