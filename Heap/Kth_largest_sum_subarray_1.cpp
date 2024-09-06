class Solution
{
public:
  int kthLargest(vector<int> &arr, int k)
  {
    // code here
    vector<int> store;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i + 1; j < n; j++)
      {
        sum += arr[j];
        store.push_back(sum);
      }
    }
    sort(store.begin(), store.end());

    return store[store.size() - k];
  }
};