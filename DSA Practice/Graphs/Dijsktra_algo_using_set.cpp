class Solution
{
public:
  // Function to find the shortest distance of all the vertices
  // from the source vertex S using Dijkstra's Algorithm.
  vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
  {
    // Use a set to store pairs of {distance, node}.
    // The set will automatically keep the pairs sorted by distance.
    set<pair<int, int>> st;

    // Initialize the distance vector with a large number (representing infinity).
    vector<int> dist(V, 1e9);

    // Insert the source node with distance 0 into the set.
    st.insert({0, S});
    dist[S] = 0;

    // While there are nodes in the set to process:
    while (!st.empty())
    {
      // Get the node with the smallest distance.
      // st.begin() points to the first element of the set (i.e., the node with the smallest distance).
      auto it = *(st.begin()); // it is a pair {distance, node}
      int node = it.second;    // Extract the node.
      int dis = it.first;      // Extract the distance.

      // Remove this node from the set as it's being processed.
      st.erase(it);

      // Traverse all adjacent nodes (neighbors) of the current node.
      for (auto it : adj[node])
      {
        int adjNode = it[0]; // Adjacent node (neighbor).
        int edgW = it[1];    // Weight of the edge to the adjacent node.

        // If a shorter path to the adjacent node is found:
        if (dis + edgW < dist[adjNode])
        {
          // If the adjacent node was previously in the set, erase it.
          // This ensures that we update the distance with the new, shorter path.
          if (dist[adjNode] != 1e9)
            st.erase({dist[adjNode], adjNode});

          // Update the distance of the adjacent node.
          dist[adjNode] = dis + edgW;

          // Insert the updated {distance, node} pair into the set.
          st.insert({dist[adjNode], adjNode});
        }
      }
    }

    // Return the final distance array containing the shortest distances from source S.
    return dist;
  }
};
