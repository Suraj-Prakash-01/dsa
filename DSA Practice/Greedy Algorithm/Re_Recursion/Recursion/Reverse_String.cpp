#include <iostream>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;

void reverse(std::string &str, int i, int j)
{
  // Base condition
  if (i > j)
    return;

  // Swapping strings to make it reversed strings
  std::swap(str[i], str[j]);

  // Recursive Call
  reverse(str, i + 1, j - 1);
}

int main()
{
  std::string name = "madam";
  reverse(name, 0, name.size() - 1);
  cout << "Reversed String: " << name << std::endl;
}