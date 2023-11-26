#include <iostream>
using std::cin;
using std::cout;

void sel_sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;

    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }

    if (minIndex != i)
    {
      std::swap(arr[minIndex], arr[i]);
    }
  }
}

int main()
{
  int arr[] = {5, 2, 8, 1, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  sel_sort(arr, n);
  cout << "The sorted array is ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << std::endl;
}