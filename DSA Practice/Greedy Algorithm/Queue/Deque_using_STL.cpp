#include <iostream>
#include <queue>

using namespace std;

int main()
{
  // Initializing deque
  deque<int> dq;

  dq.push_front(10);
  dq.push_back(20);

  cout << dq.front() << std::endl;
  cout << dq.back() << std::endl;

  dq.pop_front();

  cout << dq.front() << std::endl;
  cout << dq.back() << std::endl;

  dq.pop_back();

  if (dq.empty())
    cout << "Deque is empty" << std::endl;
  else
    cout << "Deque is not empty" << std::endl;
}