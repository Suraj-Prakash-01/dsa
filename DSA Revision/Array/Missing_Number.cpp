
// Using Formula to find the actual sum if all numbers were there
class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int sum = 0;
    int actual_sum = n * (n + 1) / 2;

    for (auto it : nums)
    {
      sum += it;
    }
    return actual_sum - sum;
  }
};

// Using Find method to find the missing number
class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int n = nums.size();
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
      if (find(nums.begin(), nums.end(), i) == nums.end())
      {
        result = i;
        break;
      }
    }
    return result;
  }
};

// Using O(n^2) instead of O(n) to find the missing number

// Using XOR

class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    int missing = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
      missing ^= i ^ nums[i];
    }
    return missing;
  }
};