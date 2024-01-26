#include <iostream>
using std::cin;
using std::cout;

// Function to sort an array using selection sort algorithm
void selectionSort(int arr[], int i, int n)
{
  // Base case: if we have reached the last element, return
  if (i == n - 1)
    return;

  // Initialize the minimum index to the current index
  int minIndex = i;

  // Loop through the remaining elements in the array
  for (int j = i + 1; j < n; j++)
  {
    // If the current element is smaller than the element at the minimum index
    if (arr[j] < arr[minIndex])
    {
      // Update the minimum index to the current index
      minIndex = j;
    }
  }

  // Swap the element at the current index with the smallest element in the remaining array
  std::swap(arr[i], arr[minIndex]);

  // Recursively sort the remaining elements in the array
  selectionSort(arr, i + 1, n);
}

int main()
{
  int arr[] = {6, 4, 8, 2, 10};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, 0, n); // Function Call

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}