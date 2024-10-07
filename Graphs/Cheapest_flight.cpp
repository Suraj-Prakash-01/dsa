class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    // Step 1: Create an adjacency list to store flight connections and their costs.
    vector<pair<int, int>> adj[n]; // 'adj' is an array of vectors where each index represents a city.
    for (auto it : flights)
    {
      adj[it[0]].push_back({it[1], it[2]}); // it[0] is the source city, it[1] is the destination, and it[2] is the cost.
    }

    // Step 2: Initialize a queue for BFS traversal where each element is (stops, (current city, current cost)).
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}}); // Start with 0 stops from the source city with a cost of 0.

    // Step 3: Create a distance vector initialized to a large value (infinity) to track the minimum cost to reach each city.
    vector<int> dist(n, 1e9); // 1e9 is a large number representing infinity.
    dist[src] = 0;            // The cost to reach the source city from itself is 0.

    // Step 4: Perform a BFS traversal over the graph to find the cheapest flight.
    while (!q.empty())
    {
      auto it = q.front();
      q.pop();

      int stops = it.first;        // Current number of stops taken.
      int node = it.second.first;  // Current city (node).
      int cost = it.second.second; // Current cost to reach this city.

      // If the number of stops exceeds the allowed limit 'k', skip further processing.
      if (stops > k)
        continue;

      // Step 5: Explore all neighboring cities from the current city.
      for (auto iter : adj[node])
      {
        int adjNode = iter.first; // Neighboring city (adjacent node).
        int edW = iter.second;    // Edge weight or cost to travel to the neighboring city.

        // If a cheaper path to 'adjNode' is found with the current cost and within allowed stops, update it.
        if (cost + edW < dist[adjNode] && stops <= k)
        {
          dist[adjNode] = cost + edW;                 // Update the minimum cost to reach 'adjNode'.
          q.push({stops + 1, {adjNode, cost + edW}}); // Push the new state (stops+1, adjNode, updated cost) to the queue.
        }
      }
    }

    // Step 6: If the destination city is unreachable, return -1.
    if (dist[dst] == 1e9)
      return -1;      // If 'dist[dst]' is still infinity, no valid path was found.
    return dist[dst]; // Return the minimum cost to reach the destination city.
  }
};
