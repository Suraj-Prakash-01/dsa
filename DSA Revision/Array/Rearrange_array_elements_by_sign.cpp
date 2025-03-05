// Brute Force O(n^2)

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] >= 0)
        pos.push_back(nums[i]);
      if (nums[i] < 0)
        neg.push_back(nums[i]);
    }

    int i = 0, j = 0;
    for (int k = 0; k < n; k += 2)
    {
      nums[k] = pos[i];
      nums[k + 1] = neg[j];
      j++;
      i++;
    }
    return nums;
  }
};

// Efficient O(n) using two pointers

class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int n = nums.size();

    int i = 0, j = 1;
    vector<int> ans(nums.size(), 0);

    for (auto it : nums)
    {
      // If the number is positive, push it at even indexes
      if (it > 0)
      {
        ans[i] = it;
        i += 2;
      }

      // If the number is negative, push it at odd indexes
      else
      {
        ans[j] = it;
        j += 2;
      }
    }
    return ans;
  }
};
