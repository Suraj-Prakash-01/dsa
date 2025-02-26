#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void subset(int ind, std::vector<int> &arr, std::vector<int> &ds, std::vector<std::vector<int>> &ans)
{
  // Pushing the empty array
  ans.push_back(ds);

  for (int i = ind; i < arr.size(); i++)
  {
    // To avoid duplicate cases
    if (i != ind && arr[i] == arr[i - 1])
      continue;

    ds.push_back(arr[i]);
    subset(i + 1, arr, ds, ans);
    ds.pop_back();
  }
}

int main()
{
  std::vector<int> arr = {1, 2, 2};
  std::vector<int> ds;
  std::vector<std::vector<int>> ans;

  subset(0, arr, ds, ans);

  // Printing the ultimate array containing non duplicate subsets
  for (auto it : ans)
  {
    for (auto it1 : it)
    {
      cout << it1 << " ";
    }
    cout << std::endl;
  }
}