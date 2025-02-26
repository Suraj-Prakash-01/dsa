class Solution
{
public:
  void solve(string digits, string output, int index, string mapping[10], vector<string> &ans)
  {
    //  base case
    if (index >= digits.length())
    {
      ans.push_back(output);
      return;
    }

    // processing

    int dig = digits[index] - '0';
    string letterCom = mapping[dig];

    for (int i = 0; i < letterCom.length(); i++)
    {
      output.push_back(letterCom[i]);
      solve(digits, output, index + 1, mapping, ans);
      output.pop_back();
    }
  }

  vector<string> letterCombinations(string digits)
  {
    vector<string> ans;
    if (digits.length() == 0)
    {
      return ans;
    }
    string output = "";
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    //  solve using recursion

    solve(digits, output, 0, mapping, ans);

    return ans;
  }
};