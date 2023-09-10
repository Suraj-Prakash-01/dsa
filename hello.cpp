#include <iostream>
#include <algorithm>

void swapAlternate(int arr[], int n)
{
  for (int i = 0; i < n; i += 2)
  {
    if (i + 1 < n)
    {
      std::swap(arr[i], arr[i + 1]);
    }
  }
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main()
{
  int arr[6] = {1, 54, 98, -23, -43, 45};
  int brr[5] = {1, 2, 3, 4, 5};

  swapAlternate(arr, 6);
  swapAlternate(brr, 5);

  printArray(arr, 6);
  printArray(brr, 5);
}