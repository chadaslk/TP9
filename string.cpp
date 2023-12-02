#include "string.h"
#define SIZE_MAX 100
#include <iostream>


//default constructor
string::string(){
  taille_ = 11;
  char def_str[11]{'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D'}; // non trivial content
  str_ = new char[taille_+2];
  for(int i=0; i < 11 ; i++){
    str_[i] = def_str[i];
  }
}

//copy constructor
string::string(const string& s){
  taille_ = s.taille_ ;
  str_ = new char[taille_];
  for(int i = 0; i<= s.taille_ + 2 ; i++){
    str_[i] = s.str_[i];
  }
}



// Returns a pointer to an array that contains a null-terminated sequence of
// characters (i.e., a C-string) representing the current value of the string object.
char* string::c_str(){
  char* end_of_string = new char [2];
  end_of_string [0] = '/';
  end_of_string [1] = '0';
  string cstr = str + end_of_string;
  return cstr_;
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

// surcharge de l'opérateur operator=(char c){
string& string::operator=(char c){
  // libérer la mémoire existante
  delete[] str_;
  str_ = new char[3];
  str_[0] = c;
  str_[1] = '/';
  str_[2] = '0';

  return *this;

}

//surcharge de l'opérateur
//string& string::operator+(const string& s, const char* c){
  //string new_str ;
  //t = s.taille_ + c.size();
  //char* n_str = new char [t];
  //new_str.taille_ = s.taille_ + 1 ;
  // utilisation de l'opérateur operator = (const string&) peut-être
  //for (int i = 0 , i < s.taille_ , i++){
    //n_str[i] = s.str_[i];
  //}
  //for (int i = s.taille_ , i < t , i++){
    //n_str[i] = c[i];
  //}
  //new_str.str_[new_str.taille_ - 1] = c;
  //string new_string(n_str, t);
  //return (s.str_ + c);
//}

void string::get_str(){
  for(int i = 0 ; i<taille_ ; i++){
    std::cout << str_[i] << " ";
  }
}
