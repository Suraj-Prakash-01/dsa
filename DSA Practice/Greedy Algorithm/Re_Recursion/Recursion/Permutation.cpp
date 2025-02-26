/* ----------   Approach 1   ---------*/

class Solution
{
public:
  void recurPermute(int ind, vector<int> &nums, vector<vector<int>> &ans)
  {
    // Base Condition
    if (ind == nums.size())
    {
      ans.push_back(nums); // Pushing the new permuted subset into the ultimate array
      return;
    }

    for (int i = ind; i < nums.size(); i++)
    {
      swap(nums[ind], nums[i]);         // Swapping the elements to form a new order
      recurPermute(ind + 1, nums, ans); // Recursive Call
      swap(nums[ind], nums[i]);         // Swapping the element again to form new permutation
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> ans;    // Ultimate array
    recurPermute(0, nums, ans); // Recursive Call
    return ans;
  }
};

/*-------   Approach 2   ----------*/

class Solution
{
public:
  void permutation(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
  {
    if (ds.size() == nums.size())
    {
      // Pushing permuted array
      ans.push_back(ds);
      return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (!freq[i])
      {                        // If that element is not used
        ds.push_back(nums[i]); // Push that element in ds
        freq[i] = 1;           // Mark frequency as 1 (means it is being used)
        permutation(ds, nums, ans, freq);
        freq[i] = 0;   // Not in use
        ds.pop_back(); // Removing the used element
      }
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> ans; // Ultimate array
    // A temporary array which will store permutations
    // until they are pushed in ultimate array
    vector<int> ds;

    int freq[nums.size()]; // Hash array to check whether number can be used or not
    for (int i = 0; i < nums.size(); i++)
      freq[i] = 0; // Assigning every number to 0 means not touched

    permutation(ds, nums, ans, freq); // Recursive Call
    return ans;
  }
};
