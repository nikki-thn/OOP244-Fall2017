#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict{
   
	class Account{
		private:
			double m_balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:
			// TODO: Write a prototype for constructor which initializes balance
			Account();
			Account(double);

			// TODDO: Write a function prototype for the virtual function credit 
			virtual void credit (double);

			// TODO: Write a function prototype for the virtual function debit
			virtual bool debit (double);

			// TODO: Write a function prototype for the virtual function display
			virtual void display (ostream&) const = 0;
   };
};
#endif
