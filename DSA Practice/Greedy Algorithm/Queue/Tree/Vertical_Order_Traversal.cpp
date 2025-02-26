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
  /**
   * Vertical Order Traversal of a Binary Tree
   *
   * This function takes the root of a binary tree as input and returns a vector of vectors,
   * where each inner vector represents the nodes' values in a vertical order.
   */

  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    // Create a map to store the nodes' values, where the key is the x-coordinate and the value is a map of y-coordinates to node values
    map<int, map<int, multiset<int>>> nodes;

    // Create a queue to store the nodes to be processed, along with their x and y coordinates
    queue<pair<TreeNode *, pair<int, int>>> todo;

    // Initialize the queue with the root node and its coordinates (0, 0)
    todo.push({root, {0, 0}});

    // Process the nodes in the queue
    while (!todo.empty())
    {
      // Get the next node and its coordinates from the queue
      auto p = todo.front();
      todo.pop();
      TreeNode *node = p.first;
      int x = p.second.first, y = p.second.second;

      // Insert the node's value into the corresponding position in the nodes map
      nodes[x][y].insert(node->val);

      // Add the node's left and right children to the queue with their updated coordinates
      if (node->left)
      {
        todo.push({node->left, {x - 1, y + 1}});
      }
      if (node->right)
      {
        todo.push({node->right, {x + 1, y + 1}});
      }
    }

    // Create a vector to store the result
    vector<vector<int>> ans;

    // Iterate over the nodes map and construct the result vector
    for (auto p : nodes)
    {
      // Create a vector to store the nodes' values in a vertical order
      vector<int> col;

      // Iterate over the y-coordinates and concatenate the node values into a single vector
      for (auto q : p.second)
      {
        col.insert(col.end(), q.second.begin(), q.second.end());
      }

      // Add the resulting vector to the result vector
      ans.push_back(col);
    }

    // Return the result vector
    return ans;
  }
};