class Solution
{
public:
  int numJewelsInStones(string jewels, string stones)
  {
    // Using unordered map
    unordered_map<int, int> ans;
    int count = 0;

    // For storing frequency of each character
    for (int i = 0; i < stones.size(); i++)
    {
      ans[stones[i]] += 1;
    }

    // For retrieving the frequency of characters all at once
    for (int i = 0; i < jewels.size(); i++)
    {
      count += ans[jewels[i]];
    }

    return count;
  }
};