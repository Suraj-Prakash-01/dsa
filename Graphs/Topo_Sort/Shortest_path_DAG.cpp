class Solution
{
private:
  void topo(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st)
  {
    vis[node] = 1;
    for (auto it : adj[node])
    {
      int v = it.first;
      if (!vis[v])
        topo(v, adj, vis, st);
    }
    st.push(node); // Push node to stack after all its descendants are processed.
  }

public:
  vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
  {
    // Create the adjacency list.
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    { // Loop over M (number of edges), not N.
      int u = edges[i][0];
      int v = edges[i][1];
      int wt = edges[i][2];
      adj[u].push_back({v, wt});
    }

    // Find the topological sort.
    int vis[N] = {0};
    stack<int> st;

    for (int i = 0; i < N; i++)
    {
      if (!vis[i])
        topo(i, adj, vis, st);
    }

    // Initialize distances to all vertices as infinite.
    vector<int> dist(N, INT_MAX);
    dist[0] = 0; // Assuming node 0 is the source.

    // Process nodes in topological order.
    while (!st.empty())
    {
      int node = st.top();
      st.pop();

      if (dist[node] != INT_MAX)
      { // Only process if the node is reachable.
        for (auto it : adj[node])
        {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v])
          {
            dist[v] = dist[node] + wt;
          }
        }
      }
    }

    // Replace unreachable node distances (still INT_MAX) with -1.
    for (int i = 0; i < N; i++)
    {
      if (dist[i] == INT_MAX)
        dist[i] = -1;
    }

    return dist;
  }
};
