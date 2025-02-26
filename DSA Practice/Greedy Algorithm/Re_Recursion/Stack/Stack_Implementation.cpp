#include <iostream>
#include <stack>

using std::cin;
using std::cout;

class Stack
{

  // Properties
public:
  int *arr;
  int top;
  int size;

  // Behavior
  Stack(int size)
  {
    this->size = size;
    arr = new int(size);
    top = -1;
  }

  void push(int element)
  {
    if (size - top > 1)
      arr[++top] = element;
    else
      cout << "Stack Overflow" << std::endl;
  }

  void pop()
  {
    if (top >= 0)
      top--;
    else
      cout << "Stack Underflow" << std::endl;
  }

  int peek()
  {
    if (top >= 0)
      return arr[top];
    cout << "Stack is empty" << std::endl;
    return -1;
  }

  bool empty()
  {
    if (top >= 0)
      return false;
    return true;
  }
};

int main()
{
  Stack s(5);

  s.push(1);
  s.push(2);
  s.push(3);

  cout << s.peek() << std::endl;

  s.pop();
  cout << s.peek() << std::endl;
}