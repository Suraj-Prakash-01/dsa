#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> arr = {2, 5, 3, 8, 6, 9, 1, 3, 6};

  std::sort(arr.rbegin(), arr.rend());
  for (int i = 0; i < arr.size(); i++)
  {
    std::cout << " " << arr[i];
  }
}