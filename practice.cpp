#include <iostream>
#include <vector>
using std::cin;
using std::cout;

int waveprint(std::vector<int> arr, int nRow, int nCol)
{
  std::vector<int> ans;

  for (int col = 0; col <= nCol; col++)
  {

    if (col & 1)
    {
      // Odd Index -> Bottom to top

      for (int row = nRow - 1; row >= 0; row--)
      {
        ans.push_back(arr[row][col]);
      }
    }

    else
    {
      // 0 or Even Index -> Top to bottom
      for (int row = 0; row < nRow; row++)
      {
        ans.push_back(arr[row][col]);
      }
    }
  }
  return ans;
}
