#include <iostream>
using std::cin;
using std::cout;

int gcd(int a, int b)
{
  if (a == 0)
    return b;

  if (b == 0)
    return a;

  while (a != b)
  {
    if (a > b)
      a = a - b; // Uses Euler's theorem

    else
      b = b - a; // Uses Euler's theorem
  }
  return a;
}

int main()
{
  int a, b;
  cout << "Enter the values of a and b " << std::endl;
  cin >> a >> b;

  cout << "The GCD is " << gcd(a, b) << std::endl;
}