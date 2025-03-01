class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    unordered_map<int, int> mpp;

    for (auto it : nums)
    {
      mpp[it]++;
    }

    for (auto it : mpp)
    {
      if (it.second == 1)
        return it.first;
    }
    return -1;
  }
};

// Can use sorting as well

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i += 2)
    {
      if (nums[i] != nums[i - 1])
        return nums[i - 1];
    }
    return nums[nums.size() - 1];
  }
};

// Can use XOR  -- (A^A^B) = (B^A^A) = (A^B^A) = B

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int ans = 0;
    for (auto it : nums)
      ans ^= it;
    return ans;
  }
};