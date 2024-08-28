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

/**
 * Solution class for validating Binary Search Trees (BSTs)
 */
class Solution
{
public:
  /**
   * Checks if a given binary tree is a valid Binary Search Tree (BST)
   *
   * @param root the root node of the binary tree
   * @return true if the tree is a valid BST, false otherwise
   */
  bool isValidBST(TreeNode *root)
  {
    /**
     * Call the recursive helper function with initial min and max values
     * set to the minimum and maximum possible integer values
     */
    return isValidBST(root, LONG_MIN, LONG_MAX);
  }

  /**
   * Recursive helper function to validate a BST
   *
   * @param root the current node being validated
   * @param minVal the minimum allowed value for the current node
   * @param maxVal the maximum allowed value for the current node
   * @return true if the subtree rooted at `root` is a valid BST, false otherwise
   */
  bool isValidBST(TreeNode *root, long minVal, long maxVal)
  {
    /**
     * Base case: an empty tree is a valid BST
     */
    if (root == nullptr)
      return true;

    /**
     * Check if the current node's value is within the allowed range
     */
    if (root->val <= minVal || root->val >= maxVal)
      return false;

    /**
     * Recursively validate the left and right subtrees
     */
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
  }
};

/**
 * Example usage:
 *
 * Given the following binary tree:
 *
 *      2
 *     / \
 *    1   3
 *
 * The `isValidBST` function would return `true`, since the tree is a valid BST.
 *
 * However, given the following binary tree:
 *
 *      2
 *     / \
 *    3   1
 *
 * The `isValidBST` function would return `false`, since the tree is not a valid BST.
 */