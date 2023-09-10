#include <iostream>
#include <limits.h> // Holds INT_MAX  and INT-MIN

int getMin(int num[], int n)
{
  int min = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    if (num[i] < min)
    {
      min = num[i];
    }
  }
  return min;
}

int getMax(int num[], int n)
{
  int max = INT_MIN; // Used to choose first item in the array as max value

  for (int i = 0; i < n; i++)
  {
    if (num[i] > max) // First value becomes the max value
    {
      max = num[i];
    }
  }
  return max;
}

int main()
{
  int size;
  std::cin >> size;

  int num[100];

  // Taking input in array
  for (int i = 0; i < size; i++)
  {
    std::cin >> num[i];
  }

  std::cout << "Maximum value is " << getMax(num, size) << std::endl;
  std::cout << "Minimum value is " << getMin(num, size) << std::endl;
}