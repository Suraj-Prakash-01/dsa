void NextGreaterToLeft(vector<int> &arr, int n)
{
  // Extra vector space to store final result
  vector<int> ans;
  stack<int> st;

  for (int i = 0; i < n; i++)
  {
    // If stack is empty that means there is no other element to compare with
    if (st.empty())
      ans.push_back(-1);

    // If top value of stack is greater than current number then push it in the array
    else if (!st.empty() && st.top() > arr[i])
      ans.push_back(st.top());

    // If top value of stack is not greater than current number
    else if (!st.emtpy() && st.top() <= arr[i])
    {
      // Popping until we find a greater number
      while (!st.emtpy() && st.top() <= arr[i])
        st.pop();

      // If stack becomes empty, then next greater number doesn't exist
      if (st.emtpy())
        ans.push_back(-1);

      // If it's not empty, that means there is a next greater number
      else
        ans.push_back(st.pop()); // Pushing the grearter number in the final array
    }
    // Pushing the current element from the array into the stack
    st.push(arr[i]);
  }
}