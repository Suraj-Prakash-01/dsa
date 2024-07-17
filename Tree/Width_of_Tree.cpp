/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    if (!root)
      return 0;                     // If the tree is empty, the width is 0.
    int ans = 0;                    // To store the maximum width.
    queue<pair<TreeNode *, int>> q; // Queue for BFS, storing nodes and their indices.
    q.push({root, 0});              // Start with the root node at index 0.

    while (!q.empty())
    {
      int size = q.size();         // Number of nodes at the current level.
      int mmin = q.front().second; // Minimum index at the current level.
      int first, last;             // Variables to track the first and last indices at this level.
      for (int i = 0; i < size; i++)
      {
        int cur_id = q.front().second - mmin; // Normalize the index.
        TreeNode *node = q.front().first;     // Get the current node.
        q.pop();                              // Remove the node from the queue.

        if (i == 0)
          first = cur_id; // Track the first index.
        if (i == size - 1)
          last = cur_id; // Track the last index.

        // Add left and right children to the queue with updated indices.
        if (node->left)
          q.push({node->left, cur_id * 2 + 1});
        if (node->right)
          q.push({node->right, cur_id * 2 + 2});
      }
      ans = max(ans, last - first + 1);
    }
    return ans;
  }
};