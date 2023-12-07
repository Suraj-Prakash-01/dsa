#include <iostream>
using std::cin;
using std::cout;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return
}

int main()
{
  int a, b;
  cout << "Enter the values of a and b " << std::endl;
  cin >> a >> b;

  cout << "The GCD is" << gcd(a, b) << std::endl;
}