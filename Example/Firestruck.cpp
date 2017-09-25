//Main.cpp

#include "Firestruck.h"

using namespace safety;

int main() {

  Firestruck aTruck, fancyTruck(1000, "magneta");
  Firestruck anotherTruck(10); //using the constructor with parameter
  
  {
  Firestruck thirdTruck(100, "Pink");
  thirdTrcuk.display(); //the object only exist in a block scope and will be destroyed when it's out of scope
  } //destructor is default to destroy an object asa it goes out of scope
  
    //aTruck.setEmpty();
  aTruck.display();
  
  Firestruck arr[3];
  
  
  //a constructor cannot be called on an existing object
  
return 0;
}


//Firestruck.h

#ifndef SAFETY_FIRESTRUCK_H
#define SAFETY_FIRESTRUCT_H

namespace safety {

class Firestruck {

char* m_pColor;
short m_waterCap;
//....  

  public:
  Firestruck(); //constructor is special function beause it is called automatically by compiler
                //it never returns a value
  Firestruck(short cap, const char* pCol = "red"); 
  ~Firestruck();
  
  void setEmpty();
  void display() const;
  
};

}
#endif

//Firestruck.cpp
#include <iostream>
#include <cstring>
#include "Firestruck.h"

using namespace std;

namespace safety {
   
  Firestruck::Firestruck(){ //an empty constructor will do nothing without a body, unlike destructor
   //EVERY attributes should be initalized
    //constructor is called right after the compiler has allocated memmory for an object, every time 
    //we build an object,constructor will being called
    cout << "Firestruck::Firestruck" << endl; //message to check that the constructor is called
    setEmpty(); 
  }
  
  Firestruck::Firestruck (short cap, const char* pCol){ //don't include the default value in implemetation file
  
  m_waterCap = cap;
  int size = strlen(pCol); //find out string length for memmory allocation
  m_pColor = new char[size + 1] //we need to allocate dynamic memory for string to avoid bugs
  strcpy(m_pColor,pCol); //copy one string to another  
  }
  
  Firestruck::~Firestruck(){
   
   cout << "destructor is called" << endl;
    //objects are destroyed in the reversed order that they were created
   delete [] m_pColor;
  }
  
  
 void Firestruck::setEmpty(){
 
 m_pColor = nullptr;
 m_waterCap = 0;  
 }
  
  void display(const Firestruck *this) // first parameter of all member function is a hidden parameter (Firestruck *this)
  //const inside the parameter to indicate we will not modify that particular parameter
  //const outside to indicate we will not modify the current instance (or object)
  void Firestruck::display() const{
    //notes: we cannot print a nullptr, so we have to check
    if (nullptr != m_pColor) { // not neccessary in this order, but easier to detect error
    cout << "The color is " << this->m_pColor << endl;
    cout << "Water capacity is " << m_waterCap << endl;
    }
    else {
    cout << "The object is empty" << endl;
    }
    
  }  
}
