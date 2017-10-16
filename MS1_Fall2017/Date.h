// Final Project Milestone 1

//Nikki Truong - 112 314 174 - Section B
//OOP244 - Fall 2017

#ifndef SICT_DATE_H
#define SICT_DATE_H

#define NO_ERROR 0  // No error the date is valid
#define CIN_FAILED 1  //istream failed when entering information
#define YEAR_ERROR 2  //Year value is invalid
#define MON_ERROR  3  //Month value is invalid
#define DAY_ERROR  4  //Day value is invalid

namespace sict {

	const int min_year = 2000;
	const int max_year = 2030;

	class Date {

		int year_;
		int mon_;
		int day_;
		int errorCode_;
		int comparator_;

		void errCode(int); //to set errorCode data member to value of parameter
		int mdays(int, int)const; //returns number of days based on current month & year

	public:

		Date(); //no parameter constructor
		Date(int, int, int); //3 parameters constructor

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		int errCode()const; 	//Returns the readErrorCode_ value.
		bool bad()const;   	//Returns true if readErrorCode_ is not equal to zero.

		std::istream& read(std::istream& istr); //read from stream
		std::ostream& write(std::ostream& ostr)const; //print to stream

	};

	std::istream& operator>> (std::istream& is, Date& s);
	std::ostream& operator<< (std::ostream& is, const Date& s);


}
#endif
