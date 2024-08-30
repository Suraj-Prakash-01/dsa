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
  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    // Initialize an index variable i to 0, which will be used to traverse the preorder sequence
    int i = 0;
    // Call the build function to start constructing the binary search tree, passing the preorder sequence, index i, and a bound of INT_MAX
    return build(preorder, i, INT_MAX);
  }

  // Recursive function to build the binary search tree from the preorder traversal sequence
  TreeNode *build(vector<int> &A, int &i, int bound)
  {
    // Base case: if the index i has reached the end of the preorder sequence or the current element exceeds the bound, return NULL
    if (i == A.size() || A[i] > bound)
      return NULL;

    // Create a new TreeNode with the current element's value and increment the index i
    TreeNode *root = new TreeNode(A[i++]);

    // Recursively build the left subtree by calling build with the updated index i and a bound equal to the current node's value
    root->left = build(A, i, root->val);

    // Recursively build the right subtree by calling build with the updated index i and the original bound
    root->right = build(A, i, bound);

    // Return the root node of the current subtree
    return root;
  }
};