class Solution
{
public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                   pair<int, int> destination)
  {
    // If source and destination are the same
    if (source == destination)
      return 0;

    // Initialize queue for BFS
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();

    // Distance array initialized to a large value
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;

    // Push the source node with distance 0
    q.push({0, {source.first, source.second}});

    // Direction vectors for moving in the grid (up, right, down, left)
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
      auto it = q.front();
      q.pop();

      int dis = it.first;
      int r = it.second.first;
      int c = it.second.second;

      // Explore all 4 directions
      for (int i = 0; i < 4; i++)
      {
        int newr = r + dr[i];
        int newc = c + dc[i];

        // Check if the new cell is within bounds, is traversable (grid[newr][newc] == 1), and gives a shorter path
        if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])
        {
          dist[newr][newc] = dis + 1;

          // If the destination is reached
          if (newr == destination.first && newc == destination.second)
            return dis + 1;

          // Push the new cell into the queue
          q.push({dis + 1, {newr, newc}});
        }
      }
    }

    // If destination cannot be reached
    return -1;
  }
};
