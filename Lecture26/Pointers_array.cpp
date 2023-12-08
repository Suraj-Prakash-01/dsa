#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int arr[10];
  // The name "array" points to the address of the array
  // Both will point the same address
  /*
  cout << "Address of first memory block is " << arr << std::endl;
  cout << "Address of first memory block is " << &arr[0] << std::endl;
  */

  int temp[10];
  cout << sizeof(temp) << std::endl;

  int *ptr = &temp[0];
  cout << sizeof(ptr) << std::endl;
}