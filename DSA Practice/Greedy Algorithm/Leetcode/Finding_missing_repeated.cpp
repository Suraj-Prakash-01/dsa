/* The Solution class provides a method to find the missing and repeated values in a given grid. */
class Solution
{
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
  {
    int n = grid.size(), miss, rep;
    // Creating a vector to check a number's visit
    vector<int> ans(n * n, 1);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        // To mark a number's visit
        ans[grid[i][j] - 1]--;
      }
    }

    for (int i = 0; i < n * n; i++)
    {
      // If a number visited twice, it will have -1 in vector
      if (ans[i] == -1)
        rep = i + 1;
      // If a number wasn't visited, it will have 1 in vector
      if (ans[i] == 1)
        miss = i + 1;
    }

    return {rep, miss};
  }
};