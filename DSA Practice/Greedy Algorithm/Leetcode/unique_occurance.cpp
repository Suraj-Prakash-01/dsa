/*  Approach 1  */

class Solution
{
public:
  bool uniqueOccurrences(vector<int> &arr)
  {
    unordered_map<int, int> m;
    // Saving frequency of elements in maps
    for (int i = 0; i < arr.size(); i++)
    {
      m[arr[i]]++;
    }

    unordered_set<int> s;
    for (auto x : m)
    {
      int freq = x.second;
      if (s.find(freq) != s.end())
        return false;
      else
      {
        s.insert(freq);
      }
    }
    return true;
  }
};

/*    Approach 2    */

class Solution
{
public:
  bool uniqueOccurrences(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    vector<int> v;

    for (int i = 0; i < arr.size(); i++)
    {
      int cnt = 1;

      // Count occurrences of the current element
      while (i + 1 < arr.size() && arr[i] == arr[i + 1])
      {
        cnt++;
        i++;
      }
      // Inserting it's count to v
      v.push_back(cnt);
    }
    sort(v.begin(), v.end());

    for (int i = 1; i < v.size(); i++)
    {
      if (v[i] == v[i - 1])
      {
        return false;
      }
    }
    return true;
  }
};