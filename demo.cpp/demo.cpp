#include <iostream>

int binarySearch(int arr[], int size, int key)
{
  int start = 0;
  int end = size - 1;

  // Below formula can be used when the start+end>INT_MAX
  // int mid=start + (end-start)/2;
  int mid = (start + end) / 2;

  while (start <= end)
  {
    if (arr[mid] == key)
      return mid;

    // If key is greater than mid value
    else if (key > arr[mid])
      start = mid + 1;

    // If the key is smaller than mid value
    else
    {
      end = mid - 1;
    }
    mid = (start + end) / 2;
  }
  return -1;
}

int main()
{
  int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int key;
  std::cin >> key;

  int index = binarySearch(arr, 9, key);
  std::cout << "The key is present at index " << index << std::endl;
}