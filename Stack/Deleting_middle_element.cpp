#include <bits/stdc++.h>

void solve(stack<int> &inputStack, int count, int n)
{
  // Base Case
  if (count == n / 2)
  {
    inputStack.pop();
    return;
  }

  // Storing the top element to push it back in later
  int num = inputStack.top();
  inputStack.pop();

  // Recursive Call
  solve(inputStack, count + 1, n);

  inputStack.push(num); // Pushing the values back in the stack
}

void deleteMiddle(stack<int> &inputStack, int N)
{

  int count = 0;
  solve(inputStack, count, N);
}