#include <iostream>
#include <cstring>
#include "AidApp.h"
#define _CRT_SECURE_NO_WARNINGS

namespace sict {

	void AidApp::loadRecs() { //opens the data file for reading

		datafile_.open(filename_, ios::in);
		datafile_.clear();
		datafile_.seekg(0);

		bool ok = !datafile_.fail();
		int readIndex = 0;
		char a;

		while (!datafile_.eof() && ok) {
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

		}

		noOfProducts_ = readIndex;

	} //function

	void AidApp::saveRecs() { //opens the data file for writting

		fstream file("amaPrd.txt", ios::out);

		if (file.is_open()) {
			for (int i = 0; i < noOfProducts_ - 1; i++) {
				product_[i]->store(file);
			}

			product_[noOfProducts_ - 1]->store(file, false);
		}

		file.close();
		loadRecs();
	}

int AidApp::isYes() {

		char input;
		bool yesOrNo;
		int flag = 1;

		while (flag != 0) {
			cout << "(Y)es to proceed or (N)o to cancel. Only Y/y, N/n is accepted: ";
			cin >> input;
			cin.ignore(2000, '\n');

			if (input == 'N' || input == 'n') {
				yesOrNo = 0;
				flag = 0;
			}
			else if (input == 'Y' || input == 'y') {
				yesOrNo = 1;
				flag = 0;
			}
			else {
				cout << "Invalid input. Please try again.";
			}
		}

		return yesOrNo;
	}
	
	void AidApp::addProduct(bool isPerishable) { //add a product

		int choice;
		int found;

		Product* ptr;
		
		if (isPerishable == true) {
			AmaPerishable* temp = new AmaPerishable;
			cin >> *temp;
			ptr = temp;
		}
		else {
			AmaProduct* temp = new AmaProduct;
			cin >> *temp;
			ptr = temp;
		}

		found = searchProducts(ptr->sku());

		if (found != -1) {
			cout << "Item is already exited. Would you like to update?" << endl;
			choice = isYes();
			if (choice == 1) {
				updateItem(ptr, found);
			}		
		}

		 if (found == -1 || choice == 0) {
			product_[noOfProducts_] = ptr;
			cout << "Item is added" << endl;
			cout << *product_[noOfProducts_] << endl;
			noOfProducts_++;
		}

		saveRecs();
	}

	void AidApp::updateItem(Product* rhs, int index) {

		product_[index] = rhs;
		cout << "Updated successfully!" << endl;
		cout << *product_[index] << endl;
		
	}

	void AidApp::addQty(const char* sku) { //update Qty of a product

		int index = -1;
		int qty = 0;
		index = searchProducts(sku);
		int choice;

		if (index <= -1) {
			cout << "NOT FOUND" << endl;
		}

		else {
			cout << "Please enter the number of purchased items." << endl;
			cin >> qty;

			if (qty <= 0) {
				cout << "Would you like to subtract current quantity:" << endl;
				choice = isYes();
				if (choice == 1 && product_[index]->quantity() >= qty) {
					product_[index]->quantity(product_[index]->quantity() + qty);
					cout << " - Updated quantity is " << product_[index]->quantity() << endl;
				}
				else {
					cout << "Invalid quantity input or Cancelled" << endl;
				}
			}

			else if (qty < product_[index]->qtyNeeded()) {

				product_[index]->quantity(qty + product_[index]->quantity());
				cout << "Updated!" << endl;
			}

			else if (qty >= product_[index]->qtyNeeded()) {

				int acceptQty = product_[index]->qtyNeeded() - product_[index]->quantity();
				int extraQty = qty - acceptQty;

				cout << "Too many items! Only " << product_[index]->qtyNeeded() <<
					" is needed, please return the extra " << extraQty << " items." << endl;
				product_[index]->quantity(acceptQty + product_[index]->quantity());

				cout << "Accepted " << acceptQty << " - Updated quantity is " << product_[index]->quantity() << endl;
			}
		}
		saveRecs(); //to save changes
	}

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

		datafile_.close();
		//close fil;e, deletre memory, save files
	}

	int AidApp::menu() {

		int input = 0;
		cout << "Disaste Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display Product" << endl;
		cout << "3- Add non-perishable" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quatity of purchased products" << endl;
		cout << "6- Delete products" << endl;
		cout << "0- Exit program" << endl;

		cin >> input;

		if (input < 0 || input > 6) {
			input = -1;
		}

		cin.ignore(2000, '\n');

		return input;
	}

	void AidApp::listProducts() const {

		double totalCost = 0.0;
		bool isLow;
		cout << " Row |Low| SKU   | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl;
		cout << "-----|---|-------|--------------------|-------|----|----------|----|----------" << endl;

		for (int i = 0; i < noOfProducts_; i++) {

			isLow = lowStock(product_[i]);
		//	cout <<"void AidApp::listProducts() const {" <<  isLow << endl;
			int count = 1;
			cout.width(4);
			cout << i + 1 << " |";

			if (isLow)
				cout << "***|" ;
			else
				cout << "   |";

			cout << *product_[i] << endl;



			if (((i + count) % 10) == 0 && noOfProducts_ > (i + count)) {
				pause();
			}


			totalCost += *product_[i];//calculate totalCost
		}

		cout << "-------------------------------------------------------------------------------" << endl;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Total cost of support: $" << totalCost << endl;
		cout.unsetf(ios::fixed);
	}

	bool AidApp::lowStock(Product* rhs) const {
		bool isLow = false;

			if (rhs->quantity() <= (int)(0.20* rhs->qtyNeeded()))
				isLow = true;
	
		return isLow;
	}


	int AidApp::searchProducts(const char* sku) const { //search a product by sku

		int index = -1;

		for (int i = 0; i < noOfProducts_; i++) {

			if (strcmp(product_[i]->sku(), sku) == 0) {
				index = i; //if item is found, return index
			}
		}

		if (index != -1) {
			cout << endl;
			product_[index]->write(cout, false);
			cout << endl << endl;
		}

		return index;
	}

	void AidApp::deleteItem(const char* sku) {

		int found = searchProducts(sku);
		cout << "Confirm to delete. ";
		int yes = isYes();

		if (found == -1 && yes == 0) {
			cout << "Product not found or Cancelled" << endl;
			
		}
		else if (found != -1 && yes == 1) {
			for (found; found < noOfProducts_; found++) {
				product_[found] = product_[found + 1];
			}
			noOfProducts_--;
		}

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
				cin.getline(sku, MAX_SKU_LEN, '\n');
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
				cin.getline(sku, MAX_SKU_LEN, '\n');
				addQty(sku);
				break;

			case 6:
				cout << "Please enter the SKU: " << endl;
				cin.getline(sku, MAX_SKU_LEN, '\n');
				deleteItem(sku);
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
