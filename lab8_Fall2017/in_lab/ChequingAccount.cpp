// Name: Nikki Truong
// Student_id: 112 314 174
// Section B
// Lab 7 - at home

#include "ChequingAccount.h"

namespace sict {

	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee)
		: Account(balance) {

		if (transactionFee > 0.0) m_transactionFee = transactionFee;
		if (monthlyFee > 0.0) m_monthlyFee = monthlyFee;
	}

	bool ChequingAccount::credit(double amount) {

		bool isSuccess = Account::credit(amount);
		if (isSuccess) Account::debit(m_transactionFee);

		return isSuccess;
	}

	bool ChequingAccount::debit(double amount) {

		bool isSuccess = Account::debit(amount);
		if (isSuccess) Account::debit(m_transactionFee);

		return isSuccess;
	}

	void ChequingAccount::monthEnd() {

		ChequingAccount::debit(m_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& os) const {

		os << "Account type: Chequing" << std::endl;
		Account::display(os);
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "Per Transaction Fee: " << m_transactionFee << std::endl;
		os << "Monthly Fee: " << m_monthlyFee << std::endl;
	}

}
