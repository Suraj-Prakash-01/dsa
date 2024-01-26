#include <iostream>
using std::cin;
using std::cout;

bool binarySearch(int arr[], int s, int e, int k)
{
  // Base Case
  // Element not found
  if (s > e)
    return false;

  // Updating mid value after every recursive call
  int mid = (e + s) / 2;

  // Element found
  if (arr[mid] == k)
    return true;

  // Trimming search space
  if (arr[mid] > 1)
    return binarySearch(arr, mid + 1, e, k);
  else
    return binarySearch(arr, s, mid - 1, k);
}

int main()
{
  int arr[6] = {2, 4, 6, 10, 14, 20};
  int s = 0;
  int e = 5;
  int k = 16;

  if (binarySearch(arr, 0, 5, k))
    cout << "Element is present" << std::endl;
  else
    cout << "Element is not present" << std::endl;
}
