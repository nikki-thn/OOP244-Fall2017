#include <iostream>

using namaspace std;

//can be as many as we like <T1, T2, T3, etc>
template<typename T, typename RT>
RT& add (T a, T b) {

//** if RT is a custom type, we must have approriate constructor to support the intinialization
  RT result(0);
  RT result = 0;
  //Animal(0);
  
//** need an overload of approriate 
//in this case we need 2 operator, copy assignmnent for RT and operator+ for T type;
  
  RT = Foo(a + b);
  
//** We need a copy constructor for RT and a destructor for RT
  return result;
}

class Foo {
  long val;
  long val2;
public:
  Foo() { cout << "Foo::Foo()" << endl; val = 10; }
  Foo(int) { cout << "Foo::Foo(int)" << endl; val = 20; }
  Foo& operator=(const Foo& ); //copy assignment
  Foo& operator=(short a) { //val = a; 
  val2 = a;}


};

int main() {
  cout << add<short, float, double>(10, 22.32) << endl;
  cout << add<short, float, int>(10.10, 22.32) << endl;
  
  cout << add <short, Foo>(10, 22);
  
  return 0;
}
