#include <iostream>
#include <vector>
#include <stack>
using std::cin;
using std::cout;

// Node class represents a node in the binary tree
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  // Constructor to initialize a node with given data
  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

// Function to build a binary tree
Node *BuildTree(Node *root)
{
  // Prompt user to enter data for the current node
  cout << "Enter the data: " << std::endl;
  int data;
  cin >> data;
  root = new Node(data);

  // If data is -1, return NULL to indicate no node
  if (data == -1)
    return NULL;

  // Recursively build the left and right subtrees
  cout << "Enter data for inserting left of " << data << std::endl;
  root->left = BuildTree(root->left);

  cout << "Enter data for inserting right of" << data << std::endl;
  root->right = BuildTree(root->right);

  return root;
}

// Function to perform postorder traversal of the binary tree
void postorder_Traversal(Node *root, std::vector<int> &postorder)
{
  // Base case: if the tree is empty, return
  if (root == NULL)
    return;

  // Use two stacks to perform postorder traversal
  std::stack<Node *> st1, st2;
  st1.push(root);

  // First, push nodes to st1 and their children to st2
  while (!st1.empty())
  {
    root = st1.top();
    st1.pop();
    st2.push(root);

    if (root->left != NULL)
    {
      st1.push(root->left);
    }

    if (root->right != NULL)
    {
      st1.push(root->right);
    }
  }

  // Then, pop nodes from st2 and add their data to the postorder vector
  while (!st2.empty())
  {
    root = st2.top();
    st2.pop();
    postorder.push_back(root->data);
  }
}

int main()
{
  Node *root = NULL;
  std::vector<int> postorder;

  // Create a binary tree
  root = BuildTree(root);

  // Perform postorder traversal and store the result in the postorder vector
  postorder_Traversal(root, postorder);

  // Print the postorder traversal result
  for (int i = 0; i < postorder.size(); i++)
  {
    cout << postorder[i] << " ";
  }
  cout << std::endl;
}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 7 -1 8 -1 -1 -1