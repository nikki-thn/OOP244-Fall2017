/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 5 - In lab
*/

// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H


// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {

		int numer; //numerator
		int deno; //denominator


		int gcd() const; // returns the greatest common divisor of num and denom
		int max() const; // returns the maximum of num and denom
		int min() const; // returns the minimum of num and denom
		void reduce();   // simplifies a Fraction by dividing the 
						 // numerator and denominator to their greatest common divisor 

	public:

		// TODO: declare the member functions
		Fraction();
		Fraction(int nn, int nd);

		bool isEmpty() const;
		void display() const;

		// TODO: declare the + operator overload
		Fraction operator+ (Fraction& num);
		Fraction operator* (Fraction& num);
		bool& operator== (Fraction& num);
		bool& operator!= (Fraction& num);
		Fraction operator+= (Fraction& num);

	};

}


#endif
