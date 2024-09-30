class Solution
{
public:
  // Function to determine if all courses can be finished given prerequisites.
  bool canFinish(int n, vector<vector<int>> &avl)
  {
    vector<int> adj[n]; // Adjacency list to represent the graph

    // Build the adjacency list from the prerequisite pairs
    for (auto it : avl)
    {
      adj[it[0]].push_back(it[1]); // it[0] is a prerequisite for it[1]
    }

    vector<int> indegree(n, 0); // Initialize in-degree array to count incoming edges
    // Calculate the in-degrees for all vertices
    for (int i = 0; i < n; i++)
    {
      for (auto it : adj[i])
      {
        indegree[it]++; // Increment in-degree for each adjacent vertex
      }
    }

    queue<int> q;     // Queue to store vertices with in-degree 0 (no prerequisites)
    vector<int> topo; // Vector to store the topological order of courses

    // Add all vertices with in-degree 0 to the queue
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i); // Push vertex to queue if it has no prerequisites
      }
    }

    // Perform BFS to generate the topological order
    while (!q.empty())
    {
      int node = q.front(); // Get the front node
      q.pop();

      topo.push_back(node); // Add node to the topological order
      // Decrease the in-degree of all adjacent vertices
      for (auto it : adj[node])
      {
        indegree[it]--; // Reduce in-degree by 1 for each neighbor
        if (indegree[it] == 0)
        {
          q.push(it); // Push to queue if in-degree becomes 0
        }
      }
    }

    // If the number of nodes in topological order equals n, return true (no cycle)
    return topo.size() == n; // Return true if all courses can be finished
  }
};
