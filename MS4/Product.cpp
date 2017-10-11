#include <iostream>
#include <cstring>
#include"Product.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {

	Product::Product() {

		sku_ [0] = '\0';
		name_ = nullptr;
		taxed_ = true;
		price_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(const char* sku, const char* name) {

		if (name != nullptr) {
			name_ = new char[strlen(name) + 1];
			strcpy(name_, name);
		}

		if (strlen(sku) < MAX_SKU_LEN && sku != nullptr) {
			strcpy(sku_, sku);
		}
		
		taxed_ = true;
		price_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(char* sku, char* name, bool taxed, double price, int qtyNeeded) {

		if (name != nullptr) {
			name_ = new char[strlen(name) + 1];
			strcpy(name_, name);
		}

		if (strlen(sku) < MAX_SKU_LEN && sku != nullptr) {
			strcpy(sku_, sku);
		}

		bool cont = name_ != nullptr && sku_[0] != '\0';
			
		if (cont){
			quantity_ = 0;
			price_ = price;
			qtyNeeded_ = qtyNeeded;

			if (taxed == false) {
				taxed_ = taxed;
			}
		}

		else {

			sku_[0] = '\0';
			name_ = nullptr;
			taxed_ = true;
			price_ = 0;
			quantity_ = 0;
			qtyNeeded_ = 0;
		}
	}



	Product::~Product() {

		delete [] name_;
	}

	Product::Product(const Product& temp) {

		name_ = nullptr;
		*this = temp;

	}

	Product& Product::operator= (const Product& temp) {

		//check for self-assignment
		if (this != &temp) {

			strcpy(sku_, temp.sku_);
			quantity_ = temp.quantity_;
			price_ = temp.price_;
			qtyNeeded_ = temp.qtyNeeded_;
			taxed_ = temp.taxed_;

			delete[] name_;

			//allocate memory
			if (temp.name_ != nullptr) {

				name_ = new char[strlen(temp.name_) + 1];
				strcpy(name_, temp.name_);
			}
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
	
		name_ = new char[strlen(name) + 1];
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
		if (strcmp(sku_,sku)) {
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
		totalCost = temp.quantity() * temp.cost();

		value += totalCost;

		return value;
	}
	
	std::ostream& Product::write(std::ostream& os, bool linear ) const {

		return os;
	}

	std::istream& Product::read(std::istream& is) {

		//is >> name_ >> sku_ >> qtyNeeded_ >> quantity_;

		return is;
	}

	//to input
	std::istream& operator>> (std::istream& is, Product& s) {
		s.read(is);
		return is;
	}

	//to display
	std::ostream& operator<< (std::ostream& os, const Product& s) {
		s.write(os, true);
		return os;
	}

}
