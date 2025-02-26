#include <iostream>
#include <stack>

using std::cin;
using std::cout;

int main()
{
  // Creation of Stack
  std::stack<int> s;

  // Push Operation
  s.push(1);
  s.push(2);

  // Pop Operation
  s.pop();

  cout << "Printing top element " << s.top() << std::endl;

  if (s.empty())
  {
    cout << "Stack is empty" << std::endl;
  }
  else
  {
    cout << "Stack is not empty" << std::endl;
  }

  cout << "Size of stack is: " << s.size() << std::endl;

  return 0;
}
