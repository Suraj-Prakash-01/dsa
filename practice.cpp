#include <iostream>
using std::cin;
using std::cout;

bool checkPalindrome(char arr[], int n)
{
  int s = 0;
  int e = n - 1;
  while (s < e)
  {
    if (arr[s] != arr[e])
      return false;
    else
    {
      s++;
      e--;
    }
  }
  return true;
}

void reverse(char *arr, int n)
{
  int s = 0, e = n - 1;
  while (s <= e)
    std::swap(arr[s++], arr[e--]);
}

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
  int n = getLength(arr);
  cout << "Number of characters in your name is " << n;
  // Calling funtion to reverse the array
  reverse(arr, n);
  cout << "\nThe reverse string is " << arr;

  // To check whether the string is palindrome or not
  cout << "\nCheck palindrome or not :" << checkPalindrome(arr, n) << std::endl;
}