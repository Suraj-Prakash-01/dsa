#include <bits/stdc++.h>
stack<int> pushAtBottom(stack<int> &myStack, int x)
{

  // Base Case
  if (myStack.empty())
  {
    myStack.push(x);
    return myStack;
  }

  // Storing element to be pushed into the stack later
  int ans = myStack.top();
  myStack.pop();

  // Recursive Call
  pushAtBottom(myStack, x);

  // Pushing saved element into stack
  myStack.push(ans);
  return myStack; // Returning the modified stack
}
