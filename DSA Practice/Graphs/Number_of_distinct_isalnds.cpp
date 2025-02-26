class Solution
{
private:
  // Depth First Search (DFS) helper function to explore an island
  // and store the relative positions of its cells
  void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &v, int x, int y)
  {

    int n = grid.size();    // Number of rows
    int m = grid[0].size(); // Number of columns
    vis[row][col] = 1;      // Mark the current cell as visited

    // Store the relative position of the current cell with respect to the starting cell of the island
    v.push_back({row - x, col - y});

    // Direction arrays for moving in 4 directions: up, right, down, left
    int drow[] = {-1, 0, 1, 0}; // Row adjustments
    int dcol[] = {0, 1, 0, -1}; // Column adjustments

    // Explore the 4 possible directions
    for (int i = 0; i < 4; i++)
    {
      int nrow = row + drow[i]; // Calculate new row index
      int ncol = col + dcol[i]; // Calculate new column index

      // Check if the new cell is within bounds, not visited, and is a land cell (1)
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol])
      {
        // Recursively perform DFS for the neighboring land cell
        dfs(nrow, ncol, grid, vis, v, x, y);
      }
    }
  }

public:
  // Function to count the number of distinct islands
  int countDistinctIslands(vector<vector<int>> &grid)
  {
    int n = grid.size();    // Number of rows
    int m = grid[0].size(); // Number of columns

    vector<vector<int>> vis(n, vector<int>(m, 0)); // 2D vector to track visited cells
    set<vector<pair<int, int>>> st;                // Set to store distinct islands represented by relative coordinates

    // Traverse each cell in the grid
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        // If the cell is a land cell and not visited yet
        if (!vis[i][j] && grid[i][j])
        {
          vector<pair<int, int>> v;      // Vector to store the relative positions of the current island cells
          dfs(i, j, grid, vis, v, i, j); // Perform DFS to explore the island
          st.insert(v);                  // Insert the vector into the set to track distinct islands
        }
      }
    }

    // Return the number of distinct islands (size of the set)
    return st.size();
  }
};
