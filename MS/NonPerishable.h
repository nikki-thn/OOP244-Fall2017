// Name: Nikki Truong
// Student_id: 112 314 174
// Section E
// Milestone 2

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

		void setName(const char*); //copy to m_name from parameter

		//return m_name member
		const char* name() const { return m_name; }

		//return the cost after tax (if m_isTaxed true)
		double cost() const { return m_isTaxed ? m_price * (1 + tax_rate) : m_price; }

		//copy to m_error from parameter
		void message(const char* errorMess) { if (errorMess) m_error.message(errorMess); }

		//true is m_error has no content
		bool isClear() const { return m_error.isClear(); }

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

		bool operator==(const char*) const; //compare name
		bool operator>(const char*) const; //compare name, true if >
		int operator+=(int); //increment currentQty
		bool operator>(const Product&) const; //compare name
											  
		//reset m_qty to parameter
		void quantity(int qty) { m_currentQty = qty; }

		//return true if object is not in an error state, no error means not empty??
		bool isEmpty() const { return m_sku[0] == '\0'; }

		// return m_needQty
		int qtyNeeded() const { return m_needQty; }

		// return m_currentQty
		int quantity() const { return m_currentQty; }

		//return total costs of all items
		double total_cost() const { return m_currentQty * cost(); }

	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
}

#endif