#include "ChequingAccount.h"

namespace sict {

	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee) 
		: Account (balance) {

		if (transactionFee > 0.0) m_transactionFee = transactionFee;
		if (monthlyFee > 0.0) m_monthlyFee = monthlyFee;
	}

	bool ChequingAccount::credit(double amount) {

		bool isAdded = Account::credit(amount);
		if (isAdded) {
			debit(m_transactionFee);
			isAdded = true;
		}

		return isAdded;
	}

	bool ChequingAccount::debit(double amount) {
		
		bool isSubstracted = Account::debit(amount);
		
		if (isSubstracted) {
			debit(m_transactionFee);
			isSubstracted = true;
		}
			return isSubstracted;
	}

	void ChequingAccount::monthEnd() {
		debit(m_monthlyFee);
	}
	void ChequingAccount::display(std::ostream& os) const {

		os << "Account type: Savings" << std::endl;
		Account::display(os);
		os << "Interest Rate (%): ";
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Per Transaction Fee: " << m_transactionFee << std::endl;
		os << "Monthly Fee: " << m_monthlyFee << std::endl;

	}

}