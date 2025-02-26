class Solution
{
public:
  // Function returns the second
  // largest elements
  int getSecondLargest(vector<int> &arr)
  {

    int mone = INT_MIN;
    int mtwo = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] > mone)
      {
        mtwo = mone;
        mone = arr[i];
      }
      else if (arr[i] > mtwo && arr[i] != mone)
        mtwo = arr[i];
    }
    return mtwo == INT_MIN ? -1 : mtwo;
  }
};