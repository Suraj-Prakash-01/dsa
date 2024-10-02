class Solution
{
public:
  // Function to perform Topological Sort using Kahn's Algorithm (BFS)
  vector<int> topoSort(int V, vector<int> adj[])
  {
    // Array to store the in-degree (number of incoming edges) for each vertex.
    int indegree[V] = {0};

    // Calculate the in-degree for each vertex.
    for (int i = 0; i < V; i++)
    {
      for (auto it : adj[i]) // 'it' represents the adjacent vertex of vertex 'i'.
        indegree[it]++;      // Increment in-degree of vertex 'it' because there is an edge from 'i' to 'it'.
    }

    // Queue to store all vertices with in-degree 0.
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
        indegree[it]--;        // Decrease the in-degree of each adjacent vertex by 1.
        if (indegree[it] == 0) // If in-degree of the adjacent vertex becomes 0, add it to the queue.
          q.push(it);
      }
    }

    return topo;
  }

  // Function to find the order of characters in an alien language dictionary.
  string findOrder(string dict[], int n, int k)
  {
    vector<int> adj[k]; // Adjacency list for the graph.

    // Build the graph by comparing adjacent words.
    for (int i = 0; i < n - 1; i++)
    {
      string s1 = dict[i];
      string s2 = dict[i + 1];

      int len = min(s1.size(), s2.size());
      for (int ptr = 0; ptr < len; ptr++)
      {
        if (s1[ptr] != s2[ptr])
        {
          adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // Create a directed edge from s1[ptr] to s2[ptr].
          break;                                       // Once a difference is found, stop further comparisons for this pair of words.
        }
      }
    }

    // Perform topological sort to find the order of characters.
    vector<int> topo = topoSort(k, adj);
    string ans = "";

    // Convert the topological sort result to characters.
    for (auto it : topo)
      ans += char(it + 'a');

    return ans;
  }
};
