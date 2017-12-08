#ifndef SICT_HERO_H
#define SICT_HERO_H

#include <iostream>

namespace sict {

	const int max_round = 100;

	class Hero {

		char m_name[41];
		int m_health;
		int m_attack;

	public:

		Hero();
		Hero(const char name[], int health, int attack);

		bool isAlive() const { return m_health > 0; } //returns true is hero is alive
		void operator-=(int attack); //deduct strength from current object's health
		int attackStrength() const { return m_attack; } //return m_attack
		bool isEmpty() const; //return true is object is empty
		friend std::ostream& operator<<(std::ostream&, const Hero&); //helper function to insert name into ostream

	};

	const Hero& operator*(const Hero &, const Hero &);

}

#endif
