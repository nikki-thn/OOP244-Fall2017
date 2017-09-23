#include "Account.h"

using namespace std;

namespace ict{ 
	
	//default constructor
	Account::Account() {
		m_balance = 0.0;
	}

	// constructor   
	Account::Account (double balance) {
		if (balance >= 0.0) {
			m_balance = balance;
		}
		else {
			m_balance = 1.0;
		}
	}

	// credit (add) an amount to the account balance
	void Account::credit (double credit) {
		m_balance += credit;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit  (double debit) {

		bool isExceed = false;
		if (debit <= m_balance) {
			m_balance -= debit;
		}
		else if (debit > m_balance) {
			isExceed = true;
		}
		return isExceed;
	}

	double Account::getBalance() const
	{
		return m_balance;
	} 

	void Account::setBalance( double newBalance )
	{
		m_balance = newBalance;
	} 
}