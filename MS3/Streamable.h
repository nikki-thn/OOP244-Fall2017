#ifndef SICT_STREAMABLE_H
#define SICT_STREAMABLE_H

#include <iostream>
#include <fstream>

namespace sict{

	class Streamable {

		virtual std::fstream& store(std::fstream& file, bool addNewLine)const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& os, bool linear)const;
		virtual std::istream& read(std::istream& is);

	};
}

#endif
