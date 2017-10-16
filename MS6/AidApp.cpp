#include <iostream>
#include <cstring>
#include "AidApp.h"
#define _CRT_SECURE_NO_WARNINGS

namespace sict {

	AidApp::AidApp(const char* filename) {

		int size = strlen(filename); //enhancement
		if (filename != nullptr && size < 256) {
			strncpy(filename_, filename, size);
		}

		*product_ = nullptr;
		noOfProducts_ = 0;
		loadRecs();//loads the Records by calling loadRecs

	}

	void AidApp::pause() const { //print "Press enter to continue..."\n

		cout << "Press Enter to continue..." << endl;
		cin.ignore(2000, '\n');
	}

	int AidApp::menu() {

		int select = -2;
		int input = -2;
		cout << "Disaste Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display Product" << endl;
		cout << "3- Add non-perishable" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quatity of purchased products" << endl;
		cout << "0- Exit program" << endl;

		cin >> input;

		if (input >= 0 && input <= 5) {
			select = input;
		}
		else {
			select = -1;
		}

		cin.clear();

		return select;

	}
	void AidApp::loadRecs() { //opens the data file for reading
		int readIndex = 0;

		fstream datafile_(filename_, ios::in);
		datafile_.open(filename_);

		if (!datafile_.is_open()) {

			datafile_.clear(); //clear the failure **** HOW?
			datafile_.close(); //close file
			fstream datafile_(filename_, ios::out); //open new file for writting
			datafile_.close(); //close file
		}
		else {
			while (datafile_) {
				char productType;
				delete[] product_[readIndex];

				datafile_ >> productType;

				if (productType == 'P') {

					product_[readIndex] = new AmaPerishable;
				}

				if (productType == 'N') {

					product_[readIndex] = new AmaProduct;
				}

				else {
					datafile_.ignore();
					//Product::load(product_[readIndex]);
					//load the product from the file (using its load method)
					readIndex++;
				}

				noOfProducts_ = readIndex;
			} //while loop

			datafile_.close();
		}// else
	} //function

	void AidApp::saveRecs() { //opens the data file for writting

		fstream datafile_(filename_, ios::out);
		if (datafile_.is_open()) {
			for (int i = 0; i < noOfProducts_; i++) {
				datafile_ << product_[i] << endl;
			}
		}
		datafile_.close();
	}

	void AidApp::listProducts() const { //print stuff

		double totalCost = 0;

		cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expire   " << endl;
		cout << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;

		for (int i = 0; i < noOfProducts_; i++) {
			cout.width(4);
			cout << i << "|" << product_[i] << endl;
			if (i == 10) {
				pause();
			}
			totalCost += Product::cost();
		}
		cout << "---------------------------------------------------------------------------" << endl;

		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Total cost of support: $" << totalCost;
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
			AmaPerishable newPerishable;
			cin >> newPerishable;
			product_[noOfProducts_] = &newPerishable;
			saveRecs();
		}
		else {
			AmaProduct newNonPerishable;
			cin >> newNonPerishable;
			product_[noOfProducts_] = &newNonPerishable;
			saveRecs();
		}	
	}


	int AidApp::runs() { //display menu and receive user's selection

		int flag = 1;
		int choice;
		char sku[MAX_NO_RECS];

		choice = menu();

		while (flag != 0) {
			 
			switch (choice) {
			
			case 1:
				listProducts();
				pause();
			case 2:
				cout << "Please enter the SKU: " << endl;
				cin >> sku;
				searchProducts(sku);
				pause();
			case 3:
				addProduct(false);
				loadRecs();
			case 4: 
				addProduct(true);
				loadRecs();
			case 5:
				cout << "Please enter the SKU: " << endl;
				cin >> sku;
				addQty(sku);
			case 0:
				cout << "Goodbye!!" << endl;
				flag = 0;
			default:
				cout << "===Invalid Selection, try again.===" << endl;
				pause();
			}

		}

		return 0;
	}

	int main() {
	

		return 0;
	}

}
