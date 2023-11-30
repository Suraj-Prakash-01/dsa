#include <iostream>
using std::cin;
using std::cout;

int duplicate(int arr[], int n)
{
  // To initialize an integer for comparing values
  int i = 0;

  for (int j = 0; j < n; j++)
  {
    // If it's not equal, then it is unique element
    if (arr[i] != arr[j])
    {
      // To count number of unique element
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

int print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int arr[] = {1, 2, 2, 3, 3, 4, 5, 6, 8, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "The number of unique elements in sorted array are " << duplicate(arr, n) << std::endl;
  print(arr, n);
}