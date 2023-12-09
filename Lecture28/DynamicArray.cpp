#include <iostream>
using std::cin;
using std::cout;

int getSum(int *arr, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  return sum;
}

int main()
{
  int n;
  cin >> n;

  // Varible size Array
  int *arr = new int[n];

  // Taking input n in the array
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int ans = getSum(arr, n);

  cout << " Answer is " << ans << std::endl;
}