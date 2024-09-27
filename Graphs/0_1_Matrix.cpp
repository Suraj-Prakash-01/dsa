class Solution
{
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
  {
    int n = mat.size();    // Number of rows in the matrix
    int m = mat[0].size(); // Number of columns in the matrix

    vector<vector<int>> vis(n, vector<int>(m, 0));  // Initially, all cells are unvisited
    vector<vector<int>> dist(n, vector<int>(m, 0)); // Initially, distances are set to 0

    // Queue to perform BFS, storing pairs of cell coordinates (row, column) and the distance.
    queue<pair<pair<int, int>, int>> q;

    // Traverse the entire matrix to find all cells with 0.
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mat[i][j] == 0)
        {
          // If the cell contains 0, push it into the queue with distance 0.
          q.push({{i, j}, 0});
          vis[i][j] = 1; // Mark the cell as visited.
        }
      }
    }

    // Define directions for moving in 4 possible directions: up, right, down, left.
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // Perform BFS to find the shortest distance to the nearest 0 for all cells.
    while (!q.empty())
    {
      int r = q.front().first.first;  // Get the current cell's row.
      int c = q.front().first.second; // Get the current cell's column.
      int d = q.front().second;       // Get the current distance from 0.
      q.pop();                        // Remove the front element from the queue.

      // Update the distance of the current cell.
      dist[r][c] = d;

      // Explore all 4 possible directions from the current cell.
      for (int i = 0; i < 4; i++)
      {
        int nrow = r + drow[i]; // Calculate the new row.
        int ncol = c + dcol[i]; // Calculate the new column.

        // Check if the new cell is within bounds and hasn't been visited.
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
        {
          // Push the new cell into the queue with distance incremented by 1.
          q.push({{nrow, ncol}, d + 1});
          vis[nrow][ncol] = 1; // Mark the new cell as visited.
        }
      }
    }

    // Return the final distance matrix.
    return dist;
  }
};
