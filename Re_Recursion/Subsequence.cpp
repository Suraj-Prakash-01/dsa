#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void subsequence(int ind, std::vector<int> &ds, int arr[], int n)
{
  // Base Case
  if (ind == n)
  {
    // Printing the subsequence
    for (auto it : ds)
      cout << it << " ";
    cout << std::endl;
    return;
  }

  // Pick Condition
  ds.push_back(arr[ind]);
  subsequence(ind + 1, ds, arr, n);

  // Not pick Condition
  ds.pop_back();
  subsequence(ind + 1, ds, arr, n);
}

int main()
{
  int arr[3] = {3, 1, 2};
  int n = 3;

  std::vector<int> ds;
  subsequence(0, ds, arr, n);
}
