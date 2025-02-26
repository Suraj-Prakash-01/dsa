/* ----- To print all the subsequences -----*/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void subset_sum(int ind, std::vector<int> &ds, int arr[], int sum, int target, int n)
{
  // Base Case
  if (ind >= n)
  {
    if (sum == target)
    {
      for (auto it : ds)
        cout << it << " ";
      cout << std::endl;
    }
    return;
  }

  // Pick Condition
  ds.push_back(arr[ind]);
  sum += arr[ind];
  subset_sum(ind + 1, ds, arr, sum, target, n);

  // Not pick Condition
  sum -= arr[ind];
  ds.pop_back();
  subset_sum(ind + 1, ds, arr, sum, target, n);
}

int main()
{
  int arr[3] = {1, 2, 1};
  int n = 3;
  std::vector<int> ds;
  int target = 2;

  subset_sum(0, ds, arr, 0, target, n);
}

/* ----- To print just one subsequence ----- */

#include <iostream>
#include <vector>
using std::cin;
using std::cout;

bool subset_sum(int ind, std::vector<int> &ds, int arr[], int sum, int target, int n)
{
  // Base Case
  if (ind >= n)
  {
    // If the condition is satisfied
    if (sum == target)
    {
      for (auto it : ds)
        cout << it << " ";
      cout << std::endl;
      return true;
    }
    // If the condition is not satisfied
    return false;
  }

  // Pick Condition
  ds.push_back(arr[ind]);
  sum += arr[ind];
  if (subset_sum(ind + 1, ds, arr, sum, target, n) == true)
    return true; // To end the future recursion calls

  // Not pick Condition
  sum -= arr[ind];
  ds.pop_back();
  if (subset_sum(ind + 1, ds, arr, sum, target, n) == true)
    return true; // To end the future recursion calls

  return false;
}

int main()
{
  int arr[3] = {1, 2, 1};
  int n = 3;
  std::vector<int> ds;
  int target = 2;

  subset_sum(0, ds, arr, 0, target, n);
}

/* ----- Counting the number of subsets having sum == Target -----*/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;

int subset_sum(int ind, int arr[], int sum, int target, int n)
{
  // Base Case
  if (ind >= n)
  {
    // If the condition is satisfied
    if (sum == target)
      return 1;
    // If the condition is not satisfied
    return 0;
  }

  // Pick Condition
  sum += arr[ind];
  int l = subset_sum(ind + 1, arr, sum, target, n);

  // Not pick Condition
  sum -= arr[ind];
  int r = subset_sum(ind + 1, arr, sum, target, n);

  return l + r;
}

int main()
{
  int arr[] = {1, 2, 1, 2, 3, 4};
  int n = 6;
  int target = 4;

  cout << subset_sum(0, arr, 0, target, n) << std::endl;
}