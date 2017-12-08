#ifndef SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {

		int m_bonusAttack;
		int m_defend;

	public:

		SuperHero();
		SuperHero(const char name[], int health, int attack, int bonusAttack, int defend);
		
		int attackStrength() const { return this->attackStrength + m_bonusAttack; }
		int defend() const { return m_defend; }

	};

	const SuperHero& operator* (const SuperHero& first, const SuperHero& second);
}

#endif
