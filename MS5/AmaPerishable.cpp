#include<iostream>
#include"AmaPerishable.h"

namespace sict {


	AmaPerishable::AmaPerishable() : AmaProduct('P') {}

	void expiry(const Date &value) {

		Date temp;

		temp = value;

	}

	std::fstream& AmaPerishable::store(std::fstream& file, bool addNewLine)const {
		
		AmaProduct::store(file, false);

		char a = ',';

		file << a << expiry_;

		return file;
	}
	
	std::fstream& AmaPerishable::load(std::fstream& file) {
		
		AmaProduct::load(file);
		Date::read(file);
	
	//	char input[100]; 

	//	file.getline(input, 100, '\n');


		file.ignore();
		
		cout << input << endl;

		return file;
	}

	std::ostream& AmaPerishable::write(std::ostream& os, bool linear = true)const {
	

			if (linear) {
				AmaProduct::write(os, true);
				if (err_.isClear()) {
					os << expiry_;
				}
			}
			else {
				AmaProduct::write(os, false);
				if (err_.isClear()) {
					os << "Expiry date: " << expiry_;
				}
			}
		
		return os;
	}

	std::istream& AmaPerishable::read(std::istream& istr) {

		AmaProduct::read(istr);

		Date temp;

		if (err_.isClear()) {
			cout << "Expirey date (YYYY/MM/DD): ";
			istr >> temp;

			if (temp.errCode() == CIN_FAILED) {
				err_.message("Invalid Date Entry");
				istr.setstate(ios::failbit);
			}
			if (temp.errCode() == YEAR_ERROR) {
				err_.message("Invalid Year in Date Entry");
				istr.setstate(ios::failbit);
			}
			if (temp.errCode() == MON_ERROR) {
				err_.message("Invalid Month in Date Entryy");
				istr.setstate(ios::failbit);
			}
			if (temp.errCode() == DAY_ERROR) {
				err_.message("Invalid Day in Date Entry");
				istr.setstate(ios::failbit);
			}
			if (temp.errCode() == NO_ERROR) {
				err_.clear();
				expiry_ = temp;
			}
		}
		return istr;
	}

	std::istream& operator>> (std::istream& is, AmaPerishable& s) {
		s.read(is);
		return is;
	}

	std::ostream& operator<< (std::ostream& os, const AmaPerishable& s) {
		s.write(os, true);
		return os;
	}
}
