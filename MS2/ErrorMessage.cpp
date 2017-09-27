#include <iostream>
#include "ErrorMessage.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {

	ErrorMessage::ErrorMessage() {

	}
	ErrorMessage::ErrorMessage(const char*) {

	}
	ErrorMessage::ErrorMessage(const ErrorMessage&) {
	}
	virtual ErrorMessage::~ErrorMessage(){
	}

	ErrorMessage& ErrorMessage::operator= (const ErrorMessage&) = delete{
	}
	ErrorMessage& ErrorMessage::operator= (const char*){
	}

	void ErrorMessage::clear(){
	}
	bool ErrorMessage::isClear() const{
	}
	void ErrorMessage::message(const char*){
	}
	const char* ErrorMessage::message()const{
	}

	std::ostream& ErrorMessage::write(std::ostream& ostr) const{
	         }



}
