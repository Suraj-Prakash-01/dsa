#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;

// Class to define a tree
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

// Function to build a tree
Node *buildTree(Node *root)
{
  cout << "Enter the data: " << std::endl;
  int data;
  cin >> data;
  root = new Node(data);

  if (data == -1)
    return NULL;

  // Calling the function recursively to keep on creating left and right element of the tree
  cout << "Enter data for inserting in left of " << data << std::endl;
  root->left = buildTree(root->left);

  cout << "Enter data for inserting in right of " << data << std::endl;
  root->right = buildTree(root->right);

  return root;
}

void zigzag(Node *root, std::vector<std::vector<int>> &ans)
{
  // Base Case
  if (root == NULL)
    return;

  std::queue<Node *> q;
  q.push(root);

  // Flag 0 means usual level order i.e., left to right
  bool flag = 0;

  while (!q.empty())
  {
    int n = q.size();
    std::vector<int> row(n);
    for (int i = 0; i < n; i++)
    {
      Node *node = q.front();
      q.pop();

      // Find position to fill the node's value
      // It means if flag is true, nodes will be filled from left to right i.e., from the first index
      // And if the flag is false, that means array will be filled from right to left i.e., from the last index
      int index = (flag) ? i : (n - i - 1);

      row[index] = node->data;
      if (node->left)
        q.push(node->left);

      if (node->right)
        q.push(node->right);
    }

    // After this level
    flag = !flag;
    ans.push_back(row);
  }
}

int main()
{
  Node *root = NULL;
  std::vector<std::vector<int>> ans;

  // Creating a Tree
  root = buildTree(root);
  zigzag(root, ans);

  // Printing the zig zag result
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << std::endl;
  }
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 8 -1 -1 -1
