class Solution
{
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    // Create a map to store each integer from the array as a key and its frequency as the value
    map<int, int> mp;
    for (auto it : arr)
      mp[it]++;

    // Create a set of pairs to store the frequency and integer from the map, sorted in non-decreasing order of frequency
    set<pair<int, int>> st;
    for (auto it : mp)
      st.insert({it.second, it.first});

    // Initialize a variable to keep track of the number of unique integers that have a frequency less than or equal to k
    int count = 0;

    // Iterate over the set and remove the first k integers that have a frequency less than or equal to k
    for (auto it : st)
    {
      if (it.first <= k)
      {
        count++;
        k -= it.first;
      }
    }

    // Return the total number of unique integers in the array minus the count variable
    return mp.size() - count;
  }
};