class Solution
{
public:
  // Function to find the order of courses given their prerequisites.
  vector<int> findOrder(int n, vector<vector<int>> &avl)
  {
    vector<int> adj[n]; // Adjacency list to represent the graph

    // Build the adjacency list from the prerequisite pairs
    // Note: it[1] is the course that depends on it[0]
    for (auto it : avl)
    {
      adj[it[1]].push_back(it[0]); // Add edge from dependent course to prerequisite course
    }

    vector<int> indegree(n, 0); // Initialize in-degree array to count incoming edges
    // Calculate the in-degrees for all vertices (courses)
    for (int i = 0; i < n; i++)
    {
      for (auto it : adj[i])
      {
        indegree[it]++; // Increment in-degree for each prerequisite course
      }
    }

    queue<int> q;     // Queue to store vertices (courses) with in-degree 0 (no prerequisites)
    vector<int> topo; // Vector to store the topological order of courses

    // Add all courses with in-degree 0 to the queue
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i); // Push course to queue if it has no prerequisites
      }
    }

    // Perform BFS to generate the topological order
    while (!q.empty())
    {
      int node = q.front(); // Get the front node (course) from the queue
      q.pop();

      topo.push_back(node); // Add the course to the topological order
      // Decrease the in-degree of all adjacent vertices (courses that depend on this course)
      for (auto it : adj[node])
      {
        indegree[it]--; // Reduce in-degree by 1 for each dependent course
        if (indegree[it] == 0)
        {
          q.push(it); // Push to queue if in-degree becomes 0 (no remaining prerequisites)
        }
      }
    }

    // Check if the topological order includes all courses (detect cycle)
    if (topo.size() == n)
    {
      return topo; // Return valid topological order if all courses are included
    }
    return {}; // Return an empty vector if not all courses can be finished (cycle exists)
  }
};
