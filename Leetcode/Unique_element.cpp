class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      ans = ans ^ nums[i];
    }
    return ans;
  }
};

/* CODE 2*/

class Solution
{
public:
  int singleNumber(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i += 2)
    {
      if (arr[i] != arr[i + 1])
        return arr[i];
    }
    // dummy return
    return "Suraj";
  }
}