#include <iostream>
#include <vector>
using std::cin;
using std::cout;

// Adding a bool operator will limit the output to just one output
bool printS(int i, std::vector<int> &ans, int s, int sum, int arr[], int n)
{
  if (i == n) // Here i is index
  {
    // Condition Satisfied
    if (s == sum) // Print only if the sum of subsequence is target sum
    {
      for (auto it : ans)
      {
        cout << it << " ";
      }
      cout << std::endl;
      return true;
    }
    // Return the answer after every potential sum it finds
    // Condition not satisfied
    return false;
  }

  // From here, it's usual structure
  ans.push_back(arr[i]);
  s += arr[i];
  // Take or Pick condition
  if (printS(i + 1, ans, s, sum, arr, n) == true)
    return true;

  s -= arr[i];
  ans.pop_back();
  // Not pick Condition
  if (printS(i + 1, ans, s, sum, arr, n) == true)
    return true;

  return false;
}

int main()
{
  int arr[] = {1, 2, 1};
  int n = 3;
  int sum = 2;
  std::vector<int> ans;
  printS(0, ans, 0, sum, arr, n);
}