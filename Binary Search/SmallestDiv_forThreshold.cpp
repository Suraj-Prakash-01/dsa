class Solution
{
public:
  int sumByD(vector<int> &arr, int div)
  {
    int sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
      sum += arr[i] / div + (arr[i] % div != 0);
    return sum;
  }

public:
  int smallestDivisor(vector<int> &nums, int threshold)
  {
    int n = nums.size();
    int low = 1;
    // Max element function return the iterator
    // so we use * to dereference it
    int high = *max_element(nums.begin(), nums.end());

    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (sumByD(nums, mid) <= threshold)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return low;
  }
};