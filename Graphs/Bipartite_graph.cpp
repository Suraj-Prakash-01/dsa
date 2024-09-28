class Solution
{
private:
  // Helper function to check if the component starting from 'start' is bipartite
  bool check(int start, vector<vector<int>> &adj, int color[])
  {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start coloring the first node with color 0

    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      // Traverse all adjacent nodes of the current node
      for (auto adjNode : adj[node])
      {
        // If the adjacent node is not colored, assign the opposite color
        if (color[adjNode] == -1)
        {
          q.push(adjNode);
          color[adjNode] = !color[node]; // Assign opposite color
        }
        // If the adjacent node has the same color as the current node, the graph is not bipartite
        else if (color[adjNode] == color[node])
        {
          return false;
        }
      }
    }
    return true; // No conflict, so it's bipartite
  }

public:
  // Function to check if the graph is bipartite
  bool isBipartite(vector<vector<int>> &graph)
  {
    int V = graph.size(); // Get the number of vertices
    int color[V];         // Array to store colors of vertices
    for (int i = 0; i < V; i++)
    {
      color[i] = -1; // Initialize all vertices as uncolored (-1)
    }

    // Check every component of the graph
    for (int i = 0; i < V; i++)
    {
      // If the node is not colored, check if its component is bipartite
      if (color[i] == -1)
      {
        if (!check(i, graph, color))
        {
          return false; // If any component is not bipartite, return false
        }
      }
    }
    return true; // All components are bipartite, return true
  }
};
