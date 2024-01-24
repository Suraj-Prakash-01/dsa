#include <iostream>
using std::cin;
using std::cout;

bool powerOfFour(int n)
{
  // Base Condition
  if (n == 0)
    return false; // Since no power of 4 can give result as 0
  if (n == 1)
    return true; // If the number is power of 4, it will give 1 at the end
  if (n % 4 != 0)
    return false; // If there is any remainder after division, it can't be power of 4

  // Recursive Call
  return powerOfFour(n / 4);
}

int main()
{
  int n;
  cout << "Enter a positive integer: ";
  cin >> n;

  if (powerOfFour(n))
    cout << n << " is power of 4" << std::endl;
  else
    cout << n << " is not power of 4" << std::endl;
}