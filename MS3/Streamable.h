#ifndef SICT_STREAMABLE_H
#define SICT_STREAMABLE_H

namespace sict{

	class Streamable {

		virtual fstream& store (fstream& file, bool addNewLine = true)const;
		virtual fstream& load (std::fstream& file);
		virtual ostream& write (ostream& os , bool linear ) const;
		virtual istream& read (istream& is);

	};
}

#endif
