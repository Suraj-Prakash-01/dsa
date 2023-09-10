#include <iostream>

int setbit(int n)
{
  int count = 0;
  while (n != 0)
  {
    if (n & 1)
    {
      count++;
    }
    n = n >> 1;
  }
  return count;
}

int main()
{
  int a, b;
  std::cin >> a >> b;

  int bit_count = setbit(a) + setbit(b);
  std::cout << "The total count of setbit is " << bit_count << std::endl;
}