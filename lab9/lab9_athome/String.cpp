#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict {




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
			m_capacity = strlen(pSource);

			if (size >= m_capacity + 1) {

				m_pString = new char[size + 1];
				strcpy(m_pString, pSource);
			}
			else if (size < m_capacity + 1) {

				m_pString = new char[m_capacity + 1];
				strcpy(m_pString, pSource);
			}
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
		int length = strlen(other.m_pString);
		if (size >= length + 1) {
			m_pString = new char[size];
			strcpy(m_pString, other.m_pString);
		}

		else if (size < length + 1) {
			m_pString = new char[length + 1];
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
		if (newsize > m_capacity) {
			m_capacity = newsize + 1;
		}
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
			delete[] m_pString;
			m_pString = new char[strlen(other.m_pString) + 1];
			strcpy(m_pString, other.m_pString);

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
		//delete[] m_pString;
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
		if (!s2.empty() && !this->empty()) {

			//strcmp(this->m_pString, s2.m_pString)
			//	cout << this->m_pString;
			//cout << s2.m_pString;
			//cout << "isSame" << isSame << endl;
			if (strcmp(m_pString, s2.m_pString)) {
				isSame = true;
			}
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
		if (this != &s2) {
			strcat(this->m_pString, s2.m_pString);
		}
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
