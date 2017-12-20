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
		char m_unit[max_unit_length + 1];
		int m_currentQty;
		int m_needQty;
		double m_price;
		bool m_isTaxed;
		ErrorMessage m_error;

	protected:

		void setName(const char*); //copy to m_name from parameter		
		const char* name() const; //return m_name member
		double cost() const; //return the cost after tax (if m_isTaxed true)	
		void message(const char* errorMess);//copy to m_error from parameter	
		bool isClear() const; 	//true is m_error has no content

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
		int operator+=(int); //increment currentQty
		bool operator==(const char*) const; //compare name
	
		bool operator>(const char* sku) const; //return true if m_sku is greater than parameter 
		bool operator>(const Product& rhs) const; //compare m_name and parameter	
		void quantity(int qty); //reset m_qty to parameter
		bool isEmpty() const; //return true if object is empty
		int qtyNeeded() const; 	// return m_needQty
		int quantity() const; // return m_currentQty
		double total_cost() const; //return total costs of all items

	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();
}

#endif