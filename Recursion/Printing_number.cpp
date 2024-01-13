#include <iostream>
using std::cin;
using std::cout;

void print(int n)
{
  // Base Case
  if (n == 0)
    return;

  // Recusive Relation
  print(n - 1);
  cout << n << std::endl;
}

int main()
{
  int n;
  cin >> n;
  cout << std::endl;
  print(n);
}