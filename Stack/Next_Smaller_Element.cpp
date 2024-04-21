#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
  stack<int> st;
  st.push(-1);
  vector<int> ans(n);

  // Traversing the array in reverse
  for (int i = n - 1; i >= 0; i--)
  {
    int num = arr[i];

    // Popping the elements in the stack till we find the first smalller element
    while (st.top() >= num)
      st.pop();

    // ans is the top element of the stack
    ans[i] = st.top();

    // Previously popped elements are already larger than the current one
    // Therefore, there is not need to push the popped element, current element will work just fine
    st.push(num);
  }
  return ans;
}