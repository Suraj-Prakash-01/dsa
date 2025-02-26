class Solution
{
private:
  // Helper function to perform DFS and check if the graph is bipartite
  bool check(int node, int col, vector<vector<int>> &adj, int color[])
  {
    color[node] = col; // Color the current node

    // Traverse all adjacent nodes
    for (auto it : adj[node])
    {
      // If the adjacent node is uncolored, recursively color it with the opposite color
      if (color[it] == -1)
      {
        if (check(it, !col, adj, color) == false)
        {
          return false;
        }
      }
      // If the adjacent node has the same color, the graph is not bipartite
      else if (color[it] == col)
      {
        return false;
      }
    }
    return true; // If no conflict in coloring, return true
  }

public:
  // Function to check if the entire graph is bipartite
  bool isBipartite(vector<vector<int>> &graph)
  {
    int V = graph.size();
    int color[V];

    // Initialize all nodes as uncolored
    for (int i = 0; i < V; i++)
    {
      color[i] = -1;
    }

    // Check for bipartiteness for each component
    for (int i = 0; i < V; i++)
    {
      if (color[i] == -1)
      {
        // If any component is not bipartite, return false
        if (check(i, 0, graph, color) == false)
        {
          return false;
        }
      }
    }
    return true; // All components are bipartite
  }
};
