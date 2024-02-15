#include <iostream>
#include <string.h>
using std::cin;
using std::cout;

// Parent Class
class Human
{

  // Properties of parent
public:
  int height;
  int weight;
  int age;

public:
  int getAge()
  {
    return this->age;
  }

  void setWeight(int w)
  {
    this->weight = w;
  }
};

// Child class - inherits from Human Class
class Male : public Human
{
public:
  std::string color;

  void sleep()
  {
    cout << "Male is sleeping" << std::endl;
  }
};

int main()
{
  Male male;

  // Even though these three properties aren't included in the male class
  // It still doesn't throw any error since they are inherited from the human class
  cout << male.age << std::endl;
  cout << male.height << std::endl;
  cout << male.weight << std::endl;

  cout << male.color << std::endl;
  male.setWeight(65);
  cout << male.weight << std::endl;
  male.sleep();
}