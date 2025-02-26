#include <iostream>
using std::cin;
using std::cout;

// Parent Class 1
class Vehicle
{
public:
  Vehicle()
  {
    cout << "This is a vehicle" << std::endl;
  }
};

// Parent Class 2
class Fare
{
public:
  Fare()
  {
    cout << "Fare of Vehicle" << std::endl;
  }
};

// Child Class 1
class Car : public Vehicle
{
};

// Child Class 2
class Bus : public Vehicle, public Fare
{
};

int main()
{

  // Creating object of sub-class will invoke the constructor of base class
  Bus obj;
}