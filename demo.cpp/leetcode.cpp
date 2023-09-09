#include <iostream>
#include <math.h>

int main()
{
  int n;
  std::cin >> n;

  int ans = 0;
  int i = 0;
  while (n != 0)
  {
    int bit = n & 1;

    ans = (bit * pow(10, i)) + ans;

    n = n >> 1;
    i++;
  }
  std::cout << "Answer is " << ans << std::endl;
}