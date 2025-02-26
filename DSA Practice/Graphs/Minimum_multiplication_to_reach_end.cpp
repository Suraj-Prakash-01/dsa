class Solution
{
public:
  int minimumMultiplications(vector<int> &arr, int start, int end)
  {
    // Step 1: Initialize a queue for BFS. Each element in the queue is a pair (current number, steps).
    queue<pair<int, int>> q;
    q.push({start, 0}); // Start from the 'start' number with 0 steps taken.

    // Step 2: Initialize a distance array with a large value (infinity) to keep track of the minimum steps to reach each number.
    vector<int> dist(100000, 1e9); // 100000 represents the mod limit, so we track numbers modulo 100000.
    dist[start] = 0;               // The distance (steps) to reach the start number is 0.

    int mod = 100000; // Use a modulus of 100000 to ensure all numbers are within this range.

    // Step 3: Start BFS to explore all possible multiplication paths.
    while (!q.empty())
    {
      int node = q.front().first;   // The current number being processed.
      int steps = q.front().second; // The number of steps taken to reach this number.
      q.pop();

      // Step 4: Try multiplying the current number by each multiplier in the array.
      for (auto it : arr)
      {
        int num = (it * node) % mod; // Calculate the new number after multiplication, keeping it within the mod range.

        // Step 5: If the new number can be reached in fewer steps, update the distance array and continue exploring from this number.
        if (steps + 1 < dist[num])
        {
          dist[num] = steps + 1; // Update the minimum steps to reach 'num'.

          // If the new number is the target 'end' number, return the steps taken to reach it.
          if (num == end)
            return steps + 1;

          // Otherwise, push the new number and updated steps to the queue for further exploration.
          q.push({num, steps + 1});
        }
      }
    }

    // Step 6: If the 'end' number cannot be reached, return -1 to indicate no valid sequence of multiplications exists.
    return -1;
  }
};
