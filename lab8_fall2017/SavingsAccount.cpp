#include "SavingsAccount.h"

namespace sict {

	// TODO: constructor initializes balance and interest rate
	SavingsAccount::SavingsAccount(double balance, double interestRate) :
			Account (balance) { 
		if (interestRate > 0) m_interestRate = interestRate;
	}

	// TODO: perform month end transactions
	void SavingsAccount::monthEnd(){
		credit(balance()*m_interestRate);
	}

	// TODO: display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& os){ 
		os << "Account type: Savings" << std::endl;
		Account::display(os);
		os << "Interest Rate (%): " << os.precision(2) << m_interestRate << std::endl;
	}

	/*iAccount* CreateAccount(const char*, double) {
		iAccount* pAccount = nullptr;

		if (account[0] == 's' || account[0] == 'S') {
			pAccount = new SavingsAccount(balance);
		}

	}*/
}