#include <iostream>

int ReverseSorted(int arr[], int n, int k)
{
  // To find the target element in the reverse sorted array
  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == k)
      return mid;

    // If the left part of the array is sorted
    else if (arr[low] <= arr[mid])
    {
      if (arr[low] <= k && k <= arr[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    // If the right part of the array is sorted
    else
    {
      if (arr[mid] <= k && k <= arr[high])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  return -1;
}

int main()
{
  // A reversed Sorted array
  int arr[9] = {5, 6, 7, 8, 0, 1, 2, 3, 4};
  int k;
  std::cin >> k;

  int value = ReverseSorted(arr, 9, k);
  std::cout << "The target element is present at the index " << value << std::endl;
}