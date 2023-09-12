#include <iostream>

int main()
{
  int a, b;
  std::cin >> a >> b;

  std::cout << "The value before swapping is : " << a << " " << b << std::endl;

  a = a + b;
  b = a - b;
  a = a - b;

  std::cout << "The value after swapping : " << a << " " << b << std::endl;
}