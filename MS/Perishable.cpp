// Name: Nikki Truong
// Student_id: 112 314 174
// Section E
// Milestone 2


#include "Perishable.h"

using namespace std;

namespace sict {

	Perishable::Perishable() : NonPerishable('P') { }

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {

		NonPerishable::store(file, false);

		file << ',' << m_expired;
		if (newLine) file << '\n';
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {

		NonPerishable::load(file);

		file >> m_expired;
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) {

		NonPerishable::write(os, linear);

		if (isClear()) {
			if (linear) os << m_expired << std::endl;
			else os << "Expiry date: " << m_expired << endl;
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {

		Date temp;

		NonPerishable::read(is);

		if (!is.fail()) {

			cout << "Expiry date (YYYY/MM/DD): ";
			temp.read(is);

			if (temp.errCode() == CIN_FAILED) {
				message("Invalid Date Entry");
				is.istream::setstate(ios::failbit);
			}
			else if (temp.errCode() == YEAR_ERROR) {
				message("Invalid Year in Date Entry");
				is.istream::setstate(ios::failbit);
			}
			else if (temp.errCode() == MON_ERROR) {
				message("Invalid Month in Date Entry");
				is.istream::setstate(ios::failbit);
			}
			else if (temp.errCode() == DAY_ERROR) {
				message("Invalid Day in Date Entry");
				is.istream::setstate(ios::failbit);
			}
			if (!temp.bad() && !is.fail()) {
				m_expired = temp;
			}
		}
		return is;
	}


	std::ostream& operator<<(std::ostream& os, Perishable& rhs) {

		rhs.write(os);
		return os;
	}

	std::istream& operator>>(std::istream& is, Perishable& rhs) {

		rhs.read(is);
		return is;
	}

	Product* CreatePerishable() {
		Product * pPerishable = new Perishable;
		return pPerishable;
	}

}