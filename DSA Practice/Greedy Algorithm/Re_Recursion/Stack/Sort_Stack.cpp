#include <bits/stdc++.h>
void sortedInsert(stack<int> &s, int num)
{
  // Base Case
  // Extra case will stop removing element and place respective element at the correct place
  if (s.empty() || (!s.empty() && s.top() < num))
  {
    s.push(num);
    return;
  }

  int n = s.top();
  s.pop();

  // Recursive Call
  sortedInsert(s, num);
  s.push(n);
}

stack<int> sortStack(stack<int> &s)
{
  // Base Case
  if (s.empty())
  {
    return s;
  }

  int num = s.top();
  s.pop();

  sortStack(s);

  sortedInsert(s, num);
  return s;
}