#include <bits/stdc++.h>
#include <vector>
using namespace std;

void sort(vector<int> &arr)
{
  if (arr.size() == 1 || arr.size() == 0)
    return;
  int temp = arr[arr.size() - 1];
  arr.pop_back();
  sort(arr.begin(), arr.end());
  insert(arr, temp);
}

void insert(vector<int> &arr, int temp)
{
  if (arr.size() == 0 || arr[arr.size() - 1] <= temp)
  {
    arr.push_back(temp);
    return;
  }
  int val = arr[arr.size() - 1];
  arr.pop_back();
  insert(arr, temp);
  arr.push_back(val);
  return;
}

int main()
{
  int arr[6] = {2, 9, 1, 5, 3, 9};
  sort(arr);
  for (auto i : arr)
  {
    cout << i << " ";
  }
}
