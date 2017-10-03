#include <iostream>
#include <cstring>
#include"Product.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {

	Product::Product() {

		sku_ [0] =  '\0';
		price_ = 0;
		name_ = nullptr;
		quantity_ = 0;
		qtyNeeded_ = 0;
		taxed_ = true;
	}

	Product::Product(const char* sku, const char* name) {

		if (sku != " " && name != " ") {
			strncpy(sku_, sku, MAX_SKU_LEN);
			name_ = new char[strlen(name) + 1];
			strcpy(name_, name);
		}
	}

	Product::Product(char* sku, char* name, bool taxed, double price, int qtyNeeded) {

		if (sku != " " && name != " ") {
			strncpy(sku_, sku, MAX_SKU_LEN);
			name_ = new char[strlen(name) + 1];
			strcpy(name_, name);


			quantity_ = 0;
			price_ = price;
			qtyNeeded_ = qtyNeeded;

			if (taxed == false) {
				taxed_ = taxed;
			}
		}

		else {
			sku_[MAX_SKU_LEN + 1] = { '\0' };
			price_ = 0;
			name_ = nullptr;
			quantity_ = 0;
			qtyNeeded_;
			taxed_ = true;
		}
	}



//	Product::~Product() {

//		delete[] name_;
//	}

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

		return *this;
	}
	
	
	void Product::sku(char sku[]) {
		strcpy(sku_, sku);
	}

	void Product::price(double price) {
		price_ = price;
	}

	void Product::name(char* name) {
		strcpy(name_, name);
	}

	void Product::taxed(bool taxed) {
		taxed_ = taxed;
	}

	void Product::quantity(int quantity) {
		quantity_ = quantity;
	}

	void Product::qtyNeeded(int qtyNeeded) {
		qtyNeeded_ = qtyNeeded;
	}

	double Product::cost() const {

		double cost = 0;
		if (taxed_ == true) {
			cost = price_ * (TAX + 1);
		}

		return cost;
	}

	bool Product::isEmpty() const {

		bool empty = false;

		if (sku_[0] == '\0') {

			empty = true;
		}

		return empty;
	}

	bool Product::operator== (const char* sku) {

		bool isSame = false;
		if (sku_ == sku) {
			isSame = true;
		}

		return isSame;
	}

	int Product::operator+= (int value) {
	
		quantity_ += value;

		return quantity_;
	}

	int Product::operator-= (int value) {
	
		quantity_ -= value;

		return quantity_;
	}


	double operator+= (double& value, const Product& temp) {
		
		double totalCost = 0;
		totalCost = temp.quantity() * temp.price();

		totalCost += value;

		return totalCost;
	}
	
	std::istream& Product::read(std::istream& istr) {
	
		
		return istr;
	}

	std::ostream& Product::write(std::ostream& ostr)const {

		cout << name_ << endl;
		return ostr;
	}

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
