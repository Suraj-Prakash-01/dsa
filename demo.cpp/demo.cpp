#include <iostream>

int main()
{
  int arr[10];
  int size = sizeof(arr) / sizeof(int);

  std::cout << "size of array is " << size << std::endl;
}