class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> mp;
    string temp;
    for (const string &s : strs)
    {
      // we will sort every string so that I can know the anagrams and this will be the key
      temp = s;
      sort(temp.begin(), temp.end());

      // here we check If this key found before or we should add it
      if (mp.find(temp) == mp.end())
      {
        mp[temp] = {s};
      }
      else
      {
        mp[temp].push_back(s);
      }
    }

    // here we get the groups of angrams in a verctor and return them
    vector<vector<string>> ans;
    for (const auto &it : mp)
    {
      ans.push_back(it.second);
    }
    return ans;
  }
};