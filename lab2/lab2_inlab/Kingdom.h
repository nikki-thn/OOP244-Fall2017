/*
Nikki Truong - 112 214 174
OOP244 - Fall 2017
Workshop 2 - In lab
*/


#ifndef SICT_KINGDOM_H //header guard
#define SICT_KINGDOM_H

namespace sict {

	//declare struct Kingdom
	struct Kingdom {

		char m_name[31 + 1];
		int m_population;
	};

	//the function receive a unmodifiable reference to object type Kingdom
	//and print out kingdom's name and poppulation
	void display (const Kingdom&);



}


#endif 

