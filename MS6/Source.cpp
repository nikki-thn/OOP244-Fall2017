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
		//	cout << *temp << endl;
			ama[n++] = temp;

		}
		else if (a == 'N') {
			AmaProduct* temp = new AmaProduct;
			temp->load(file);
		//	cout << *temp << endl;
			ama[n++] = temp;

		}
		else if (a != 'N' || a != 'P') {
			file.close();
		}
	} while (!file.eof() && ok);

	AmaPerishable ath;
	
	fstream file1;
	file1.open("psh.txt", ios::out);

	bool ok1 = !file1.fail() && file1.is_open();
	if (ok1) {
		for (int j = 0; j < n; j++) {
			//ath.store(file1);
			cout << *ama[j] << endl;
			ama[j]->store(file1);
			cout << "success" << endl;
		}
		
	}


//	AidApp app("amaPrd.txt");
//	app.addQty("132");
//	app.addQty("5678");
//	app.runs();
	//int n = app.searchProducts("5896");
	
	return 0;
}