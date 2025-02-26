#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;

void sum_solver(int ind, int sum, std::vector<int> &arr, int n, std::vector<int> &ans)
{
  if (ind == n)
  {
    // If the index reaches the limit, that means sum of subset is already decided
    // So we will push the sum to the array that we will return
    ans.push_back(sum);
    return;
  }

  // Picking up condition
  sum_solver(ind + 1, sum + arr[ind], arr, n, ans);

  // Not picking up condition
  sum_solver(ind + 1, sum, arr, n, ans);
}

std::vector<int> subset_sum_I(std::vector<int> &arr, int n)
{
  std::vector<int> ans;
  int sum = 0;
  sum_solver(0, 0, arr, n, ans);
  // Sorting the array since it is mentioned in the question
  sort(ans.begin(), ans.end());
  return ans; // Returning the array containint the sum of subsets
}

int main()
{
  std::vector<int> arr{3, 1, 2};
  int n = arr.size();
  std::vector<int> ans = subset_sum_I(arr, n);

  // Displaying all the elements from the ans-array
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}