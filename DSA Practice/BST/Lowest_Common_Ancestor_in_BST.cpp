/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;  // value of the node
 *     TreeNode *left;  // left child of the node
 *     TreeNode *right;  // right child of the node
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}  // constructor to initialize the node
 * };
 */

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    // base case: if the root is NULL, return NULL
    if (root == NULL)
      return NULL;

    // get the current node's value
    int curr = root->val;

    // if the current node's value is less than both p's and q's values, move right
    if (curr < p->val && curr < q->val)
      return lowestCommonAncestor(root->right, p, q);

    // if the current node's value is greater than both p's and q's values, move left
    if (curr > p->val && curr > q->val)
      return lowestCommonAncestor(root->left, p, q);

    // if the current node's value is between p's and q's values, it is the lowest common ancestor
    return root;
  }
};