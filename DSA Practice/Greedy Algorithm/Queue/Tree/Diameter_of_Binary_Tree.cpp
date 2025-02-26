#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;

// Class to define a tree node
class Node
{
public:
  int data;    // Data stored in the node
  Node *left;  // Pointer to the left child node
  Node *right; // Pointer to the right child node

  // Constructor to initialize a node with given data
  Node(int data)
  {
    this->data = data;
    this->left = NULL;  // Initialize left child as NULL
    this->right = NULL; // Initialize right child as NULL
  }
};

// Function to build a tree recursively
Node *buildTree(Node *root)
{
  cout << "Enter the data: " << std::endl;
  int data;
  cin >> data;
  root = new Node(data);

  // Base case: If data is -1, return NULL to indicate no node
  if (data == -1)
    return NULL;

  // Recursively build the left subtree
  cout << "Enter data for inserting in left of " << data << std::endl;
  root->left = buildTree(root->left);

  // Recursively build the right subtree
  cout << "Enter data for inserting in right of " << data << std::endl;
  root->right = buildTree(root->right);

  return root;
}

// Function to calculate the height of a tree
int height(Node *root, int &diameter)
{
  // Base case: If the tree is empty, height is 0
  if (root == NULL)
    return 0;

  // Recursively calculate the height of the left and right subtrees
  int lh = height(root->left, diameter);
  int rh = height(root->right, diameter);

  diameter = std::max(diameter, lh + rh);

  // Return the maximum height of the subtrees plus 1
  return 1 + std::max(lh, rh);
}

int main()
{
  Node *root = NULL; // Initialize the root node as NULL
  int diameter = 0;

  // Create a tree by recursively building the left and right subtrees
  root = buildTree(root);

  height(root, diameter);
  cout << "Diameter of the tree is " << diameter << std::endl;
}