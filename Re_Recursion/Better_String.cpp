/* The better string is the one which has the maximum number of unique subsets*/

#include <iostream>
#include <set>
#include <string>
using std::cin;
using std::cout;

void sub(int i, std::string &ds, std::string &s, std::set<std::string> &ans)
{
  if (i == s.size())
  {
    ans.insert(ds); // Since we are using set, it will remove the duplicate cases
    return;
  }

  // Include the current character
  ds.push_back(s[i]);
  sub(i + 1, ds, s, ans);
  ds.pop_back();

  // Exclude the current character
  sub(i + 1, ds, s, ans);
}

int main()
{
  std::string str1 = "gfg", str2 = "ggg";
  std::set<std::string> s1, s2;
  std::string a = "", b = "";

  sub(0, a, str1, s1);
  sub(0, b, str2, s2);

  int l = s1.size();
  int m = s2.size();

  if (l >= m)
    cout << "The Better String is " << str1 << std::endl;
  else
    cout << "The Better String is " << str2 << std::endl;
}