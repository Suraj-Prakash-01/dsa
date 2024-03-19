#include <iostream>
using std::cin;
using std::cout;

// Hierarchial Inheritance
class A
{
public:
  void func1()
  {
    cout << "Inside function 1" << std::endl;
  }
};

// class B inherits class A
class B : public A
{
public:
  void func2()
  {
    cout << "Inside function 2" << std::endl;
  }
};

// Class C also inherits class A
class C : public A
{
public:
  void func3()
  {
    cout << "Inside function 3" << std::endl;
  }
};

int main()
{
  A obj1;
  obj1.func1();

  B obj2;
  obj2.func1();
  obj2.func2();

  C obj3;
  obj3.func1();
  obj3.func3();
}