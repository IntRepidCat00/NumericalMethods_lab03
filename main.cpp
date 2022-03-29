#include <iostream>
#include "extra.h"

int main()
{
  LinearEquationSystem MySystem1, MySystem2;

  std::string divideLine(60, '=');

//  std::cout << divideLine << std::endl;
//
//  MySystem1.printSystem();
//
//  std::cout << divideLine << std::endl;
//
//  MySystem1.inverseMatrixMethod();

  std::cout << divideLine << std::endl;

  MySystem2.printSystem();

  std::cout << divideLine << std::endl;

  MySystem2.CramersMethod();

  std::cout << divideLine << std::endl;

  return 0;
}
