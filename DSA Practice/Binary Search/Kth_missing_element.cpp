class Solution
{
public:
  int findKthPositive(vector<int> &arr, int k)
  {
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      int missing = arr[mid] - (mid + 1);
      if (missing < k)
        low = mid + 1;
      else
        high = mid - 1;
    }
    // u will understand this one after doing dry run
    // return low+k;
    return k + high + 1;
  }
};