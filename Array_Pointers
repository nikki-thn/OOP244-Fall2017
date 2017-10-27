#include <iostream>

using namespace std;

int main() {

	int a = 10;
	int* ptrA = &a;

	int b[5] = { 1, 2, 3, 4, 5 };
	cout << "address of A is: " << ptrA << endl;
	cout << "value of A is: " << *ptrA << endl;

	ptrA = b;

	// ptrA[0] = 1; ***invalid code because ptrA is a pointer, it's NOT an array
	// Hence, the offset operator [] cannot be used

	cout << "1st element is: " << *ptrA << endl;
	//*ptrA will output the first element because the name of array contains the address AND the first element of the array

	cout << "2nd element is: " << *(++ptrA) << endl;
	cout << "3rd element is: " << *++ptrA << endl;
	//Note that *++ptrA and *(++ptrA) are equivalent because order of operation
	//Postfix ++ --, then prefix ++ -- , then * operator

	ptrA = b + 3; //this means at address of b, increments by 3 (memory block NOT value)
	//ptrA = &b[3] //equivalent, it's poititng to the 4th element in the array

	cout << "4th element is: " << *ptrA << endl;
	cout << "5th element is: " << *++ptrA << endl;
	//cout << "Runtime error, garbage value as the address does not hold valid data " << *++ptrA << endl;

	ptrA = &b[2]; //reset ptrA to point to address of 3rd element which is 3
	*ptrA = 10; //change value at the current address (&b[2])

	cout << "Value holding at ptrA now: " << b[2] << endl;

	*(ptrA + 1) = 20; //now ptrA is pointing to the next element (next memory block)
	
	cout << b[3] << endl;

	//for (int i = 0; i < 5; i++) {
	//	cout << b[i] << endl;
	//}

	ptrA = b;
	
  //Print out array using pointers
	for (int i = 0; i < 5; ptrA++, i++) {
		cout << *ptrA << endl;
	}
	return 0;
}
