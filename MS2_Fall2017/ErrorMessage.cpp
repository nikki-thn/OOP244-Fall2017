// Name: Nikki Truong
// Student_id: 112 314 174
// Section E
// Milestone 2

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "ErrorMessage.h"


namespace sict {

	ErrorMessage::ErrorMessage(const char* errorMessage) {

		//if not empty, allocate memory and set object
		if (errorMessage != nullptr) {
			m_message = new char[strlen(errorMessage) + 1];
			strcpy(m_message, errorMessage);
		}
		//else set object in safe empty state
		else {
			m_message = nullptr;
		}
	}

	ErrorMessage::~ErrorMessage() {

		//clear allocated memory
		delete[] m_message;
	}

	void ErrorMessage::clear() {

		//clear current object and set it back to safe empty state
		delete[] m_message;
		m_message = nullptr;
	}

	bool ErrorMessage::isClear() const {

		bool isclear = false;

		//set it to true if message is empty
		if (m_message == nullptr) {
			isclear = true;
		}

		return isclear;
	}

	void ErrorMessage::message(const char* str) {

		//clear memory and allocate memory for new message
		delete[] m_message;
		m_message = new char[strlen(str) + 1];

		//copy new message into object
		strcpy(m_message, str);
	}

	const char* ErrorMessage::message()const {

		//return adddress of current message
		return m_message;
	}


	std::ostream& operator<< (std::ostream& os, const ErrorMessage& err) {

		//if object is not empty, print out the error
		if (!err.isClear())
			os << err.m_message;
		return os;
	}


}
