class Solution
{
public:
  vector<vector<int>> transpose(vector<vector<int>> &matrix)
  {
    int row = matrix.size();
    int col = matrix[0].size();

    // Initialisation of 2D vector
    // This vector is col X row of original matrix
    vector<vector<int>> ans(col, vector<int>(row));

    // We took this way bcz of ans is col X row
    for (int i = 0; i < col; i++)
    {
      for (int j = 0; j < row; j++)
      {
        ans[i][j] = matrix[j][i];
      }
    }
    return ans;
  }
};