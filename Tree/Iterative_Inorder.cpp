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

  // If data is -1, consider it as NULL and return
  if (data == -1)
    return NULL;

  // Recursively build the left and right subtrees
  cout << "Enter data for inserting left of " << data << std::endl;
  root->left = BuildTree(root->left);

  cout << "Enter data for inserting right of" << data << std::endl;
  root->right = BuildTree(root->right);

  return root;
}

// Function to perform inorder traversal of the binary tree
void inorder_Traversal(Node *root, std::vector<int> &inorder)
{
  // Use a stack to store nodes for traversal
  std::stack<Node *> st;
  Node *temp = root;

  while (true)
  {
    // Move to the leftmost node and push nodes to the stack
    if (temp != NULL)
    {
      st.push(temp);
      temp = temp->left;
    }

    else
    {
      // If the stack is empty, traversal is complete
      if (st.empty())
        break;

      // Pop a node from the stack, add its data to the inorder vector, and move to its right child
      temp = st.top();
      st.pop();
      inorder.push_back(temp->data);
      temp = temp->right;
    }
  }
}

int main()
{
  Node *root = NULL;
  std::vector<int> inorder;

  // Create a binary tree
  root = BuildTree(root);

  // Perform inorder traversal and store the result in the inorder vector
  inorder_Traversal(root, inorder);

  // Print the inorder traversal result
  for (int i = 0; i < inorder.size(); i++)
  {
    cout << inorder[i] << " ";
  }
  cout << std::endl;
}
