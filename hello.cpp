#include <iostream>

int AP(int n)
{
  return (3 * n + 7);
}

int main()
{
  int n;
  std::cin >> n;

  std::cout << "The n'th term of the AP is " << AP(n) << std::endl;
}