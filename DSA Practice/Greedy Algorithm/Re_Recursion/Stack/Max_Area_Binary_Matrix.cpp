/* The concept behind this solution is that we create a vector of each row and treat it as a vector array for histogram
  Then we find the maximum area in that histogram and after that we add the previous array to the next row accordingly
  and update the  vector array and then again find it's maximum area
  And lastly compare the new Area with the previous and update the maximum area out of those two
  After the final loop ends, we get the maximum area in the matrix
*/

vector<int> nearestSmallestToLeft(vector<int> &arr, int n)
{
  // Extra space for storing indexes of smallest element on the left side
  vector<int> left;
  stack<pair<int, int>> st;
  // Making a pseudo index to aid when finding the width for maximu area
  int pseudoIndex = -1;

  for (int i = 0; i < n; i++)
  {
    // If the stack is empty
    if (st.empty())
      left.push_back(pseudoIndex);

    // If the top element of stack is smaller than the current element of the array
    else if (!st.empty() && st.top().first < arr[i])
      left.push_back(st.top().second);

    // If the top element of the stack is not smallter than  the current element of the array
    else if (!st.empty() && st.top().first >= arr[i])
    {
      // Popping elements of the stack until we find the smaller element or stack becomes empty
      while (!st.empty() && st.top().first >= arr[i])
        st.pop();

      // If the stack becomes empty
      if (st.empty())
        left.push_back(pseudoIndex);

      // If stack is not empty and we find a smaller element
      else
        left.push_back(st.top().second);
    }
    // Pushing the current element in the stack
    st.push({arr[i], i});
  }
  return left;
}

vector<int> nearestSmallestToRight(vector<int> &arr, int n)
{
  // Extra space for storing indexes of smallest element on the left side
  vector<int> right;
  stack<pair<int, int>> st;
  // Making a pseudo index to aid when finding the width for maximu area
  int pseudoIndex = n;

  for (int i = n - 1; i >= 0; i--)
  {
    // If the stack is empty
    if (st.empty())
      right.push_back(pseudoIndex);

    // If the top element of stack is smaller than the current element of the array
    else if (!st.empty() && st.top().first < arr[i])
      right.push_back(st.top().second);

    // If the top element of the stack is not smallter than  the current element of the array
    else if (!st.empty() && st.top().first >= arr[i])
    {
      // Popping elements of the stack until we find the smaller element or stack becomes empty
      while (!st.empty() && st.top().first >= arr[i])
        st.pop();

      // If the stack becomes empty
      if (st.empty())
        right.push_back(pseudoIndex);

      // If stack is not empty and we find a smaller element
      else
        right.push_back(st.top().second);
    }
    // Pushing the current element in the stack
    st.push({arr[i], i});
  }
  reverse(arr.begin(), arr.end());
  return right;
}

int largestRectangle(vector<int> &arr, int n)
{

  // Storing left and right arrays
  vector<int> left, right, width(n);

  // Finding left and right array which hold indexes of nearest smallest to left and right respectively
  left = nearestSmallestToLeft(arr, n);
  right = nearestSmallestToRight(arr, n);

  // Initialising area to INT_MIN to compare later
  int area = INT_MIN;

  for (int i = 0; i < n; i++)
  {

    // Length and width of the rectangle
    int length = arr[i];
    int width = right[i] - left[i] - 1;

    // Finding area for each element of the given array
    newArea = length * width;

    // Updating area if it's greater than the existing one
    area = max(area, newArea);
  }
  // Returning the greatest area
  return area;
}

int maximalRectangle(vector<vector<int>> &matrix)
{
  // Finding rows and columns of the matrix
  int m = matrix.size();
  int n = matrix[0].size();

  // Assigning area to INT_MIN to compare later
  int area = INT_MIN;
  vector<int> ans(n);

  // Traversing in order to form histogram like structure from the matrix
  for (int i = 0; i < m; i++)
  {
    // This loop will help to form the histogram by converting 2-D matrix to 1-D array
    for (j = 0; j < n; j++)
    {
      // Making sure that we don't count those bars which have base as 0, it will be like floating bar
      if (matrix[i][j] == 0)
        ans[j] = 0;
      // Adding value to previous vector to make it a histogram
      else
        ans[j] = ans[j] + matrix[i][j];
    }
    // Comparing and updating largest area my finding largest area formed by that histogram up until that moment
    area = max(area, largestRectangle(ans, n));
  }
  return area;
}
