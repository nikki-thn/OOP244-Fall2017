#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace ict {




	//////////////////////////////////////////////////////
	//
	// Default Constructor
	// String::String(int capacity);
	//
	// initialize the string with an internal buffer capacity of 
	// "capacity." 
	// default capacity is 1 (minimum needed for an empty string)
	//
	// 
	String::String(int size) {
		m_pString = nullptr;
		m_capacity = size;
	}

	//////////////////////////////////////////////////////
	//
	// String::String(const char* p, int capacity);
	//
	// Construct a String from a char array
	// Should initialize the internal buffer to at least 
	// the length of the string need to hold pSource, 
	// or capacity, whichever is greater.
	//
	// 
	String::String(const char* pSource, int size) {

		if (pSource != nullptr) {

			int length = strlen(pSource);

			if (size >= length) {
				m_capacity = size + 1;	
			}
			else if (size < length) {
				m_capacity = length + 1;
			}

			m_pString = new char[m_capacity + 1];
			strcpy(m_pString, pSource);
		}
		else {

			*this = String();
		}

	}

	//////////////////////////////////////////////////////
	//
	// String::String(const String &s, int capacity);
	//
	// Copy constructor
	//
	// Construct a String from another String
	//
	// 
	String::String(const String& other, int size)
	{
		if (this != &other) {
			int length = strlen(other.m_pString);
			if (size >= length) {
				m_capacity = size + 1;
			}

			else if (size < length) {
				m_capacity = length + 1;
			}
			m_pString = new char[m_capacity + 1];
			strcpy(m_pString, other.m_pString);
		}
	}



	//////////////////////////////////////////////////////
	//
	// String::resize(int newsize)
	//
	// resize the internal buffer to the value given
	// do NOT shrink the string buffer smaller than 
	// that needed to hold the existing string!
	// (length + 1);
	//    
	void String::resize(int newsize)
	{
			m_capacity += (newsize + 1);
			delete[] m_pString;
			m_pString = new char[m_capacity];
	}


	//////////////////////////////////////////////////////
	//
	// String::operator=(const String& other)
	// 
	// Assignment operator
	// copy string "other" to this object
	//   
	// 
	String& String::operator=(const String& other)
	{
		if (this != &other) {

			int length = strlen(other.m_pString);

			if (m_capacity <= length) {
				m_capacity = length + 1;
			}

			if (m_pString != other.m_pString) {
				delete[] m_pString;

				//	else { m_capacity = m_capacity + 1;	}

				m_pString = new char[m_capacity];
				strcpy(m_pString, other.m_pString);
			}
		}

		return *this;
	}


	//////////////////////////////////////////////////////
	//
	// String::~String
	// 
	// destructor
	// 
	// clean up the internal string buffer  
	// 
	String::~String()
	{
		delete[] m_pString;
	}

	//////////////////////////////////////////////////////
	//
	// String::length()
	// 
	// return the length of the string
	// 
	// 
	int String::length() const
	{
		int length = 0;
		if (m_pString != nullptr) {
			length = strlen(this->m_pString);
		}
		return length;
	}


	//////////////////////////////////////////////////////
	//
	// String::operator const char*() const
	// 
	// convert the String to a char*
	// 
	// 
	String::operator const char *() const
	{
		const char *aString;
		return aString = this->m_pString;
	}


	//////////////////////////////////////////////////////
	//
	// String::empty()
	// 
	// 
	// returns true if the string is empty
	// i.e. either the first char is \0, or 
	// length is 0.
	bool String::empty() const
	{
		bool isEmpty = false;

		if (m_pString == nullptr || m_capacity == 1) {
			isEmpty = true;
		}
		return isEmpty;
	}

	//////////////////////////////////////////////////////
	//
	// String::operator bool()
	// 
	// same as empty(), just wrapped in an operator
	// 
	//     
	String::operator bool() const
	{
		return m_pString != nullptr;
	}


	//////////////////////////////////////////////////////
	//
	// String::operator==(const String& s2) const
	// 
	// returns true if *this == s2.
	// You can use the strcmp function to check if 
	// two strings are equal, or write your own
	// treating the string as a char-array
	//      
	bool String::operator==(const String& s2) const
	{
		bool isSame = false;

		if (!(strcmp(m_pString, s2.m_pString))) {

			isSame = true;
		}
		return isSame;
	}


	//////////////////////////////////////////////////////
	//
	// String::operator+=(const String& s2)
	// 
	// Concatenates s2 to the end of *this
	//
	// implements *this = (*this + s2)
	// return *this
	// 
	// 
	String& String::operator+=(const String& s2)
	{
		String temp = *this;
		if (this != &s2) {
			int size = strlen(s2.m_pString);
			temp.resize(size);
			strcpy(temp.m_pString, this->m_pString);
			strcat(temp.m_pString, s2.m_pString);
		}

		*this = temp;
		return *this;
	}



	//////////////////////////////////////////////////////
	//
	// String::operator+(const String& s2) const
	// 
	// implements the operator (*this + s2)
	// returns the expression
	// DOES NOT MODIFY *this
	// 
	// 
	String String::operator+(const String& s2) const
	{
		String temp = *this;
		if (this != &s2) {
			int size = strlen(s2.m_pString);
			temp.resize(size);
			strcpy(temp.m_pString, this->m_pString);
		}
		return strcat(temp.m_pString, s2.m_pString);
	}

	//////////////////////////////////////////////////////
	//
	// String::operator+=(char c)
	// 
	// Adds a single char c to the end of the string in *this
	// Grows the string buffer if necessary.
	//  
	String& String::operator+= (char c)
	{
		this->resize(1);
		int size = strlen(m_pString);
		m_pString[size] = c;
		m_pString[size + 1] = '\0';
		return *this;
	}



	//////////////////////////////////////////////////////
	//
	// String::substr
	// 
	// Returns a substring of the current string. In case of error
	// return an empty String() object instead.
	// 
	// return the string slice starting at index, at most len characters
	// 
	// both index and len have to lie inside the string. If they do not, then 
	// that is an error
	// 
	//String String::substr(int index, int len) const
	//	{
	//return *this;
	//	}

	void String::display(std::ostream& os) const {
		cout << m_pString;
	}

	//////////////////////////////////////////////////////
	//
	// operator<<
	// 
	// Print the string to the output stream
	// 
	// clean up the internal string buffer  
	// 
	std::ostream& operator<<(std::ostream& ostream, const String &s)
	{
		s.display(ostream);
		ostream.clear();
		return ostream;
	}

	//////////////////////////////////////////////////////
	//
	// operator>>
	// 
	// Input a string from an input stream into the String s
	// 
	// Note: the input can be ANY length in character. You will need to 
	// read it one char at a time. 
	// 
	std::istream& operator>>(std::istream& istream, String &s)
	{
		s = "";
		char tempC = 0;
		do
		{
			tempC = istream.get();
			if (tempC != '\n')
			{
				s += tempC;
			}
			else
				break;
		} while (1);
		return istream;
	}


}


/*#define CATCH_CONFIG_MAIN


#include <iostream>
//#include <cassert>
//#include "String.h"
#include "catch.hpp"
#include "String.h"


//using namespace std;
using namespace ict;




TEST_CASE("Test for lab 9", "[Tag to classify tests]") { //using TEST_CASE to create a unit test
													     //[Tag] is optional
	char a[] = "Hello";
	String newString (a);
	//String bString = newString;
//	String cString(" World");
	newString += 'A';
//	String bString = newString + cString;

//	String dString("Hello World");
//	bool abool = (bString == dString);
	int length = strlen("HelloA");

//	REQUIRE(abool); //this is where we specify the results we want if test runs successfully
	REQUIRE(newString.length() == length);
	//REQUIRE(cString.resize(10) == (length + 11));
}

TEST_CASE("Another test") {

	String aString("Hello");
	String bString("World");
	bString += aString;
	bString.resize(10);

	REQUIRE(bString.resize(10) == 16);
	REQUIRE(aString.length() == 5);
}


TEST_CASE("Test for lab 9") {

String newString("Hello");
String aString(" World");
String cString("Hello World");
newString += aString;

//	String bString = newString + cString;

//	String dString("Hello World");
bool abool = (newString == cString);

int length = strlen(cString);

REQUIRE(abool); //this is where we specify the results we want if test runs successfully
REQUIRE(newString.length() == length);
//REQUIRE(cString.resize(10) == (length + 11));
}

*/
