#include <iostream>
#include <algorithm>

void reverse(int arr[], int n)
{
  int start = 0;
  int end = n - 1;
  while (start <= end)
  {
    std::swap(arr[start], arr[end]);
    start++;
    end--;
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

  reverse(arr, 6);
  reverse(brr, 5);

  printArray(arr, 6);
  printArray(brr, 5);
}