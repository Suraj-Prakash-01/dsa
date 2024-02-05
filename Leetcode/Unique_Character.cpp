class Solution
{
public:
  int firstUniqChar(string s)
  {
    // Array to store frequency of characters
    int ans[26];

    // Saving frequency of characters in array
    for (int i = 0; i < s.size(); i++)
    {
      ans[s[i] - 'a']++;
    }

    // Checking for unique characters
    for (int i = 0; i < s.size(); i++)
    {
      if (ans[s[i] - 'a'] == 1)
        return i;
    }

    return -1; // Returning -1 if no characters is unique
  }
};