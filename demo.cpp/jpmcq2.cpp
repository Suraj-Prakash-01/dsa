#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;

int duplicate(int arr[], int n)
{
  // To initialize an integer for comparing values
  int i = 0;

  for (int j = 0; j < n; j++)
  {
    // If it's not equal, then it is unique element
    if (arr[i] != arr[j])
    {
      // To count number of unique element
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

int print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int arr[] = {1, 2, 2, 3, 3, 4, 5, 6, 8, 8};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "The number of unique elements in sorted array are " << duplicate(arr, n) << std::endl;
  print(arr, n);
}

int compress(std::vector<char> &chars)
{
  int i = 0;
  int ansIndex = 0;
  int n = chars.size();

  while (i < n)
  {
    // Initialising j so that we can compare it with i index
    int j = i + 1;
    while (j <= n && chars[i] == chars[j])
      j++;

    // To store old character
    chars[ansIndex++] = chars[i];

    int count = j - i;

    if (count > 1)
    {
      // To convert counting into single digit and saving in answer
      string cnt = std::to_string(count);
      for (char ch : cnt)
        chars[ansIndex++] = ch;
    }
    // redirecting the pointer to j
    i = j;
  }
  return ansIndex;
}