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