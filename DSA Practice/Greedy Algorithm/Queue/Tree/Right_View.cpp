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
private:
  void right(TreeNode *root, int level, vector<int> &ds)
  {
    if (root == NULL)
      return;
    // If size is equal that means that level is not included yet as level starts from 0 not 1
    if (level == ds.size())
      ds.push_back(root->val);

    // To make it left view, just traverse left then right
    right(root->right, level + 1, ds);
    right(root->left, level + 1, ds);
  }

public:
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> ds;
    right(root, 0, ds);
    return ds;
  }
};