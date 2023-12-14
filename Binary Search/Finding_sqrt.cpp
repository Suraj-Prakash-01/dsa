int floorSqrt(int n)
{
  // Traversing array from 1 to n
  int low = 1, high = n;
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    long long val = mid * mid;

    // Searching for more element
    if (val <= n)
      low = mid + 1;
    else
      high = mid - 1;
  }
  // returning high because at the end of the binary search
  // high will be the answer
  return high;
}
