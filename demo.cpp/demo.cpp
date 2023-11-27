#include <iostream>
using std::cin;
using std::cout;

void bubble_sort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    // For round 1 ot n-1

    for (int j = 0; j < n - i; j++)
    {
      if (arr[j] > arr[j + 1])
        std::swap(arr[j], arr[j + 1]);
    }
  }
}

int main()
{
  int arr[] = {5, 2, 8, 1, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  bubble_sort(arr, n);
  cout << "The sorted array is ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << std::endl;
}
