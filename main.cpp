#include "string.h"
#include <iostream>

int main() {
  string s;
  s.get_str();
  //s.clear();
  //s.get_str();
  //s = 'b';
  //s.get_str();
  //string s1 = s + 'y';
  //std::cout << s1.c_str();
  //string s1(s);
  //s1.get_str();

  // Clem :
  char mot_test[100];
  std::cout<<"Enter a word with size<99"<<std::endl;
  std::cin>>mot_test;
  string string_test = string(mot_test);
  std::cout<<"le constructeur à partir d'un c-string est crée"<<std::endl;
  std::cout<<"la fonction length renvoie pour string_test : "<<string_test.length()<<std::endl;
  std::cout<<string::size_max<<std::endl;
  // end Clem

  std::exit(EXIT_SUCCESS);
}
