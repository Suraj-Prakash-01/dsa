#include <iostream>

bool isEven(int a)
{
  if (a & 1)
  {
    return 0;
  }
  return 1;
}

int main()
{
  int num;
  std::cin >> num;

  if (isEven(num))
  {
    std::cout << "Num is even" << std::endl;
  }
  else
  {
    std::cout << "Num is odd" << std::endl;
  }
}