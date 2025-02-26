#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;

void find_subsets(int ind, std::vector<int> &nums, std::vector<int> &ds, std::vector<std::vector<int>> &ans)
{
  // Stores subsets in the ultimate array
  ans.push_back(ds);

  for (int i = ind; i < nums.size(); i++)
  {
    // If the subset element encounters duplicate element, it skips that iteration
    if (i != ind && nums[i] == nums[i - 1])
      continue;

    // Pushing an element in the subset
    ds.push_back(nums[i]);

    // Recursive Call
    find_subsets(i + 1, nums, ds, ans);

    // Removing the element to make a space for another subset
    ds.pop_back();
  }
}

std::vector<std::vector<int>> subset_with_dup(std::vector<int> &nums)
{
  std::vector<std::vector<int>> ans; // Ultimate Array
  std::vector<int> ds;               // Temporary array to hold the subsets
  sort(nums.begin(), nums.end());    // Sorting the array so that all duplicate element be at the adjacent index
  find_subsets(0, nums, ds, ans);    // Calling find_subsets function to create subsets
  return ans;
}

int main()
{
  std::vector<int> nums{1, 2, 2};

  // Saving all subsets we got form function call in the variable ans
  std::vector<std::vector<int>> ans = subset_with_dup(nums);

  // Displaying all the subsets
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << std::endl;
  }
}