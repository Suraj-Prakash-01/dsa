#include <iostream>
using std::cin;
using std::cout;

void update2(int &n)
{
  n++;
}
void update1(int n)
{
  n++;
}

int main()
{
  // int i = 5;

  // // Creating reference Variable
  // int &ref = i;

  // cout << i << std::endl;
  // i++;
  // cout << i << std::endl;
  // ref++;
  // cout << i << std::endl;

  int n = 5;
  cout << "Before " << n << std::endl;
  update1(n);
  cout << "After update1 " << n << std::endl;
  update2(n);
  cout << "After update2 " << n << std::endl;
}