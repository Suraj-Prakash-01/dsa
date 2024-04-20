/* ---------- Approach 1 ----------*/

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

/* ---------- Approach 2 ---------- */

class Solution
{
public:
  bool isValid(string s)
  {

    // Return false if size of string is odd i.e. one bracket doesn't have matching bracket
    if (s.size() & 1)
      return false;

    stack<char> a;

    for (char c : s)
    {
      // If opening bracket found, push it into stack
      if (c == '(' || c == '{' || c == '[')
        a.push(c);

      // If not, check stack top and then pop
      else
      {
        // It doesn't have matching opening brakcet for closing bracket
        if (a.empty())
          return false;

        // If everything is fine
        else if ((c == ')' && a.top() == '(') || (c == '}' && a.top() == '{') || (c == ']' && a.top() == '['))
          a.pop();
        else
          return false;
      }
    }
    // If parenthesis pattern is valid, stack will be empty at the end
    return a.empty();
  }
};
