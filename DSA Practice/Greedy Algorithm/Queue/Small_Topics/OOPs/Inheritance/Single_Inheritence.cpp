#include <iostream>
using std::cin;
using std::cout;

// Base Class
class Animal
{
public:
  int age;
  int weight;

  void speak()
  {
    cout << "Speaking" << std::endl;
  }
};

// Derived Class
class Dog : public Animal
{
};

int main()
{
  Dog d;
  d.speak();
  cout << d.age << std::endl;
}