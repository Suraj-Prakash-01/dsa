#include <iostream>
#include <limits.h>
#include <algorithm>

int main()
{
  int arr[5];
  int mini = INT_MAX;
  int size = sizeof(arr) / sizeof(int);

  std::cout << "size of array is " << size << std::endl;
  for (int i = 0; i < size; i++)
  {
    std::cin >> arr[i];
  }

  for (int j = 0; j < size; j++)
  {
    mini = std::min(mini, arr[j]);
  }
  std::cout << "The minimum value is " << mini;
}