#ifndef SICT_CHEQUING_ACCOUNT_H
#define SICT_CHEQUING_ACCOUNT_H 
#include <iostream>
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {
		 
		double m_transactionFee;
		double m_monthlyFee;

	public:
		ChequingAccount(double balance = 0.0, double transactionFee = 0.0, double monthlyFee = 0.0);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};

}
#endif
