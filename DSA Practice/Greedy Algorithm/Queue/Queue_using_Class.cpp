#include <iostream>

using std::cin;
using std::cout;

class queue
{
public:
  int *arr;
  int size;
  int qfront; // Using qfront as front clashes with the function name
  int rear;

  queue(int size)
  {
    this->size = size;
    arr = new int[size];
    qfront = 0;
    rear = 0;
  }

  // Operations
public:
  // Function to check whether queue is empty or not
  bool empty()
  {
    if (qfront == rear)
      return true;
    return false;
  }

  // Function to push element at the rear in the queue
  void enqueue(int n)
  {
    if (rear == size) // Queue is already full
      return;
    arr[rear++] = n;
  }

  // Function to pop element from the front in the queue
  void dequeue()
  {
    if (qfront == rear) // Queue is empty
      return;

    qfront++;

    // If front and rear points to the same index
    // Then we initialize it to zero to avoid wasting space
    if (qfront == rear)
    {
      qfront = 0;
      rear = 0;
    }
  }

  // Function to display the front element
  int front()
  {
    if (qfront == rear) // Queue is empty
      return -1;

    // It points to the next front element
    return arr[qfront];
  }

  // Funtion ot display the rear element
  int back()
  {
    if (qfront == rear) // Queue is empty
      return -1;

    // We are writing rear-1 because rear is pointing to the next available position
    return arr[rear - 1];
  }
};

int main()
{
  queue q(5);

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);

  q.dequeue();

  cout << q.front() << std::endl;
  cout << q.back() << std::endl;

  if (q.empty())
    cout << "Queue is empty" << std::endl;
  else
    cout << "Queue is not empty" << std::endl;
}
