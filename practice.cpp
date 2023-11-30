#include <iostream>
using std::cin;
using std::cout;

int getLength(char arr[])
{
  int count = 0;
  // This counts total number of iterations
  for (int i = 0; arr[i] != '\0'; i++)
    count++;
  return count;
}

int main()
{
  char arr[100];
  cout << "Enter your name :";
  // cin doesn't read words after space,enter or tab
  cin >> arr;
  cout << "Your name is " << arr << std::endl;
  cout << "Number of characters in your name is " << getLength(arr);
}