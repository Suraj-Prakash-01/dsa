#include <iostream>
#include <vector>
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

// Function to check leaf node
bool isLeaf(Node *root)
{
  if (root->left == NULL && root->right == NULL)
    return true;
  return false;
}

// Function to store left boundary of the tree
void addLeft(Node *root, std::vector<int> &res)
{
  Node *curr = root->left; // Pointer

  while (curr)
  {
    // Pushing data into the ultimate array
    if (!isLeaf(curr))
      res.push_back(curr->data);

    // If the left node exist, we will keep on going for that
    if (curr->left)
      curr = curr->left;
    // If not, we will go for right node
    else
      curr = curr->right;
  }
}

// Using preorder traversal to find leaves in order
void addLeaves(Node *root, std::vector<int> &res)
{
  if (root == NULL)
    return;
  if (isLeaf(root))
  {
    res.push_back(root->data);
    return;
  }

  addLeaves(root->left, res);
  addLeaves(root->right, res);
}

// To add the right leaves of the tree for boundary traversal
void addRight(Node *root, std::vector<int> &res)
{
  Node *curr = root->right;
  std::vector<int> temp;

  while (curr)
  {
    if (!isLeaf(curr))
      temp.push_back(curr->data);

    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }

  for (int i = temp.size() - 1; i >= 0; i--)
  {
    res.push_back(temp[i]);
  }
}

void Boundary_Traversal(Node *root, std::vector<int> &res)
{
  if (root == NULL)
    return;
  if (!isLeaf(root))
    res.push_back(root->data);

  addLeft(root, res);
  addLeaves(root, res);
  addRight(root, res);
}

int main()
{
  Node *root = NULL;
  std::vector<int> res;

  // Creating a Tree
  root = buildTree(root);
  Boundary_Traversal(root, res);

  cout << "The boundary Traversal is: ";
  // Printing the result of boundary traversal
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}

// Input ->  1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 8 -1 -1 -1
