#include "string.h"
#include <iostream>

int main() {
  string s;
  s.get_str();
  s.clear();
  s.get_str();
  //std::cout << s.c_str();
  //string s1(s);
  //s1.get_str();

  std::exit(EXIT_SUCCESS);
}
