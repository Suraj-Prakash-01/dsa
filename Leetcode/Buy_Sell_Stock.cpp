/*  Code 1 */
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    if (n <= 1)
    {
      return 0; // No transactions can be performed with 0 or 1 element
    }

    int maxProfit = 0;
    int minPrice = prices[0];

    for (int i = 1; i < n; i++)
    {
      maxProfit = max(maxProfit, prices[i] - minPrice); // Storing profit
      minPrice = min(minPrice, prices[i]);              // Updating minPrice
    }

    return maxProfit;
  }
};

/*  Code 2  */
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int mini = INT_MAX; // Temporary min
    int profit = 0;     // Net profit
    int maxi = 0;       // Temporary max

    for (int i = 0; i < prices.size(); i++)
    {
      if (prices[i] < mini)
      { // Condition to update min value
        mini = prices[i];
      }
      maxi = prices[i] - mini; // Storing profit at that particular interval
      if (profit < maxi)
      {
        profit = maxi; // Updating Profit
      }
    }
    return profit; // Returning profit
  }
};