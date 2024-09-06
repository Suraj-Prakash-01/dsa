class Solution
{
public:
  // Function to return the minimum cost of connecting the ropes.
  long long minCost(vector<long long> &arr)
  {
    // Create a min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (auto i : arr)
      pq.push(i);

    long long cost = 0;
    while (pq.size() > 1)
    {
      long long a = pq.top();
      pq.pop();

      long long b = pq.top();
      pq.pop();

      cost += a + b;
      pq.push(a + b);
    }
    return cost;
  }
};