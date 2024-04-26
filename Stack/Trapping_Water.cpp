// The concept of this solution is that the water will only be stored in between two bars which has the highest length
// And the smaller bars out of two bars will be the highest level till which water will be trapped

int trap(vector<int> &arr, int n)
{
  // Creating two arrays for storing left and right highest heights
  vector<int> mxLeft(n);
  vector<int> mxRight(n);

  // Initializing first element of array mxLeft to first element of given array
  mxLeft[0] = arr[0];
  // Comparing and filling the array containing max element in the left
  for (int i = 1; i < n; i++)
    mxLeft[i] = max(arr[i], mxLeft[i - 1]);

  // Same as above for finding the biggest element on the right side of the array
  mxRight[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--)
    mxRight[i] = max(arr[i], mxRight[i + 1]);

  // This variable will store the trapped water
  int sum = 0;

  // Loop to find the total trapped water
  // Water will only trapped between the minimum height among two highest bars
  for (int i = 0; i < n; i++)
    sum += min(mxLeft[i], mxRight[i]) - arr[i];

  return sum;
}