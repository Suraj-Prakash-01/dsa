#include <iostream>
#include <string>
using std::cin;
using std::cout;

bool palindrome(int i, std::string &s)
{

  // Base Condition
  // If i exceeds half of the string means all the elements
  // are compared, we return true.
  if (i >= s.length() / 2)
    return true;

  // If the start is not equal to the end, not the palindrome.
  if (s[i] != s[s.length() - i - 1])
    return false;

  // If both characters are the same, increment i and check start+1 and end-1.
  // Recursive call
  return palindrome(i + 1, s);
}

int main()
{

  std::string s;
  cout << "Enter a string to check: ";
  cin >> s;
  if (palindrome(0, s))
    cout << "Palindrome" << std::endl;
  else
    cout << "Not Palindrome" << std::endl;
  cout << std::endl;
}