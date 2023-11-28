#include <iostream>
#include <vector>
using std::cout;
using std::vector;

// Function to reverse an array
vector<int> reverse(vector<int> v)
{
  int s = 0;
  int e = v.size() - 1;

  while (s <= e)
  {
    // Reversing opposite ends at the same time through swapping
    std::swap(v[s], v[e]);
    s++;
    e--;
  }
  return v;
}

void print(vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << std::endl;
}

int main()
{
  vector<int> v;

  v.push_back(12);
  v.push_back(5);
  v.push_back(45);
  v.push_back(78);
  v.push_back(1);
  v.push_back(94);

  // Original array
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << std::endl;

  vector<int> ans = reverse(v);

  // To get an reverse array
  print(ans);
  return 0;
}