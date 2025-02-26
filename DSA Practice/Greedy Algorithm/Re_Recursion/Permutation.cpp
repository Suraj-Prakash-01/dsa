/* ----- Approach 1 -> Using Extra Space -----*/

// What we different number for first index for permutation and maintained freq array check whether it's used or not
// We iterated until we get an unused number and used in and updated the freq array
// After inserting the values into an ultimate array from temporary array, we popped those elements and updated freq array again

#include <iostream>
#include <vector>
using std::cin;
using std::cout;

void permutation(std::vector<int> &ds, std::vector<int> arr, int freq[], std::vector<std::vector<int>> &ans)
{
  // Base Case
  if (ds.size() == arr.size())
  {
    ans.push_back(ds);
    return;
  }

  // Traversing until we get an unused number from the array
  for (int i = 0; i < arr.size(); i++)
  {
    if (!freq[i])
    {
      // Adding the element and updating the freq array
      ds.push_back(arr[i]);
      freq[i] = 1;

      permutation(ds, arr, freq, ans);

      // Popping from the temporary array and updating the freq array
      freq[i] = 0;
      ds.pop_back();
    }
  }
}

int main()
{
  std::vector<int> arr = {1, 2, 3};
  int freq[arr.size()] = {0};
  std::vector<int> ds;
  std::vector<std::vector<int>> ans;

  permutation(ds, arr, freq, ans);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << std::endl;
  }
}

/* ----- Approach 2 -> Using no extra space ----- */

//

#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;

void permutation(int ind, std::vector<int> &arr, std::vector<std::vector<int>> &ans)
{
  // Base Case
  if (ind == arr.size())
  {
    ans.push_back(arr);
    return;
  }

  for (int i = ind; i < arr.size(); i++)
  {
    std::swap(arr[ind], arr[i]);
    permutation(ind + 1, arr, ans);
    std::swap(arr[ind], arr[i]);
  }
}

int main()
{
  std::vector<int> arr = {1, 2, 3};
  std::vector<std::vector<int>> ans;

  permutation(0, arr, ans);

  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << std::endl;
  }
}