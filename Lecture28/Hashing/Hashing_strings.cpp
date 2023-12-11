#include <iostream>
#include <string>
using std::cin;
using std::cout;

int main()
{
  std::string s;
  cin >> s;

  // Precompute
  int hash[26] = {0};
  for (int i = 0; i < s.size(); i++)
  {
    hash[s[i] - 'a'] += 1;
  }

  // Displaying hash
  for (int i = 0; i < 26; i++)
  {
    cout << hash[i] << " ";
  }

  int q;
  cout << std::endl
       << "Enter number of queries" << std::endl;
  cin >> q;
  // No. of queries
  while (q--)
  {
    char c;
    cin >> c;
    // Fetch
    cout << hash[c - 'a'] << std::endl;
  }
  return 0;
}
