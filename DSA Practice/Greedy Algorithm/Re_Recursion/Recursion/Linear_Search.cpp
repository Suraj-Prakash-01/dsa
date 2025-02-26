#include <iostream>
using std::cin;
using std::cout;

bool linearSearch(int arr[], int size, int key)
{
  // Base Conditon
  if (size == 0)
    return false;
  if (arr[0] == key)
    return true; // Key Found

  return linearSearch(arr + 1, size - 1, key);
}

int main()
{
  int arr[5] = {3, 5, 1, 2, 6};
  int size = 5;
  int key = 2;

  if (linearSearch(arr, size, key))
    cout << "Key is present" << std::endl;
  else
    cout << "Key is not present" << std::endl;
}