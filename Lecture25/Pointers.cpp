#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int i = 5;
  int *p = &i;

  cout << p << std::endl;
  cout << *p << std::endl;

  // Copying a Pointer
  int *q = p;
  cout << p << " -- " << q << std::endl;
  cout << *p << " -- " << *q << std::endl;
}