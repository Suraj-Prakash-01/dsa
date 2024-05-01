/* ----- Implementing stack using 2 queues ----- */

class MyStack
{
public:
  // One is the main queue and other is the supporting queue
  queue<int> q1;
  queue<int> q2;

  MyStack() {}

  void push(int x)
  {
    // Push the new element in the supporting queue
    q2.push(x);

    // Transfering all the element in the supporting queue
    // This way, the last inserted element will the first one to pop
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }

    // Swapping the values to bring back the elements in the main queue
    swap(q1, q2);
  }

  // Returning the popped element
  int pop()
  {
    int ans = q1.front();
    q1.pop();

    return ans;
  }

  int top()
  {
    return q1.front();
  }

  bool empty()
  {
    if (q1.empty())
      return true;
    return false;
  }
};

/* ----- Implementing stack using a single queue ----- */

class MyStack
{
public:
  queue<int> q;

  MyStack()
  {
  }

  void push(int x)
  {
    // Pushing the current element in the queue
    q.push(x);
    int n = q.size();

    for (int i = 0; i < n - 1; i++)
    {
      // Pushing the front elemnt of the queue to the top
      // So that when we pop, popped element would be the last inserted element
      q.push(q.front());

      // popping the front element as we have already pushing it at the rear of the queue
      q.pop();
    }
  }

  // Returns the popped element
  int pop()
  {
    int ans = q.front();
    q.pop();

    return ans;
  }

  // Returns the first element
  int top()
  {
    return q.front();
  }

  // Checks if the queue is empty or not
  bool empty()
  {
    if (q.empty())
      return true;
    return false;
  }
};