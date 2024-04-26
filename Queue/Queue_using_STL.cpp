/* ---------- Queue using STL ---------- */

#include <iostream>
#include <queue>

using std::cin;
using std::cout;

int main()
{
  // Creating a queue
  std::queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);

  cout << " The size of queue is: " << q.size() << std::endl;
  if (q.empty())
    cout << "Queue is empty" << std::endl;
  else
    cout << "Queue is not empty" << std::endl;

  cout << "The Front element is: " << q.front() << std::endl;
  cout << "The back element is: " << q.back() << std::endl;

  q.pop();
  cout << "The Front element is: " << q.front() << std::endl;
}
