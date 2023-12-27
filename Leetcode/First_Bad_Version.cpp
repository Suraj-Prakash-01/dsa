// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
  int firstBadVersion(int n)
  {
    int ans = n;
    int low = 1, high = n;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (isBadVersion(mid))
      {
        ans = mid;      // Saving the answer
        high = mid - 1; // Lookinng for furthur ans
      }
      else
        low = mid + 1; // Trimming left search space
    }
    return ans;
  }
};