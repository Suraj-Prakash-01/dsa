class Solution
{
public:
  // This function checks if a given integer is a perfect square
  bool isPerfectSquare(int num)
  {
    // If the number is 0 or 1, it is a perfect square
    if (num == 0 || num == 1)
      return true;

    // Initialize the low and high bounds for the binary search
    int low = 1;
    int high = num;

    // Continue the binary search while the low bound is less than or equal to the high bound
    while (low <= high)
    {
      // Calculate the middle index between the low and high bounds
      int mid = low + (high - low) / 2;

      // Check if the number is a perfect square
      // If the remainder of the division is 0 and the middle index is equal to the integer divided by the middle index
      if (num % mid == 0 && mid == num / mid)
      {
        // Return true
        return true;
      }
      // If the middle index is less than the integer divided by the middle index
      else if (mid < num / mid)
      {
        // Move the low bound to the right of the middle index
        low = mid + 1;
      }
      // If the middle index is greater than the integer divided by the middle index
      else
      {
        // Move the high bound to the left of the middle index
        high = mid - 1;
      }
    }

    // If the binary search ends and no perfect square is found, return false
    return false;
  }
};