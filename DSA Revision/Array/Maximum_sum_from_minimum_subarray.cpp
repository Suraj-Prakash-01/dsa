// Using O(n^2)

class Solution
{
public:
  // Function to find pair with maximum sum
  int pairWithMaxSum(vector<int> &arr)
  {
    // Your code goes here
    int n = arr.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      int mini = arr[i];
      int smin = arr[i + 1];
      for (int j = i + 1; j < n; j++)
      {
        if (mini >= arr[j])
        {
          smin = mini;
          mini = arr[j];
        }

        else if (smin > arr[j])
        {
          smin = arr[j];
        }
        int sum = mini + smin;
        maxi = max(maxi, sum);
      }
    }
    return maxi;
  }
};

// Using O(n) -- Choosing 2 consecutive numbers with maximum sum

class Solution
{
public:
  // Function to find pair with maximum sum
  int pairWithMaxSum(vector<int> &arr)
  {
    // Your code goes here
    int n = arr.size();

    int res = arr[0] + arr[1];

    for (int i = 1; i < n - 1; i++)
    {
      res = max(res, arr[i] + arr[i + 1]);
    }
    return res;
  }
};