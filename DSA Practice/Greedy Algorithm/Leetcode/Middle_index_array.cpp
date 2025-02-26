class Solution
{
public:
  int findMiddleIndex(vector<int> &nums)
  {
    int n = nums.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      result = result + nums[i];
    }
    int left = 0;
    for (int i = 0; i < n; i++)
    {
      int rigth = result - left - nums[i];
      if (left == rigth)
      {
        return i;
      }
      left += nums[i];
    }
    return -1;
  }
};