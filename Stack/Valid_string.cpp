#include <bits/stdc++.h>
int findMinimumCost(string str)
{
  // If string length is odd
  if (str.size() % 2 == 1)
    return -1;

  stack<char> st;

  for (char c : str)
  {

    // c is open bracket
    if (c == '{')
      st.push(c);

    // c is closed bracket
    else
    {
      // Top element of stack is open bracket i.e., valid string then we pop
      if (!st.empty() && st.top() == '{')
        st.pop();

      // Not valid so push bracket into the stack
      else
        st.push(c);
    }
  }

  // Now only invalid expression is in the stack
  int a = 0, b = 0;
  while (!st.empty())
  {
    // Counting open brackets and closed brackets
    if (st.top() == '{')
      a++;
    else
      b++;
    st.pop();
  }

  return (a + 1) / 2 + (b + 1) / 2;
}