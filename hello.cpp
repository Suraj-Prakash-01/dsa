#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  int i = 1;
  while (i <= n)
  {
    int j = 1;
    while (j <= n)
    {
      std::cout << 3 * (i - 1) + j;
      j = j + 1;
    }
    std::cout << std::endl;
    i += 1;
  }
}