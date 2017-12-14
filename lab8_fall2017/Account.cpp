// Name: Nikki Truong
// Student_id: 112 314 174
// Section B
// Lab 7 - at home

// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the Account class
///////////////////////////////////////////////////

#include "Account.h"

namespace sict {

	// TODO: constructor initializes account balance, defaults to 0.0 
	Account::Account(double balance) {
		if (balance > 0) m_balance = balance;
	}

	// TODO: credit adds +ve amount to the balance 
	bool Account::credit(double amount) { 

		bool wasAdded = false;
		if (amount > 0) {
			m_balance += amount;
			wasAdded = true;
		}
		return wasAdded;
	}

	// TODO: debit subtracts a +ve amount from the balance
	bool Account::debit(double amount) {

		bool wasSubstracted = false;
		if (amount > 0) {
			m_balance -= amount;
			wasSubstracted = true;
		}
		return wasSubstracted;
	}

	void Account::display(std::ostream& os) const {
		os << "Balance: $" << os.setf(std::ios::fixed) << os.precision(2) << m_balance << std::endl;
	}

}