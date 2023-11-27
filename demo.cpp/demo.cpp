#include <iostream>
using std::cin;
using std::cout;

void insertion_sort(int arr[], int n)
{
  // We started with i=1 bcz we considered
  // First element as already sorted one
  for (int i = 1; i < n; i++)
  {
    int temp = arr[i];
    int j = i - 1;
    for (; j >= 0; j--)
    {
      if (arr[j] > temp)
      {
        // Shift in position to make space for new element
        arr[j + 1] = arr[j];
      }
      else
      {
        // In order to stop if the element doesn't need to be sorted
        break;
      }
    }
    // To input value at the space created
    arr[j + 1] = temp;
  }
}

int main()
{
  int arr[] = {5, 2, 11, 9, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  insertion_sort(arr, n);
  cout << "The sorted array is ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << std::endl;
}
