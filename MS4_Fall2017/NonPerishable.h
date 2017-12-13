#ifndef SICT_NON_PERISHABLE_H
#define SICT_NON_PERISHABLE_H

#include "Product.h"
#include "ErrorMessage.h"

namespace sict {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13; //tax rate 13%

	class NonPerishable : public Product {

		char m_type;
		char m_sku[max_sku_length + 1];
		char* m_name;
		char m_unit[max_unit_length];
		int m_currentQty;
		int m_needQty;
		double m_price;
		bool m_isTaxed;
		ErrorMessage m_error;

	protected:

		void name(const char*); //copy to m_name from parameter
		double cost() const; //return the cost after tax (if taxed)
		void message(const char* errorMess); //copy to m_error from parameter
		const char* name() const; //return m_name member
		bool isClear() const; //true is m_error has no content

	public:

		NonPerishable(char type = 'N'); //Zero-One argument Constructor 
		NonPerishable(const char* sku, const char* name, const char* unit, int currentQty = 0,
			bool isTaxed = true, double price = 0.0, int needQty = 0); //Seven argument Constructor 
		~NonPerishable(); // Destructor

		NonPerishable(const NonPerishable&); //copy constructor
		NonPerishable& operator=(const NonPerishable&); //copy assignment

		std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& is);

		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;

	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
}

#endif