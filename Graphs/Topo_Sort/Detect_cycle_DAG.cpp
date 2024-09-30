class Solution
{
public:
  // Function to detect cycle in a directed graph using Kahn's Algorithm (BFS).
  bool isCyclic(int V, vector<int> adj[])
  {
    int indegree[V] = {0}; // Array to store in-degree of each vertex.

    // Calculate in-degree of each vertex.
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i])
        indegree[it]++; // Increment in-degree of adjacent vertices.
    }

    queue<int> q; // Queue to store vertices with 0 in-degree.

    // Add all vertices with in-degree 0 to the queue.
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }

    vector<int> topo; // To store the topological order.

    // Process all vertices with in-degree 0.
    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      topo.push_back(node); // Add node to topological order.

      // Reduce the in-degree of adjacent vertices.
      for (auto it : adj[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it); // Add to queue if in-degree becomes 0.
      }
    }

    // If topo size is equal to V, there's no cycle.
    // If topo size is less than V, a cycle exists.
    return topo.size() != V; // Return true if a cycle is detected.
  }
};
