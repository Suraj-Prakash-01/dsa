class Solution
{
public:
  vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
  {
    // Create adjacency list for the graph
    // Each node points to the list of nodes it's connected to
    vector<int> adj[N];
    for (auto it : edges)
    {
      // Since the graph is undirected, add both directions
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }

    // Distance array to store the shortest path distance from the source
    // Initialize all distances to a very large value (infinity)
    int dist[N];
    for (int i = 0; i < N; i++)
      dist[i] = 1e9;

    // The distance to the source itself is 0
    dist[src] = 0;

    // Queue for performing BFS (Breadth-First Search)
    queue<int> q;

    // Start BFS with the source node
    q.push(src);
    while (!q.empty())
    {
      int node = q.front(); // Get the current node from the front of the queue
      q.pop();              // Remove the node from the queue

      // Traverse all adjacent nodes (neighbors) of the current node
      for (auto it : adj[node])
      {
        // If the current path gives a shorter distance, update it
        if (dist[node] + 1 < dist[it])
        {
          dist[it] = 1 + dist[node]; // Update the shortest distance for this node
          q.push(it);                // Push the neighbor into the queue for further exploration
        }
      }
    }

    // Result vector to store the final shortest distances
    vector<int> ans(N, -1); // Initialize with -1, meaning no path found initially

    // Copy the computed distances into the result array
    for (int i = 0; i < N; i++)
    {
      if (dist[i] != 1e9) // If the node is reachable from the source
        ans[i] = dist[i]; // Store the distance
    }

    return ans; // Return the result array with the shortest paths
  }
};
