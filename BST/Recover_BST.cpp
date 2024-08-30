/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; // value of the node
 *     TreeNode *left; // left child node
 *     TreeNode *right; // right child node
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // constructor with value and children
 * };
 */

class Solution
{
  // Pointer to the first node that is out of order
  TreeNode *first;

  // Pointer to the previous node in the inorder traversal
  TreeNode *prev;

  // Pointer to the middle node that is out of order (if there are two swaps)
  TreeNode *middle;

  // Pointer to the last node that is out of order
  TreeNode *last;

public:
  /**
   * Performs an inorder traversal of the binary tree and detects nodes that are out of order.
   *
   * @param root The root of the binary tree.
   */
  void inorder(TreeNode *root)
  {
    // Base case: if the root is NULL, return
    if (root == NULL)
      return;

    // Recursively traverse the left subtree
    inorder(root->left);

    // Check if the current node is out of order with the previous node
    if (prev != NULL && (root->val < prev->val))
    {
      // If this is the first out-of-order node, set first and middle
      if (first == NULL)
      {
        first = prev;
        middle = root;
      }
      // If this is the second out-of-order node, set last
      else
        last = root;
    }

    // Update the previous node
    prev = root;

    // Recursively traverse the right subtree
    inorder(root->right);
  }

  /**
   * Recovers a corrupted binary search tree by swapping the values of the nodes that are out of order.
   *
   * @param root The root of the corrupted binary tree.
   *
   * Example:
   * Input: [3, 1, 4, null, null, 2]
   * Output: [2, 1, 4, null, null, 3]
   */
  void recoverTree(TreeNode *root)
  {
    // Initialize the pointers to NULL
    first = middle = last = NULL;

    // Create a new TreeNode with minimum value as the previous node
    prev = new TreeNode(INT_MIN);

    // Perform the inorder traversal to detect out-of-order nodes
    inorder(root);

    // Swap the values of the out-of-order nodes
    if (first && last)
      swap(first->val, last->val);
    else if (first && middle)
      swap(first->val, middle->val);
  }
};