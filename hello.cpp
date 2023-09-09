#include <iostream>

bool isPrime(int n)
{
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int n;
  std::cin >> n;

  if (isPrime(n))
  {
    std::cout << n << " is a prime number";
  }
  else
  {
    std::cout << n << " is not a prime number";
  }
}
