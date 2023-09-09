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
    bit = n & 1;
    n = n >> 1;
    ans = (bit * pow(10, i)) + ans;
    i++;
  }
  std::cout << ans;
}