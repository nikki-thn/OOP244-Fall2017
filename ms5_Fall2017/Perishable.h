// Name: Nikki Truong
// Student_id: 112 314 174
// Section E
// Milestone 2

#ifndef SICT_PERISHABLE_H
#define SICT_PERISHABLE_H

#include "NonPerishable.h"
#include "Date.h"

namespace sict {

	class Perishable : public NonPerishable {

		Date m_expired;

	public:

		Perishable(); //constructor

		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear = true) const;
		std::istream& read(std::istream& is);

		//return expiry date
		const Date& expiry() const { return m_expired; }
	};

	Product* CreatePerishable();
}

#endif
