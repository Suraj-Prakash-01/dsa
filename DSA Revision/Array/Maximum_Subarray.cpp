// Solution 1 - Using 2 loops for making an array and one for counting sum

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        int sum = 0;

        for (int k = i; k <= j; k++)
        {
          sum += nums[k];
        }
        maxi = max(sum, maxi);
      }
    }
    return maxi;
  }
};

// Solution 2  - Using 2 loops for making an array and adding while doing so

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i; j < n; j++)
      {
        sum += nums[j];
        maxi = max(sum, maxi);
      }
    }
    return maxi;
  }
};

// Solution 3 - Using Kadane's Algorithm for O(n) time complexity

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    long long maxi = LONG_MIN;
    long long sum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      sum += nums[i]; // Adding the result

      // Comparing the resultant sum and maxi
      maxi = max(maxi, sum);

      // If at any point, the sum goes less than 0, we exclude it
      // as it is only going to reduce the sum when added
      if (sum < 0)
        sum = 0;
    }
    return maxi;
  }
};