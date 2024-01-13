#include <iostream>
#include <string>
using std::cin;
using std::cout;
void sayDigit(int n, std::string arr[])
{
  // Base Condition
  if (n == 0)
    return;

  // Processing
  int digit = n % 10;
  n = n / 10;

  // Recursive Call
  sayDigit(n, arr);
  cout << arr[digit] << " ";
}

int main()
{
  std::string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

  int n;
  cin >> n;

  cout << std::endl;
  sayDigit(n, arr);
  cout << std::endl;
}