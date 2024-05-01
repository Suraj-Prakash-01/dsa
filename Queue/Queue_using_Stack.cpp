/* ----- Simple approach to implementing a queue using two stacks -----*/

class MyQueue
{
public:
  stack<int> s1; // Stack 1 to store the elements of the queue
  stack<int> s2; // Stack 2 to temporarily store the elements of the queue

  MyQueue()
  {
  }

  /* ----- Push method to add an element to the queue -----*/
  void push(int x)
  {
    // Move all elements from stack 1 to stack 2
    while (!s1.empty())
    {
      s2.push(s1.top());
      s1.pop();
    }

    // Add the new element to stack 1
    s1.push(x);

    // Move all elements from stack 2 back to stack 1
    while (!s2.empty())
    {
      s1.push(s2.top());
      s2.pop();
    }
  }

  /* ----- Pop method to remove an element from the queue -----*/
  int pop()
  {
    // Check if the queue is empty
    if (s1.empty())
      return -1;

    // Remove the top element from stack 1
    int ans = s1.top();
    s1.pop();

    return ans;
  }

  /* ----- Peek method to view the top element of the queue -----*/
  int peek()
  {
    // Check if the queue is empty
    if (s1.empty())
      return -1;

    // Return the top element of stack 1
    return s1.top();
  }

  /* ----- Empty method to check if the queue is empty -----*/
  bool empty()
  {
    // Check if stack 1 is empty
    if (s1.empty())
      return true;

    return false;
  }
};