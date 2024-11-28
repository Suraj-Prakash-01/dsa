class Solution
{
public:
  // Function to determine if you can reach the last index of the array
  // `nums` represents the maximum jump length from each position
  bool canJump(vector<int> &nums)
  {
    // Initialize the farthest index that can be reached
    int maxIndex = 0;

    // Iterate through each position in the `nums` array
    for (int i = 0; i < nums.size(); i++)
    {
      // If the current index is beyond the farthest reachable index, return false
      if (i > maxIndex)
        return false;

      // Update the farthest reachable index
      maxIndex = max(maxIndex, i + nums[i]);
    }

    // If the loop completes, it means the last index is reachable
    return true;
  }
};