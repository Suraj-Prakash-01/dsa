#include <iostream>
#include <string.h>
using std::cin;
using std::cout;

class Student
{

  // Every data member is combined in a single entity called class
private:
  std::string name;
  int age;
  int height;

  int getAge()
  {
    return this->age;
  }
};

int main()
{
  Student s;
  cout << "Everything is working just fine" << std::endl;
}