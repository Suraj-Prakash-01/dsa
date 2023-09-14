// One approach for sorting array in descending order

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//   // Get the vector
//   vector<int> a = {1, 45, 54, 71, 76, 12};

//   // Print the vector
//   cout << "Vector: ";
//   for (int i = 0; i < a.size(); i++)
//     cout << a[i] << " ";
//   cout << endl;

//   // Sort the vector in descending order
//   sort(a.begin(), a.end(), greater<int>());

//   // Print the reversed vector
//   cout << "Sorted Vector in descending order:\n";
//   for (int i = 0; i < a.size(); i++)
//     cout << a[i] << " ";
//   cout << endl;

//   return 0;
// }

// Another approach to sort array in descending array
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