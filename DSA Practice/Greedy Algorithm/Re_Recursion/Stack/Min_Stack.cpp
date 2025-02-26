/* ----- Finding Min Stack using Extra Spack -----*/

stack<int> st;
// Supporting stack which will stack the mininum value of the main stack
stack<int> ss;

void push(int num)
{
  st.push(num);

  // We can only push element in the supporting stack if
  // Either supportive stack is empty
  // or the top element of the supportive stack is greater than or equal to the  pushed element
  if (ss.empty() || ss.top() >= num)
    ss.push(num);
}

int pop()
{
  // If stack is empty
  if (s.empty())
    return -1;

  // Storing the top element of the main stack to compare it with the top element of the supporting stack
  int top = st.top();
  st.pop();

  // Popping top element of the supporting stack if the top elemnt is equal to the stored value from the main stack
  if (ss.top() == top)
    ss.pop();
}

int getMin()
{
  // If the supporting stack is empty
  if (ss.empty())
    return -1;

  // If supporting stack is not empty, that means it's holding the minimum value
  return ss.top();
}

/* ----- Min Stack using no extra space ----- */
