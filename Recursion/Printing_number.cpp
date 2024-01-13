#include <iostream>
using std::cin;
using std::cout;

void print(int n)
{
  // Base Case
  if (n == 0)
    return;

  cout << n << std::endl;
  print(n - 1);
}

int main()
{
  int n;
  cin >> n;
  cout << std::endl;
  print(n);
}