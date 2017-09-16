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

		//check phone's validity 
		bool validCheck(const long long);
		void extractNum(const long long, int&, int&, int&, int&);
		bool isEmpty() const;
		void display() ;

	};

}


#endif
