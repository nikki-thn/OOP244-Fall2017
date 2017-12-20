// Name: Nikki Truong
// Student_id: 112 314 174
// Section E
// Milestone 2

#include <cstring>
#include <fstream>
#include "NonPerishable.h"

using namespace std;

namespace sict {

	//copy to m_name from parameter
	void NonPerishable::setName(const char* name) {

		if (name != nullptr) {
			m_name = nullptr;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		//if parameter is empty, delete previous name
		else {
			if (m_name != nullptr) delete[] m_name;
			m_name = nullptr;
		}
	}

	//Zero-One argument Constructor 
	NonPerishable::NonPerishable(char type) {

		if (type != ' ') m_type = type;
		else m_type = 'N';

		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';
		m_currentQty = 0;
		m_needQty = 0;
		m_price = 0.0;
		m_isTaxed = true;
		m_error.clear();
	}

	//Seven argument Constructor 
	NonPerishable::NonPerishable(const char* sku, const char* pName, const char* unit, int currentQty,
		bool isTaxed, double price, int needQty) {

		if (sku != nullptr && pName != nullptr && unit != nullptr) {

			if (strlen(sku) < max_sku_length)
				strcpy(m_sku, sku);
			else m_sku[0] = '\0';

			setName(pName);

			if (strlen(unit) < max_sku_length)
				strcpy(m_unit, unit);
			else m_unit[0] = '\0';

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
			strcpy(m_unit, rhs.m_unit);

			delete[] m_name;
			m_name = new char[strlen(rhs.m_name) + 1];
			strcpy(m_name, rhs.m_name);

			m_currentQty = rhs.m_currentQty;
			m_needQty = rhs.m_needQty;
			m_price = rhs.m_price;
			m_isTaxed = rhs.m_isTaxed;

			m_error.message(rhs.m_error.message());
		}
		else {
			m_name = nullptr;
		}
		return *this;
	}

	//returns true if m_sku and sku in parameter are same
	bool NonPerishable::operator==(const char* sku) const {

		bool isSame = false;

		if (sku != nullptr && m_name != nullptr) {
			if (strcmp(m_sku, sku) == 0) isSame = true;
		}
		return isSame;
	}

	//increase currentQty by parameter
	int NonPerishable::operator+=(int unit) {

		if (unit > 0) m_currentQty += unit;

		return m_currentQty;
	}

	std::fstream& NonPerishable::store(std::fstream& file, bool addNewLine)const {

		char a = ','; //char delimiter

		file << m_type << a << m_sku  << a << m_name << a << m_price << a;
		file << m_isTaxed << a << m_currentQty << a << m_unit << a << m_needQty;

		if (addNewLine == true) file << std::endl;

		return file;
	}

	std::fstream& NonPerishable::load(std::fstream& file) {

		char a; //char delimiter

		char nameIn[max_name_length];

		file.getline(m_sku, max_sku_length, ',');
		file.getline(nameIn, max_name_length, ',');
		setName(nameIn);

		file >> m_price >> a;
		file >> m_isTaxed >> a;
		file >> m_currentQty >> a;
		file.getline(m_unit, max_unit_length, ',');
		file >> m_needQty >> a;

		return file;
	}

	std::ostream& NonPerishable::write(std::ostream& os, bool linear) const {

		if (m_error.isClear()) {
			if (linear) {
				os.setf(ios::left);
				os.width(max_sku_length);
				os << m_sku << "|";
				os.width(20);
				os << m_name << "|";
				os.unsetf(ios::left);
				os.width(7);
				os.setf(ios::fixed);
				os.precision(2);
				os << cost() << "|";

				os.width(4);
				os << m_currentQty << "|";

				os.setf(ios::left);
				os.width(10);
				os << m_unit << "|";
				os.unsetf(ios::left);

				os.width(4);
				os << m_needQty << "|";
			}

			else {
				os << "Sku: " << m_sku << std::endl;
				os << "Name: " << m_name << std::endl;
				os.setf(ios::fixed);
				os.precision(2);
				os << "Price: " << cost() << std::endl;
			
				if (m_isTaxed) {
					os << "Price after tax: " << cost() << std::endl;
				}
				else {
					os << "Price after tax: N/A" << std::endl;
				}
				os.unsetf(ios::fixed);
				os << "Quantity on hand: " << m_currentQty << " " << m_unit << std::endl;
				os << "Quantity needed: " << m_needQty << std::endl;
			}
		}
		else {
			os << m_error.message();
		}

		return os;
	}

	std::istream& NonPerishable::read(std::istream& is) {

		bool isValid = true;

		char taxIn = ' ';
		char nameIn[max_name_length];
		int qty = 0;
		double price = 0.0;

		if (!is.fail()) {

			std::cout << "Sku: ";
			is.getline(m_sku, max_sku_length, '\n');

			cout << "Name: ";
			is.getline(nameIn, max_name_length, '\n');
			setName(nameIn);

			cout << "Unit: ";
			is.getline(m_unit, max_unit_length, '\n');

			cout << "Taxed? (y/n): ";
			is >> taxIn;
			is.ignore(200, '\n');


			if (taxIn != 'N' && taxIn != 'n' && taxIn != 'Y' && taxIn != 'y') {
				m_error.message("Only (Y)es or (N)o are acceptable");
				is.setstate(ios::failbit);
				isValid = false;
			}
			else if (taxIn == 'N' || taxIn == 'n') {
				m_isTaxed = false;
			}
			else if (taxIn == 'Y' || taxIn == 'y') {
				m_isTaxed = true;
			}

			if (isValid != false) {
				cout << "Price: ";
				is >> price;

				if (price <= 0.0) {
					m_error.message("Invalid Price Entry");
					is.setstate(ios::failbit);
					isValid = false;
				}
				else {
					m_price = price;
				}
			}

			if (isValid != false) {
				cout << "Quantity On Hand: ";
				is >> qty;

				if (m_currentQty < 0) {
					m_error.message("Invalid Quantity Entry");
					is.setstate(ios::failbit);
					isValid = false;
				}
				else {
					m_currentQty = qty;
				}
			}

			if (isValid != false) {
				cout << "Quantity Needed: ";
				is >> qty;

				if (m_needQty < 0) {
					m_error.message("Invalid Quantity Needed Entry");
					is.setstate(ios::failbit);
					isValid = false;
				}
				else {
					m_needQty = qty;
				}
			}

			if (isValid == true) m_error.clear();
		}

		return is;
	}

	//display to ostream
	std::ostream& operator<<(std::ostream& out, const Product& rhs) {

		rhs.write(out, true);
		return out;
	}

	//input from istream
	std::istream& operator>>(std::istream& in, Product& rhs) {

		rhs.read(in);
		return in;
	}

	//add totalCost of current object with the double recieve and return reference
	double operator+=(double& value, const Product& rhs) {

		value += rhs.total_cost();
		return value;
	}

	//create NonPerishable pointer
	Product* CreateProduct() {

		Product * pNonperishable = new NonPerishable;
		return pNonperishable;
	}

}