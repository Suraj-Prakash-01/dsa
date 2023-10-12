#include <iostream>

int Ceil(int arr[], int n, int x)
{
  // To find the ceil of the sorted array
  int low = 0, high = n - 1;
  int ans;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] >= x)
    {
      ans = arr[mid];
      high = mid - 1; // To keep looking furthur for ceil value
    }

    else
      low = mid + 1;
  }
  return ans;
}

int main()
{
  int arr[9] = {1, 4, 9, 12, 34, 45, 68, 84, 99};
  int x;
  std::cin >> x;

  int value = Ceil(arr, 9, x);
  std::cout << "The ceil of the sorted array is" << value << std::endl;
}