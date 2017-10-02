//ArrayList.h
#ifndef COLLECTION_ARRAYLIST_H
#define COLLECTION_ARRAYLIST_H

namespace collection{

class ArrayList {
     short* m_pItems;
     int m_size; //the number of items in m_pItems
     
 public:
     ArrayList(); //constructor and destructor are mutator
     ArrayList(short item);
     ~ArrayList();
     
     void display() const; //query
     void add (short item); //not a query
     
     ArrayList& operator+= (short item);
     ArrayList& operator+= (const ArrayList& aList);
     ArrayList operator+(short item); //no & sign because it is returned a completely new object
     
     operator bool() const; //we dont put return type because we know what it will return (true or false)
};

}

#endif


//ArratList.cpp
#include <iostream>
#include "ArratList.h"

namespace collection {

     //we need to initialize every single data members in class regardless of empty state signal
     ArrayList::ArrayList() {
     
          this->m_pItems = nullptr;
          this->m_size = 0;
     
     }
     
     ArrayList::ArrayList(short item) {
          //notes that we cannot call the default constructor on existing object
          //we need a temporary object to copy 
          
          this* = ArrayList(); // don't understand
          //Notes*** only use constructor when memory for object has not yet created
          this->add(item);
     }     
     
     ArrayList::~ArrayList() {
     
         delete [] this->m_pItems;
         this->m_pItems = nullptr; //useless when put in destructor but a good practice when used anywhere during codes
     }
     
     void ArrayList::display() const {
         
          //no need for null check because m_size already do the job
         for (int i = 0; i < this->m_size; i++) {
            cout << " " << this->m_pItems[i];
         }
         
         cout << endl;    
     }

     void ArrayList::add (short item) {
          
          //allocate memory to store the new array
          short * tmp = new short [this->m_size +1];
          
          //copy from the old array into the new one
          for (int i = 0; i < this-.m_size; i++) {
               tmp[i] = this-.m_pItems[i];
          }
          //deallocate memory for old array
          delete [] this->m_pItems;
          this->m_pItems = nullptr; //not neccessary again with good design
          
          //store the new element into the new array
          tmp[this->m_size] = item;
          
          //copy the address into the attribute
          this->m_pItems = tmp;
          this->m_size++; //should it be the other way around??          
     }     

     ArrayList& ArrayList::operator+=(short item) {
      
          this->add(item); //resuse code
          return *this; //return reference of the object
     }
     
     ArrayList& ArrayList::operator+= (const ArrayList& alist) {
          
          for (int i = 0; i < alist.m_size; i++) {
               
               this->add(aList.m_pItems[i]);
          }
          
          return *this;
     }     

     ArrayList::operator bool() const {
      
     /*     if (this->m_size > 0)
               return true;
          else 
               return false;
       */
          
          return this->m_size > 0; //alternative way to do
     }     
     
}

//main.cpp
#include <iostream>
#include "ArrayList.h"


int main () {

    Arraylist al;
     al.add(10);
     al.add(11);
     al.add(20);
     al.display();
     
     al += 25; //same as add function but using operator instead
     (al += 25) += 30; //return specify from function so we can do multiple operations at same time
     
     ArrayList al2;
     (al2 += 100) += 200;
     al2.display();
     
     al += al2;
     al.display();
     
     al2 = al + 32;

     if (al) {
          cout << "There are element in the list!" << endl;
     }
     else 
     {
          coout << "List empty" << endl;
     }
     
     ArrayList al4 = 50; //only works because the al4 is not existed at this very line, if the object already exist, compiler will 
     //not use constructor but it will go look for an operator, remember that constructor can only called once when object is created
     ArrayList al4(50); //same syntax as assignment, distinction haopens deoends on status of the object
     
     al4 = 60; //on this line, compiler will look for an assignment operator, it cannot call the constructor because al4 is existing
     
     //special function such as dedault constructor, destructor and copy constructor and copy assignment operator, these are automatically
     //added by the compiler.
     
     //basically it takes number 60 turns it into an arraylist and then use the default copy assignmnet to turn the temp object (60) and copy it into al4
     
     al4.display();
          
    return 0;
}





