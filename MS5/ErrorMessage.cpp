#include <iostream>
#include <cstring>
#include "ErrorMessage.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {

	ErrorMessage::ErrorMessage() {

		message_ = nullptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage) {

		message(errorMessage);
	}
	//	ErrorMessage::ErrorMessage(const ErrorMessage&) {

	ErrorMessage::~ErrorMessage() {

		delete[] message_;
	}

	//ErrorMessage& ErrorMessage::operator= (const ErrorMessage&) = delete{

	ErrorMessage& ErrorMessage::operator= (const char* errorMessage) {

		clear();
		message(errorMessage);

		return *this;
	}

	void ErrorMessage::clear() {

		delete[] message_;
		message_ = nullptr;
	}

	bool ErrorMessage::isClear() const {
		bool isEmpty;

		if (message_ == nullptr || message_ == " " ) {
			isEmpty = true;
		}
		else if (message_ != nullptr) {
			isEmpty = false;
		}

		return isEmpty;
	}

	void ErrorMessage::message(const char* value) {

		clear();
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
	}

	const char* ErrorMessage::message()const {

		return message_;
	}

	std::ostream& ErrorMessage::display(std::ostream& os)const {

		bool isEmpty = isClear();

		if (isEmpty == false) {
			cout << message_ << endl;
		}
		else {
			cout << "object is empty" << endl;
		}
		return os;
	}

	std::ostream& operator<< (std::ostream& os, ErrorMessage& temp) {

		return temp.display(os);
	}



}
