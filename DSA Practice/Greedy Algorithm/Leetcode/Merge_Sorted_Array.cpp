// Solution 3
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int i = m - 1;     // i is used to iterate through nums1 from the end
    int j = n - 1;     // j is used to iterate through nums2 from the end
    int k = m + n - 1; // k is used to iterate through the merged array from the end

    // Continue the while loop as long as there are elements left in both arrays
    while (i >= 0 and j >= 0)
    {
      // If the current element in nums1 is greater than the current element in nums2
      if (nums1[i] > nums2[j])
      {
        // Copy the current element from nums1 into the merged array
        nums1[k] = nums1[i];

        // Decrement the indices i and k
        i--, k--;
      }
      else
      {
        // Otherwise, copy the current element from nums2 into the merged array
        nums1[k] = nums2[j];

        // Decrement the indices j and k
        j--, k--;
      }
    }

    // To handle the leftover elements
    while (j >= 0)
    {
      // Copy the current element from nums2 into the merged array
      nums1[k] = nums2[j];

      // Decrement the indices k and j
      k--, j--;
    }
  }
};