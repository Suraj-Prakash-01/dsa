class Solution
{
public:
  long long largestPerimeter(vector<int> &nums)
  {
    // Sorting the array
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long sum = 0;

    // Finding the sum of all the elements
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
    }

    // Traversing it in reverse till 2nd last element
    for (int i = n - 1; i > 1; i--)
    {
      // If the sum of rest the element  is greater than last element
      // It means the perimeter is valid
      if ((sum - nums[i]) > nums[i])
        return sum;

      // If not, excluding last element from the perimeter
      // And trying with next greatest element
      else
        sum -= nums[i];
    }

    // Returning -1 if no valid perimeter is found
    return -1;
  }
};