/* ---------- Approack 1 ----------*/

#include <bits/stdc++.h>
#include <stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
  stack<int> st;
  st.push(-1);
  vector<int> ans(n);

  // Treaverses in reverse
  for (int i = n - 1; i >= 0; i--)
  {
    int num = arr[i];

    // Popping until we find the element smaller than the current element
    // arr[st.top()] retrieves the value of the element at the index equal to the top element of the stack
    while (st.top() != -1 && arr[st.top()] >= num)
      st.pop();

    // it stores the index of next smaller elements
    ans[i] = st.top();
    // Pushing the index into the stack
    st.push(i);
  }
  return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
  stack<int> st;
  st.push(-1);
  vector<int> ans(n);

  // We just changes the loop condition for finding the previous smaller element
  for (int i = 0; i < n; i++)
  {
    int num = arr[i];

    while (st.top() != -1 && arr[st.top()] >= num)
      st.pop();

    // Ans is the top element of the stack
    ans[i] = st.top();
    st.push(i);
  }
  return ans;
}

int largestRectangle(vector<int> &heights)
{
  int n = heights.size();

  // Storing next smaller elemnet indexes
  vector<int> next(n);
  next = nextSmallerElement(heights, n);

  // Storing previous smaller indexes
  vector<int> prev(n);
  prev = prevSmallerElement(heights, n);

  int area = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    int l = heights[i];

    // If the next greater element is beyond last element, then changing it to n
    if (next[i] == -1)
      next[i] = n;

    // Formula for finding width of the rectangles
    int b = next[i] - prev[i] - 1;

    int newArea = l * b;
    // Comparing the new area with the previously stored areas
    area = max(area, newArea);
  }
  // Returning the greatest area
  return area;
}

/* ---------- Apporach 2 ----------*/

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
  vector<int> left, right;

  // Finding left and right array which hold indexes of nearest smallest to left and right respectively
  left = nearestSmallestToLeft(arr, n);
  right = nearestSmallestToRight(arr, n);

  // Initialising area to INT_MIN to compare with later on
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