// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include"AmaProduct.h"

namespace sict {
	
	AmaProduct::AmaProduct() {
		unit_[0] = '\0';
		fileTag_ = 'N';
	}

	AmaProduct::AmaProduct(const char fileTag) {

		if (fileTag != 'N') {
			fileTag_ = fileTag;
		}
		else {
			unit_[0] = '\0';
			fileTag_ = 'N';
		}
	}

	void AmaProduct::unit(const char* value) {

		if (value != nullptr && strlen(value) < 11) {
			std::strcpy(unit_, value);
		}
		else {
			unit_[0] = '\0';
		}
	}

	std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine) const {

		char a = ',';

		file << fileTag_ << a;
		file << sku() << a << name() << a << price() << a << taxed() <<
			a << quantity() << a << unit_ << a << qtyNeeded();

		if (addNewLine) {
			file << '\n';
		}

		return file;
	}

	std::fstream& AmaProduct::load(std::fstream& file) {

		double priceIn;
		bool taxedIn;
		int qtyIn, qtyNeededIn;
		char skuIn[MAX_SKU_LEN + 1], nameIn[21];
		char a;
	        
		file.ignore(3);
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

		return file;
	}

	std::ostream& AmaProduct::write(std::ostream& os, bool linear)const {


		if (!err_.isClear()) {
			err_.display(os);
		}

		else {
			if (linear) {
				os.setf(ios::left);
				os.width(MAX_SKU_LEN);
				os << sku() << "|";
				os.width(20);
				os << name() << "|";
				os.unsetf(ios::left);
				os.setf(ios::right);
				os.width(7);
				os.setf(ios::fixed);
				os.precision(2);
				if (taxed()) {
					os << cost() << "|";
				}
				else {
					os << price() << "|";
				}
				os.width(4);
				os << quantity() << "|";
				os.unsetf(ios::right);
				os.setf(ios::left);
				os.width(10);
				os << unit_ << "|";
				os.unsetf(ios::left);
				os.setf(ios::right);
				os.width(4);
				os << qtyNeeded() << "|";
			}

			else {
				os << "Sku: " << sku() << std::endl;
				os << "Name: " << name() << std::endl;
				os.setf(ios::fixed);
				os.precision(2);
				os << "Price: " << price() << std::endl;
				if (taxed()) {
					os << "Price after tax: " << cost() << std::endl;
				}
				else {
					os << "Price after tax: N/A" << std::endl;
				}
				os << "Quantity on hand: " << quantity() << " " << unit_ << std::endl;
				os << "Quantity needed: " << qtyNeeded() << std::endl;
			}
		}

		return os;
	}

	std::istream& AmaProduct::read(std::istream& istr) {

		if (!istr.fail()) {
			double aDouble;
			int qtyInput, qtyNeededInput;
			char nameIn[50];
			char skuIn[MAX_SKU_LEN + 1];
			char taxedIn;
			bool isValid = true;

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

			if (taxedIn != 'N' && taxedIn != 'n' && taxedIn != 'Y' && taxedIn != 'y') {
				err_.message("Only (Y)es or (N)o are acceptable");
				istr.setstate(ios::failbit); //-- istr.fail();
				isValid = false;
			}
			else if (taxedIn == 'N' || taxedIn == 'n') {
				taxed(false);
				istr.clear();
				istr.ignore(200, '\n');
			}
			else if (taxedIn == 'Y' || taxedIn == 'y') {
				taxed(true);
				istr.clear();
				istr.ignore(200, '\n');
			}

			if (isValid != false) {
				cout << "Price: ";
				istr >> aDouble;

				if (!(aDouble > 0.0)) {
					err_.message("Invalid Price Entry");
					istr.setstate(ios::failbit);
					isValid = false;
				}
				else {
					price(aDouble);
					istr.clear();
					istr.ignore(200, '\n');
				}
			}

			if (isValid != false) {
				cout << "Quantity On Hand: ";
				istr >> qtyInput;

				if (!(qtyInput > 0)) {
					err_.message("Invalid Quantity Entry");
					istr.setstate(ios::failbit);
					isValid = false;
				}
				else {
					quantity(qtyInput);
					istr.clear();
					istr.ignore(200, '\n');
				}
			}

			if (isValid != false) {
				cout << "Quantity Needed: ";
				istr >> qtyNeededInput;

				if (!(qtyNeededInput > 0)) {
					err_.message("Invalid Quantity Needed Entry");
					istr.setstate(ios::failbit);
					isValid = false;
				}
				else {
					qtyNeeded(qtyNeededInput);
				}
			}


			if (isValid == true) {
				err_.clear();
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
