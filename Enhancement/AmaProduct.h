#ifndef SICT_AMAPRODUCT_H
#define SICT_AMAPRODUCT_H

#include <iostream>
#include "Product.h"
#include "ErrorMessage.h"

using namespace std;

namespace sict {

	class AmaProduct : public Product , public ErrorMessage {
		
		char fileTag_;
		char unit_[11];

	protected:
		ErrorMessage err_;
		AmaProduct(const char fileTag);

	public:

		AmaProduct();
	
		const char* unit() const { return unit_; } //return type issue
		void unit(const char* value);
		fstream& store(fstream& file, bool addNewLine = true)const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear = true)const;
		istream& read(istream& istr);
	};

	istream& operator>> (std::istream& is, AmaProduct& s);
	ostream& operator<< (std::ostream& is, const AmaProduct& s);
}


#endif


