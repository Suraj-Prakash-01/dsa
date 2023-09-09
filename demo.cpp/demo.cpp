#include <iostream>
#include <cmath>

int main()
{
  int n;
  std::cin >> n;
  int bit;
  int ans = 0;
  int i = 0;
  while (n != 0)
  {
    bit = n % 10;
    if (bit == 1)
    {
      ans = ans + pow(2, i);
    }
    n = n / 10;
    i++;
  }
  std::cout << ans;
}