#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  int bit;
  int rev;

  while (n != 0)
  {
    bit = n & 1;
    n = n >> 1;
  }
  std::cout << bit;
}