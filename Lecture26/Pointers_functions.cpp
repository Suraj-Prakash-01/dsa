#include <iostream>
using std::cin;
using std::cout;

void print(int *p)
{
  cout << *p << std::endl;
}

void update(int *p)
{
  // This change will only be seen in the function
  // p = p + 1;
  // cout << "Inside " << p << std::endl;
  *p = *p + 1; // This will change the value from the address
}

int getSum(int *arr, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }
  return sum;
}

int main()
{
  int value = 5;
  int *p = &value;

  cout << "Before " << *p << std::endl;
  update(p);
  cout << "After " << *p << std::endl;

  int arr[6] = {1, 2, 3, 4, 5, 6};
  // We are passing a part of array
  cout << "Sum is " << getSum(arr + 3, 3) << std::endl;
}