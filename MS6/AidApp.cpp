#include <iostream>
#include <cstring>
#include "AidApp.h"
#include "Product.h"
#define _CRT_SECURE_NO_WARNINGS

namespace sict {
	
	AidApp::AidApp(const char* filename) {

		if (filename != nullptr) {

			strcpy(filename_, filename);
			for (int i = 0; i < MAX_NO_RECS; i++) {
				product_[i] = nullptr;
			}

			noOfProducts_ = 0;
			loadRecs();//loads the Records by calling loadRecs
		}
	}

	void AidApp::pause() const { //print "Press enter to continue..."\n

		cout << "Press Enter to continue...\n";
	
		cin.ignore(2000, '\n');
	}

	int AidApp::menu() {

		int input = -2;
		cout << "Disaste Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display Product" << endl;
		cout << "3- Add non-perishable" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quatity of purchased products" << endl;
		cout << "0- Exit program" << endl;

		cin >> input;

		if (input < 0 || input > 5) {
			input = -1;
		}
		cin.ignore(2000, '\n');

		return input;
	}
	
	void AidApp::loadRecs() { //opens the data file for reading
		
		//int readIndex = noOfProducts_;

		datafile_.open(filename_, ios::in);

		bool ok = !datafile_.fail();
		int readIndex = 0;
		char a;
		do {
			datafile_ >> a;
			datafile_.ignore();

			if (a == 'P') {

				AmaPerishable* temp = new AmaPerishable;
				temp->load(datafile_);
			//	cout << *temp << endl;
				product_[readIndex++] = temp;

			}
			else if (a == 'N') {
				AmaProduct* temp = new AmaProduct;
				temp->load(datafile_);
			//	cout << *temp << endl;
				product_[readIndex++] = temp;

			}
			else if (a != 'N' || a != 'P') {
				datafile_.close();
			}
		} while (!datafile_.eof() && ok);

		noOfProducts_ = readIndex;

	/*	for (int i = 0; i < noOfProducts_; i++) {
			cout << *product_[i] << endl;
		}*/

	
	} //function

	void AidApp::saveRecs() { //opens the data file for writting
	
		datafile_.open(filename_, ios::out);
		if (datafile_.is_open()) {
			for (int i = 0; i < noOfProducts_; i++) {
			(*product_[i]).store(datafile_);
			}
		}
		datafile_.close();
	}

	void AidApp::listProducts() const { //print stuff

		double totalCost = 0.0;

		cout << " Row | SKU   | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl;
		cout << "-----|-------|--------------------|-------|----|----------|----|----------" << endl;

		for (int i = 0; i < noOfProducts_; i++) {
			cout.width(4);
			cout << i + 1 << " |" << *product_[i] << endl;
		//	if (i == 9) {
		//		pause();
		//	}
			totalCost = totalCost += *product_[i];
		}
		cout << "---------------------------------------------------------------------------" << endl;

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Total cost of support: $" << totalCost << endl;
		cout.unsetf(ios::fixed);
	}


	int AidApp::searchProducts(const char* sku) const { //search a product by sku

		int index = -1;
		for (int i = 0; i < noOfProducts_; i++) {
			if (product_[i]->sku() == sku) {
				index = i;
			}
		}
		return index;
	}

	void AidApp::addQty(const char* sku) { //update Qty of a product
		int index = 0;
		int qty = 0;
		index = searchProducts(sku);

		if (index == -1) {
			cout << "NOT FOUND" << endl;
		}

		if (index >= 0 && index < noOfProducts_) {// enhancement
			cout << "Please enter the number of purchased items." << endl;
			cin >> qty;
			cin.ignore(2000, '\n');

			if (qty <= 0) {
				cout << "Invalid quantity value" << endl;

			}

			if (qty <= product_[index]->qtyNeeded()) {
				product_[index]+= qty;
				cout << "Updated!" << endl;
			}

			if (qty > product_[index]->qtyNeeded()) {
				int extraQty = qty - product_[index]->qtyNeeded();
				int acceptQty = product_[index]->qtyNeeded() - product_[index]->quantity();
				cout << "Too many items; only " << product_[index]->qtyNeeded() <<
					"is needed, please return the extra" << extraQty << " items " << endl;
				product_[index] += acceptQty;
				cout << "Updated!" << endl;
			}	
		}
	}

	void AidApp::addProduct(bool isPerishable) { //add a product
		
		if (isPerishable == true) {
			AmaPerishable* temp = new AmaPerishable;
			temp->read(datafile_);
			//	cout << *temp << endl;
			product_[noOfProducts_++] = temp;
		}
		else {
			AmaProduct* temp = new AmaProduct;
			temp->read(datafile_);
			//	cout << *temp << endl;
			product_[noOfProducts_++] = temp;
		}	
	}


	int AidApp::runs() { //display menu and receive user's selection

		int flag = 1;
		int choice;
		char sku[7] = { '\0' };

		while (flag != 0) {
		choice = menu();
			 
			switch (choice) {
			
			case 1:
				cout << "test" << endl;
			//	listProducts();
				//pause();
				break;
			case 2:
				cout << "Please enter the SKU: " << endl;
				cin >> sku;
				searchProducts(sku);
				break;
			case 3:
				addProduct(false);
				loadRecs();
				break;
			case 4: 
				addProduct(true);
				loadRecs();
				break;
			case 5:
				cout << "Please enter the SKU: " << endl;
				cin >> sku;
				cin.ignore(2000, '\n');
				addQty(sku);
				break;
			case 0:
				cout << "Goodbye!!" << endl;
				flag = 0;
				break;
			default:
				cout << "===Invalid Selection, try again.===" << endl;
				pause();
				break;
			}

		}

		return 0;
	}

	
}
