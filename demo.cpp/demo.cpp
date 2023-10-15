#include <iostream>

int ReverseSorted(int arr[], int n, int k)
{
  // To find the target element in the reverse sorted array
  // that contains the duplicate elements as well
  int low = 0;
  int high = n - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == k)
      return mid;

    else if (arr[low] == mid && arr[mid] == arr[high])
    {
      low = low + 1;
      high = high - 1;
      continue;
    }

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
  // A reversed Sorted array with duplicate elements
  int arr[7] = {3, 1, 2, 3, 3, 3, 3};
  int k;
  std::cin >> k;

  int value = ReverseSorted(arr, 7, k);
  std::cout << "The target element is present at the index " << value << std::endl;
}