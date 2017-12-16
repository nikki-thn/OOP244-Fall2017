// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file allocates an Account object in dynamic memory
///////////////////////////////////////////////////
#include "SavingsAccount.h" 
#include "Account.h"
#include "ChequingAccount.h"
namespace sict {


	// define interest rate
	const double interest_rate = 0.05;
	const double transaction_fee = 0.05;
	const double monthly_fee = 2.00;

	// TODO: Allocator function
	iAccount* CreateAccount(const char* account, double balance) {

		iAccount* pAccount = nullptr;

		if (account[0] == 's' || account[0] == 'S') {
			pAccount = new SavingsAccount(balance, interest_rate);
		}
		else if (account[0] == 'c' || account[0] == 'C') {
			pAccount = new ChequingAccount (balance, transaction_fee, monthly_fee);
		}
		return pAccount;
	}



}