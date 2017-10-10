#ifndef SICT_DATE_H__
#define SICT_DATE_H__

#include <iostream>
#include <cstring>


#define NO_ERROR 0  // No error the date is valid
#define CIN_FAILED 1  //istream failed when entering information
#define YEAR_ERROR 2  //Year value is invalid
#define MON_ERROR  3  //Month value is invalid
#define DAY_ERROR  4  //Day value is invalid


namespace sict {

	class Date {
	private:

		int year_;
		int mon_;
		int day_;
		int readErrorCode_;

		int value()const;
		void errCode(int);

	public:

		Date();
		Date(int year, int mon, int day);

		bool operator==(const Date& D)const;
		bool operator!=(const Date& D)const;
		bool operator<(const Date& D)const;
		bool operator>(const Date& D)const;
		bool operator<=(const Date& D)const;
		bool operator>=(const Date& D)const;

		int errCode()const; 	//Returns the readErrorCode_ value.
		bool bad()const;   	//Returns true if readErrorCode_ is not equal to zero.

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;

		int mdays()const;
	};


	std::istream& operator>> (std::istream& is, Date& s);
	std::ostream& operator<< (std::ostream& is, const Date& s);


}
#endif
