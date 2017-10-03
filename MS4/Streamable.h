#ifndef SICT_STREAMABLE_H
#define SICT_STREAMABLE_H

#include <iostream>
#include <fstream>

namespace sict {

	class Streamable {

	public:	
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;
		virtual std::fstream& load(std::fstream& ) = 0;
		virtual std::ostream& write(std::ostream& , bool)const = 0;
		virtual std::istream& read(std::istream& is) = 0;

	};


}

#endif
