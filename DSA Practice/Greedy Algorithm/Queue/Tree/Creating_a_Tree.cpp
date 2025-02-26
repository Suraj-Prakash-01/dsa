#include <iostream>
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

// Code for preorder traversal
void preorder(Node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

int main()
{
  Node *root = NULL;

  // Creating a Tree
  root = buildTree(root);
  preorder(root);
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 8 -1 -1 -1
