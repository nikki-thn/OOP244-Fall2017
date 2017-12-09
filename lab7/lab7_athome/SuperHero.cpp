// Name: Nikki Truong
// Student_id: 112 314 174
// Section B
// Lab 7 - at home

#include <iostream>
#include "SuperHero.h"

using namespace std;

namespace sict {

	SuperHero::SuperHero() {
		m_bonusAttack = 0;
		m_defend = 0;
	}

	SuperHero::SuperHero(const char name[], int health, int attack, int bonusAttack, int defend) :
		Hero(name, health, attack) {
		m_bonusAttack = bonusAttack;
		m_defend = defend;
	}

	int SuperHero::attackStrength() const {

		int superHeroAttk = 0;
		if (!isEmpty()) {
			superHeroAttk = Hero::attackStrength() + m_bonusAttack;
		}

		return superHeroAttk;
	}

	const SuperHero& operator* (const SuperHero& first, const SuperHero& second) {

		SuperHero firstCopy = first;
		SuperHero secondCopy = second;
		const SuperHero* superHeroWinner = nullptr;
		int numRounds = 1;

		std::cout << "Super Fight! " << first << " vs " << second << " : ";

		while (numRounds <= max_round) {

			firstCopy -= second.attackStrength() - firstCopy.defend();
			secondCopy -= first.attackStrength() - secondCopy.defend();

			if ((firstCopy.isAlive() && !secondCopy.isAlive()) ||
				(!firstCopy.isAlive() && !secondCopy.isAlive())) {

				superHeroWinner = &first;
				break;
			}
			else if (secondCopy.isAlive() && !firstCopy.isAlive()) {

				superHeroWinner = &second;
				break;
			}
			numRounds++;
		}

		cout << "Winner is " << *superHeroWinner;
		cout << " in " << numRounds << " rounds." << endl;

		return *superHeroWinner;

	}

}
