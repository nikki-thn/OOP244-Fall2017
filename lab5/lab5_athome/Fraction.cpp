/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 5 - In lab
*/

// TODO: insert header files
#include<iostream>
#include"Fraction.h"

using namespace std;
// TODO: continue the namespace
namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction() {
		numer = -1;
		deno = -1;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int nn, int nd) {

		//data valid if numerator is non-negative and denomeator is positive
		bool valid = nn >= 0 && nd > 0;

		if (valid == 1) {

			//copy data to object when valid
			numer = nn;
			deno = nd;
		}

		if (valid == 0) {

			*this = Fraction(); //set object to safety state if data are invalid
		}
	}

	// TODO: implement the max query
	// max returns the maximum of the numerator and denominator
	//
	int Fraction::max() const {

		int max = numer;

		if (numer < deno) {

			max = deno;
		}

		return max;
	}

	// TODO: implement the min query
	// min returns the minimum of the numerator and denominator
	//
	int Fraction::min() const {

		int min = numer;

		if (numer > deno) {

			min = deno;
		}

		return min;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {

		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found

			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}

		return g_c_d;
	}

	// TODO: implement the reduce modifier
	// reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
	//
	//***reduce function is not called, need to call it somewhere
	void Fraction::reduce() {

		int g_c_d = gcd();

		numer /= g_c_d;
		deno /= g_c_d;
	}

	// TODO: implement the display query
	// display inserts num/denom into the output stream
	//
	void Fraction::display() const {

		Fraction a = *this;

		a.reduce(); //???why reduce() takes effective in operator+ function???

		bool empty = isEmpty();

		//print out when object is not empty
		if (empty == false) {

			if (a.deno != 1) {
				cout << a.numer << "/" << a.deno << endl;
			}

			if (a.deno == 1) {
				cout << a.numer << endl;
			}
		}

		//print out error message if object is empty
		if (empty == true) {

			cout << "no fraction stored" << endl;
		}

	}


	// TODO: implement the isEmpty query
	// isEmpty returns true if Fraction object is in a safe empty state
	//
	bool Fraction::isEmpty() const {

		bool emptyCheck = false;

		if (numer == -1) {

			emptyCheck = true;
		}

		return emptyCheck;
	}

	// TODO: implement the + operator
	// + operator adds the rhs to the current object and reduces the result
	// https://www.codingunit.com/cplusplus-tutorial-unary-and-binary-operator-overloading-and-static-members
	Fraction Fraction::operator+ (Fraction& num) {

		bool empty = isEmpty();
		int addedNumer = 0;
		int addedDeno = 0;

		if (empty == false) {
			addedNumer = (numer * num.deno) + (num.numer * deno);
			addedDeno = deno * num.deno;
		}

		if (empty == true) {

			*this = Fraction();
		}

		return Fraction(addedNumer, addedDeno);
	}

	Fraction Fraction::operator* (Fraction& num) {

		bool empty = isEmpty();
		int multipliedNumer = 0;
		int multipliedDeno = 0;

		if (empty == false) {

			multipliedNumer = numer * num.numer ;
			multipliedDeno = deno * num.deno;
		}

		if (empty == true) {

			*this = Fraction();
		}

		return Fraction(multipliedNumer, multipliedDeno);
	}

	bool& Fraction::operator== (Fraction& num) {

		bool isEqual = false;
		bool empty = isEmpty();

		if (empty == false) {
			if (numer == num.numer && deno == num.deno) {

				isEqual = true;
			}
		}

		if (empty == true) {

			*this = Fraction();
		}

		return isEqual;
	}

	bool& Fraction::operator!= (Fraction& num) {

		bool isNotEqual = false;
		bool empty = isEmpty();

		if (empty == false) {
			if (numer != num.numer && deno != num.deno) {

				isNotEqual = true;
			}
		}

		if (empty == true) {

			*this = Fraction();
		}

		return isNotEqual;
	}

	Fraction Fraction::operator+= (Fraction& num) {

		bool empty = isEmpty();	
		
		Fraction temp = *this;
		temp = operator+(num);
		
		//call reduce() to reduce of current object and the unmodifiable reference
		num.reduce();
		temp.reduce();

		if (empty == false) {

			*this = temp;
		}

		if (empty == true) {

			*this = Fraction();
		}

		return temp;

	}


}
