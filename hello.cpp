#include <iostream>

int main()
{
  int ans = 0;
  int size;
  std::cin >> size;
  int arr[7] = {1, 2, 3, 3, 4, 5, 1};

  for (int i = 0; i < size; i++)
  {
    ans = ans ^ arr[i]; // Xor makes same entries zero
  }
  std::cout << ans;
}