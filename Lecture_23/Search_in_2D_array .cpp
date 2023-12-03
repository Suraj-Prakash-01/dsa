class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int row = matrix.size();
    int column = matrix[0].size();

    // Finding starting and ending index
    int s = 0;
    int e = row * column - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {

      int element = matrix[mid / column][mid % column];

      if (element == target)
        return 1;

      if (target > element)
        s = mid + 1;

      else
        e = mid - 1;

      mid = s + (e - s) / 2;
    }
    return 0;
  }
};