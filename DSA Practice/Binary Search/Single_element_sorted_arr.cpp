class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    int n = nums.size(), high = n - 2, low = 1;
    // considering edge cases
    if (n == 1)
      return nums[0];
    if (nums[0] != nums[1])
      return nums[0];
    if (nums[n - 1] != nums[n - 2])
      return nums[n - 1];

    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        return nums[mid];

      // We are in left
      if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        low = mid + 1;

      // We are on the right
      else
        high = mid - 1;
    }
    return -1;
  }
};