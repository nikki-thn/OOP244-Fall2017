#include "SavingsAccount.h"

namespace sict {

	// TODO: constructor initializes balance and interest rate
	SavingsAccount::SavingsAccount(double balance, double interestRate) :
			Account (balance) { 
		if (interestRate > 0) m_interestRate = interestRate;
		else m_interestRate = 0.0;
	}

	// TODO: perform month end transactions
	void SavingsAccount::monthEnd(){
		credit(balance()*m_interestRate);
	}

	// TODO: display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& os) const{ 
	
		os << "Account type: Savings" << std::endl;
		Account::display(os);
		os << "Interest Rate (%): ";
		os.setf(std::ios::fixed);
		os.precision(2);
		os << m_interestRate * 100 << std::endl;
	}

}