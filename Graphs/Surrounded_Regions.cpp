class Solution
{
private:
  // Depth First Search (DFS) to explore all connected 'O's
  void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis, int drow[], int dcol[])
  {
    // Mark the current cell as visited
    vis[row][col] = 1;
    int n = board.size();    // Number of rows in the board
    int m = board[0].size(); // Number of columns in the board

    // Explore the four possible directions (up, right, down, left)
    for (int i = 0; i < 4; i++)
    {
      int nrow = row + drow[i]; // New row index
      int ncol = col + dcol[i]; // New column index

      // Check if the new position is within bounds, not visited, and is 'O'
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
      {
        dfs(nrow, ncol, board, vis, drow, dcol); // Recursive call to DFS
      }
    }
  }

public:
  // Main function to solve the problem
  void solve(vector<vector<char>> &board)
  {
    int n = board.size(); // Number of rows in the board
    if (n == 0)
      return;                // If the board is empty, return
    int m = board[0].size(); // Number of columns in the board

    // Initialize the visited matrix to keep track of visited cells
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Direction arrays for moving in 4 possible directions
    int drow[] = {-1, 0, 1, 0}; // Up, right, down, left
    int dcol[] = {0, 1, 0, -1};

    // Traversing the first row and last row
    for (int j = 0; j < m; j++)
    {
      // Traversing the first row
      if (!vis[0][j] && board[0][j] == 'O')
      {
        dfs(0, j, board, vis, drow, dcol); // Start DFS if 'O' is found
      }

      // Traversing the last row
      if (!vis[n - 1][j] && board[n - 1][j] == 'O')
      {
        dfs(n - 1, j, board, vis, drow, dcol); // Start DFS if 'O' is found
      }
    }

    // Traversing the first column and last column
    for (int i = 0; i < n; i++)
    {
      // Traversing the first column
      if (!vis[i][0] && board[i][0] == 'O')
      {
        dfs(i, 0, board, vis, drow, dcol); // Start DFS if 'O' is found
      }

      // Traversing the last column
      if (!vis[i][m - 1] && board[i][m - 1] == 'O')
      {
        dfs(i, m - 1, board, vis, drow, dcol); // Start DFS if 'O' is found
      }
    }

    // After DFS, mark all unvisited 'O's as 'X'
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        // Convert unvisited 'O's to 'X'
        if (!vis[i][j] && board[i][j] == 'O')
        {
          board[i][j] = 'X';
        }
      }
    }
  }
};
