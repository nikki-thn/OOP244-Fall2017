#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
		private:
			double m_transactionFee;

			// TODO: chargeFee subtract transaction fee form the balance
			double m_chargeFree;

		public:

			// TODO: constructor initializes balance and transaction fee 
			CheckingAccount(double, double);

			//updates balance by deducting transecationFree 
			void chargeFee();

			// TODO: Write a function prototype to override credit function
			void credit (double);

			// TODO: Write a function prototype to override debit function
			bool debit (double);

			// TODO: Write a function prototype to  override display function
			void display (ostream &) const;
	};
};
#endif
