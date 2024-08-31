
class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    // Create a min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> p;

    // Step 1: Push the first k elements into the heap
    for (int i = 0; i < k; i++)
    {
      p.push(nums[i]);
    }

    // Step 2: Iterate through the remaining elements and update the heap
    for (int i = k; i < nums.size(); i++)
    {
      if (nums[i] > p.top())
      {
        // If the current element is larger than the smallest element in the heap,
        // remove the smallest element and push the current element into the heap
        p.pop();
        p.push(nums[i]);
      }
    }

    // The k-th largest element is the smallest element in the heap
    return p.top();
  }
};