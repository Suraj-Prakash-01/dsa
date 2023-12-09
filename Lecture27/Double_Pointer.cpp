#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int i = 5;
  int *p = &i;
  int **p2 = &p;

  cout << " Printing p " << p << std::endl;
  // cout << "Address of p " << &p << std::endl;
  cout << *p2 << std::endl;

  // Ways to get the values

  cout << i << std::endl;
  cout << *p << std::endl;
  cout << **p2 << std::endl;
}