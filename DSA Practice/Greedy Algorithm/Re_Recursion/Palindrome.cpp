#include <iostream>
#include <string>
using std::cin;
using std::cout;

bool palindrome(std::string &s, int i)
{
  // Base Case
  // If it reaches till this far, this means all previous elements were equal
  if (i >= s.size() / 2)
    return true;

  // If the elements are not equal
  if (s[i] != s[s.size() - 1 - i])
    return false;

  // If the elements are equal
  return palindrome(s, ++i);
}

int main()
{
  std::string s = "madam";
  std::string p = "suraj";

  cout << palindrome(s, 0) << std::endl;
  cout << palindrome(p, 0) << std::endl;
}
