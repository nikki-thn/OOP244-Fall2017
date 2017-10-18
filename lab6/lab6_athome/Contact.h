#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict {

	class Contact {

		char m_name[20];
		int m_numOfPhones;
		long long* m_phoneNum;

	public:

		Contact(); //no parameter constructor
		Contact(const char*, const long long*, int); //3 parameter constructor
		~Contact(); //destructor

		Contact (const Contact&); //copy constructor
		Contact& operator= (const Contact&); //copy operator
		Contact& operator+= (const long long); //+=operator
	
		bool validCheck(const long long);	//check phone's validity 
		void extractNum(const long long, int&, int&, int&, int&); //to break down phone number
		bool isEmpty() const; //returns true if object is empty
		void display(); //query

	};

}


#endif
