#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include"Streamable.h"

#define MAX_SKU_LEN 4

namespace sict {

	class Product {

		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;

	public:

		Product();
		Product(char*, char*, bool, double, int);
		Product(const char*,const char*);
		virtual ~Product();

		Product(const Product&);
		Product& operator= (const Product&);
	
		void sku(char*);
		void price(double);
		void name(char*);
		void taxed(bool);
		void quantity(int);
		void qtyNeeded(int);

		char sku() const { return *sku_; }
		double price() const { return price_; }
		char* name() const { return name_; }
		bool taxed() const { return taxed_; }
		int quantity() const { return quantity_; }
		int qtyNeeded() const { return qtyNeeded_; }

		double cost() const;
		bool isEmpty() const;

		bool operator== (const char*);
		int operator+= (int);
		int operator-= (int);

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;

	};

	double operator+= (double&, const Product&);

	std::istream& operator>> (std::istream& is, Product& s);
	std::ostream& operator<< (std::ostream& is, const Product& s);
}


#endif
