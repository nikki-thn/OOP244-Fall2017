// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"AmaProduct.h"

namespace sict {

	AmaProduct::AmaProduct() {
		unit_[0] = '\0';
		fileTag_ = 'N';
	}

	AmaProduct::AmaProduct(const char fileTag) {

		if (fileTag != ' ') {
			fileTag_ = fileTag;
		}
		else {
			unit_[0] = '\0';
			fileTag_ = 'N';
		}
	}

	void AmaProduct::unit(const char* value) {

		if (value != nullptr && strlen(value) < 11) {
			strcpy(unit_, value);
		}
		else {
			unit_[0] = '\0';
		}
	}

	std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine) const {

		char a = ',';

		file << fileTag_ << a << sku() << a << name() << a << price() <<
			a << taxed() << a << quantity() << a << unit() << a << qtyNeeded();

		if (addNewLine) {
			file << endl;
		}

		return file;
	}

	std::fstream& AmaProduct::load(std::fstream& file) {

		double aDouble;
		bool aBool;
		int anInt;
		char nameIn[200];
		char skuIn[MAX_SKU_LEN + 1];
		char a = ',';

		file >> skuIn >> a;
		sku(skuIn);
		file >> nameIn >> a;
		name(nameIn);
		file >> aDouble >> a;
		price(aDouble);
		file >> aBool >> a;
		taxed(aBool);
		file >> anInt >> a;
		quantity(anInt);
		file >> unit_ >> a;
		file >> anInt >> a;
		qtyNeeded(anInt);

		return file;
	}

	std::ostream& AmaProduct::write(std::ostream& os, bool linear)const {

		bool flag = isClear();

		if (flag != true) {
			if (linear) {
				os.setf(ios::left);
				os.width(MAX_SKU_LEN);
				os << "|" << sku() << "|";
				os.width(20);
				os << name() << "|";
				os.unsetf(ios::left);
				os.setf(ios::right);
				os.width(7);
				os.precision(2);
				os << "Cost: " << cost() << "|";
				os.width(4);
				os << "Qty on hand: " << quantity() << "|";
				os.setf(ios::left);
				os.width(10);
				os << "Unit: " << unit_ << "|";
				os.unsetf(ios::left);
				os.setf(ios::right);
				os.width(4);
				os << "Quantity needed: " << qtyNeeded() << "|";
			}

			else {
				os << "Sku: " << sku() << std::endl;
				os << "Name: " << name() << std::endl;
				os.setf(ios::fixed);
				os.precision(2);
				os << "Price: " << price();

				if (taxed()) {
					os << "Price after tax: " << cost();
				}
				else {
					os << "Price after tax: N/A";
				}

				os << "Qty on hand: " << quantity() << std::endl;
				os << "Quantity needed: " << qtyNeeded() << std::endl;
			}
		}

		else {
			err_.display(os);
		}
		return os;
	}

	std::istream& AmaProduct::read(std::istream& istr) {

		double aDouble;
		int anInt;
		char nameIn[200];
		char skuIn[MAX_SKU_LEN + 1];
		char taxedIn;

		while (!(istr.fail()) ){
			std::cout << "Sku: ";
			istr >> skuIn;
			sku(skuIn);
			cout << "Name: ";
			istr >> nameIn;
			name(nameIn);
			cout << "Unit: ";
			istr >> unit_;
			cout << "Taxed? (y/n): ";
			istr >> taxedIn;

			if (taxedIn != 'N' || taxedIn != 'n' || taxedIn != 'Y' || taxedIn != 'y') {

				err_.message("Only (Y)es or (N)o are acceptable");
				istr.setstate(ios::failbit);
			}
		/*	else {

				if (taxedIn == 'Y' || taxedIn == 'y') {
					taxed(true);
				}
				else if (taxedIn == 'N' || taxedIn == 'n') {
					taxed(false);
				}

			} */

			//clear();

			cout << "Price: ";
			istr >> aDouble;

			if (!(aDouble > 0.0)) {
				err_.message("Invalid Price Entry");

			}
			else {
				price(aDouble);
			}

			cout << "Quantity On Hand: ";
			istr >> anInt;

			if (!(anInt > 0)) {
				err_.message("Invalid Quanity Entry");

			}
			else {
				quantity(anInt);
			}

			cout << "Quanity Needed: ";
			istr >> anInt;

			if (!(anInt > 0)) {
				err_.message("Invalid Quanity Needed Entry");

			}
			else {
				qtyNeeded(anInt);
			}

		}
		return istr;
	}

	std::istream& operator>> (std::istream& is, AmaProduct& s) {
		s.read(is);
		return is;
	}

	std::ostream& operator<< (std::ostream& os, const AmaProduct& s) {
		s.write(os, true);
		return os;
	}
}
