#include <iostream>
#include <fstream>
#include "AmaProduct.h"
#include "AmaPerishable.h"
#include "Product.h"
#include "AidApp.h"

using namespace std;
using namespace sict;

int main() {

	AidApp app("amaPrd.txt");
	app.runs();
	return 0;
}