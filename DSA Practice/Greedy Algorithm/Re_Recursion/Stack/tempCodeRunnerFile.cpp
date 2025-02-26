void Nearest_Smaller(vector<int> &arr, int n)
{

  // Extra space for storing final result
  vector<int> ans;
  stack<int> st;

  // Travering through the whole array
  for (int i = 0; i < n; i++)
  {
    // If the stack is empty
    if (st.empty())
      ans.push_back(-1);

    // If the next smallest element is the top value of the stack
    if (!st.empty() && st.top() < arr[i])
      ans.push_back(st.top());

    // If the next smallest element is not the top value of the stack
    if (!st.empty() && st.top() >= arr[i])
    {
      // Popping element until we find the next smallest element
      while (!st.empty() && st.top() >= arr[i])
        st.pop();

      // If after popping, stack becomes empty
      if (st.empty())
        ans.push_back(-1);

      // If we find the next smallest element
      if (!st.empty())
        ans.push_back(st.top());
    }
    // Pushing the current element of the array
    st.push(arr[i]);
  }
}