bool isValidParenthesis(string s)
{

  stack<char> st;

  for (int i = 0; i < s.size(); i++)
  {
    char ch = s[i];

    // If opening bracket, push in stack
    if (ch == '(' || ch == '{' || ch == '[')
      st.push(ch);

    // If closing bracket, check stacktop and pop
    else
    {
      // Checking empty stack
      if (!st.empty())
      {
        char top = st.top();
        // Comparing ch and top element, if it complement each other then we pop it
        if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
            (ch == ']' && top == '['))
          st.pop();

        // If they don't complement each other, then we it isn't valid parenthesis
        else
          return false;
      }

      // If it's empty from the start that means the first bracket it closing bracket
      // So, it's not valid parenthesis
      else
        return false;
    }
  }

  // If after all the operation, there is no element left it stack then it means it's valid
  if (st.empty())
    return true;
  else
    false; // And if there is, it's invalid
}