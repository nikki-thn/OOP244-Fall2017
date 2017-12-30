
#include <iostream>


using namespace std;

class Test {

	char member;

public:

	Test() {
		cout << "constructor" << endl;
	}

	Test(char num) : member(num) {
		cout << member << "1 para constructor" << endl;
	}

	~Test() {
		cout << member << "destructor" << endl;
	}

	Test(const Test&) {
		cout << member << "copy constructor" << endl;
	}

	Test& operator= (const Test& rhs) {
		cout << member << "copy assignment" << endl;
		return *this;
	}

	Test print(const Test rhs) {
		cout << member << "print" << endl;
		return *this;
	}
};

int main() {

	//Test a;
	Test c('c');
	Test b ('b');
	//b = c;
	b.print(c);


	return 0;
}
