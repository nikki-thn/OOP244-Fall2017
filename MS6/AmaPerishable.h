// AmaPerishable.h
#ifndef SICT_AMAPERISHABLE_H
#define SICT_AMAPERISHABLE_H

#include<iostream>
#include"AmaProduct.h"
#include"Date.h"

namespace sict {

	class AmaPerishable : public AmaProduct, public Date {

		Date expiry_;

	public:

		AmaPerishable();

		const Date& expiry() const { return expiry_; }
		void expiry(const Date &value);

		std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& istr);

	};

	std::istream& operator>> (std::istream& is, AmaPerishable& s);
	std::ostream& operator<< (std::ostream& is, const AmaPerishable& s);
}

#endif
