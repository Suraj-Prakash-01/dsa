#include <iostream>
#include <stack>

using std::cin;
using std::cout;

class TwoStack
{
  // Properties
public:
  int *arr;
  int top1, top2;
  int size;

  // Behaviour
public:
  TwoStack(int size)
  {
    this->size = size;
    top1 = -1;
    top2 = size;
    arr = new int[size];
  }

  // Push in stack 1
  void push1(int num)
  {
    // Atleast an empty space is present
    if (top2 - top1 > 1)
      arr[++top1] = num;
    else
      cout << "Stack overflow" << std::endl;
  }

  void push2(int num)
  {
    if (top2 - top1 > 1)
      arr[--top2] = num;
    else
      cout << "Stack overflow" << std::endl;
  }

  int pop1()
  {
    if (top1 >= 0)
      return arr[top1--];
    else
      return -1;
  }

  int pop2()
  {
    if (top2 < size)
      return arr[top2++];
    else
      return -1;
  }
};