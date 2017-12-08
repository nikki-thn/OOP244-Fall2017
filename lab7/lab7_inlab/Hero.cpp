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

	Hero& Hero::operator=(const Hero& hero) {
		if (&hero != this) {
			strcpy(m_name, hero.m_name);
			m_health = hero.m_health;
			m_attack = hero.m_attack;
		}
		return *this;
	}

	void Hero::operator-=(int attack) {

		if (attack > 0) {
			m_health -= attack;
		}
		if (m_health <= 0) {
			m_health = 0;
		}
	}

	int Hero::attackStrength() const {

		bool empty = isEmpty();
		if (empty == false) return m_attack;
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
		Hero winnerHero;

		int numRounds = 1;
		int winner = 0;
		cout << "Ancient Battle! " << first << " vs " << second << " : ";

		while (numRounds <= max_round) {
			firstCopy -= second.attackStrength();
			secondCopy -= first.attackStrength();

			if (!firstCopy.isAlive() && secondCopy.isAlive() ||
				(!firstCopy.isAlive() && !secondCopy.isAlive())) {
				winner = 2;
				winnerHero = second;
				break;
			}
			else if (!secondCopy.isAlive() && firstCopy.isAlive()) {
				winner = 1;
				winnerHero = first;
				break;
			}
			numRounds++;
		}

		cout << "Winner is ";
			if (winner == 1)
				cout << first;

			else if (winner == 2)
				cout << second;
			
		cout << " in " << numRounds << " rounds." << endl;

		return winnerHero;
	}

}
