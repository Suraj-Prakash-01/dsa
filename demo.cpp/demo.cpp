#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> arr1 = {1, 2, 4, 2, 8};
  std::vector<int> arr2 = {2, 5, 3, 8, 6, 9, 1, 3, 6};

  std::sort(arr2.begin(), arr2.end());
  for (int i = 0; i < arr2.size(); i++)
    std::cout << " " << arr2[i] << std::endl;
}