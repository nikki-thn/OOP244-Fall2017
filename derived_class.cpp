#include <iostream>

using namespace std;

class A {

	int m_num;

public:

	A() : m_num(0) { cout << "A() " << m_num << endl; }

	A(int num) : m_num(num) {
		cout << "A(int) " << m_num << endl;
	}

	A(const A& rhs) {
		if (&rhs != this)
			*this = rhs;
		cout << "A copy constructor " << m_num << endl;
	}

	~A() { cout << "~A() " << m_num << endl; }

	A& operator= (const A& rhs) {
		if (&rhs != this)
			this->m_num = rhs.m_num;
		cout << "A copy assignment " << m_num << endl;
		return *this;
	}

	int getNum() { return m_num; }

	A& operator+= (const A& rhs) {
		this->m_num += rhs.m_num;
		cout << "A operator+= " << m_num << endl;
		return *this;
	}

	A& operator--(int) {
		m_num--;
		cout << "A operator-- " << m_num << endl;
		return *this;
	}

};


class B : public A {

public:

	B() { cout << "B() " << getNum() << endl; }
	B(int num) : A(num) { cout << "B(int) " << getNum() << endl; }
	~B() { cout << "~B() " << getNum() << endl; }
	B(const B& rhs) {
		if (&rhs != this) *this = rhs;
		cout << "B copy constructor " << getNum() << endl;
	}

	B& operator=(const B& rhs) {
		if (&rhs != this) {
			A::operator= (rhs); //call base class copy assignment
			cout << "B copy assignment " << getNum() << endl;
		}
		return *this;
	}

	B& operator+= (const B& rhs) {
		A::operator+= (rhs);
		cout << "B operator+= " << getNum() << endl;
		return *this;
	}

	//The int type in the header distinguishes the post-fix
	//operators from their pre-fix counterparts
	//which has prototype Type& operator++()
	B operator--(int) {
		A::operator--(100); //***interesting
		cout << "B operator-- " << getNum() << endl;
		return *this;
	}

};

int main() {

	B obj, obj1(5), obj2(3);
	//Output:
	//A() 0
	//B() 0;
	//A(int) 5
	//B(int) 5
	//A(int) 3
	//B(int 3


	obj = obj1;
	//A copy assignment 5
	//B copy assignment 5

	obj1 += obj2;
	//A operator+= 8
	//B operator += 8

	obj2--;
	//A operator-- 2;
	//B operator-- 2;
	//A() 0 //new object A to build B at B copy constructor
	//A copy assignment 2 //B operator= call A's
	//B copy assignment 2 //B operator= fisnished
	//B copy constructor 2 //new B constructed
	//~B() 2 //return *this go out of scope
	//~A() 2

	return 0;
	//~B() 2
	//~A() 2
	//~B() 3
	//~A() 3
	//~B() 8
	//~A() 8
	//~B() 5
	//~A() 5
}
