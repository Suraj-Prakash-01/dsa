#include <iostream>
using std::cin;
using std::cout;

// Function Overloading
class A
{
public:
  // Below mentioned are all function of same name
  // To overload function, we add an argument to make it different
  void sayHello()
  {
    cout << "Hello Suraj" << std::endl;
  }

  // Changing return type won't help in function Overloading
  int sayHello(std::string name, int n)
  {
    cout << "Hello Suarj" << std::endl;
  }

  void SayHello(std::string name)
  {
    cout << "Hello" << name << std::endl;
  }
};

int main()
{
  A obj;
  obj.sayHello();
}