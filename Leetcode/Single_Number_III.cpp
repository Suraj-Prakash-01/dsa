class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {

    // Storing frequency of elements of nums
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
      mp[nums[i]]++;

    vector<int> ans;

    for (auto it : mp)
    {
      if (it.second == 1) // Pushing the element which has frequency 1
        ans.push_back(it.first);
    }
    return ans;
  }
};