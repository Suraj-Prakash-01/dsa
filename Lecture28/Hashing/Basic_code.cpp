#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int arr[5];
  for (int i = 0; i < 5; i++)
  {
    cin >> arr[i];
  }

  // Precompute
  int hash[15] = {0};
  for (int i = 0; i < 5; i++)
  {
    hash[arr[i]] += 1;
  }

  // Displaying hash
  for (int i = 0; i < 5; i++)
  {
    cout << hash[i] << " ";
  }

  int q = 0;
  cout << "Enter number of queries" << std::endl;
  cin >> q;
  // No. of queries
  while (q--)
  {
    int number;
    cin >> number;
    // Fetch
    cout << hash[number] << std::endl;
  }
  return 0;
}
