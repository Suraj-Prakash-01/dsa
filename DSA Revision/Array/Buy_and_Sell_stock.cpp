// Brute force o(n^2)

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int profit = 0;
    int gain = 0;
    for (int i = 0; i < n; i++)
    {
      int buy = prices[i];
      for (int j = i + 1; j < n; j++)
      {
        if (prices[j] > buy)
          gain = prices[j] - buy;
        profit = max(gain, profit);
      }
    }
    return profit;
  }
};

// Opitimized Solution o(n)

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int mini = INT_MAX; // temporary
    int maxi = 0;
    int profit = 0; // temporary

    for (int i = 0; i < n; i++)
    {
      if (prices[i] < mini)
        mini = prices[i];

      profit = prices[i] - mini;
      maxi = max(maxi, profit);
    }

    return maxi;
  }
};
