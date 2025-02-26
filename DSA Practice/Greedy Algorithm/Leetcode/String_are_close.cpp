class Solution
{
public:
  bool closeStrings(string word1, string word2)
  {
    int m = word1.size(), n = word2.size(), ans;
    if (m != n)
      return false;

    // Creating an array to store frequency
    vector<int> a(26, 0);
    vector<int> b(26, 0);

    // Counting frequency
    for (auto it : word1)
      a[it - 'a']++;
    for (auto it : word2)
      b[it - 'a']++;

    // Checking if there is any unique character in any of the word or not
    for (int i = 0; i < 26; i++)
    {
      if (a[i] == 0 && b[i] != 0)
        return false;
      if (b[i] == 0 && a[i] != 0)
        return false;
    }

    // Checking if frequency of character are same in both words
    for (int i = 0; i < 26; i++)
    {
      for (int j = 0; j < 26; j++)
      {
        if (a[i] == b[j])
        {
          a[i] = 0;
          b[j] = 0;
        }
      }
    }

    // Last check if any element is left
    for (int i = 0; i < 26; i++)
    {
      if (a[i] != 0 || b[i] != 0)
        return false;
    }
    return true;
  }
};