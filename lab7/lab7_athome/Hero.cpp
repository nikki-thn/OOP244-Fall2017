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

	const SuperHero& operator* (const SuperHero& first, const SuperHero& second) {

		SuperHero firstCopy = first;
		SuperHero secondCopy = second;
		const SuperHero* winnerHero = nullptr;
		int numRounds = 1;

		cout << "Ancient Battle! " << first << " vs " << second << " : ";

		while (numRounds <= max_round) {

			firstCopy -= second.attackStrength();
			secondCopy -= first.attackStrength();

			if ((!firstCopy.isAlive() && secondCopy.isAlive()) ||
				(!firstCopy.isAlive() && !secondCopy.isAlive())) {

				winnerHero = &second;
				break;
			}
			else if (!secondCopy.isAlive() && firstCopy.isAlive()) {

				winnerHero = &first;
				break;
			}
			numRounds++;
		}

		cout << "Winner is " << *winnerHero;
		cout << " in " << numRounds << " rounds." << endl;

		return *winnerHero;

	}

}
