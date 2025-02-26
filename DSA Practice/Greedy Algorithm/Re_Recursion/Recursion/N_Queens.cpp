class Solution
{
public:
  void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow,
             vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
  {
    if (col == n)
    {
      ans.push_back(board); // It pushes the array since it already reached the end without error
      return;
    }

    for (int row = 0; row < n; row++)
    {
      // Checking condition where queen cancels the queen
      if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
      {

        // Pick Condition
        board[row][col] = 'Q';                // If it doesn't,then another queen will be placed there
        leftRow[row] = 1;                     // Assigning 1 to show that no other queen can be placed in the same row
        lowerDiagonal[row + col] = 1;         // Assigning 1 to show that no other queen can be placed in the lower diagonal position
        upperDiagonal[n - 1 + col - row] = 1; // Assigning 1 to show that no other queen can be placed in the upper diagonal

        solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); // Recursive call for trying out all positions

        // Not pick condition
        board[row][col] = '.'; // Converting that index value back to '.'
        leftRow[row] = 0;
        lowerDiagonal[row + col] = 0;
        upperDiagonal[n - 1 + col - row] = 0; // n-1 +(col-row) creates a table just opposite to row+col
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans; // Ultimate array to store answer
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
      board[i] = s;
    }

    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
  }
};
