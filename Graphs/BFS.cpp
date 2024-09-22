class Solution
{
public:
  // Function to return Breadth First Traversal of given graph.
  vector<int> bfsOfGraph(int V, vector<int> adj[])
  {
    // Create a visited array to keep track of visited nodes
    int vis[V] = {0};

    // Mark the starting node as visited
    vis[0] = 1;

    // Create a queue for BFS
    queue<int> q;

    // Enqueue the starting node
    q.push(0);

    // Create a vector to store the BFS traversal
    vector<int> bfs;

    // Perform BFS
    while (!q.empty())
    {
      // Dequeue a node
      int node = q.front();
      q.pop();

      // Add the node to the BFS traversal
      bfs.push_back(node);

      // Explore all adjacent nodes
      for (auto it : adj[node])
      {
        // If an adjacent node is not visited, mark it as visited and enqueue it
        if (!vis[it])
        {
          q.push(it);
          vis[it] = 1;
        }
      }
    }
    return bfs;
  }
};