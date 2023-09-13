#include <iostream>

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void sortOne(int arr[], int n)
{
  int left = 0, right = n - 1;

  while (left < right)
  {

    while (arr[left] == 0 && left < right)
    {
      left++;
    }

    while (arr[right] == 1 && left < right)
    {
      right--;
    }

    // Since we are here, it means
    // arr[left]==1 amd arr[right]==0
    if (left < right)
    {
      std::swap(arr[left], arr[right]);
      left++;
      right--;
    }
  }
}

int main()
{
  int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};

  sortOne(arr, 8);
  printArray(arr, 8);

  return 0;
}