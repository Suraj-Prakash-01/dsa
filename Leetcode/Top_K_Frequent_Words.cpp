class Solution
{
public:
  static bool compare(pair<int, string> &a, pair<int, string> &b)
  {
    // If frequency of two word is same, put in lexicographical order
    if (a.first == b.first)
      return a.second < b.second;

    // else compare on the basis of their freq
    else
      return a.first > b.first;
  }

  vector<string> topKFrequent(vector<string> &words, int k)
  {
    int n = words.size();

    unordered_map<string, int> mp;
    for (auto x : words)
      mp[x]++;

    vector<pair<int, string>> v;

    for (auto x : mp)
      v.push_back({x.second, x.first});

    // Sort the vector using the above defined compare function
    sort(v.begin(), v.end(), compare);

    vector<string> ans;
    for (int i = 0; i < v.size() && k != 0; i++)
    {
      ans.push_back(v[i].second);
      k--;
    }

    return ans;
  }
};