#include <bits/stdc++.h>
class Deque
{
  int *arr;
  int front;
  int rear;
  int size;

public:
  Deque(int n)
  {
    size = n;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void pushFront(int x)
  {
    // Check full or not and front!=0  as if it becomes 0, rear would become negative
    if ((front == 0 && rear == size - 1) || (front != 0 && rear == front - 1))
      return;

    // FIrst element
    else if (front == -1)
      front = rear = 0;

    // For maintaining cyclic nature]
    else if (front == 0 && rear != size - 1)
      front = size - 1;

    // Normal case
    else
      front--;

    arr[front] = x;
  }

  void pushRear(int x)
  {
    // Checking full or not and front!=0  as if it becomes 0, rear would become negative
    if ((front == 0 && rear == size - 1) || (front != 0 && rear == front - 1))
      return;

    // If it's the first element
    else if (front == -1)
      front = rear = 0;

    // For cyclic nature
    else if (rear == size - 1 && front != 0)
      rear = 0;

    // Normal case
    else
      rear++;

    arr[rear] = x;
  }

  int popFront()
  {
    // Checking empty or not
    if (front == -1)
      return -1;

    int ans = arr[front];
    // If it's the last element
    if (front == rear)
      front = rear = -1;

    // For cyclic nature
    else if (front == size - 1)
      front = 0;

    // Normal Case
    else
      front++;

    return ans;
  }

  int popRear()
  {
    // Checking if empty or not
    if (front == -1)
      return -1;

    int ans = arr[rear];
    // If it's the last element
    if (front == rear)
      front = rear = -1;

    // To maintain cyclic nature
    else if (rear == 0)
      rear = size - 1;

    // Normal Case
    else
      rear--;

    return ans;
  }

  int getFront()
  {
    if (isEmpty())
      return -1;
    return arr[front];
  }

  int getRear()
  {
    if (isEmpty())
      return -1;
    return arr[rear];
  }

  bool isEmpty()
  {
    if (front == -1)
      return true;
    return false;
  }

  bool isFull()
  {
    //  front!=0 as if it becomes 0, rear would become negative
    if ((front == 0 && rear == size - 1) || (front != 0 && rear == front - 1))
      return true;
    return false;
  }
};