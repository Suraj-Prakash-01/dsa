class Solution
{
public:
  int maxLengthBetweenEqualCharacters(string s)
  {
    int n = s.length();
    int first, last, maxi = -1;

    for (int i = 0; i < n; i++)
    {
      first = s.find(s[i]);               // Finding first occurance in the string
      last = s.rfind(s[i]);               // Finding last occurance in the string
      maxi = max(maxi, last - first - 1); // Looking for longest substring
    }
    return maxi;
  }
};