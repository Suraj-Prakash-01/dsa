/*  Approach 1*/

// class Solution {
// public:
//     int maxProductDifference(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         return nums[n-1]*nums[n-2] - nums[0]*nums[1];
//     }
// };

/* Approach 2 */

class Solution
{
public:
  int maxProductDifference(vector<int> &nums)
  {
    int n = nums.size();
    int mini = INT_MAX, sec_mini;
    int maxi = INT_MIN, sec_maxi;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] > maxi)
      {
        sec_maxi = maxi;
        maxi = nums[i];
      }

      else
      {
        // Considering edge case if nums[i]<maxi but
        // greater than sec_maxi
        sec_maxi = max(nums[i], sec_maxi);
      }

      if (nums[i] < mini)
      {
        sec_mini = mini;
        mini = nums[i];
      }

      else
      {
        // Considering edge cases same as maxi
        sec_mini = min(nums[i], sec_mini);
      }
    }
    return maxi * sec_maxi - mini * sec_mini;
  }
};