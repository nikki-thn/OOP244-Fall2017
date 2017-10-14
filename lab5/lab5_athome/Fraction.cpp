/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 5 - at home
*/
// TODO: insert header files
#include<iostream>
#include"Fraction.h"

using namespace std;

// TODO: continue the namespace
namespace sict {

	// TODO: implement the default constructor
	Fraction::Fraction() {
		m_numerator = -1;
		m_denominator = -1;
	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator) {

		//data valid if numerator is non-negative and denomeator is positive
		bool valid = numerator >= 0 && denominator > 0;

		if (valid == 1) {

			//copy data to object when valid
			m_numerator = numerator;
			m_denominator = denominator;
		}

		if (valid == 0) {

			*this = Fraction(); //set object to safety state if data are invalid
		}
	}

	// TODO: implement the max query
	// max returns the maximum of the numerator and denominator
	int Fraction::max() const {

		int max = m_numerator;

		if (m_numerator < m_denominator) {

			max = m_denominator;
		}

		return max;
	}

	// TODO: implement the min query
	// min returns the minimum of the numerator and denominator
	int Fraction::min() const {

		int min = m_numerator;

		if (m_numerator > m_denominator) {

			min = m_denominator;
		}

		return min;
	}

	// gcd returns the greatest common divisor of num and denom
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
	void Fraction::reduce() {

		int g_c_d = gcd();

		m_numerator /= g_c_d;
		m_denominator /= g_c_d;
	}

	// TODO: implement the display query
	void Fraction::display() const {

		Fraction temp = *this;

		temp.reduce();

		bool empty = isEmpty();

		//print out when object is not empty
		if (empty == false) {

			if (temp.m_denominator != 1) {
				cout << temp.m_numerator << "/" << temp.m_denominator;
			}

			if (temp.m_denominator == 1) {
				cout << temp.m_numerator;
			}
		}

		//print out error message if object is empty
		if (empty == true) {
			cout << "no fraction stored";
		}

	}


	// TODO: implement the isEmpty query
	// isEmpty returns true if Fraction object is in safe empty state
	bool Fraction::isEmpty() const {

		bool emptyCheck = false;

		//check for safety state
		if (m_numerator == -1 && m_denominator == -1) {

			emptyCheck = true;
		}

		return emptyCheck;
	}

	// TODO: implement the operator+
	Fraction Fraction::operator+ (const Fraction& rhs) const {
		
		bool empty = isEmpty();
		Fraction temp;

		if (empty == false) {
			temp.m_numerator = (m_numerator * rhs.m_denominator) + (rhs.m_numerator * m_denominator);
			temp.m_denominator = m_denominator * rhs.m_denominator;
		}

		return temp;
	}

	// TODO: implement the operator*
	Fraction Fraction::operator* (const Fraction& rsh) const {

		bool empty = isEmpty();
		Fraction temp;
	
		//if object is not empty, perform calculation
		if (empty == false) {

			temp.m_numerator = m_numerator * rsh.m_numerator ;
			temp.m_denominator = m_denominator * rsh.m_denominator;
		}

		return temp;
	}

	// TODO: implement the operator== to compare two object
	bool Fraction::operator== (const Fraction& rsh) const {

		bool isEqual = false;
		bool empty = isEmpty();

		if (empty == false) {

			if (m_numerator == rsh.m_numerator && m_denominator == rsh.m_denominator) {
				isEqual = true;
			}
		}

		return isEqual;
	}

	// TODO: implement the operator!= to compare two object
	bool Fraction::operator!= (const Fraction& rsh) const {

		bool isNotEqual = false;
		bool empty = isEmpty();

		if (empty == false) {
			
			if (m_numerator != rsh.m_numerator && m_denominator != rsh.m_denominator) {
				isNotEqual = true;
			}
		}

		return isNotEqual;
	}

	// TODO: implement the operator+=
	Fraction& Fraction::operator+= (const Fraction& rsh) {

		bool empty = isEmpty();	
		
		Fraction temp = *this;
		
		if (empty == false) {

			temp = operator+(rsh); //add temp object with the Fraction object passed by parameter 
			temp.reduce(); //reduce object temp
		
		}
		
		return temp;
	}

}
