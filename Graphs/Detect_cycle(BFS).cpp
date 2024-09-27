class Solution
{
private:
  // Helper function to detect if there is a cycle starting from a given source node.
  // It uses BFS traversal to detect cycles in an undirected graph.
  bool detect(int src, vector<int> adj[], int vis[])
  {
    // Queue stores pairs of {current node, parent node}
    queue<pair<int, int>> q;
    q.push({src, -1}); // Push the source node with parent as -1 (since it has no parent)
    vis[src] = 1;      // Mark the source node as visited

    // Perform BFS
    while (!q.empty())
    {
      int node = q.front().first;    // Current node
      int parent = q.front().second; // Parent of the current node
      q.pop();                       // Remove the front element from the queue

      // Traverse all adjacent nodes of the current node
      for (auto adjNode : adj[node])
      {
        // If the adjacent node has not been visited, visit it
        if (!vis[adjNode])
        {
          q.push({adjNode, node}); // Push the adjacent node with the current node as its parent
          vis[adjNode] = 1;        // Mark the adjacent node as visited
        }
        // If the adjacent node is visited and it is not the parent of the current node,
        // then a cycle is detected.
        else if (adjNode != parent)
        {
          return true; // Cycle detected
        }
      }
    }
    // If no cycle is detected, return false
    return false;
  }

public:
  // Function to detect cycle in an undirected graph.
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
        if (detect(i, adj, vis) == true) // If cycle is found
          return true;                   // Return true if a cycle is detected
      }
    }
    // If no cycle is detected in the graph, return false
    return false;
  }
};
