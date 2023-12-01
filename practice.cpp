#include <iostream>
#include <string>
using std::cin;
using std::cout;

char getMaxOccChar(std::string s)
{
  int arr[26] = {0};

  // Creating an array of count of characters
  for (int i = 0; i < s.length(); i++)
  {
    char ch = s[i];

    // If character is lowercase
    if (islower(ch))
    {
      int num = ch - 'a';
      arr[num]++;
    }

    // If character is uppercase
    else if (isupper(ch))
    {
      int num = ch - 'A';
      arr[num]++;
    }
  }

  // Finding max occurrence character
  int maxi = -1, ans = 0;
  for (int i = 0; i < 26; i++)
  {
    if (maxi < arr[i])
    {
      ans = i;
      maxi = arr[i];
    }
  }

  char finalAns = 'a' + ans;
  return finalAns;
}

int main()
{
  std::string s;
  cout << "Enter a string :" << std::endl;
  cin >> s;

  cout << "Maximum occuring character is :" << getMaxOccChar(s) << std::endl;
}