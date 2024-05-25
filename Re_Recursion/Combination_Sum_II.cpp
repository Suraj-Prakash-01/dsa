#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;

void combination_Sum(int ind, std::vector<int> &arr, std::vector<int> &ds, std::vector<std::vector<int>> &ans, int target)
{
  // Base Case
  if (target == 0)
  {
    ans.push_back(ds);
    return;
  }

  for (int i = ind; i < arr.size(); i++)
  {
    // To avoid duplication
    if (i > ind && arr[i] == arr[i - 1])
      continue;

    // As if the arr[i] is greater than target, then rest will also be greater
    if (arr[i] > target)
      break;

    ds.push_back(arr[i]);
    combination_Sum(i + 1, arr, ds, ans, target - arr[i]);
    ds.pop_back();
  }
}

int main()
{
  std::vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;

  std::vector<std::vector<int>> ans;
  std::vector<int> ds;
  sort(arr.begin(), arr.end());
  combination_Sum(0, arr, ds, ans, target);

  // Printing the ultimate vector which stores all the subsequences
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << std::endl;
  }
}