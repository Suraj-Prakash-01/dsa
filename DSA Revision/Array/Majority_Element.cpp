// Solution 1

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};

//  Solution 2 - Using Extra space to store frequency of all elements

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
      m[nums[i]]++;

    for (auto it : m)
    {
      if (it.second > n / 2)
        return it.first;
    }

    return -1;
  }
};

// Solution 3 - Using linear time complexity and constant space

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {

    int count = 0;
    int ans = 0;

    // Moore's Voting Algorithm
    for (int num : nums)
    {
      if (count == 0)
        ans = num;

      if (num == ans)
        count++;
      else
        count--;
    }
    return ans;
  }
};
