class Solution
{
public:
  bool possible(vector<int> &bloomDay, int day, int m, int k)
  {
    int cnt = 0;
    int nf = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
      if (bloomDay[i] <= day)
        cnt++;
      else
      {
        // For adjacent cases
        nf += cnt / k;
        cnt = 0;
      }
    }
    // TO find no. of bouquets
    nf += cnt / k;
    return nf >= m;
  }

public:
  int minDays(vector<int> &bloomDay, int m, int k)
  {
    long long val = m * 1LL * k * 1LL;
    // Edge Case
    if (val > bloomDay.size())
      return -1;
    int mini = INT_MAX, maxi = INT_MIN;

    for (int i = 0; i < bloomDay.size(); i++)
    {
      mini = min(mini, bloomDay[i]);
      maxi = max(maxi, bloomDay[i]);
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (possible(bloomDay, mid, m, k))
        high = mid - 1;
      else
        low = mid + 1;
    }
    return low;
  }
};