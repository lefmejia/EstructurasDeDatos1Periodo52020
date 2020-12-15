#include "conjuntos.h"
#include <iostream>
#include <unordered_set>


int main()
{
  std::unordered_set<int> A = {2, 6, 4, 7};
  std::unordered_set<int> B = {2, 3, 5, 7};

  std::unordered_set<int> l1 = AuB(A, B);
  std::unordered_set<int> l2 = AnB(A, B);
  std::unordered_set<int> l3 = AdB(A, B);

  std::cout<<"A: ";
  print(A);
  std::cout<<"B: ";
  print(B);

  std::cout<<"Union de A y B: ";
  print(l1);

  std::cout<<"Interseccion de A y B: ";
  print(l2);

  std::cout<<"Diferencia de A y B: ";
  print(l3);
}