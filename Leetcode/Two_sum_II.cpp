class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    // Two Pointer Approach
    for (int i = 0, j = numbers.size() - 1; i < numbers.size() && j >= 0;)
    {
      int sum = numbers[i] + numbers[j];
      if (sum == target)
        return vector<int>{i + 1, j + 1};
      else if (sum < target)
        i++;
      else
        j--;
    }
    return vector<int>{};
  }
};