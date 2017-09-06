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
		numer = 0;
		deno = 0;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int nn, int nd) {
		
		//data valid if numerator is non-negative and denomeator is positive
		bool valid = nn >= 0 && nd > 0;

		if (valid == true) {
			
			//copy data to object when valid
			numer = nn;
			deno = nd;
		}

		if (valid == false) {

			Fraction(); //set object to safety state if data are invalid
		}
	}

	// TODO: implement the max query
	// max returns the maximum of the numerator and denominator
	//
	int Fraction::max() const {
		int greater = 0;

		if (numer >= deno) {

			greater = numer;
		}

		if (numer < deno) {

			greater = deno;
		}

		return greater;
	}

	// TODO: implement the min query
	// min returns the minimum of the numerator and denominator
	//
	int Fraction::min() const {
		int lesser = 0;

		if (numer >= deno) {

			lesser = deno;
		}

		if (numer < deno) {

			lesser = numer;
		}

		return lesser;
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
	void Fraction::reduce() {


	}

	// TODO: implement the display query
	// display inserts num/denom into the output stream
	//
	void Fraction::display() const {

		bool empty = isEmpty();

		cout << numer << "/" << deno << endl;

		if (deno == 1) {

			cout << numer << endl;
		}

		if (empty == true) {

			cout << "no fraction stored" << endl;
		}

	}


	// TODO: implement the isEmpty query
	// isEmpty returns true if Fraction object is in a safe empty state
	//
	bool Fraction::isEmpty() const {

		bool emptyCheck = true;

		if (numer != 0 && deno != 0) {

			emptyCheck = false;
		}

		return emptyCheck;

	}

	// TODO: implement the + operator
	// + operator adds the rhs to the current object and reduces the result
	//
	Fraction Fraction::operator+ (int& num) {

		int result = 0;


		return Fraction(numer, deno);
	}


}
