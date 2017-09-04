#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict {

	struct Kingdom {

		char m_name[32];
		int m_population;
};

	void display (const Kingdom);

	void display(const Kingdom*, int numElements);


}


#endif // !SICT_KINGDOM_H

