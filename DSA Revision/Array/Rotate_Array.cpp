class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end());       // Reversing the whole thing
    reverse(nums.begin(), nums.begin() + k); // Reversing the first k elements
    reverse(nums.begin() + k, nums.end());   // Reversing the last k elements
  }
};

// Second Approach could be using extra space