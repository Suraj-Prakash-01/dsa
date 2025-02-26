// class Solution {
//   public:
//     // a,b : the arrays
//     // Function to return a list containing the union of the two arrays.
//     vector<int> findUnion(vector<int> &a, vector<int> &b) {
//         // Your code here
//         // return vector with correct order of elements
//         set<int> unionSet ;

//         for(i:a){
//             unionSet.insert(i);
//         }
//         for(i:b){
//             unionSet.insert(i);
//         }

//         vector<int> result(unionSet.begin(), unionSet.end());
//         return result;
//     }
// };

class Solution
{
public:
  vector<int> findUnion(vector<int> &a, vector<int> &b)
  {
    vector<int> result;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
      if (a[i] < b[j])
      {
        // Add element if it's not already in the result
        if (result.empty() || result.back() != a[i])
        {
          result.push_back(a[i]);
        }
        i++;
      }
      else if (b[j] < a[i])
      {
        if (result.empty() || result.back() != b[j])
        {
          result.push_back(b[j]);
        }
        j++;
      }
      else
      {
        // Both elements are equal, add either one
        if (result.empty() || result.back() != a[i])
        {
          result.push_back(a[i]);
        }
        i++;
        j++;
      }
    }

    // Add remaining elements from array a
    while (i < a.size())
    {
      if (result.empty() || result.back() != a[i])
      {
        result.push_back(a[i]);
      }
      i++;
    }

    // Add remaining elements from array b
    while (j < b.size())
    {
      if (result.empty() || result.back() != b[j])
      {
        result.push_back(b[j]);
      }
      j++;
    }

    return result;
  }
};