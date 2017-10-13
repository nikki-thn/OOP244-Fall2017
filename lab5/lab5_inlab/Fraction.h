#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H


// TODO: create namespace
namespace sict {

	// TODO: define the Fraction class
	class Fraction {

		int m_numerator;
		int m_denominator;

		int gcd() const; // returns the greatest common divisor of num and denom
		int max() const; // returns the maximum of num and denom
		int min() const; // returns the minimum of num and denom
		void reduce();   // simplifies a Fraction by dividing the 
				 // numerator and denominator to their greatest common divisor 

	public:
		// TODO: declare the member functions
		Fraction(); //default constructor
		Fraction(int nn, int nd); //2 parameters constructor

		bool isEmpty() const; //to check if the object is empty
		void display() const; //query


		// TODO: declare the + operator overload
		Fraction operator+ (const Fraction&) const; //operator to add current object and another object 
	};

}


#endif
