#include <iostream>

bool search(int arr[], int size, int key)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == key)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
  int key;
  std::cin >> key;

  bool found = search(arr, 10, key);

  if (found)
  {
    std::cout << "Key is present" << std::endl;
  }
  else
  {
    std::cout << "Key not found" << std::endl;
  }
}