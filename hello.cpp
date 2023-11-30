#include <iostream>
using std::cout;
void merge(int arr1[], int m, int arr2[], int n, int arr3[])
{
  int i = 0, j = 0;
  while (arr1.size() < (m + n))
}

// To print the array
void print(int ans[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
}

int main()
{
  int arr1[5] = {1, 3, 5, 7, 9};
  int arr2[3] = {2, 4, 6};
  int arr3[8];

  merge(arr1, 5, arr2, 3, arr3);
  print(arr1, 8);

  return 0;
}
