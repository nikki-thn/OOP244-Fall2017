#ifndef HERO_H
#define HERO_H

#include <iostream>

namespace sict {
	class Hero {
		char m_name[41];
		int  m_attack;
		int  m_maximumHealth;
		int  m_health;

		bool isEmpty() const;

	public:
		// constructors
		Hero();
		Hero(const char name[], int maximumHealth, int attack);

		// member functions
		bool isAlive() const { return m_health > 0; }
		void respawn();
		void deductHealth(int);
		void display(std::ostream&) const;
		int  getAttack() const { return m_attack; }

		// friend helper function to insert name into ostream
		friend std::ostream& operator<<(std::ostream&, const Hero&);
	};

    void applyDamage (Hero& A, Hero& B);
    const Hero & operator*(const Hero &, const Hero &);
}

#endif

