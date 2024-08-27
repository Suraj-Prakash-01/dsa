// This is a class definition for a solution to a problem
class Solution
{
public:
  // This function builds a binary tree from given inorder and postorder traversals
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    // Check if the sizes of the input vectors are equal
    if (inorder.size() != postorder.size())
      // If not, return NULL (i.e., no tree can be built)
      return NULL;

    // Create a hashmap to store the indices of elements in the inorder vector
    map<int, int> hm;

    // Iterate over the inorder vector and store the indices of each element in the hashmap
    for (int i = 0; i < inorder.size(); ++i)
    {
      // Store the index of the current element in the hashmap
      hm[inorder[i]] = i;
    }

    // Call the buildTreePostIn function to construct the binary tree
    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
  }

  // This function recursively constructs the binary tree from the inorder and postorder traversals
  TreeNode *buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &hm)
  {
    // Check if the postorder indices are out of range or if the inorder indices are out of range
    if (ps > pe || is > ie)
      // If so, return NULL (i.e., no subtree can be built)
      return NULL;

    // Create a new TreeNode with the value of the current postorder element
    TreeNode *root = new TreeNode(postorder[pe]);

    // Find the index of the current postorder element in the inorder vector
    int inRoot = hm[postorder[pe]];

    // Calculate the number of elements in the left subtree
    int numsLeft = inRoot - is;

    // Recursively construct the left subtree
    root->left = buildTreePostIn(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hm);

    // Recursively construct the right subtree
    root->right = buildTreePostIn(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);

    // Return the constructed root node
    return root;
  }
};