#include <iostream>

int LowerBound(int arr[], int n, int x)
{
  // To find the lower bound in the Binary Search

  int low = 0, high = n - 1;
  int ans = n; // This ans variable will return the lower bound

  while (low <= high)
  {
    int mid = (low + high) / 2;

    // Maybe an answer
    if (arr[mid] >= x)
    {
      ans = mid;
      // Looking for more small index on left
      high = mid - 1;
    }

    else
    {
      low = mid + 1; // Looking in right part
    }
  }
  return ans;
}

#include <iostream>

int UpperBound(int arr[], int n, int x)
{
  // To find the Upper bound in the Binary Search

  int low = 0, high = n - 1;
  int ans = n; // This ans variable will return the upper bound

  while (low <= high)
  {
    int mid = (low + high) / 2;

    // Maybe an answer
    if (arr[mid] >= x)
    {
      ans = mid;
      // Looking for more small index on left
      high = mid - 1;
    }

    else
    {
      low = mid + 1; // Looking in right part
    }
  }
  return ans;
}

int First_LastPosition(int arr, int n, int x)
{
  int lb = LowerBound(arr, 9, x);
}

int main()
{
  int arr[9] = {1, 4, 9, 12, 34, 45, 68, 84, 99};
  int x;
  std::cin >> x;

  std::cout << "The ceil of the sorted array is" << value << std::endl;
}