#ifndef SICT_ERROR_MESSAGE_H
#define SICT_ERROR_MESSAGE_H

namespace sict {

	class ErrorMessage {

		char* message_;

	public:
	
		ErrorMessage();
		ErrorMessage(const char*);
		ErrorMessage(const ErrorMessage&) = delete;
		virtual ~ErrorMessage();

		ErrorMessage& operator= (const ErrorMessage& ) = delete;
		ErrorMessage& operator= (const char* );

		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message()const;
		std::ostream& display(std::ostream& os)const;
	};

		std::ostream& operator<<(std::ostream&,  ErrorMessage&);
		
	


}


#endif
