#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void printf(int index, std::vector<int> &ds, int arr[], int n)
{
  if (index == n)
  {
    for (auto it : ds)
    {
      cout << it << " ";
    }
    if (ds.size() == 0) // These two statements can be excluded from
      cout << "{}";     //  the code as they just shows null array
    cout << std::endl;
    return;
  }

  // Take or pick the particular index into the subsequence
  ds.push_back(arr[index]);
  printf(index + 1, ds, arr, n);
  ds.pop_back();

  // Not pick, or not take condition,
  // This element is not added to your subsequence
  printf(index + 1, ds, arr, n);
}

int main()
{
  int arr[3] = {3, 1, 2};
  int n = 3;
  std::vector<int> ds;
  printf(0, ds, arr, n);
  return 0;
}