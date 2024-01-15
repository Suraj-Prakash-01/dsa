#include <iostream>
using std::cin;
using std::cout;

// Finding sum by passing parameters in the function
int parameterized_add(int n, int sum)
{
  if (n < 1)
    // We need to return sum right here since nobody is waiting for it's call
    return sum;
  return parameterized_add(n - 1, sum + n); // Using sum parameter
}

// Finding sum by creating function in a particular manner
int functional_add(int n)
{
  if (n < 1)
    // We don't need to return sum as (n+) part is waiting for it's call
    return 0;
  return n + functional_add(n - 1); // Using functional way
}

int main()
{
  int n, sum = 0;
  cout << "Enter a number: ";
  cin >> n;

  cout << "The parameterized sum of numbers is  " << parameterized_add(n, sum) << std::endl;
  cout << "The functional sum of numbers is  " << functional_add(n) << std::endl;
}