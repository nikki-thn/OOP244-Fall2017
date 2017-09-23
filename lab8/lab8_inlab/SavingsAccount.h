#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{

	class SavingsAccount : public Account{

		private:

    		double m_interestRate; // interest rate (percentage) 
		public:
		
		// TODO: put prototypes here
		SavingsAccount(double, double);

		//function returns amount of interest earns by an account
		double calculateInterest ();

		//function display account info
		void display (ostream&) const;
   };

};
#endif

