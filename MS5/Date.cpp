
#include <iostream>
#include "Date.h"
#include "general.h"

using namespace std;

namespace sict {

	Date::Date() {
		//set value to safe empty state
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;
	}

	Date::Date(int year, int mon, int day) {

		if (year != 0) {
			year_ = year;
			mon_ = mon;
			day_ = day;
			readErrorCode_ = NO_ERROR;
		}
		else {
			*this = Date();
		}
	}

	bool Date::operator==(const Date& D)const {
		bool isTrue = false;

		if (year_ == D.year_ && mon_ == D.mon_ && day_ == D.day_) {
			isTrue = true;
		}

		return isTrue;
	}

	bool Date::operator!=(const Date& D)const {
		bool isTrue = false;

		if (year_ != D.year_ || mon_ != D.mon_ || day_ != D.day_) {
			isTrue = true;
		}

		return isTrue;
	}

	bool Date::operator<(const Date& D)const {
		bool isTrue = false;

		if (year_ < D.year_) {
			isTrue = true;
		}

		else if (year_ == D.year_) {

			if (mon_ < D.mon_) {
				isTrue = true;
			}

			else if (mon_ == D.mon_) {
				if (day_ < D.day_) {
					isTrue = true;
				}
			}

		}

		return isTrue;
	}

	bool Date::operator>(const Date& D)const {
		bool isTrue = false;

		if (year_ > D.year_) {
			isTrue = true;
		}

		else if (year_ == D.year_) {

			if (mon_ > D.mon_) {
				isTrue = true;
			}

			else if (mon_ == D.mon_) {
				if (day_ > D.day_) {
					isTrue = true;
				}
			}

		}

		return isTrue;
	}

	bool Date::operator<=(const Date& D)const {
		bool isTrue = false;

		if (year_ <= D.year_ && mon_ <= D.mon_ && day_ <= D.day_) {
			isTrue = true;
		}

		if (year_ == D.year_ && mon_ <= D.mon_ && day_ <= D.day_) {
			isTrue = true;
		}

		if (year_ == D.year_ && mon_ <= D.mon_) {
			isTrue = true;
		}

		return isTrue;
	}

	bool Date::operator>=(const Date& D)const {
		bool isTrue = false;

		if (year_ >= D.year_ && mon_ >= D.mon_ && day_ >= D.day_) {
			isTrue = true;
		}

		if (year_ == D.year_ && mon_ >= D.mon_ && day_ >= D.day_) {
			isTrue = true;
		}

		if (year_ == D.year_ && mon_ >= D.mon_) {
			isTrue = true;
		}

		return isTrue;
	}

	//Returns the readErrorCode_ value.
	int Date::errCode()const {

		return readErrorCode_;
	}

	//Returns true if readErrorCode_ is not equal to zero
	bool Date::bad()const {
		bool isNotZero = false;

		if (readErrorCode_ != 0) {
			isNotZero = true;
		}

		return isNotZero;
	}

	std::istream& Date::read(std::istream& istr) {

		char a;
		istr >> year_ >> a >> mon_ >> a;
		
		day_ = mdays();
		
		//mdays(); ****don't know how

		if (year_ == 0 || mon_ == 0 || day_ == 0) {
			readErrorCode_ = CIN_FAILED;
		}

		if (year_ >= MIN_YEAR && year_ <= MAX_YEAR && day_ >= 1 && day_ <= 31
			&& mon_ >= 1 && mon_ <= 12) {
			readErrorCode_ = NO_ERROR;
		}

		if (year_ != 0 && (year_ < MIN_YEAR || year_ > MAX_YEAR)) {
			readErrorCode_ = YEAR_ERROR;
		}
		
		if (year_ != 0 && mon_ != 0 && (mon_ < 1 || mon_ > 12)) {
			readErrorCode_ = MON_ERROR;
		}
		
		if (day_ != 0 && mon_ != 0 && year_ != 0 && (day_ < 1 || day_ > 31)) {
			readErrorCode_ = DAY_ERROR;
		}
		
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr)const {
			
		ostr << year_ << "/";
		//ostr.setf(ios::fixed);
		ostr.width(2);
		ostr.fill('0');
		ostr << mon_ << "/";
		ostr.width(2);
		ostr << day_ << endl;
               // ostr.unsetf(ios::fixed);
		
		return ostr;
	}

	//sets memeber readErrorCode to value from parameter
	void Date::errCode(int errorCode) {

		readErrorCode_ = errorCode;
	}

	//to input
	std::istream& operator>> (std::istream& is, Date& s) {
		s.read(is);
		return is;
	}

	//to display
	std::ostream& operator<< (std::ostream& os, const Date& s) {
		s.write(os);
		return os;
	}

	int Date::value()const {
		return year_ * 372 + mon_ * 31 + day_;
	}

	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}



}
