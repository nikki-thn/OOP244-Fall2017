#include <iostream>
#include <fstream>
#include "AmaProduct.h"
#include "AmaPerishable.h"
#include "Product.h"
#include "AidApp.h"

using namespace std;
using namespace sict;

int main() {

	Product* ama[10];
	fstream file;
	file.open("amaPrd.txt", ios::in);
	bool ok = !file.eof();
	int n = 0;
	char a;
	do {
		file >> a;
		file.ignore();

		if (a == 'P') {

			AmaPerishable* temp = new AmaPerishable;
			temp->load(file);
			cout << *temp << endl;
			ama[n++] = temp;

		}
		else if (a == 'N') {
			AmaProduct* temp = new AmaProduct;
			temp->load(file);
			cout << *temp << endl;
			ama[n++] = temp;

		}
		else if (a != 'N' || a != 'P') {
			file.close();
		}
	} while (!file.eof() && ok);

	
	for (int i = 0; i < n; i++) {
		cout << *ama[i] << endl;
	}
	

	return 0;
}
