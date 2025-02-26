#include <iostream>
using std::cin;
using std::cout;

class B
{
public:
  int a;
  int b;

  int add()
  {
    return a + b;
  }

  // Examples of Operator Polymorphism
  void operator+(B &obj)
  {
    int value1 = this->a;
    int value2 = obj.a;

    cout << "Output " << value2 - value1 << std::endl;
  }

  void operator()()
  {
    cout << "Main Bracket hu" << std::endl;
  }
};

int main()
{
  B obj1, obj2;

  obj1.a = 4;
  obj2.a = 7;

  obj1 + obj2;
  obj1();
}