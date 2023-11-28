#include "string.h"
#define SIZE_MAX 100
#include <iostream>


//default constructor
string::string(){
  taille_ = 5;
  char def_str[5]{'H', 'E', 'L', 'L', 'O'}; // non trivial content
  str_ = new char[taille_];
  for(int i=0; i < 5 ; i++){
    str_[i] = def_str[i];
  }
}

//copy constructor
string::string(const string& s){
  taille_ = s.taille_ ;
  str_ = new char[taille_];
  for(int i = 0; i<= s.taille_ ; i++){
    str_[i] = s.str_[i];
  }
}



// Returns a pointer to an array that contains a null-terminated sequence of
// characters (i.e., a C-string) representing the current value of the string object.
char* string::c_str(){
  //char* cstr = str_;
  return str_;
}

// implementation of size()
int string::size(){
  return taille_;
}

// implementation of clear()
void string::clear(){
  taille_ = 0;
  str_ = new char[taille_];

}

void string::get_str(){
  for(int i = 0 ; i<taille_ ; i++){
    std::cout << str_[i] << " ";
  }
}
