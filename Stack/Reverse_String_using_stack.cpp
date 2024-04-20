#include <iostream>
#include <stack>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
  std::string str = "suraj";

  std::stack<char> s;

  // Pushing string into Stack
  for (int i = 0; i < str.size(); i++)
  {
    s.push(str[i]);
  }

  // Creating a new empty variable to hold string
  std::string ans;

  // Using to stack property to reverse the string
  while (!s.empty())
  {
    ans.push_back(s.top());
    s.pop();
  }

  cout << "The reversed string is: " << ans << std::endl;
  return 0;
}