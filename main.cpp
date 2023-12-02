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

  ////LISA
  string str_H;
  str_H.afficher();
  std::cout << " " << std::endl;

  //test capacity() function
  std::cout << "Test de la fonction capacity() : " << std::endl;
  std::cout << "Taille : " << str_H.size() << std::endl;
  std::cout << "Capacité : " << str_H.capacity() << std::endl;
  std::cout << " " << std::endl;

  //test empty() function
  std::cout << "Test de la fonction empty : " << std::endl;
  std::cout << "Empty doit retourner FALSE (0) : " << str_H.empty() << std::endl;
  str_H.clear();
  std::cout << "Empty doit retourner TRUE (1) : " << str_H.empty() << std::endl;
  std::cout << " " << std::endl;

  //test reserve(int n) function
  string str;
  std::cout << "Test de la fonction reserve(int n) : " << std::endl;
  std::cout << "Taille : " << str.size() << std::endl;
  std::cout << "Capacité : " << str.capacity() << std::endl;
  str.reserve(30);
  std::cout << "Taille après réserve (non modifiée) : " << str.size() << std::endl;
  std::cout << "Capacité après réserve : " << str.capacity() << std::endl;
  std::cout << " " << std::endl;

  //test operator=(const char*)
  std::cout << "Test de l'operator=(const char*) : " << std::endl;
  string str_e;
  str_e="Testing string egality";
  std::cout << "Test égalité : " ; str_e.afficher();
  std::cout << " " << std::endl;

  //test operator+(const string&, const string&)
  std::cout << "Test de l'operator+(const string&) : " << std::endl;
  string str_T, str_s;
  str_T="Testing ";
  str_s="string";
  std::cout << "Test de l'addition de deux strings : " ; (str_T+str_s).afficher();
  std::cout << "Test de l'addition d'une chaîne de caractères et d'un string : " ; (str_T+"string").afficher();
  string str_c ("A character sequence");
  std::cout << "Transformation d'une séquence de caractères en string : " ; str_c.afficher() ;
  std::cout << " " << std::endl;

  str.~string();

  ////FIN LISA

  std::exit(EXIT_SUCCESS);
}
