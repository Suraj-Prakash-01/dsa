class Solution
{
public:
  bool check(char c)
  {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }
  bool halvesAreAlike(string s)
  {
    int count = 0, n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
      if (check(s[i]))
        count++;
      if (check(s[n - i - 1]))
        count--;
    }
    return count == 0;
  }
};