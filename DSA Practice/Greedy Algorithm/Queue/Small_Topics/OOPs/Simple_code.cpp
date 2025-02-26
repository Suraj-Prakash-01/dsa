#include <iostream>
#include "Cool.cpp" // Importing class from a different file
using std::cin;
using std::cout;

class Hero
{
  // Default class of properties are private that means it can't be accessed outside the class
  // properties
public:
  int health;
  char level;

  // Getter -- Setter

  int getHealth()
  {
    return health;
  }

  char getLevel()
  {
    return level;
  }

  void setHealth(int h)
  {
    health = h;
  }

  void setLevel(char l)
  {
    level = l;
  }
};

int main()
{
  // Creation of Object
  // Cool c; // Creating object of cool
  Hero h1;

  cout << "The Health is: " << h1.health << std::endl;
  cout << "The level is: " << h1.level << std::endl;

  // cout << "Size of h1: " << sizeof(h1) << std::endl;
  // cout << "Size of c: " << sizeof(c) << std::endl;

  h1.setHealth(40);
  cout << "Enter health of h1: " << h1.getHealth();
}