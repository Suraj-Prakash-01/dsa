#include <iostream>
#include <string>
using std::cin;
using std::cout;

std::string replaceSpaces(std::string str)
{
  std::string temp = "";
  for (int i = 0; i < str.length(); i++)
  {
    // If the character is a space
    if (str[i] == ' ')
    {
      temp.push_back('@');
      temp.push_back('4');
      temp.push_back('0');
    }

    // If character is not a space
    else
    {
      temp.push_back(str[i]);
    }
  }
  return temp;
}
