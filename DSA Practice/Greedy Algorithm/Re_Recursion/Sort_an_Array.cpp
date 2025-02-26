#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void insert(std::vector<int> &arr, int val)
{
  // Base Case
  if (arr.size() == 0 || arr[arr.size() - 1] <= val)
  {
    arr.push_back(val);
    return;
  }

  // Storing the last element and popping it
  int temp = arr[arr.size() - 1];
  arr.pop_back();

  // Calling the recursive function to find suitable position for values
  insert(arr, val);
  arr.push_back(temp);
}

void sorting(std::vector<int> &arr)
{
  // Base Case
  if (arr.size() == 1)
    return;

  // Storing the last element and popping it
  int val = arr[arr.size() - 1];
  arr.pop_back();

  // Breaking the array into even smaller part
  sorting(arr);

  // Inserting all the element in a sorted manner that was popped so for
  insert(arr, val);
}

int main()
{
  std::vector<int> arr = {4, 2, 1, 5, 3};

  sorting(arr);

  // Printing the sorted array
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << std::endl;
}