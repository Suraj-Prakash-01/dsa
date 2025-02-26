#include <iostream>
using std::cin;
using std::cout;

// Function to merge two sorted subarrays of a given array
void merge(int arr[], int s, int e)
{
  // Calculate the middle index of the array
  int mid = (s + e) / 2;

  // Calculate the length of the two subarrays
  int len1 = mid - s + 1;
  int len2 = e - mid;

  // Create two temporary arrays to store the two subarrays
  int *first = new int[len1];
  int *second = new int[len2];

  // Copy the values from the main array to the temporary arrays
  int mainArrayIndex = s;
  for (int i = 0; i < len1; i++)
    first[i] = arr[mainArrayIndex++];

  mainArrayIndex = mid + 1;
  for (int i = 0; i < len2; i++)
    second[i] = arr[mainArrayIndex++];

  // Merge the two sorted temporary arrays back to the main array
  int index1 = 0;
  int index2 = 0;
  mainArrayIndex = s;

  // Compare and merge the elements of the two subarrays
  while (index1 < len1 && index2 < len2)
  {
    if (first[index1] <= second[index2])
    {
      arr[mainArrayIndex] = first[index1];
      index1++;
    }
    else
    {
      arr[mainArrayIndex] = second[index2];
      index2++;
    }
    mainArrayIndex++;
  }

  // Copy any remaining elements from the first subarray
  while (index1 < len1)
  {
    arr[mainArrayIndex] = first[index1];
    index1++;
    mainArrayIndex++;
  }

  // Copy any remaining elements from the second subarray
  while (index2 < len2)
  {
    arr[mainArrayIndex] = second[index2];
    index2++;
    mainArrayIndex++;
  }

  // Free the memory allocated for the temporary arrays
  delete[] first;
  delete[] second;
}

void mergeSort(int arr[], int s, int e)
{
  // Base Condition
  if (s >= e)
    return;

  int mid = (s + e) / 2;

  // To sort left part
  mergeSort(arr, s, mid);

  // To sort right part
  mergeSort(arr, mid + 1, e);

  // To merge
  merge(arr, s, e);
}

int main()
{
  int arr[5] = {2, 5, 1, 6, 9};
  int n = 5;

  mergeSort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}