// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{

  string s;
  cin >> s;
  string ops;
  for (int i = 0; i < s.size(); ++i)
  {
    if (isdigit(s[i]))
    {
      int n = s[i] - '0';
      string tmp;
      i++;
      while (s[i] != ']')
      {
        if (s[i] == '[')
          continue;
        tmp += s[i];
      }
      tmp = n * tmp;
      ops += tmp;
    }
    else
      ops += s[i];
  }
  cout << ops;
  return 0;
}
