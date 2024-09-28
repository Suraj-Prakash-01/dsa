class Solution
{
private:
  void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int drow[], int dcol[])
  {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;

    for (int i = 0; i < 4; i++)
    {
      int nrow = row + drow[i];
      int ncol = col + dcol[i];

      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol])
        dfs(nrow, ncol, grid, vis, drow, dcol);
    }
  }

public:
  int numEnclaves(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
      // Traversing Fist column
      if (!vis[i][0] && grid[i][0])
        dfs(i, 0, grid, vis, drow, dcol);

      // Traversing Last column
      if (!vis[i][m - 1] && grid[i][m - 1])
        dfs(i, m - 1, grid, vis, drow, dcol);
    }

    for (int j = 0; j < m; j++)
    {
      // Traversing First Row
      if (!vis[0][j] && grid[0][j])
        dfs(0, j, grid, vis, drow, dcol);

      // Traversing Last Row
      if (!vis[n - 1][j] && grid[n - 1][j])
        dfs(n - 1, j, grid, vis, drow, dcol);
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] && !vis[i][j])
          cnt++;
      }
    }

    return cnt;
  }
};