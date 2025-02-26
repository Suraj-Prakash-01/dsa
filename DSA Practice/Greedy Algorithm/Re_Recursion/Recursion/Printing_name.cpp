#include <iostream>
using std::cin;
using std::cout;

void print_Name(int count, int n)
{
  if (count > n)
    return;
  cout << "Suraj " << count << std::endl;
  print_Name(count + 1, n);
}

int main()
{
  int n, count = 1;
  cout << "Enter the number of times you wanna print name: "
       << " ";
  cin >> n;
  print_Name(count, n);
}