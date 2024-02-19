#include <iostream>
using std::cin;
using std::cout;

class Parent
{
public:
  void show()
  {
    cout << "Inside Parent Class" << std::endl;
  }
};

// Overriding Methods of Parent class
class subclass1 : public Parent
{
public:
  void show()
  {
    cout << "Inside Subclass 1" << std::endl;
  }
};

class subclass2 : public Parent
{
public:
  void show()
  {
    cout << "Inside Subclass 2" << std::endl;
  }
};

int main()
{
  subclass1 obj1;
  subclass2 obj2;

  obj1.show();
  obj2.show();
}
