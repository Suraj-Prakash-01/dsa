#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int arr[3][4];

  cout << "Enter the elements :" << std::endl;
  // For taking input in 2-D array
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cin >> arr[i][j];
    }
  }

  // For printing 2-D array
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << std::endl;
  }
}