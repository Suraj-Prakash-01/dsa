#include <iostream>
using std::cin;
using std::cout;

bool isSorted(int arr[], int n)
{
  // Base Condition
  if (n == 1 || n == 0) // Array of size less than 2 is already sorted
    return true;

  if (arr[0] > arr[1])
    // After we move the address, every first element becomes 0
    return false;
  else
    // Moving the address forward and that decreases the size
    isSorted(arr + 1, n - 1);
}

int main()
{
  int arr[5] = {2, 3, 6, 8, 9};
  int n = 5;

  bool ans = isSorted(arr, n);

  if (ans)
    cout << "Array is sorted";
  else
    cout << "Array is not sorted";
}