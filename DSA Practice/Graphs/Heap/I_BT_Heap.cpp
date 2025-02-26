class Solution
{
public:
  // Function to count the number of nodes in the binary tree
  int countNode(struct Node *root)
  {
    if (root == NULL)
      return 0;
    return 1 + countNode(root->left) + countNode(root->right);
  }

  // Function to check if a binary tree is a complete binary tree
  bool isCBT(struct Node *root, int index, int cnt)
  {
    if (root == NULL)
      return true;
    if (index >= cnt)
      return false;
    return isCBT(root->left, 2 * index + 1, cnt) && isCBT(root->right, 2 * index + 2, cnt);
  }

  // Function to check if a binary tree satisfies the max-heap property
  bool isMaxOrder(struct Node *root)
  {
    if (root == NULL)
      return true;
    if (root->left == NULL && root->right == NULL)
      return true;
    if (root->right == NULL)
      return root->data > root->left->data;

    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);

    bool current = (root->left != NULL ? root->data > root->left->data : true) && (root->right != NULL ? root->data > root->right->data : true);

    return left && right && current;
  }

  // Function to check if a binary tree is a heap
  bool isHeap(struct Node *tree)
  {
    int index = 0;
    int totalCount = countNode(tree);
    return isCBT(tree, index, totalCount) && isMaxOrder(tree);
  }
};
