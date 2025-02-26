#include <iostream>
using std::cin;
using std::cout;

void reachHome(int src, int dest)
{
  cout << "Source " << src << " Destination " << dest << std::endl;

  // Base Condition
  if (src == dest)
  {
    cout << "Destination Reached" << std::endl;
    return;
  }

  // Processing
  src++;

  // Recursive Call
  reachHome(src, dest);
}

int main()
{
  int dest = 10;
  int src = 1;

  cout << std::endl;

  reachHome(src, dest);
}