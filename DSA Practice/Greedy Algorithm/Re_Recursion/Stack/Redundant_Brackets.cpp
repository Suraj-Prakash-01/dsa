#include <bits/stdc++.h>

// Redundant Brakcet means Useless brackets
bool findRedundantBrackets(string &s)
{
  stack<char> st;

  for (char c : s)
  {
    // If the character is among below mentioned, push it in the stack
    if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/')
      st.push(c);

    else
    {
      // If it's closing bracket, it must have an operator in between them
      if (c == ')')
      {
        bool isRedundant = true;

        // popping until we get a opening bracket
        while (st.top() != '(')
        {
          char top = st.top();

          // If operator is there, then it's not redundant
          if (top == '+' || top == '-' || top == '*' || top == '/')
            isRedundant = false;
          st.pop();
        }

        // if operator condition doesn't work , then it's redundant
        if (isRedundant)
          return true;
        // Popping the opening bracket if it's not redundant
        st.pop();
      }
      else
        continue;
    }
  }
  // If until the last element, nothing is returned that means it's not redundant
  return false;
}
