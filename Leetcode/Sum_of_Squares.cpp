class Solution
{
public:
  int sumOfSquares(vector<int> &nums)
  {
    int n = nums.size(); // Finding size of the array
    int sum = 0;         // Initializing sum

    for (int i = 0; i < n; i++)
    {
      // If it follows the condition n%i+1==0, then adding square of arr[i]
      if (n % (i + 1) == 0)
        sum += nums[i] * nums[i];
    }

    // Returning sum
    return sum;
  }
};