class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    // vector<int> ans;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] + nums[j] == target)
        {
          // ans.push_back(i);
          // ans.push_back(j);
          return {i, j};
          break;
        }
      }
    }
    // return ans;
    return {};
  }
};

// We can improve this by using hash table to store the original indexes
// And then sort the array and then apply 2 pointer