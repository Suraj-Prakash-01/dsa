#include <iostream>

int binarySearch(int arr[], int low, int high, int key)
{

  // Below formula can be used when the start+end>INT_MAX
  // int mid=start + (end-start)/2;

  // This checks the basic condition of Binary Search
  if (low > high)
    return -1;

  int mid = (low + high) / 2;

  if (arr[mid] == key)
    return mid;

  // The argument present in the return makes it recursive since it goes on
  // until we find the key element user has asked for
  else if (key > arr[mid])
    return binarySearch(arr, mid + 1, high, key);

  return binarySearch(arr, low, high - 1, key);
}

int main()
{
  int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int key;
  std::cin >> key;

  int index = binarySearch(arr, 0, 8, key);
  std::cout << "The key is present at index " << index << std::endl;
}