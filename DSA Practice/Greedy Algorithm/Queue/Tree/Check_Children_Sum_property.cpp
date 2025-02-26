/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
  // Function to check whether all nodes of a tree have the value
  // equal to the sum of their child nodes.
  int isSumProperty(Node *root)
  {
    // Base case: if the node is null, return true (considered as 0)
    if (!root)
      return true;

    // If it's a leaf node, return true
    if (!root->left && !root->right)
      return true;

    // Get the values of left and right children
    int leftSum = root->left ? root->left->data : 0;
    int rightSum = root->right ? root->right->data : 0;

    // Check the current node's data against the sum of its children
    if (root->data != leftSum + rightSum)
      return false;

    // Recur for left and right subtrees
    return isSumProperty(root->left) && isSumProperty(root->right);
  }
};