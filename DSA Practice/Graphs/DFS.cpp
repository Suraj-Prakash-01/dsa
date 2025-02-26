class Solution
{
private:
  void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &result)
  {
    // Mark the current node as visited
    visited[node] = 1;
    // Add the current node to the result list
    result.push_back(node);

    // Recursively visit all unvisited adjacent nodes
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        dfs(it, adj, visited, result);
      }
    }
  }

public:
  // Function to return a list containing the DFS traversal of the graph
  vector<int> dfsOfGraph(int V, vector<int> adj[])
  {
    // Initialize visited array and result list
    vector<int> visited(V, 0); // Using vector for better clarity
    vector<int> result;

    // Loop through all nodes to handle disconnected components
    for (int start = 0; start < V; start++)
    {
      if (!visited[start])
      {
        dfs(start, adj, visited, result);
      }
    }

    return result; // Return the complete DFS traversal
  }
};
