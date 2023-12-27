#include <iostream>

using namespace std;

void print_recursive(int n)
{
  // Base Condition
  if (n <= 0)
  {
    return; // Used to end the void function
  }
  // Hypotheisis
  print_recursive(n - 1);
  // Induction
  cout << n << endl; // Will give output from 1 to n as
                     // Recusive call is stored in stack
}

int main()
{
  int n;
  cout << "Enter a positive integer: ";
  cin >> n;
  cout << "Printing numbers from 1 to " << n << " using recursive function: " << endl;
  print_recursive(n);
  return 0;
}