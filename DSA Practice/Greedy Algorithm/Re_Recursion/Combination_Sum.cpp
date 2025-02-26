#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void combination_Sum(int i, std::vector<int> &arr, std::vector<int> &ds, std::vector<std::vector<int>> &ans, int target)
{
  // Base Case
  if (i == arr.size())
  {
    if (target == 0)
      ans.push_back(ds);
    return;
  }

  // Picking the same element
  if (arr[i] <= target)
  {
    ds.push_back(arr[i]);
    combination_Sum(i, arr, ds, ans, target - arr[i]);
    ds.pop_back(); // This line will be used when all the other elements from the array is used
  }

  // Moving on to the next element
  combination_Sum(i + 1, arr, ds, ans, target);
}

int main()
{
  std::vector<int> arr = {2, 3, 5, 6};
  int target = 8;

  std::vector<std::vector<int>> ans;
  std::vector<int> ds;
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