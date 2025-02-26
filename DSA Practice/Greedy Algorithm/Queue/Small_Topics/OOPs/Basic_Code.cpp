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

  Hero()
  {
    cout << "Constructor Called" << std::endl;
  }

  Hero(int health, char level)
  {
    this->health = health;
    this->level = level;
  }

  void print()
  {
    cout << "Health: " << this->health << std::endl;
    cout << "Level: " << this->level << std::endl;
  }

  // Copy Constructor
  Hero(Hero &temp)
  {
    this->health = health;
    this->level = level;
  }

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
  // Static Allocation
  Hero h(100, 'D');
  h.print();

  // Copy Constructor
  Hero i(h);
  i.print();

  // h.setHealth(40);
  // h.setLevel('D');
  // cout << "The level is: " << h.level << std::endl;
  // cout << "The health is: " << h.health << std::endl;

  // // Dynamic Allocation
  // Hero *h1 = new Hero;
  // h1->setLevel('G');
  // h1->setHealth(70);
  // cout << "The level is: " << h1->level << std::endl;
  // cout << "The health is: " << h1->getHealth() << std::endl;
}