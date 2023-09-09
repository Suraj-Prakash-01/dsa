#include <iostream>

int fact(int a)
{
  int f = 1;
  while (a > 0)
  {
    f = f * a;
    a--;
  }
  return f;
}

int nCr(int n, int r)
{
  int c = fact(n) / (fact(r) * fact(n - r));
  return c;
}

int main()
{
  int n, r;
  std::cin >> n >> r;

  std::cout << "The combination is " << nCr(n, r) << std::endl;
}