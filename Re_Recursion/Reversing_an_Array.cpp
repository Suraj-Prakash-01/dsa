#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void reverse(std::vector<int> &arr, int i, int j)
{
  // Base Case
  if (i > j)
    return;

  std::swap(arr[i], arr[j]);
  return reverse(arr, ++i, --j);
}

int main()
{
  std::vector<int> arr = {1, 2, 3, 4, 5};
  reverse(arr, 0, 4);

  for (int i = 0; i < 5; i++)
  {
    cout << arr[i] << " ";
  }
}