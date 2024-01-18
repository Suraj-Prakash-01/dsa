#include <iostream>
#include <vector>
using std::cin;
using std::cout;

// Adding a bool operator will limit the output to just one output
int printS(int i, int s, int sum, int arr[], int n)
{
  if (i == n) // Here i is index
  {
    // Condition Satisfied
    if (s == sum)
      return 1;
    // Condition not satisfied
    else
      return 0;
  }

  s += arr[i];
  // Take or Pick condition
  int l = printS(i + 1, s, sum, arr, n);

  s -= arr[i];
  // Not pick Condition
  int r = printS(i + 1, s, sum, arr, n);

  return l + r;
}

int main()
{
  int arr[] = {1, 2, 1};
  int n = 3;
  int sum = 2;
  cout << printS(0, 0, sum, arr, n) << std::endl;
}