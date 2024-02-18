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

// Derived Class inheriting Derived Class
class GermanShephard : public Dog
{
};

int main()
{
  GermanShephard d;
  d.speak();
  cout << d.age << std::endl;
}