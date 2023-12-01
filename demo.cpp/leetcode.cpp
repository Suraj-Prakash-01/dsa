#include <iostream>
#include <string>
using std::cin;
using std::cout;

std::string removeOccurrences(std::string s, std::string part)
{
  while (s.size() != 0 && s.find(part) < s.length())
  {
    s.erase(s.find(part), part.length());
  }
  return s;
}

int main()
{
  std::string s, part;
  cout << "Enter a string : ";
  cin >> s;
  cout << "Enter part of that string : ";
  cin >> part;

  cout << "The new string without part is :" << removeOccurrences(s, part) << std::endl;
}