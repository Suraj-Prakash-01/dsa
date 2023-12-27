#include <iostream>
using std::cin;
using std::cout;

// Function to calculate factorial
long long factorial(int n)
{
  // Base case
  if (n <= 0)
    return 1;
  // Recursive case
  else
    return n * factorial(n - 1);
}

int main()
{
  int n;
  cout << "Enter a positive integer: ";
  cin >> n;

  // Check if the input is a negative number
  if (n < 0)
  {
    cout << "Error! Factorial of a negative number doesn't exist.";
  }
  else
  {
    cout << "Factorial of " << n << " = " << factorial(n);
  }

  return 0;
}