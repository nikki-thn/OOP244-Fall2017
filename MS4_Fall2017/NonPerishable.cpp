#define  _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "NonPerishable.h"

namespace sict {

	//copy to m_name from parameter
	void NonPerishable::name(const char* name) {

		if (name != nullptr) {

		//	if (m_name != nullptr) delete [] m_name;
	 m_name = nullptr;

			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else {
			delete[] m_name;
			m_name = nullptr;
		}
	}

	//return m_name member
	const char* NonPerishable::name() const { return m_name; }

	//return the cost after tax (if m_isTaxed true)
	double NonPerishable::cost() const {

		double prodCost = 0.0;

		if (m_isTaxed == true) prodCost = m_price * (1 + tax_rate);
		else prodCost = m_price;

		return prodCost;
	}

	//copy to m_error from parameter
	void NonPerishable::message(const char* errorMess) {

		if (errorMess != nullptr) m_error.setMessage(errorMess);

	}

	//true is m_error has no content
	bool NonPerishable::isClear() const {

		bool clear = false;

		if (m_error.isClear() == true) clear = true;

		return clear;
	}

	//Zero-One argument Constructor 
	NonPerishable::NonPerishable(char type) {

		if (type != 'N') {
			m_type = type;
		}

		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';
		m_currentQty = 0;
		m_needQty = 0;
		m_price = 0.0;
		m_isTaxed = true;
	}

	//Seven argument Constructor 
	NonPerishable::NonPerishable(const char* sku, const char* pName, const char* unit, int currentQty,
		bool isTaxed, double price, int needQty) {



		if (sku != nullptr && pName != nullptr && unit != nullptr) {
			strcpy(m_sku, sku);
			name(pName);
			strcpy(m_unit, unit);
			m_currentQty = currentQty;
			m_isTaxed = isTaxed;
			m_price = price;
			m_needQty = needQty;
		}
		else {
			*this = NonPerishable();
		}
	}

	// Destructor
	NonPerishable::~NonPerishable() {
		if (m_name != nullptr) {
			delete[] m_name;
		}
	}

	//copy constructor
	NonPerishable::NonPerishable(const NonPerishable& rhs) {

		m_name = nullptr;
		*this = rhs;
	}

	//copy assignment
	NonPerishable& NonPerishable::operator=(const NonPerishable& rhs) {

		if (this != &rhs) {

			m_type = rhs.m_type;
			strcpy(m_sku, rhs.m_sku);

			delete[] m_name;
			m_name = new char[strlen(rhs.m_name) + 1];
			strcpy(m_name, rhs.m_name);

			strcpy(m_unit, rhs.m_unit);
			m_currentQty = rhs.m_currentQty;
			m_needQty = rhs.m_needQty;
			m_price = rhs.m_price;
			m_isTaxed = rhs.m_isTaxed;

			m_error.setMessage(rhs.m_error.message());
		}
		else {
			m_name = nullptr;
		}

		return *this;
	}

	//returns true if m_sku and sku in parameter are same
	bool NonPerishable::operator==(const char* sku) const {

		bool isSame = false;

		if (sku != nullptr) {
			if (strcmp(m_sku, sku) == 0) isSame = true;
		}
		return isSame;
	}

	//return total costs of all items
	double NonPerishable::total_cost() const {

		double total = 0.0;

		total += cost();
		return total;
	}

	//reset m_qty to parameter
	void NonPerishable::quantity(int qty) { m_currentQty = qty; }

	//return true if object is not in an error state
	bool NonPerishable::isEmpty() const { return m_error.isClear(); }

	// return m_needQty
	int NonPerishable::qtyNeeded() const { return m_needQty; }

	// return m_currentQty
	int NonPerishable::quantity() const { return m_currentQty; }

	//return true if m_sku is greater than parameter
	bool NonPerishable::operator>(const char*) const {
		//as in length or as in compare the two numbers????

		return true;
	}

	int NonPerishable::operator+=(int unit) {

		if (unit > 0) m_currentQty += unit;
		else m_currentQty;

		return m_currentQty;
	}

	bool NonPerishable::operator>(const Product& rhs) const {

		return true;
	}

	std::fstream& NonPerishable::store(std::fstream& file, bool addNewLine)const {

		char a = ','; //char delimiter

		if (!file.fail()) {

			file << m_type << a << m_name << a << m_sku << a << cost() << a;
			file << m_currentQty << a << m_unit << a << m_needQty;

			if (addNewLine == true) file << std::endl;

		}

		file.close();

		return file;
	}
	std::fstream& NonPerishable::load(std::fstream& file) {
		char a; //char delimiter

		if (!file.fail()) {
			while (file.eof()) {
				file >> m_type >> a >> m_name >> a >> m_sku >> a;
				file >> m_currentQty >> a >> m_unit >> a >> m_needQty;
			}

			return file;
		}
	}

	std::ostream& NonPerishable::write(std::ostream& os, bool linear) const {

		return os;
	}

	std::istream& NonPerishable::read(std::istream& is) {

		return is;
	}

	//cout
	std::ostream& operator<<(std::ostream& out, const Product& rhs) {

		rhs.write(out, true);
		return out;
	}

	//cin
	std::istream& operator>>(std::istream& in, Product& rhs) {

		rhs.read(in);
		return in;
	}

	//
	double operator+=(double& total, const Product& rhs) {
		total = rhs.total_cost();

		return total;
	}

	Product* CreateProduct() {

		Product * pNonperishable = new NonPerishable;
		return pNonperishable;
	}

}