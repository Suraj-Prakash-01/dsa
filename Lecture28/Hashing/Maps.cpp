#include <iostream>
#include <map>
using std::cin;
using std::cout;

int main()
{
  int arr[10];
  for (int i = 0; i < 10; i++)
  {
    cin >> arr[i];
  }

  // Pre-Compute
  // <int,int> stores <number,frequency>
  std::map<int, int> mpp;
  for (int i = 0; i < 10; i++)
    mpp[arr[i]]++;

  for (auto it : mpp)
  {
    cout << "Number " << it.first << " appears " << it.second << " times.\n";
  }

  int q;
  cout << "Enter number of queries" << std::endl;
  cin >> q;
  while (q--)
  {
    int number;
    cin >> number;
    // Fetchinh numbrt gives frequency
    cout << mpp[number] << std::endl;
  }
  return 0;
}