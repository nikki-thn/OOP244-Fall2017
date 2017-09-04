#include<iostream>
#include "Kingdom.h"

using namespace std;

namespace sict {


	void display(const Kingdom kingdom) {

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;

	}

	void display(const Kingdom* kingdom, int numElements) {

		int totalPopulation = 0;


		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < numElements; i++) {

		cout << i + 1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;

		totalPopulation += kingdom[i].m_population;

		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT:" << totalPopulation << endl;
		cout << "------------------------------" << endl;

	}



}