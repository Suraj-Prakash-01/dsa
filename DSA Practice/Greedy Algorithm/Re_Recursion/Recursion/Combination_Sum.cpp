#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void findCombination(int i, int target, std::vector<int> &arr, std::vector<std::vector<int>> &ans, std::vector<int> &ds)
{
  if (i == arr.size())
  {
    // If the target becomes 0, it will stop and push that array into ans
    if (target == 0)
      ans.push_back(ds);
    return;
  }

  // Picking up condition
  if (arr[i] <= target)
  {
    ds.push_back(arr[i]);
    findCombination(i, target - arr[i], arr, ans, ds);
    /*  While returning we need to pop the element
        To make it the way it was before pushing that element*/
    ds.pop_back();
  }

  // Not picking up condition
  // If we don't pick, we will increase index by 1 to give next element a chance
  findCombination(i + 1, target, arr, ans, ds);
}
std::vector<std::vector<int>> combination_sum(std::vector<int> &candidates, int target)
{
  std::vector<std::vector<int>> ans; // To store the final answer
  std::vector<int> ds;               // To store temporary array while recursion
  findCombination(0, target, candidates, ans, ds);
  return ans;
}

int main()
{
  std::vector<int> candidates{2, 3, 6, 7};
  int target = 7;

  std::vector<std::vector<int>> ans = combination_sum(candidates, target);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << "  ";
    }
    cout << std::endl;
  }
}