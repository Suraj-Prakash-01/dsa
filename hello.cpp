#include <iostream>
#include <iomanip> // contains setprecision function

int main()
{
  double f = 15.784315289;
  // Fixed brings the cursor to the decimal
  // so that number can be counted after that
  std::cout << std::fixed;
  std::cout << std::setprecision(5) << f << std::endl;
}