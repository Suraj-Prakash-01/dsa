/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; // The value of the node
 *     TreeNode *left; // Pointer to the left child node
 *     TreeNode *right; // Pointer to the right child node
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor with value and child nodes
 * };
 */
class Solution
{
public:
  // Function to build a binary tree from preorder and inorder traversal sequences
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    // Create an unordered map to store the indices of inorder traversal sequence
    unordered_map<int, int> inMap;

    // Iterate through the inorder traversal sequence and store the indices in the map
    for (int i = 0; i < inorder.size(); i++)
    {
      // Map the value to its index in the inorder traversal sequence
      inMap[inorder[i]] = i;
    }

    // Call the recursive buildTree function with the initial indices
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
  }

private:
  // Recursive function to build a binary tree from preorder and inorder traversal sequences
  TreeNode *buildTree(const vector<int> &preorder, int preStart, int preEnd, const vector<int> &inorder, int inStart, int inEnd, const unordered_map<int, int> &inMap)
  {
    // Base case: if the preorder or inorder indices are out of range, return nullptr
    if (preStart > preEnd || inStart > inEnd)
    {
      return nullptr;
    }

    // Create a new TreeNode with the value from the preorder traversal sequence
    TreeNode *root = new TreeNode(preorder[preStart]);

    // Find the index of the root node in the inorder traversal sequence
    int inRoot = inMap.at(root->val);

    // Calculate the number of nodes in the left subtree
    int numsLeft = inRoot - inStart;

    // Recursively build the left subtree
    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);

    // Recursively build the right subtree
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    // Return the root node of the constructed binary tree
    return root;
  }
};