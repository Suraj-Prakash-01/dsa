#include <iostream>
using std::cin;
using std::cout;
void sortedArray(int arr[], int n)
{
  // Base Condition - Already sorted
  if (n == 0 || n == 1)
    return;

  // Solving for just one condition
  // This will plave the largest element at the end of the array
  for (int i = 0; i < n - 1; i++) // loop till n-1 bcz we are taking i+1 into account
  {
    if (arr[i] > arr[i + 1])
      std::swap(arr[i], arr[i + 1]);
  }

  // Recursive call
  sortedArray(arr, n - 1);
}

int main()
{
  int arr[5] = {2, 5, 1, 6, 9};
  sortedArray(arr, 5);

  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << " ";
  }
}