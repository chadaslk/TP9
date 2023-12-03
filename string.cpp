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
  str_[11] = '/';
  str_[12] = '0';
}

/*string::string(){
  taille_ = 0;
  str_ = nullptr;

}*/

//copy constructor
string::string(const string& s){
  taille_ = s.taille_ ;
  str_ = new char[taille_+2]; // pour inclure '/0'
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
/*string string::operator+(const string& s, const char* c){
  t = s.taille_ + c.size(); // taille_ du nouveau string
  char* n_str = new char [t];
  new_str.taille_ = s.taille_ + 1 ;
  // utilisation de l'opérateur operator = (const string&) peut-être
  for (int i = 0 , i < s.taille_ , i++){
    n_str[i] = s.str_[i];
  }
  for (int i = s.taille_ , i < t , i++){
    n_str[i] = c[i];
  }
  string new_string(n_str);
  return new_string;
}
*/
string string::operator+(const char* c){
  int t = taille_ + sizeof(c) ; // taille_ du nouveau string
  char* n_str = new char [t];
  for (int i = 0  ;i < taille_ ; i++){
    n_str[i] = str_[i];
  }
  for (int i = taille_ ; i < t-2 ; i++){
    n_str[i] = c[i-taille_];
  }
  string new_string(n_str);
  return new_string.str_;
}





void string::get_str(){
  for(int i = 0 ; i<taille_ ; i++){
    std::cout << str_[i] << " ";
  }
}



// Operator=  (Clem)
string& string::operator=(const string& str){
  	int length = str.length();
    if(length > size_max){
      std::cout<<("La taille a dépassé SIZE_MAX ! Il faut construire un string plus petit.");
    }
    // si le string que l'on attribue est de plus grande taille que celui initial
    if(taille_<length +1){
      reserve(length+1);
    }
    for (int i=0; i<length+1; i++){
      this->str_[i] = str.str_[i];
    }
		return *this;
}

// Operator+ (Clem)
string string::operator+(const char str){
	string new_string;
	int new_size = this->length() + 1;
	if(new_size > size_max){
		std::cout<<("La taille a dépassé SIZE_MAX ! Il faut construire un string plus petit.");
	}
	new_string.reserve(new_size+1);
	for (int i=0; i<new_size-1; i++){
		new_string.str_[i] = str_[i];
	}
	new_string.str_[new_size-1] = str;
	new_string.str_[new_size] = '\0';
	return new_string;
}

/////PARTIE LISA

//Destructeur
string::~string() { //destructor OK ça marche
  delete[] str_;
}


//Fonction membre capacity()
int string::capacity() const {
  //Retourner la capacité actuelle de la chaîne, sachant que si la chaîne a une taille <= 15 la capacité est fixée à 15,
  //sinon elle correspond soit à la capcité réservée, soit à la taille du string
  if (taille_>allocated_memory_){
  return taille_;
  }
  else {
      return allocated_memory_;
    }
    return taille_;
}


//Fonction membre empty()
bool string::empty() const{
  // Retourner TRUE (1) si la chaîne est vide, FALSE (0) sinon
  return (taille_ == 0);
}


//Fonction membre reserve (int n)
void string::reserve(int new_capacity) {
    // Si la nouvelle capacité est inférieure ou égale à l'actuelle, ne rien faire
    if (new_capacity <= taille_) {
      return;
    }
    else {
    // Allouer de la mémoire avec la nouvelle capacité
    char* new_str_ = new char[new_capacity];
    // Copier le contenu actuel dans la nouvelle mémoire
      if (str_) {
        for (int i=0; i<taille_ + 1; i++){
          new_str_[i]=str_[i];
        }
    delete[] str_; // Libérer l'ancienne mémoire
    str_ = new_str_;
    allocated_memory_=new_capacity;
        }
    }
}


//Operator =
/*string& string::operator=(const char* s){
  //Affecte une chaine de caractères à l'objet
  if (str_){
    delete[] str_ ; //Liberer la mémoire déjà existante
  }
  int taille_s = 0;
  while(s[taille_s]!='\0') taille_s++;
  str_ = new char[taille_s];
  for (int i=0; i<taille_s; i++){
    str_[i]=s[i];
  }
  return *this;
}*/


//Operator +
/*string string::operator+(const string& str){
  //Concaténer les chaînes
  string resultat;
  //Allouer une nouvelle mémoire avec la somme des tailles
  int taille_str = 0;
  while(str.str_[taille_str]!='\0') taille_str++;
  while(str_[taille_]!='\0') taille_++;
  resultat.taille_ = taille_ + taille_str;
  resultat.str_ = new char[resultat.taille_];
  //Copier les deux chaînes dans la nouvelle mémoire
  if (str_){
    for (int i=0; i<taille_; i++){
      resultat.str_[i]=str_[i];
    }
  }
    if (str.str_){
    for (int j=0; j<taille_str; j++){
      resultat.str_[j+taille_]=str.str_[j];
    }
  }
  //Ajout du caractère nul à la fin
  resultat.str_[resultat.taille_]='\0';
  return resultat;
}*/


//Constructor string(const char*)
string::string(const char* s): str_(nullptr), taille_(0) {
  //Transformer un char* en string
  int taille_s = 0;
  while(s[taille_s]!='\0') taille_s++;
  taille_ = taille_s +1;
  str_ = new char[taille_];
  for (int i=0; i<taille_; i++){
    str_[i]=s[i];
  }
}


//Fonction membre afficher()
void string::afficher() const {
  //Afficher le string dans le terminal
  if(str_) {
    std::cout << str_ << std::endl;
  }
}


//Fonction get_allocated_memory()
int string::get_allocated_memory() const {
  int allocated_memory_ = 15;
  if (taille_<=15){
    return allocated_memory_;
  }
  return taille_ ;
}

///// FIN PARTIE LISA
