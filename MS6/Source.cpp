#include <iostream>
#include <fstream>
#include "AmaProduct.h"
#include "AmaPerishable.h"
#include "Product.h"

using namespace std;
using namespace sict;

int main() {

	fstream file;
	file.open("amaPrd.txt", ios::in);
	sict::Product* ama;
	int count = 0;
	
	while (!file.fail()) {
	char a;
	 int size = 0;
	file >> a;
	file.ignore();
	if (a == 'P') {
		
		ama = new AmaPerishable[size + 1];
		ama[size].load(file);
		cout << ama[size] << endl;
		size++;
	}
	else {
		ama = new AmaProduct [size + 1];
		ama[size].load(file);
		cout << ama[size] << endl;
		size++;
	}

	//cout << "fcffcf" << size << endl;
	count = size;
	}

//	for (int i = 0; i < 5; i++) {
//		cout << ama[i] << endl;
//	}
	return 0;
}