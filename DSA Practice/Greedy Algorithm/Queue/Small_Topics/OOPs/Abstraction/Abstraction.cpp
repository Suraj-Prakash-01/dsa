#include <iostream>
using std::cin;
using std::cout;

class abstraction
{
private:
  int a, b;

public:
  // Method to set values of private members
  void set(int x, int y)
  {
    a = x;
    b = y;
  }

  void display()
  {
    cout << "a = " << a << std::endl;
    cout << "b = " << b << std::endl;
  }
};

int main()
{
  abstraction obj;
  obj.set(10, 20);
  obj.display();
}