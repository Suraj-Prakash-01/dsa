#include <vector>
#include <queue>
#include <limits.h> // For LLONG_MAX to handle large values of distance

class Solution
{
public:
  int countPaths(int n, vector<vector<int>> &roads)
  {
    // Step 1: Create adjacency list for the graph, where each node stores pairs of (neighbor, edge weight)
    vector<pair<long long, long long>> adj[n];
    for (auto it : roads)
    {
      // Add both directions for an undirected graph
      adj[it[0]].push_back({it[1], it[2]});
      adj[it[1]].push_back({it[0], it[2]});
    }

    // Step 2: Priority queue for Dijkstra's algorithm, to always process the node with the smallest distance first
    // The priority queue stores pairs of (distance, node)
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    // Step 3: Distance vector to store the shortest distance to each node, initialized to LLONG_MAX (infinity)
    vector<long long> dist(n, LLONG_MAX);
    // Ways vector to count the number of ways to reach each node using the shortest path
    vector<long long> ways(n, 0);

    // Step 4: Start from node 0, where the distance is 0 and there is 1 way to start
    dist[0] = 0;
    ways[0] = 1;

    // Step 5: Push the starting node into the priority queue with a distance of 0
    pq.push({0, 0});

    // Step 6: Set a large modulo constant to avoid overflow
    const long long mod = (long long)(1e9 + 7);

    // Step 7: Perform Dijkstra's algorithm
    while (!pq.empty())
    {
      long long dis = pq.top().first;   // Current distance to the node
      long long node = pq.top().second; // Current node
      pq.pop();

      // Skip if we already found a better path
      if (dis > dist[node])
        continue;

      // Step 8: Explore all neighbors of the current node
      for (auto iter : adj[node])
      {
        long long adjNode = iter.first; // Neighboring node
        long long edW = iter.second;    // Weight of the edge to the neighbor

        // Step 9: If a shorter path to adjNode is found, update the distance
        if (dis + edW < dist[adjNode])
        {
          dist[adjNode] = dis + edW;     // Update the shortest distance to adjNode
          ways[adjNode] = ways[node];    // Reset the number of ways to reach adjNode
          pq.push({dis + edW, adjNode}); // Push the updated distance and node to the priority queue
        }
        // Step 10: If an equally short path is found, update the number of ways
        else if (dis + edW == dist[adjNode])
        {
          ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // Add the new number of ways, modulo the constant
        }
      }
    }

    // Step 11: Return the number of ways to reach the last node (n-1), modulo the constant
    return ways[n - 1] % mod;
  }
};
