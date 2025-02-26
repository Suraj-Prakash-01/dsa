class Solution
{
public:
  string frequencySort(string s)
  {
    // Initializing pair to save map data
    vector<pair<int, char>> v;
    map<char, int> mp; // Initializing map
    for (int i = 0; i < s.size(); i++)
    { // Saving frequency of characters
      mp[s[i]]++;
    }
    for (auto i : mp)
    {
      v.push_back({i.second, i.first}); // Pushing map data into pair
    }
    sort(v.rbegin(), v.rend()); // Sorting pair to find the maximum frequency

    string ans; // Initializing empty string to store result

    // Traversing in pair to add characters in "ans"
    for (auto i : v)
    {
      for (int j = 0; j < i.first; j++)
      {
        ans += i.second;
      }
    }
    // Returning final result
    return ans;
  }
};