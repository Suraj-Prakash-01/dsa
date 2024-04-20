void insertAtBottom(stack<int> &stack, int num)
{
  // Base Case
  if (stack.empty())
  {
    stack.push(num);
    return;
  }

  // Storing element to be pushed into the stack later
  int ans = stack.top();
  stack.pop();

  // Recursive Call
  insertAtBottom(stack, num);

  // Pushing saved element into stack
  stack.push(ans);
}

void reverseStack(stack<int> &stack)
{
  // Base Case
  if (stack.empty())
    return;

  int num = stack.top();
  stack.pop();

  // Break the stack till the very last element
  reverseStack(stack);

  // Insert previously popped elements from bottom so last popped element becomes the top element at the end
  insertAtBottom(stack, num);
}