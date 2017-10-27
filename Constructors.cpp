// pointer to classes example
#include <iostream>
using namespace std;

class Rectangle {
	int width, height;
public:
	Rectangle();
	Rectangle(int a, int b);
	int area(void) { return width * height; }
};

Rectangle::Rectangle() : width(3), height(3) {}

Rectangle::Rectangle(int x, int y) : width(x), height(y) {}

int main() {

//Rectangle obj(3, 4);

	Rectangle *baz[2]; //an array to store pointer of object Rectangle type
  
 	baz[0] = new Rectangle;
	baz[1] = new Rectangle(5,6);
 
	//baz = new Rectangle[2] { 3,5 } ;
  
	//cout << "obj's area: " << obj.area() << '\n';
	//cout << "*foo's area: " << foo->area() << '\n';
	//cout << "*bar's area: " << bar->area() << '\n';
	//cout << "baz[0]'s area:" << baz[0].area() << '\n';
  
	cout << "baz[1]'s area:" << baz[0]->area() << '\n';
	cout << "baz[1]'s area:" << baz[1]->area() << '\n';

	//delete[] baz;
	return 0;
}
