#include "string.h"
#define SIZE_MAX 100
#include <iostream>

//Max size  (Clem)
const int string::size_max = 100;

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

// Constructor   (Clem)
string::string(char* str) {
    // Allouer de la mémoire pour la chaîne de caractères
    taille_=2;
    str_ = new char[taille_];
    // Calcul de la longueur de la chaîne
    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    taille_=length;
    if(taille_ > size_max){
      std::cout<<("La taille a dépassé SIZE_MAX ! Il faut construire un string plus petit.");
    }
    // Copier les caractères de la chaîne C dans la nouvelle chaîne
    for (int i = 0; i <= taille_+1; ++i) {
        str_[i] = str[i];
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

// Calcul de la longueur de la chaîne  (Clem)
int string::length() const{
  int length = 0;
  while (str_[length] != '\0') {
      ++length;
  }
  return length;
}


// Use numeric_limits to get the maximum value representable   (Clem)
int string::max_size() const{
    return size_max;
}




//Resize  (Clem)
void string::resize(int new_size, char char_){
  if(new_size > this->max_size()){
	std::cout<<("La taille a dépassé SIZE_MAX ! Il faut construire un string plus petit.");
  }
	int string_size = this->length();
	if (new_size>string_size){
		for (int i=string_size; i<new_size+1 ; i++){
			str_[i] = char_;
    }
  }
	else if(new_size<string_size){
    str_[new_size+1] = '\0';
  }
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



// Operator=  (Clem)
void string::operator=(const string& str){
  	int length = str.length();
    if(length > size_max){
      std::cout<<("La taille a dépassé SIZE_MAX ! Il faut construire un string plus petit.");
    }
    // si le string que l'on attribue est de plus grande taille que celui initial
    if(taille_<length +1){
    //  reserve(length+1);                        //////////////// A decommenter quand reserve(size_t) sera crée
    }
    for (int i=0; i<length+1; i++){
      this->str_[i] = str.str_[i];
    }
}

// Operator+ (Clem)
string string::operator+(const string& str) {
    string new_string(*this);  // Copier la chaîne actuelle
    // Copier les caractères de str à la fin de new_string
    for (int i = 0; i < str.taille_; ++i) {
        new_string.str_[new_string.taille_ + i] = str.str_[i];
    }
    // Mettre à jour la taille de new_string
    new_string.taille_ += str.taille_;
    if(new_string.taille_ > size_max){
      std::cout<<("La taille a dépassé SIZE_MAX ! Il faut construire un string plus petit.");
    }
    return new_string;
}

/// OU PEUT-ETRE   (Clem)
/*
string string::operator+(const string& str){
  string new_string;
  int new_size = this->length() + 1;
  if(new_size > size_max){
    std::cout<<("La taille a dépassé SIZE_MAX ! Il faut construire un string plus petit.");
  }
  //new_string.reserve(new_size+1);                  //////////////// A decommenter quand reserve(size_t) sera crée
  for (int i=0; i<new_size-1; i++){
    new_string.str_[i] = str_[i];
  }
  new_string.str_[new_size] = str;
  new_string.str_[new_size+1] = '\0';
  return new_string;
}
*/
