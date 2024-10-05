class Solution
{
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex S using Dijkstra's Algorithm.
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    // Priority queue to store {distance, node}.
    // Using min-heap to get the node with the smallest distance at the top.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance array to store the shortest distance from the source to each node.
    vector<int> dist(V);

    // Initialize all distances to infinity (or a large number).
    for (int i = 0; i < V; i++)
      dist[i] = 1e9; // Representing infinity as 1e9.

    // Distance of the source node to itself is 0.
    dist[S] = 0;

    // Push the source node into the priority queue with distance 0.
    pq.push({0, S});

    // While there are nodes to process in the priority queue:
    while (!pq.empty())
    {
      // Get the node with the smallest distance.
      int dis = pq.top().first;
      int node = pq.top().second;
      pq.pop();

      // Traverse all adjacent nodes (neighbors) of the current node.
      for (auto it : adj[node])
      {
        int adjNode = it[0];    // Adjacent node (neighbor).
        int edgeWeight = it[1]; // Weight of the edge to the adjacent node.

        // If a shorter path is found to the adjacent node:
        if (dis + edgeWeight < dist[adjNode])
        {
          // Update the distance of the adjacent node.
          dist[adjNode] = dis + edgeWeight;

          // Push the adjacent node into the priority queue with updated distance.
          pq.push({dist[adjNode], adjNode});
        }
      }
    }

    // Return the final distance array containing the shortest distances from source S.
    return dist;
  }
};
