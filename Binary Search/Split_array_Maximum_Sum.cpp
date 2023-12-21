class Solution
{
public:
  int low(vector<int> &arr, int k, int mid)
  {
    int count = 1;
    int add = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      if (add + arr[i] <= mid)
        add += arr[i];

      else
      {
        // Passing to next subarray
        count++;
        // Checking if it exceeds the given no. of subarrays 'k'
        if (count > k || arr[i] > mid)
          return false;
        add = arr[i];
      }
    }
    return true;
  }

public:
  int splitArray(vector<int> &nums, int k)
  {
    int s = 0, sum = 0;
    // To apply binary search on search space 0 to sum
    for (int i = 0; i < nums.size(); i++)
      sum += nums[i];

    int e = sum, ans = -1;

    while (s <= e)
    {
      int mid = s + (e - s) / 2;

      if (low(nums, k, mid))
      {
        ans = mid;
        // Still looking for answer in left
        e = mid - 1;
      }
      else
        s = mid + 1;
    }
    return ans;
  }
};