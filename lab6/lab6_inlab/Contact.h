#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict {

	class Contact {

		char name[21];
		int numOfPhones;
	
		long long* phoneNum;

	public:

		Contact();
		Contact(const char*, const long long*, int);
		~Contact();

		bool isEmpty() const;
		void display() const;

	};

	//exact number
	//bool exact(long long);


}


#endif


//Dynamic allocated array http://www.cs.fsu.edu/~jestes/cop3330/notes/dma.html 
//Another link https://stackoverflow.com/questions/15369913/dynamic-arrays-inside-a-class
