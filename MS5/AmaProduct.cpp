// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
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

		if (value != nullptr && std::strlen(value) < 11) {
			std::strcpy(unit_, value);
		}
		else {
			unit_[0] = '\0';
		}
	}

	std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine) const {

			char a = ',';

		file << fileTag_ << a << sku() << a << name() << a << price() << a << taxed() <<
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
				
		file.getline(skuIn, MAX_SKU_LEN, ',');
		sku(skuIn);
		file.getline(nameIn, 20, ',');
		name(nameIn);
		file >> priceIn >> a;
		price(priceIn);
		file >> taxedIn >> a;
		taxed(taxedIn);
		file >> qtyIn >> a;
		quantity(qtyIn);
		file.getline(unit_, 10, ',');
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
					//cout << sku() << std::endl;
					os << sku() << "|";
					os.width(20);
					os << name() << "|";
					os.unsetf(ios::left);
					os.setf(ios::right);
					os.width(7);
					os.setf(ios::fixed);
					os.precision(2);
					os << cost() << "|";
					os.width(4);
					os << quantity() << "|";
					os.unsetf(ios::right);
					os.setf(ios::left);
					os.width(10);
					os << unit_ << "|";
					os.unsetf(ios::left);
					os.setf(ios::right);
					os.width(4);
					os  << qtyNeeded() << "|";
				}

				else {
					os << "Sku: " << sku() << std::endl;
					os << "Name: " << name() << std::endl;
					os.setf(ios::fixed);
					os.precision(2);
					os << "Price: " << price() << std::endl;;

					if (taxed()) {
						os << "Price after tax: " << cost() << std::endl;;
					}
					else {
						os << "Price after tax: N/A" << std::endl;;
					}

					os << "Quantity on hand: " << quantity() << " " << unit_ << std::endl;
					os << "Quantity needed: " << qtyNeeded() << std::endl;
				}
			}
		
		return os;
	}

	std::istream& AmaProduct::read(std::istream& istr) {

		double aDouble;
		int qtyInput, qtyNeededInput;
		char nameIn[200];
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
		std::cin.clear();

		if (taxedIn != 'N' && taxedIn != 'n' && taxedIn != 'Y' && taxedIn != 'y') {
			err_.message("Only (Y)es or (N)o are acceptable");
			istr.setstate(ios::failbit); //-- istr.fail();
			isValid = false;
		}
		else if (taxedIn == 'N' || taxedIn == 'n') {
			taxed(false);
			
		}
		else if (taxedIn == 'Y' || taxedIn == 'y') {
			taxed(true);
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
				std::cin.clear();
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
				std::cin.clear();
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
				std::cin.clear();
			}
		}


		if (isValid == true) {
			err_.clear();	
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
