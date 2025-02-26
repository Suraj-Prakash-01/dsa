class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int n = digits.size();

    // This loop checks from reverse
    // If the loop doesn't encounter number less than 9 till the end
    // It doesn't return any array
    for (int i = n - 1; i >= 0; i--)
    {
      if (digits[i] < 9)
      {
        digits[i]++;
        return digits;
      }
      digits[i] = 0;
    }

    vector<int> ans;
    // Pushing 1 ahead of pushing all element of digits
    ans.push_back(1);

    // Pushing all elements of digits
    for (int i = 0; i < n; i++)
      ans.push_back(digits[i]);

    return ans;
  }
};