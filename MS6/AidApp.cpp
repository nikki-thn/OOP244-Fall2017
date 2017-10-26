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

	AidApp::~AidApp() {
		//close fil;e, deletre memory, save files
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

		datafile_.open(filename_, ios::in);
		datafile_.seekg(0);
		bool ok = !datafile_.fail();
		int readIndex = 0;
		char a;
		do {
			datafile_ >> a;
			datafile_.ignore();

			if (a == 'P') {

				AmaPerishable* temp = new AmaPerishable;
				temp->load(datafile_);
				product_[readIndex++] = temp;

			}
			else if (a == 'N') {
				AmaProduct* temp = new AmaProduct;
				temp->load(datafile_);
				product_[readIndex++] = temp;
			}
			else if (a != 'N' || a != 'P') {
				datafile_.close();
			}
		} while (!datafile_.eof() && ok);

		noOfProducts_ = readIndex;

		cout << "noOfProducts" << noOfProducts_ << endl;
		for (int i = 0; i < noOfProducts_; i++) {
			cout << *product_[i] << endl;
		}
		



	} //function

	void AidApp::saveRecs() { //opens the data file for writting

		
		datafile_.open("amaPrd.txt", ios::out|ios::trunc);
		datafile_.seekp(0);

		if (datafile_.is_open()) {
			for (int i = 0; i < noOfProducts_ - 1; i++) {
				product_[i]->store(datafile_);
			}

			product_[noOfProducts_ - 1]->store(datafile_, false);
		}

		datafile_.close();

		loadRecs();
	}

	void AidApp::listProducts() const { 

		double totalCost = 0.0;

		cout << " Row | SKU   | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl;
		cout << "-----|-------|--------------------|-------|----|----------|----|----------" << endl;

		for (int i = 0; i < noOfProducts_; i++) {
			cout.width(4);
			cout << i + 1 << " |" << *product_[i] << endl;
			if (i == 9) {
				pause();
			}
			totalCost += *product_[i];
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

			if (strcmp(product_[i]->sku(), sku) == 0) {
				index = i;
			}
		}

		cout << endl;
		product_[index]->write(cout, false);
		cout << endl;	
		cout << endl;
		return index;
	}

	void AidApp::addQty(const char* sku) { //update Qty of a product

		int index = -1;
		int qty = 0;
		index = searchProducts(sku);

		if (index <= -1) {
			cout << "NOT FOUND" << endl;
		}

		else {
			cout << "Please enter the number of purchased items." << endl;
			cin >> qty;

			if (qty <= 0) {
				cout << "Invalid quantity value" << endl;
			}

			else if (qty <= product_[index]->qtyNeeded()) {

				product_[index]->quantity(qty + product_[index]->quantity());
				cout << "Updated!" << endl;
				//cout << product_[index]->quantity() << endl;
				//	cout << *product_[index] << endl;
			}

			else if (qty > product_[index]->qtyNeeded()) {

				int extraQty = qty - product_[index]->quantity();
				int acceptQty = product_[index]->qtyNeeded() - product_[index]->quantity();

				cout << "Too many items; only " << product_[index]->qtyNeeded() <<
					" is needed, please return the extra " << extraQty << " items " << endl;
				product_[index]->quantity(acceptQty + product_[index]->quantity());

				cout << "Accepted" << acceptQty << endl;
				cout << "New quantity" << product_[index]->quantity() << endl;
				cout << *product_[index] << endl;
			}
		}
	}

	void AidApp::addProduct(bool isPerishable) { //add a product

		cout << "noOfProducts" << noOfProducts_ << endl;

		if (isPerishable == true) {
			AmaPerishable* temp = new AmaPerishable;
			cin >> *temp;
			product_[noOfProducts_] = temp;
			
		}
		else {
			AmaProduct* temp = new AmaProduct;
			cin >> *temp;
			product_[noOfProducts_] = temp;
		}

			cout << "noOfProducts" << noOfProducts_ << endl;
			cout << *product_[noOfProducts_] << endl;
			noOfProducts_++;
			saveRecs();
	}


	int AidApp::runs() { //display menu and receive user's selection

		int flag = 1;
		int choice;
		char sku[MAX_SKU_LEN] = { '\0' };

		while (flag != 0) {
			choice = menu();

			switch (choice) {

			case 1:
				listProducts();
				pause();
				break;
			case 2:
				cout << "Please enter the SKU: " << endl;
				cin >> sku;
				searchProducts(sku);
				break;
			case 3:
				addProduct(false);
				break;
			case 4:
				addProduct(true);
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
