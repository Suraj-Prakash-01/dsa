#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int arr[5] = {1, 2, 3, 4, 5};
  char ch[6] = "abcde";

  // This one returns address of the array
  cout << arr << std::endl;
  // This one will return complete array
  cout << ch << std::endl;

  char *c = &ch[0];
  // This one prints the whole character array as well
  cout << c << std::endl;
}