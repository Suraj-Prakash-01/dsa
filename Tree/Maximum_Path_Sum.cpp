#include <iostream>
#include <algorithm>
#include <limits.h>
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

int maximum_path_sum(Node *root, int &maxi)
{
  // Base Case
  if (root == NULL)
    return 0;

  // Traversing left and right side of the tree
  // We are introducing max value in this so that we can avoid any negative numbers
  int left = std::max(0, maximum_path_sum(root->left, maxi));
  int right = std::max(0, maximum_path_sum(root->right, maxi));

  // Updating maxi after getting left and right element
  maxi = std::max(maxi, left + right + root->data);

  // Returning the value after selecting the path giving maximum values
  return root->data + std::max(left, right);
}

int main()
{
  Node *root = NULL;
  int maxi = INT_MIN;

  // Creating a Tree
  root = buildTree(root);
  maximum_path_sum(root, maxi);
  cout << "The maximum path sum in the given tree is: " << maxi << std::endl;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 8 -1 -1 -1
