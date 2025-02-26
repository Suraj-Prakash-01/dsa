#include <iostream>
#include <vector>
using std::cin;
using std::cout;

bool printS(int i, std::vector<int> &ans, int s, int sum, int arr[], int n)
{
  if (i == n) // Here i is index
  {
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
    return false;
  }

  // From here, it's usual structure
  ans.push_back(arr[i]);
  s += arr[i];
  // Take or Pick condition
  printS(i + 1, ans, s, sum, arr, n);

  s -= arr[i];
  ans.pop_back();
  // Not pick Condition
  printS(i + 1, ans, s, sum, arr, n);
}

int main()
{
  int arr[] = {1, 2, 1};
  int n = 3;
  int sum = 2;
  std::vector<int> ans;
  printS(0, ans, 0, sum, arr, n);
}