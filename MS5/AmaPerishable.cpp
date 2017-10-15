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
		
	//	file >> temp;
		read(file);
	
	//	char input[100]; 

	//	file.getline(input, 100, '\n');


		file.ignore();
		
	//	cout << input << endl;

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
		
	double priceIn;
		bool taxedIn;
		int qtyIn, qtyNeededIn;
		char skuIn[MAX_SKU_LEN + 1], nameIn[21];
		char a;
		char date[20];

		file.getline(skuIn, MAX_SKU_LEN, ',');
		file.ignore();
		sku(skuIn);
		file.getline(nameIn, 20, ',');
		name(nameIn);
		file.ignore();
		file >> priceIn >> a;
		price(priceIn);
		file >> taxedIn >> a;
		taxed(taxedIn);
		file >> qtyIn >> a;
		quantity(qtyIn);
		file.getline(unit_, 10, ',');
		file.ignore();
		file >> qtyNeededIn >> a;
		qtyNeeded(qtyNeededIn);
		fille.get;ine(date, 29, ',');

		return file;
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
