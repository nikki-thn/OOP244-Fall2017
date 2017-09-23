#include <iostream>
#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here  
	//constructor
	CheckingAccount::CheckingAccount(double balance, double transactionFee) : Account(balance) {

		if (transactionFee <= 0) {
			m_transactionFee = 0;
		}

		else {
			m_transactionFee = transactionFee;
		}

	}

	//updates balance by deducting transecationFree 
	void CheckingAccount::chargeFee() {
		double newBalance = getBalance();
		newBalance -= m_transactionFee;
		setBalance(newBalance);
	}

	// TODO: Write a function prototype to override credit function
	void CheckingAccount::credit(double creditAmt) {
		double newBalance = getBalance();
		newBalance += creditAmt;
		setBalance(newBalance);
	}

	// TODO: Write a function prototype to override debit function
	bool CheckingAccount::debit(double debitAmt) {
		bool isNotWithdrawn = Account::debit(debitAmt);
		double newBalance = getBalance();
		cout << "newBlance" << newBalance;

		if (isNotWithdrawn == false) {
			newBalance -= m_transactionFee;
			setBalance(newBalance);
		}

		return isNotWithdrawn;
	}



	//function display account info
	void CheckingAccount::display(ostream& os) const {
		cout << "Account type: Chequeing" << endl;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Balance: $ " << getBalance() << endl;
		cout << "Transaction Fee: " << m_transactionFee << endl;
	}
}