#include <iostream>
#include <cstring>
#include "AidApp.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sict {

	AidApp::AidApp(const char* filename) {

		if (filename != nullptr) {
			//int size = strlen(filename);
			strcpy(filename_, filename);
			//cout << size << "*********";
			*product_ = nullptr;
			noOfProducts_ = 0;
			loadRecs();//loads the Records by calling loadRecs
		}
	}

	void AidApp::pause() const { //print "Press enter to continue..."\n

		cout << "Press Enter to continue..." << endl;
		cin.ignore(2000, '\n');
	}

	int AidApp::menu() {

		int select;
		int input = -1;
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

		cin.ignore(2000, '\n');

		return select;
	}

//http://www.dreamincode.net/forums/topic/256999-how-do-i-dynamically-create-a-new-object/
	
	void AidApp::loadRecs() { //opens the data file for reading
		int readIndex = noOfProducts_;

		datafile_.open(filename_, ios::in);

		if (datafile_.fail()) {
			datafile_.clear();
			datafile_.close();
			datafile_.open(filename_, ios::out);
			datafile_.close();
		}
		else {
			while (!datafile_.eof()) {
				product_[readIndex] = nullptr;
				char a = 'A';
				datafile_ >> a;
				datafile_.ignore();
				//cout << "type" << a << "file is open";
				if (a == 'P') {
					cout << "File is P\n";
					product_[readIndex] = new AmaPerishable;
					//product_[readIndex]->load(datafile_);
				//	cout << product_[readIndex];
			
				}
				else if (a == 'N') {
					cout << "File is N\n";
					product_[readIndex] = new AmaProduct;
				//	product_[readIndex]->load(datafile_);
				
				}
				else {
					//cout << "File is None\n";
					//datafile_ >> a;
					//product_[readIndex]->load(datafile_);
					//readIndex++;
				}
			//	noOfProducts_ = readIndex;
			}
		}// else
	} //function
	

	void AidApp::saveRecs() { //opens the data file for writting

		datafile_.open(filename_, ios::out);
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
		cout << "Total cost of support: $" << totalCost << endl;
		cout.unsetf(ios::fixed);
	}


	int AidApp::searchProducts(const char* sku) const { //search a product by sku

		int index = -1;
		for (int i = 0; i < noOfProducts_; i++) {
			if (product_[i]->sku() == sku) {
				index = i;
				cout << product_[i];
			}
			else {
				cout << "Not found!";
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
				product_[index] += qty;
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


		while (flag != 0) {

			choice = menu();

			switch (choice) {

			case 1:
				listProducts();
				break;
			case 2:
				cout << "Please enter the SKU: ";
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
				addQty(sku);
				break;
			case 0:
				cout << "Goodbye!!" << endl;
				flag = 0;
				break;
			default:
				cout << "===Invalid Selection, try again.===" << endl;
				pause();
			}
			pause();
		}

		return 0;
	}

	fstream& AidApp::store(fstream& file, bool addNewLine) const {

		return file;
	}

	fstream& AidApp::load(fstream& file) {

		return file;
	}

	ostream& AidApp::write(ostream& os, bool linear) const {

		return os;
	}

	istream& AidApp::read(istream& istr) {

		return istr;
	}

	std::istream& operator>> (std::istream& is, AidApp& s) {
		s.read(is);
		return is;
	}
	std::ostream& operator<< (std::ostream& os, const AidApp& s) {
		s.write(os, true);
		return os;
	}

}
