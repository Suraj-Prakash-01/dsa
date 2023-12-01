#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

bool checkEqual(int a[26], int b[26])
{
  for (int i = 0; i < 26; i++)
    if (a[i] != b[i])
      return 0;
  return 1;
}
bool checkInclusion(string s1, string s2)
{

  // It makes an array of frequency of characters
  int count1[26] = {0};

  for (int i = 0; i < s1.length(); i++)
  {
    int index = s1[i] - 'a';
    count1[index]++;
  }

  // Traversing element in the string s2
  int i = 0;
  int windowSize = s1.length();
  int count2[26] = {0};

  // Running for first window
  while (i < windowSize && i < s2.length())
  {
    int index = s2[i] - 'a';
    count2[index]++;
    i++;
  }

  if (checkEqual(count1, count2))
    return 1;

  // For other window processes
  while (i < s2.length())
  {
    // Inserting frequency of nxt character(like 4th character)
    char newChar = s2[i];
    int index = newChar - 'a';
    count2[index]++;

    // Deleting frequency of first character(like 1st character)
    char oldChar = s2[i - windowSize];
    index = oldChar - 'a';
    count2[index]--;

    i++; // Increasing i for later iterations

    // Checking in each case whether it meets the requirement or not
    if (checkEqual(count1, count2))
      return 1;
  }
  return 0;
}

int main()
{
  string s1 = "ab";
  string s2 = "eidbaooo";

  cout << checkInclusion(s1, s2);
}