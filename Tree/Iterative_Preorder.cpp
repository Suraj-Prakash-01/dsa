#include <iostream>
#include <vector>
#include <stack>
using std::cin;
using std::cout;

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

Node *BuildTree(Node *root)
{
  cout << "Enter the data: " << std::endl;
  int data;
  cin >> data;
  root = new Node(data);

  if (data == -1)
    return NULL;

  cout << "Enter data for inserting left of " << data << std::endl;
  root->left = BuildTree(root->left);

  cout << "Enter data for inserting right of" << data << std::endl;
  root->right = BuildTree(root->right);

  return root;
}

void preorder_Traversal(Node *root, std::vector<int> &preorder)
{
  if (root == NULL)
    return;

  std::stack<Node *> st;
  st.push(root);

  while (!st.empty())
  {
    root = st.top();
    st.pop();

    preorder.push_back(root->data);

    if (root->right != NULL)
      st.push(root->right);
    if (root->left != NULL)
      st.push(root->left);
  }
}

int main()
{
  Node *root = NULL;
  std::vector<int> preorder;

  // To create a tree
  root = BuildTree(root);
  preorder_Traversal(root, preorder);

  for (int i = 0; i < preorder.size(); i++)
  {
    cout << preorder[i] << " ";
  }
  cout << std::endl;
}