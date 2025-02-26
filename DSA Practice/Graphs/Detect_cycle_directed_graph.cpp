class Solution
{
public:
  // Helper function to perform DFS and check for cycles in a directed graph
  bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
  {
    vis[node] = 1;     // Mark the current node as visited
    pathVis[node] = 1; // Mark the current node as part of the current path (for cycle detection)

    // Traverse through all adjacent nodes (neighbors) of the current node
    for (auto it : adj[node])
    {
      // If the adjacent node is not visited, recursively call dfsCheck on that node
      if (!vis[it])
      {
        // If the recursive call detects a cycle, return true to indicate a cycle
        if (dfsCheck(it, adj, vis, pathVis) == true)
        {
          return true;
        }
      }
      // If the adjacent node is part of the current path (pathVis is 1), it indicates a back edge, hence a cycle
      else if (pathVis[it])
      {
        return true;
      }
    }

    pathVis[node] = 0; // After finishing all adjacent nodes, mark the current node as not being part of the current path
    return false;      // No cycle found in the current DFS traversal
  }

public:
  // Function to detect cycle in a directed graph
  bool isCyclic(int V, vector<int> adj[])
  {
    int vis[V] = {0};     // Array to mark visited nodes
    int pathVis[V] = {0}; // Array to keep track of nodes in the current DFS path

    // Iterate through all the nodes in the graph
    for (int i = 0; i < V; i++)
    {
      // If the node has not been visited, start a DFS from that node
      if (!vis[i])
      {
        // If a cycle is detected during the DFS traversal, return true
        if (dfsCheck(i, adj, vis, pathVis) == true)
        {
          return true;
        }
      }
    }

    // If no cycle is detected in any of the DFS traversals, return false
    return false;
  }
};
