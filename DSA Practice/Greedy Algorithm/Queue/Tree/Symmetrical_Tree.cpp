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
  bool isSymmetric(TreeNode *root)
  {
    return root == NULL || isSym(root->left, root->right);
  }

  bool isSym(TreeNode *left, TreeNode *right)
  {
    if (left == NULL || right == NULL)
      return left == right;

    // If the left value and the right values are not same
    if (left->val != right->val)
      return false;

    // Traversing both at the same time
    return isSym(left->left, right->right) && isSym(left->right, right->left);
  }
};