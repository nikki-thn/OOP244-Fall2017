// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file defines the Account class
///////////////////////////////////////////////////

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	class Account : public iAccount{
		double m_balance;

	protected:
		double balance() const { return m_balance; } //return balance

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double balance = 0.0);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);

		virtual void display(std::ostream&) const;
	};

	//iAccount* CreateAccount(const char* account, double balance);

}
#endif