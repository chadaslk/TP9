#include "string.h"
#include <iostream>

int main() {

  // TEST DU CONSTRUCTEUR PAR DEFAUT
  string s;
  std::cout<<"Notre default string est : "<< s.c_str() << std::endl;

  //s.clear();
  //s.get_str();
  //s = 'b';
  // TEST DU COPY CONSTRUCTOR
  char * c = new char[2];
  string s3(c);
  string s1(s);
  std::cout<<"Le résultat du copy constructor est : "<< s1.c_str() << std::endl;
  //s1.c_str();
  // TEST DE LA FONCTION SIZE()
  std::cout<<"La taille de s1 est : "<< s1.size() << std::endl;
  // TEST DE L'OPERATEUR = (char)
  s = 'b';
  std::cout<<"La nouvelle valeur de s est : "<< s.c_str() << std::endl;
  // TEST DE CLEAR()
  s.clear();
  std::cout<<"La nouvelle valeur de s est : "<< s.c_str() << std::endl;
  // TEST DE L'OPERATEUR +

  c[0] = ' ';
  c[1] = '!';
  string s2 = s1 + c;
  std::cout<<"La nouvelle valeur de s1 est : "<< s2.c_str() << std::endl;

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
