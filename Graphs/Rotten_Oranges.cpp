class Solution
{
public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    // Get the dimensions of the grid
    int n = grid.size();    // number of rows
    int m = grid[0].size(); // number of columns

    // Queue to store the position of rotten oranges and the time taken to rot
    queue<pair<pair<int, int>, int>> q;

    // Visited array to track which cells have been processed
    int vis[n][m];

    // Initialize the visited array and enqueue all initially rotten oranges
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 2)
        {                      // If orange is rotten
          q.push({{i, j}, 0}); // Enqueue with initial time 0
          vis[i][j] = 2;       // Mark as visited (rotting state)
        }
        else
          vis[i][j] = 0; // Mark as not visited
      }
    }

    // Directions for moving in 4 possible directions (up, right, down, left)
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // Variable to track the maximum time taken to rot all oranges
    int tm = 0;

    // Process the queue (BFS approach)
    while (!q.empty())
    {
      // Get the front of the queue
      int r = q.front().first.first;  // Current row
      int c = q.front().first.second; // Current column
      int t = q.front().second;       // Time taken to rot the current orange
      q.pop();                        // Remove from queue

      // Traverse in 4 possible directions
      for (int i = 0; i < 4; i++)
      {
        int nrow = r + drow[i]; // New row
        int ncol = c + dcol[i]; // New column
        tm = max(tm, t);        // Update the maximum time taken

        // Check if the new position is within bounds, if it's a fresh orange and not visited
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
        {
          q.push({{nrow, ncol}, t + 1}); // Add the fresh orange to the queue with time incremented
          vis[nrow][ncol] = 2;           // Mark it as rotten
        }
      }
    }

    // After processing all rotten oranges, check if any fresh oranges are left
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1 && vis[i][j] != 2) // Fresh orange that never rotted
          return -1;                           // Impossible to rot all oranges
      }
    }

    // Return the total time taken to rot all oranges
    return tm;
  }
};
