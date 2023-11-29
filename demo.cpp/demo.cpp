#include <iostream>
#include <vector>
using std::cin;
using std::cout;

vector<int> SumArray(vector<int> &a[], int n, vector<int> &b[], int m)
{
  int ans[10];
  int i = n - 1;
  int j = m - 1;

  int carry = 0;

  while (i >= 0 && j >= 0)
  {
    int val1 = a[i];
    int val2 = b[j];

    int sum = val1 + val2 + carry;

    carry = sum / 10;
    sum = sum % 10;
    ans.push_back(sum);
    i--;
    j--;
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
