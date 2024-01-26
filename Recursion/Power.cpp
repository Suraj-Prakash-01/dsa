#include <iostream>
using std::cin;
using std::cout;
int power(int a, int b)
{
  // Base Case
  if (b == 0)
    return 1;
  if (b == 1)
    return a;

  // Concept is for even, power will be 2^10=(2^5)*(2^5)
  // and for odd, power will be 2^11=2*(2^5)*(2^5)
  int ans = power(a, b / 2); // Recursive Call

  // If b is even
  if (!(b % 2))
    return ans * ans;
  else
    // If b is odd
    return a * ans * ans;
}

int main()
{
  int a, b;
  cin >> a >> b;

  cout << "The answer is " << power(a, b) << std::endl;
}