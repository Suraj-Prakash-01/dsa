class Solution
{
public:
  // DFS function to explore the graph
  void dfs(int node, vector<int> adjLs[], vector<int> &vis)
  {
    // Mark the current node as visited
    vis[node] = 1;
    // Traverse all adjacent nodes
    for (auto it : adjLs[node])
    {
      if (!vis[it])          // If the node is not visited
        dfs(it, adjLs, vis); // Recursive call to visit it
    }
  }

public:
  // Function to find the number of connected components (provinces)
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size(); // Get the number of nodes (cities)
    vector<int> adjLs[n];       // Adjacency list representation

    // Build the adjacency list from the isConnected matrix
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        // If there's a connection and it's not the same node
        if (isConnected[i][j] == 1 && i != j)
        {
          adjLs[i].push_back(j); // Add edge to the list
          adjLs[j].push_back(i); // Since it's undirected, add both ways
        }
      }
    }

    int count = 0;         // Counter for connected components
    vector<int> vis(n, 0); // Visited array initialized to 0

    // Perform DFS for each unvisited node
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {                     // If the node is unvisited
        count++;            // Increment the count for a new province
        dfs(i, adjLs, vis); // Start DFS from this node
      }
    }
    return count; // Return the number of provinces found
  }
};
