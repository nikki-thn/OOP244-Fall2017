// Final Project Milestone 1

//Nikki Truong - 112 314 174 - Section B
//OOP244 - Fall 2017


#include <iostream>
#include "Date.h"

using namespace std;

namespace sict {

	void Date::errCode(int errorCode) {

		errorCode_ = errorCode;
	}

	int Date::mdays(int mon, int year)const {

		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	Date::Date() {

		//set data members to safe empty state
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		comparator_ = 0;
		errorCode_ = NO_ERROR;
	}

	Date::Date(int year, int month, int day) {

		//calculate how many days in month to check for valid number of days
		int daysInMonth = mdays(month, year);;

		//if conditions are met, set values to data members
		if (year >= min_year && year <= max_year && day >= 1
			&& day <= daysInMonth && month >= 1 && month <= 12) {

			errorCode_ = NO_ERROR;
			year_ = year;
			mon_ = month;
			day_ = day;
			comparator_ = year_ * 372 + mon_ * 13 + day;
		}
		else {

			*this = Date(); //set current object to safety state
		}
	}

	//returns true if two days are the same
	bool Date::operator==(const Date& rhs)const {
		bool isTrue = false;

		if (year_ == rhs.year_ && mon_ == rhs.mon_ && day_ == rhs.day_) {
			isTrue = true;
		}

		return isTrue;
	}

	//returns true if two days are not the same
	bool Date::operator!=(const Date& rhs)const {
		bool isTrue = false;

		if (year_ != rhs.year_ || mon_ != rhs.mon_ || day_ != rhs.day_) {
			isTrue = true;
		}

		return isTrue;
	}

	//returns true if current object is less than 
	bool Date::operator<(const Date& rhs)const {
		bool isTrue = false;

		if (year_ < rhs.year_) {
			isTrue = true;
		}

		else if (year_ == rhs.year_) {

			if (mon_ < rhs.mon_) {
				isTrue = true;
			}

			else if (mon_ == rhs.mon_) {
				if (day_ < rhs.day_) {
					isTrue = true;
				}
			}

		}

		return isTrue;
	}

	//returns true if current object is greater than
	bool Date::operator>(const Date& rhs)const {
		bool isTrue = false;

		if (year_ > rhs.year_) {
			isTrue = true;
		}

		else if (year_ == rhs.year_) {

			if (mon_ > rhs.mon_) {
				isTrue = true;
			}
			else if (mon_ == rhs.mon_) {
				if (day_ > rhs.day_) {
					isTrue = true;
				}
			}
		}

		return isTrue;
	}

	//returns true if current object is less or equal than
	bool Date::operator<=(const Date& rhs)const {
		bool isTrue = false;

		if (year_ <= rhs.year_ && mon_ <= rhs.mon_ && day_ <= rhs.day_) {
			isTrue = true;
		}

		if (year_ == rhs.year_ && mon_ <= rhs.mon_ && day_ <= rhs.day_) {
			isTrue = true;
		}

		if (year_ == rhs.year_ && mon_ <= rhs.mon_) {
			isTrue = true;
		}

		return isTrue;
	}

	//returns true if current object is greater or equal than
	bool Date::operator>=(const Date& rhs)const {
		bool isTrue = false;

		if (year_ >= rhs.year_ && mon_ >= rhs.mon_ && day_ >= rhs.day_) {
			isTrue = true;
		}

		if (year_ == rhs.year_ && mon_ >= rhs.mon_ && day_ >= rhs.day_) {
			isTrue = true;
		}

		if (year_ == rhs.year_ && mon_ >= rhs.mon_) {
			isTrue = true;
		}

		return isTrue;
	}

	//Returns errorCode_ member
	int Date::errCode()const {

		return errorCode_;
	}

	//Returns true if errorCode_ != to NO_ERROR
	bool Date::bad()const {

		bool hasError = false;

		if (errorCode_ != NO_ERROR) {
			hasError = true;
		}

		return hasError;
	}


	std::istream& Date::read(std::istream& istr) {

		char a;

		istr >> year_ >> a >> mon_ >> a >> day_;

		if (istr.fail()) {
			errCode(CIN_FAILED);
		}

		if (year_ == 0 || mon_ == 0 || day_ == 0) {
			errorCode_ = CIN_FAILED;
		}

		if (year_ >= min_year && year_ <= max_year && day_ >= 1 && day_ <= 31
			&& mon_ >= 1 && mon_ <= 12) {
			errorCode_ = NO_ERROR;
		}

		if (year_ != 0 && (year_ < min_year || year_ > max_year)) {
			errorCode_ = YEAR_ERROR;
		}

		if (year_ != 0 && mon_ != 0 && (mon_ < 1 || mon_ > 12)) {
			errorCode_ = MON_ERROR;
		}

		if (day_ != 0 && mon_ != 0 && year_ != 0 && (day_ < 1 || day_ > 31)) {
			errorCode_ = DAY_ERROR;
		}

		return istr;
	}


	std::ostream& Date::write(std::ostream& ostr)const {

		ostr.setf(ios::fixed);
		ostr << year_ << "/";
		ostr.fill('0');
		ostr.width(2);
		ostr << mon_ << "/";
		ostr.width(2);
		ostr << day_ << endl;
		ostr.unsetf(ios::fixed);

		return ostr;
	}


	//overload >> to read from input stream
	std::istream& operator>> (std::istream& is, Date& s) {

		s.read(is);
		return is;
	}

	//overload << to write to output stream
	std::ostream& operator<< (std::ostream& os, const Date& s) {

		s.write(os);
		return os;
	}

}
