class Solution
{
public:
  // Function to return the adjacency list for each vertex.
  vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
  {
    // Resize the adjacency list to hold V vertices
    vector<vector<int>> adj(V);

    // Traverse the edges and add them to the adjacency list
    for (auto it : edges)
    {
      adj[it.first].push_back(it.second);
      adj[it.second].push_back(it.first);
    }

    return adj;
  }
};
