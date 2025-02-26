class Solution
{
public:
  vector<int> findErrorNums(vector<int> &nums)
  {
    vector<int> ans(nums.size() + 1, 0);

    // Variable to store missing and duplicate numbers
    int miss, dup;

    // Saving the frequency of every number in the array
    for (auto it : nums)
      ans[it]++;

    for (int i = 0; i < nums.size() + 1; i++)
    {
      if (ans[i] == 2)
        dup = i; // If frequency is 2, that means it's duplicate
      if (ans[i] == 0)
        miss = i; // If the frequency of 0, it is missing
    }
    // Returning the answer
    return {dup, miss};
  }
};