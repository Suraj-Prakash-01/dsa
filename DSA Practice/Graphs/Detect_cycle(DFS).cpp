class Solution
{
private:
  bool detect(int src, int parent, vector<int> adj[], int vis[])
  {
    // Mark the current node as visited
    vis[src] = 1;

    // Traverse all adjacent nodes of the current node
    for (auto adjNode : adj[src])
    {
      // If the adjacent node has not been visited, recursively check for a cycle
      if (!vis[adjNode])
      {
        // If a cycle is detected in the recursive call, return true
        if (detect(adjNode, src, adj, vis))
          return true;
      }
      // If the adjacent node is visited and is not the parent of the current node,
      // it means a cycle is present
      else if (adjNode != parent)
      {
        return true; // Cycle detected
      }
    }
    // If no cycle is detected, return false
    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[])
  {
    // Visited array to track whether a node has been visited
    int vis[V] = {0};

    // Traverse all vertices of the graph
    for (int i = 0; i < V; i++)
    {
      // If the vertex is not visited, check for cycle starting from this vertex
      if (!vis[i])
      {
        // Call the detect() function starting from the current node
        // If a cycle is found, return true
        if (detect(i, -1, adj, vis) == true)
          return true;
      }
    }
    // If no cycle is detected in any component of the graph, return false
    return false;
  }
};
