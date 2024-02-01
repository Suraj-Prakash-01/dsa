class Solution
{
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
  {
    vector<bool> ans;                                     // Initializing boolean array
    int m = *max_element(candies.begin(), candies.end()); // Finding max element

    for (auto it : candies)
    {
      if (it + extraCandies >= m)
        ans.push_back(true); // Pushing true if the condition is met
      else
        ans.push_back(false); // Pushing false if the condition is not met
    }

    return ans; // Returning ans
  }
};