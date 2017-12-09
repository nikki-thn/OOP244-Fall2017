// Name: Nikki Truong
// Student_id: 112 314 174
// Section B
// Lab 7 - at home

#include <cstring>
#include <iostream>
#include "Hero.h"

using namespace std;

namespace sict {

	Hero::Hero() {

		m_name[0] = '\0';
		m_attack = 0;
		m_health = 0;
	}

	Hero::Hero(const char name[], int health, int attack) {

		if (strlen(name) < 40 && name[0] != '\0') {
			strcpy(m_name, name);
			m_health = health;
			m_attack = attack;
		}
		else {
			m_name[0] = '\0';
			m_attack = 0;
			m_health = 0;
			//*this = Hero(); **ask
		}
	}

	void Hero::operator-=(int attack) {

		if (attack > 0) {
			m_health -= attack;
		}
		if (m_health <= 0) {
			m_health = 0;
		}
	}

	//return true if object is empty
	bool Hero::isEmpty() const {

		bool empty = false;
		if (m_name[0] == '\0') 	empty = true;
		return empty;
	}

	ostream& operator<<(ostream& out, const Hero& hero) {

		bool empty = hero.isEmpty();

		if (empty == false) cout << hero.m_name;
		else cout << "No hero";
		return out;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {

		Hero firstCopy = first;
		Hero secondCopy = second;
		const Hero* winnerHero = nullptr;
		int numRounds = 1;

		cout << "Ancient Battle! " << first << " vs " << second << " : ";

		while (numRounds <= max_round) {

			firstCopy -= second.attackStrength();
			secondCopy -= first.attackStrength();

			if ((firstCopy.isAlive() && !secondCopy.isAlive()) ||
				(!firstCopy.isAlive() && !secondCopy.isAlive())) {

				winnerHero = &first;
				break;
			}
			else if (secondCopy.isAlive() && !firstCopy.isAlive()) {

				winnerHero = &second;
				break;
			}
			numRounds++;
		}

		cout << "Winner is " << *winnerHero;
		cout << " in " << numRounds << " rounds." << endl;

		return *winnerHero;
	}

}
