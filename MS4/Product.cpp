#include <iostream>
#include"Product.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {

	Product::Product() {

		sku_[MAX_SKU_LEN + 1] = { '\0' };
		price_ = 0;
		name_ = nullptr;
		quantity_ = 0;
		qtyNeeded_;
		taxed_ = NULL;
	}

	Product::Product(char* sku, char* name, bool taxed, double price, int qtyNeeded) {

		strncpy(sku_, sku, MAX_SKU_LEN);

		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);

		quantity_ = 0;
		price_ = price;
		qtyNeeded_ = qtyNeeded;

		if (taxed != NULL) {
			taxed_ = taxed;
		}

		else {
			taxed_ = true;
		}

	}

	Product::~Product() {

		delete[] name_;
	}

	Product::Product(const Product& temp) {

		//shallow copy
		strncpy(sku_, temp.sku_, MAX_SKU_LEN);

		quantity_ = temp.quantity_;
		price_ = temp.price_;
		qtyNeeded_ = temp.qtyNeeded_;
		taxed_ = temp.taxed_;

		//allocate memmory for name
		if (temp.name_ != nullptr) {
			delete[] name_;
			name_ = new char[strlen(temp.name_) + 1];
			strcpy(name_, temp.name_);
		}

	}

	Product& Product::operator= (const Product& temp) {

		//check for self-assignment
		if (this != &temp) {
			strncpy(sku_, temp.sku_, MAX_SKU_LEN);

			quantity_ = temp.quantity_;
			price_ = temp.price_;
			qtyNeeded_ = temp.qtyNeeded_;
			taxed_ = temp.taxed_;
		}

	
		//allocate memory
		if (temp.name_ != nullptr) {
			delete[] name_;
			name_ = new char[strlen(temp.name_) + 1];
			strcpy(name_, temp.name_);
		}

	}

	void Product::sku(char) {}
	void Product::price(double) {}
	void Product::name(char*) {}
	void Product::taxed(bool) {}
	void Product::quantity(int) {}
	void Product::qtyNeeded(int) {}

	double Product::cost() {

	}

	bool Product::isEmpty() {

		bool empty = false;

		if (sku_[0] == '\0') {

			empty = true;
		}

		return empty;
	}

	bool Product::operator+= (const char*) {}
	int Product::operator+= (int) {}
	int Product::operator-= (int) {}

	std::istream& Product::read(std::istream& istr) {
	
		return istr;
	}

	std::ostream& Product::write(std::ostream& ostr)const {
	
		return ostr;
	}

	double operator+= (double&, const Product&) {}

	//to input
	std::istream& operator>> (std::istream& is, Product& s) {
		s.read(is);
		return is;
	}

	//to display
	std::ostream& operator<< (std::ostream& os, const Product& s) {
		s.write(os);
		return os;
	}

}