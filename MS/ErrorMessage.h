// Name: Nikki Truong
// Student_id: 112 314 174
// Section E
// Milestone 2


#ifndef SICT_ERROR_MESSAGE_H
#define SICT_ERROR_MESSAGE_H
#include<iostream>

namespace sict {
	class ErrorMessage {

		char* m_message; //to store an error message

	public:

		//constructor
		explicit ErrorMessage(const char* errorMessage = nullptr);

		//destructor
		virtual ~ErrorMessage();

		//restrict copy constructor & copy assignment
		ErrorMessage(const ErrorMessage&) = delete;
		ErrorMessage& operator=(const ErrorMessage&) = delete;

		//clear current message
		void clear();

		//return true if no error message is stored
		bool isClear() const;

		//replace the current message with the new message 
		void message(const char* str);

		//return address of current error message
		const char* message()const;
	};

	//helper print out the error message
	std::ostream& operator<< (std::ostream&, const ErrorMessage&);
}
#endif
