class Solution
{
public:
  // Function to return a list containing vertices in Topological order using Kahn's Algorithm (BFS).
  vector<int> topoSort(int V, vector<int> adj[])
  {
    // Array to store the in-degree (number of incoming edges) for each vertex.
    int indegree[V] = {0};

    // Calculate the in-degree for each vertex.
    // Traverse the adjacency list for each vertex and increment the in-degree for its adjacent vertices.
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i]) // 'it' represents the adjacent vertex of vertex 'i'.
        indegree[it]++;      // Increment in-degree of vertex 'it' because there is an edge from 'i' to 'it'.
    }

    // Queue to store all vertices with in-degree 0 (i.e., vertices with no dependencies).
    queue<int> q;

    // Add all vertices with in-degree 0 to the queue.
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0) // If in-degree of vertex 'i' is 0, add it to the queue.
        q.push(i);
    }

    // Vector to store the topological sort order.
    vector<int> topo;

    // Perform BFS.
    while (!q.empty())
    {
      int node = q.front(); // Get the front node from the queue.
      q.pop();              // Remove the node from the queue.

      topo.push_back(node); // Add the node to the topological sort order.

      // Traverse all adjacent vertices of the current node.
      for (auto it : adj[node])
      {
        indegree[it]--;        // Decrease the in-degree of each adjacent vertex by 1 (as the current node has been processed).
        if (indegree[it] == 0) // If in-degree of the adjacent vertex becomes 0, add it to the queue.
          q.push(it);
      }
    }

    return topo; // Return the topologically sorted order.
  }
};
