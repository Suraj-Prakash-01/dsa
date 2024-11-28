class Solution
{
public:
  // `g` represents the greed factor of each child
  // `s` represents the size of each cookie
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    // Sort the greed factors of children in non-decreasing order
    sort(g.begin(), g.end());
    // Sort the sizes of cookies in non-decreasing order
    sort(s.begin(), s.end());

    // Initialize two pointers for children (`i`) and cookies (`j`)
    int i = 0, j = 0;

    // Iterate through both vectors until one is exhausted
    while (i < g.size() && j < s.size())
    {
      // If the current cookie can satisfy the current child's greed
      if (g[i] <= s[j])
      {
        // Move to the next child
        i++;
        // Move to the next cookie
        j++;
      }
      else
        // If the current cookie cannot satisfy the current child, try the next cookie
        j++;
    }

    // Return the number of content children
    return i;
  }
};