/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    // Base Case
    if (root == NULL || root == p || root == q)
      return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL)
      return right;
    else if (right == NULL)
      return left;

    // Both left and right are not NULL
    else
      return root;
  }
};

/* Another way could be to find the path from root to that particular node
  We will get 2 paths this way and then we start comparing it from the beginning of the array of paths
  And find the last common path for both of them and return it
*/