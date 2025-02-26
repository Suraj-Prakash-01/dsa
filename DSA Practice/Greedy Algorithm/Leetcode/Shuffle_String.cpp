// Approach !

class Solution
{
public:
  string restoreString(string s, vector<int> &indices)
  {
    string ans = "";
    map<int, char> mpp;
    for (int i = 0; i < indices.size(); i++)
    {
      mpp[indices[i]] = s[i];
    }

    for (int i = 0; i < s.length(); i++)
    {
      ans.push_back(mpp[i]);
    }
    return ans;
  }
};

// Approach 2

class Solution
{
public:
  string restoreString(string s, vector<int> &indices)
  {
    string result(s.length(), 0);
    for (int i = 0; i < s.length(); ++i)
    {
      result[indices[i]] = s[i];
    }
    return result;
  }
};