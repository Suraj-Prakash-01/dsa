#include <iostream>
using std::cin;
using std::cout;

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n, int i)
{
  // Base condition: if we have sorted all elements till i, return
  if (i == n)
    return;

  // Save the current value to compare later
  int current = arr[i];

  // Start from the previous index and shift elements greater than current value
  int j = i - 1;
  while (arr[j] > current && j >= 0)
  {
    arr[j + 1] = arr[j];
    j--;
  }

  // Place the current value at its correct position
  arr[j + 1] = current;

  // Recursively sort the remaining elements
  insertionSort(arr, n, i + 1);
}

int main()
{
  // Initialize an array with unsorted elements
  int arr[5] = {2, 1, 6, 4, 9};

  // Call the insertionSort function with the initial index as 0
  insertionSort(arr, 5, 0);

  // Print the sorted array
  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << " ";
  }
}