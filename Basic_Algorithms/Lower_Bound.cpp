int lowerBound(vector<int> arr, int n, int x)
{
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    // Maybe an answer
    if (arr[mid] >= x)
    {
      ans = mid;

      // Looking for more small index on left
      high = mid - 1;
    }

    else
    {
      low = mid + 1; // Look for right
    }
  }
  return ans;
}
