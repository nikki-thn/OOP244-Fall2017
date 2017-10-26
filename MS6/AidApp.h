#ifndef SICT_AIDAPP_H
#define SICT_AIDAPP_H

#include"AmaPerishable.h"

namespace sict {

	class AidApp{

		char filename_[256]; //holds name of the text file
		Product* product_[MAX_NO_RECS]; //an array of product pointers
		fstream datafile_; // an fstream instance to create and access a file
		int noOfProducts_; //number of products
		AidApp (const AidApp&); //use private setting to restrict copy
		AidApp& operator= (const AidApp&); //use private setting to restrict copy
	
	public:

		AidApp (const char* filename); //constructor
		~AidApp(); //seems unncessary

		void pause() const; //pause program and wait for user

		int menu(); //print out menu
		void loadRecs(); //load data from file (reading in)
		void saveRecs(); //save data to file (writting to)
		void listProducts() const; //list all products from file
		int searchProducts(const char* sku) const; //search a product by sku
		void addQty(const char* sku); //update Qty of a product
		void addProduct(bool isPerishable); //add a product
		int runs(); //display menu and receive user's selection

	};

}

#endif 

