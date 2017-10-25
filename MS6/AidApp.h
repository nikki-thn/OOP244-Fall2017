#include "AmaPerishable.h"
#include "AmaProduct.h"


#ifndef SICT_AIDAPP_H
#define SICT_AIDAPP_H

namespace sict {

	class AidApp : public Product{
		char filename_[256]; //holds name of the text file
	public:
		Product* product_[MAX_NO_RECS]; //an array of product pointers
		fstream datafile_; // an fstream instance to create and access a file
		int noOfProducts_; //number of products
		
		AidApp (const char* filename);
		AidApp (const AidApp&) = delete;
		AidApp& operator= (const AidApp&) = delete;

		void pause() const; //print "Press enter to continue..."\n

		int menu();
		void loadRecs(); //opens the data file for reading
		void saveRecs(); //opens the data file for writting
		void listProducts() const; //print stuff
		int searchProducts(const char* sku) const; //search a product by sku
		void addQty(const char* sku); //update Qty of a product
		void addProduct(bool isPerishable); //add a product
		int runs(); //display menu and receive user's selection

	};

}


#endif // !SICT_AIDAPP_H

