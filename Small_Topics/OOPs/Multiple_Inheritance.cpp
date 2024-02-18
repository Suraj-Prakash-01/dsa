#include <iostream>
using std::cin;
using std::cout;

// Base Class 1
class Animal
{
public:
  int age;
  int weight;

  void bark()
  {
    cout << "Barking" << std::endl;
  }
};

// Base Class 2
class Human
{
public:
  std::string color;

  void speak()
  {
    cout << "Speaking" << std::endl;
  }
};

// Multiple Inheritance
class hybrid : public Animal, public Human
{
};

int main()
{
  hybrid obj;
  obj.speak();
  obj.bark();
}