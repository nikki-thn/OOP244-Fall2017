// Name: Nikki Truong
// Student_id: 112 314 174
// Section B
// Lab 7 - at home

#ifndef SICT_CHEQUING_ACCOUNT_H
#define SICT_CHEQUING_ACCOUNT_H 
#include <iostream>
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {
		 
		double m_transactionFee;
		double m_monthlyFee;

	public:

		// TODO: constructor initializes account balance and transaction fee
		ChequingAccount(double , double , double );

		// TODDO: credit adds +ve amount to the balance
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);

		// TODO: month end
		void monthEnd();

		// TODO: display inserts the account information into an ostream
		void display(std::ostream&) const;
	};

}
#endif
