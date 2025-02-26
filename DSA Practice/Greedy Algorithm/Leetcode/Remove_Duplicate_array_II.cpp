class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();

    // If the array has less than 3 elements, return its size as there can't be any duplicates.
    if (n < 3)
      return n;

    // Initialize two pointers, i and j, to iterate through the array.
    // i points to the current element being processed,
    // j points to the next position where the processed element will be stored.
    int i = 0, j = 0;

    // Iterate through the array.
    while (i < n)
    {
      // Copy the current element to the new position.
      nums[j++] = nums[i++];

      // If there are more elements and the next element is the same as the current one,
      // copy the next element to the new position and increment the pointer i.
      if (i < n && nums[i] == nums[j - 1])
        nums[j++] = nums[i++];

      // While there are more elements and the current element is the same as the next one,
      // increment the pointer i to skip the duplicate elements.
      while (i < n && nums[i] == nums[j - 1])
        i++;
    }

    // Return the length of the new array after removing duplicates.
    return j;
  }
};