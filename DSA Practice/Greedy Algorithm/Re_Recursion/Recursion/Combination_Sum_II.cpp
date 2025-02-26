#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;

// Function to find all combinations of elements in `arr` that add up to `target`
void findCombination(int ind, int target, std::vector<int> &arr, std::vector<std::vector<int>> &ans, std::vector<int> &ds)
{
  // Base case: if `target` is 0, then we have found a valid combination, so add it to `ans`
  if (target == 0)
  {
    ans.push_back(ds);
    return;
  }

  // Try all elements starting from `ind`
  for (int i = ind; i < arr.size(); i++)
  {
    // Skip duplicate elements
    if (i > ind && arr[i] == arr[i - 1])
      continue;

    // Skip elements greater than `target`
    if (arr[i] > target)
      break;

    // Add current element to the combination
    ds.push_back(arr[i]);

    // Recursively find combinations for remaining `target`
    findCombination(i + 1, target - arr[i], arr, ans, ds);

    // Backtrack: remove current element from the combination
    ds.pop_back();
  }
}
std::vector<std::vector<int>> Combination_sum_II(std::vector<int> &arr, int target)
{
  // Sorting the given array
  sort(arr.begin(), arr.end());

  // Making matrix ans for storing the final result
  std::vector<std::vector<int>> ans;

  // Creating temporary array for storing elements during recursive call
  std::vector<int> ds;
  findCombination(0, target, arr, ans, ds);
  return ans;
}

int main()
{
  std::vector<int> arr{10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  std::vector<std::vector<int>> ans = Combination_sum_II(arr, target);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << std::endl;
  }
}