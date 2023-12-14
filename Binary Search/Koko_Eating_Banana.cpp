/* CODE 1*/

class Solution
{
public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int l = 0;
    int r = INT_MAX;
    while (l + 1 < r)
    {
      int m = (l + r) / 2;
      int tmp = 0;
      for (int i = 0; i < piles.size(); i++)
      {
        tmp += (piles[i] / m + (piles[i] % m != 0));
        if (tmp > h)
          break; // prevent overflow
      }
      if (tmp <= h)
        r = m;
      else
        l = m;
    }
    return r;
  }
};

/*  CODE 2*/
class Solution
{
public:
  int findMax(vector<int> &piles)
  {
    int n = piles.size();
    int maxi = INT_MIN;
    // Finding Max value since range will be from 1 to max value
    for (int i = 0; i < n; i++)
      maxi = max(maxi, piles[i]);
    return maxi;
  }

  int TotalHrs(vector<int> &piles, int hrs, int h)
  {
    long long totalH = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
      // Ceil function gives the upper limit of a value in an sorted array
      totalH += ceil((double)piles[i] / (double)hrs);
      if (totalH > h)
        break;
    }

    return totalH;
  }

public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int low = 1, high = findMax(piles);
    while (low <= high)
    {
      int mid = (low + high) / 2;
      long long totalH = TotalHrs(piles, mid, h);
      // looking for more smaller number
      if (totalH <= h)
        high = mid - 1;
      // looking in other region
      else
        low = mid + 1;
    }
    // At the end of the loop, low will point to the lowest rate
    return low;
  }
};