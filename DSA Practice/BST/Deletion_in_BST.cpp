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
 *
 **/

class Solution
{
public:
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    // If the tree is empty, return NULL
    if (root == NULL)
      return NULL;

    // If the root node is the node to be deleted, call the helper function
    if (root->val == key)
      return helper(root);

    // Initialize a dummy node to keep track of the current node
    TreeNode *dummy = root;
    while (root != NULL)
    {
      // If the current node's value is greater than the key, move to the left subtree
      if (root->val > key)
      {
        // If the left child node is the node to be deleted, call the helper function
        if (root->left != NULL && root->left->val == key)
        {
          root->left = helper(root->left);
          break;
        }
        else
          root = root->left;
      }
      else
      {
        // If the current node's value is less than or equal to the key, move to the right subtree
        if (root->right != NULL && root->right->val == key)
        {
          root->right = helper(root->right);
          break;
        }
        else
        {
          root = root->right;
        }
      }
    }
    // Return the modified root node
    return dummy;
  }

  TreeNode *helper(TreeNode *root)
  {
    // If the node to be deleted has no left child, return its right child
    if (root->left == NULL)
    {
      return root->right;
    }
    // If the node to be deleted has no right child, return its left child
    else if (root->right == NULL)
      return root->left;

    // If the node to be deleted has both left and right children, find the last right node in the left subtree
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    // Replace the right child of the last right node with the right child of the node to be deleted
    lastRight->right = rightChild;
    // Return the left child of the node to be deleted
    return root->left;
  }

  TreeNode *findLastRight(TreeNode *root)
  {
    // If the current node has no right child, return the current node
    if (root->right == NULL)
      return root;
    // If the current node has a right child, recursively call the function on the right child
    return findLastRight(root->right);
  }
}