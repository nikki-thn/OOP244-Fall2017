#include <iostream>
#include "SavingsAccount.h"


using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
	//constructor
	SavingsAccount::SavingsAccount (double balance, double interestRate) : Account (balance) {
		
		if (balance >= 0) {
			setBalance(balance);
		}
		else {
			setBalance(1.0);
		}

		if (interestRate < 0) {
			m_interestRate = 0;
		}
		else if (interestRate > 0) {
			m_interestRate = interestRate;
		}

	}

	//function returns amount of interest earns by an account
	double SavingsAccount::calculateInterest () {
		
		double interestAmt = 0.0;

		interestAmt = getBalance() * m_interestRate;

		return interestAmt;
	}

	//function display account info
	void SavingsAccount::display (ostream& os) const {
		//Account::display(os);
		cout << "Account type: Saving" << endl;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Balance: $ " << getBalance() << endl;
		cout << "Interest rate (%): " << m_interestRate * 100 << endl;
	}
};
