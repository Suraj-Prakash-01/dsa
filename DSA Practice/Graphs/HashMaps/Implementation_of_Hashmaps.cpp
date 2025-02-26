#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
  // Creation
  unordered_map<string, int> m;

  // Insertion

  // Method 1
  pair<string, int> p = make_pair("suraj", 3);
  m.insert(p);

  // Method 2
  pair<string, int> pair2("love", 2);
  m.insert(pair2);

  // Method 3
  m["mera"] = 1;

  // Searching
  cout << m["mera"] << endl;
  cout << m.at("suraj") << endl;

  // Size
  cout << m.size() << endl;

  // To check the presence
  // It gives 0 if the key is not present
  // And gives the number if it is present
  cout << m.count("love") << endl;

  // Erase
  m.erase("love");
  cout << m.size() << endl;

  // To print all elements
  // Method 1
  for (auto i : m)
  {
    cout << i.first << " " << i.second << endl;
  }

  // Method 2 - Iterator
  unordered_map<string, int>::iterator it = m.begin();

  while (it != m.end())
  {
    cout << it->first << " " << it->second << endl;
    it++;
  }
}