class Solution
{
private:
  // Helper function to perform BFS and mark visited land cells
  void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid)
  {
    // Mark the current cell as visited
    vis[row][col] = 1;

    // Queue for BFS traversal
    queue<pair<int, int>> q;
    q.push({row, col});

    // Get dimensions of the grid
    int n = grid.size();
    int m = grid[0].size();

    // Process the queue until it's empty
    while (!q.empty())
    {
      // Get the front of the queue (current cell)
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      // Traverse the neighboring cells
      for (int delrow = -1; delrow <= 1; delrow++)
      {
        for (int delcol = -1; delcol <= 1; delcol++)
        {
          // Skip diagonal neighbors (if both delrow and delcol are odd)
          if (delrow % 2 != 0 && delcol % 2 != 0)
            continue;

          // Calculate neighbor's row and column
          int nrow = row + delrow;
          int ncol = col + delcol;

          // Check if the neighbor is within bounds, is land ('1'), and hasn't been visited
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
          {
            // Mark the neighbor as visited and add it to the queue
            vis[nrow][ncol] = 1;
            q.push({nrow, ncol});
          }
        }
      }
    }
  }

public:
  // Main function to count the number of islands (groups of connected land cells)
  int numIslands(vector<vector<char>> &grid)
  {
    // Get dimensions of the grid
    int n = grid.size();
    int m = grid[0].size();

    // Visited array to track which cells have been processed
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Variable to count the number of islands
    int cnt = 0;

    // Traverse all cells in the grid
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        // If the cell is land ('1') and hasn't been visited yet, it's a new island
        if (!vis[row][col] && grid[row][col] == '1')
        {
          cnt++;                    // Increment the island count
          bfs(row, col, vis, grid); // Perform BFS to mark all connected land cells
        }
      }
    }

    // Return the total number of islands
    return cnt;
  }
};
