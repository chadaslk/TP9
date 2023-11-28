#include "string.h"
#define SIZE 100
#include <iostream>


//default constructor
string::string(){
  char def_str[5]{'H', 'E', 'L', 'L', 'O'}; // non trivial content
  for(int i=0; i < 6 ; i++){
    str_[i] = def_str[i];
  }
}

//copy constructor
string::string(const string& s){
  for(int i = 0; i<= SIZE ; i++){
    str_[i] = s.str_[i];
  }
}

//void string::get_str(){
//  for(int i = 0 ; i<SIZE ; i++){
//    std::cout << str_[i] << " ";
//  }
//}
