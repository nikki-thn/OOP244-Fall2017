#ifndef SICT_STREAMABLE_H
#define SICT_STREAMABLE_H

#include <iostream>
#include <fstream>

namespace sict {

	class Streamable {

	public:
		Streamable();
		//~Streamable();
		virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		virtual std::fstream& load(std::fstream& );
		virtual std::ostream& write(std::ostream& , bool)const;
		virtual std::istream& read(std::istream& is);

	};


}

#endif
