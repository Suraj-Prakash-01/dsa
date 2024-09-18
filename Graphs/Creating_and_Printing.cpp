#include <vector>

using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
  // Create a vector of vectors to store the adjacency list
  vector<vector<int>> ans(n);

  // ans array will store all adjacent nodes corresponding to indices
  for (int i = 0; i < m; i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];

    // Check if indices are within bounds (optional but good practice)
    if (u >= 0 && u < n && v >= 0 && v < n)
    {
      ans[u].push_back(v);
      ans[v].push_back(u);
    }
  }

  // Prepare the final adjacency list output
  vector<vector<int>> adj(n);

  for (int i = 0; i < n; i++)
  {
    adj[i].push_back(i);
    // Entering neighbors
    for (int j = 0; j < ans[i].size(); j++)
    {
      adj[i].push_back(ans[i][j]);
    }
  }

  return adj;
}
