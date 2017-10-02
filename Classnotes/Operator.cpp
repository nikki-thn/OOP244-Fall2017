//ArrayList.h
#ifndef COLLECTION_ARRAYLIST_H
#define COLLECTION_ARRAYLIST_H

namespace collection{

class ArrayList {
     short* m_pItems;
     int m_size; //the number of items in m_pItems
     
 public:
     ArrayList(); //constructor and destructor are mutator
     ~ArrayList();
     
     void display() const; //query
     
     
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
     
     ArrayList::~ArrayList() {
     
         delete [] this->m_pItems;
         this->m_pItems = nullptr; //useless when put in destructor but a good practice when used anywhere during codes
     }
     
     void ArrayList::display() const {
         
         for (int i = 0; i < this->m_size; i++) {
            
            zΩΩΩΩcout << " " << this->m_pItems[i];
         }
         
         cout << endl;    
     }
}

//main.cpp
#include <iostream>
#include "ArrayList.h"


int main () {


    return 0;
}





