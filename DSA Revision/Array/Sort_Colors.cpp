// Solution 1 - Sort the array
// Solution 2  - count the number of 0's, 1's and 2's

// Solution 3 -  Swap elements in original array

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int n = nums.size();
    int zero = 0, two = n - 1;

    for (int i = 0; i <= two; i++)
    {
      if (nums[i] == 0)
      {
        swap(nums[i], nums[zero]);
        zero++;
      }
      else if (nums[i] == 2)
      {
        swap(nums[i], nums[two]);
        two--;
        i--; // Decrement i to check the swapped element to recheck swapped values
      }
    }
  }
};
