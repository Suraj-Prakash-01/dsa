class Solution
{
private:
  void topo(int node, int vis[], stack<int> &st, vector<int> adj[])
  {
    vis[node] = 1; // Mark the current node as visited.

    // Traverse all adjacent vertices of the current node.
    for (auto it : adj[node])
    {
      if (!vis[it])
      { // If the adjacent vertex is not visited, recursively call topo for that vertex.
        topo(it, vis, st, adj);
      }
    }

    st.push(node);
  }

public:
  vector<int> topoSort(int V, vector<int> adj[])
  {
    int vis[V] = {0}; // Initialize the visited array to keep track of visited nodes (0 means not visited).
    stack<int> st;    // Stack to store the topological sort order.

    // Iterate over all vertices of the graph.
    for (int i = 0; i < V; i++)
    {
      if (!vis[i]) // If the vertex 'i' is not visited, call the topo function to process it.
        topo(i, vis, st, adj);
    }

    vector<int> ans; // Vector to store the final topological sort order.
    while (!st.empty())
    {
      ans.push_back(st.top()); // Add the top element of the stack to the result.
      st.pop();                // Remove the top element.
    }

    return ans; // Return the topologically sorted order of vertices.
  }
};
