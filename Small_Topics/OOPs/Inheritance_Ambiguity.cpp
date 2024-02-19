#include <iostream>
using std::cin;
using std::cout;

class A
{
public:
  void func()
  {
    cout << "I am A" << std::endl;
  }
};

class B
{
public:
  void func()
  {
    cout << "I am B" << std::endl;
  }
};

class C : public A, public B
{
};

int main()
{
  C obj;
  // Throwing an error since
  // it doesn't know which function needs to be called
  // obj.func();

  obj.A::func();
  obj.B::func();
}