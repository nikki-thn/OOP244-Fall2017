// Name: Nikki Truong
// Student_id: 112 314 174
// Section B
// Lab 7 - at home

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"
namespace sict {

	class SuperHero : public Hero {

		int m_bonusAttack;
		int m_defend;

	public:

		SuperHero();
		SuperHero(const char name[], int health, int attack, int bonusAttack, int defend);
		
		int attackStrength() const; //return SuperHero attack
		int defend() const { return m_defend; } //return defend

	};

	//overload operator* for SuperHero class
	const SuperHero& operator* (const SuperHero& first, const SuperHero& second);
}

#endif
