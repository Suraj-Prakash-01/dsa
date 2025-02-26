class Solution
{
public:
  int findSpecialInteger(vector<int> &arr)
  {
    int n = arr.size();
    int ans = 0;
    int count = 1;
    // To check edge cases
    if (n < 2)
      return arr[0];

    // For counting
    for (int i = 1; i < n; i++)
    {
      if (arr[i - 1] == arr[i])
        count++;
      // If it's not greater than n/4
      else
        count = 1;

      // To return the answer
      if (count > n / 4)
        ans = arr[i];
    }
    return ans;
  }
};