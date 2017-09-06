// TODO: insert header files
#include<iostream>
#include"Fraction.h"

// TODO: continue the namespace
namespace sict {

	// TODO: implement the default constructor

	// TODO: implement the two-argument constructor

	// TODO: implement the max query
	// max returns the maximum of the numerator and denominator
	//

	// TODO: implement the min query
	// min returns the minimum of the numerator and denominator
	//

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


	// TODO: implement the isEmpty query
	// isEmpty returns true if Fraction object is in a safe empty state
	//

	// TODO: implement the + operator
	// + operator adds the rhs to the current object and reduces the result
	//


}
