class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size();
    int j = 0;

    for (int i = 0; i < n; i++)
    {
      // If nums[i] is not 0, swap it with nums[j] and increment j
      if (nums[i] != 0)
      {
        if (i != j)
        { // To remove redundant swaps
          swap(nums[i], nums[j]);
        }
        j++;
      }
    }
  }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int i=0;

//         for(int j=0;j<nums.size();j++){
//             if(nums[j]!=0){
//                 swap(nums[j],nums[i]);
//                 i++;
//             }
//         }
//     }
// };