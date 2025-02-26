class Solution
{
private:
  void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int inColor, int delRow[], int delCol[])
  {
    // Color the current pixel in the result image
    ans[row][col] = color;

    // Get the number of rows and columns in the image
    int n = image.size();    // Total number of rows
    int m = image[0].size(); // Total number of columns

    // Loop over 4 possible directions: up, right, down, left
    for (int i = 0; i < 4; i++)
    {
      // Calculate the new row and column indices
      int nrow = row + delRow[i];
      int ncol = col + delCol[i];

      // Check if the new indices are within bounds, the neighboring pixel has the same initial color,
      // and it has not been colored yet in the result image.
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inColor && ans[nrow][ncol] != color)
      {
        // Recursively call DFS to continue filling the connected region
        dfs(nrow, ncol, ans, image, color, inColor, delRow, delCol);
      }
    }
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
  {
    // Get the initial color of the starting pixel
    int inColor = image[sr][sc];

    // Create a copy of the original image to store the result
    vector<vector<int>> ans = image;

    // Arrays to represent the 4 possible directions (up, right, down, left)
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    // Call the DFS function to fill the connected region starting from (sr, sc)
    dfs(sr, sc, ans, image, color, inColor, delRow, delCol);

    // Return the resulting image after flood fill
    return ans;
  }
};
