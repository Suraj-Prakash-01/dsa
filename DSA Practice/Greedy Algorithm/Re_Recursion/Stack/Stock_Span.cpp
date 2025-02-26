vector<int> NearestGreaterToLeft(vector<int> &arr, int n)
{
  // Extra space for storing index
  vector<int> ans;
  stack<pair<int, int>> st;

  for (int i = 0; i < n; i++)
  {
    // If the stack is empty
    if (st.empty())
      ans.push_back(-1);

    // If the top element of the stack is greater than the current element
    if (!st.empty() && st.top().first > arr[i])
      ans.push_back(st.top().second);

    // If the top element of the stack is not greater than the current element
    if (!st.empty() && st.top().first <= arr[i])
    {
      // Popping until we find the greater element or stack becomes empty
      while (!st.empty() && st.top().first <= arr[i])
        st.pop();

      // If the stack becomes empty
      if (st.empty())
        ans.push_back(-1);
      // If we end up finding the greater number
      else
        ans.push_back(st.top().second);
    }
    // Pushing the current element into the stack
    st.push({arr[i], i});
  }
  return ans;
}

vector<int> stockSpan(vector<int> &arr, int n)
{
  // Creating a vector to store new result
  vector<int> ans;
  ans = NearestGreaterToLeft(arr, n);

  // Converting the indexes from ans array to stock span
  for (int i = 0; i < n; i++)
    ans[i] = i - ans[i];

  // Returning the final result
  return ans;
}