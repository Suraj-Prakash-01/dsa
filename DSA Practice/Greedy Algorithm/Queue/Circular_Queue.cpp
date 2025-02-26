#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
public:
  int *arr;
  int front;
  int rear;
  int n; // size of the array

public:
  CircularQueue(int n)
  {
    this->n = n;
    arr = new int[n];
    front = rear = -1;
  }

  // Returns true if it gets pushed into the stack, and false otherwise.
  bool enqueue(int value)
  {
    // To check whether the queue is full
    if ((front == 0 && rear == n - 1) || (rear == (front - 1)))
      return false;

    // First element to enter
    else if (front == -1)
      front = rear = 0;

    else if (rear == n - 1 && front != 0)
      rear = 0; // To maintain cyclic nature

    else
      rear++; // Normal flow

    // Pushing element inside the queue
    arr[rear] = value;
    return true;
  }

  // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
  int dequeue()
  {
    // If the queue is empty.
    if (front == -1)
      return -1;

    int ans = arr[front];
    // If both front and rear are pointing to the same index
    if (front == rear)
      front = rear = -1;

    else if (front == n - 1)
      front = 0; // To maintain the cyclic nature

    else
      front++; // Normal flow
    return ans;
  }
};
