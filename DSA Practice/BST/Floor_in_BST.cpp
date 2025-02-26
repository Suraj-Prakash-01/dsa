class Solution
{

public:
  int floor(Node *root, int x)
  {
    // Code here
    int f = -1;
    while (root)
    {
      if (root->data == x)
      {
        f = root->data;
        return f;
      }

      if (x > root->data)
      {
        f = root->data;
        root = root->right;
      }
      else
      {
        root = root->left;
      }
    }
    return f;
  }
};