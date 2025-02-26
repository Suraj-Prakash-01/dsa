/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
  // Function to return a list of nodes visible from the top view
  // from left to right in Binary Tree.
  vector<int> topView(Node *root)
  {
    // array to hold the final top view of the binary tree
    vector<int> ans;

    // Covering the edge case
    if (root == NULL)
      return ans;

    // To hold the <line,value> of the tree and we chose map to arrange the lines itself
    map<int, int> mpp;

    // To hold the address of the <address,line> of the tree
    queue<pair<Node *, int>> q;

    // Pushing the first element
    q.push({root, 0});

    while (!q.empty())
    {
      auto it = q.front();
      q.pop();

      Node *node = it.first;
      int line = it.second;

      // mpp.end() is the iterator returned if the line is not found in the map
      if (mpp.find(line) == mpp.end())
        mpp[line] = node->data;

      // For defining line of the tree
      if (node->left != NULL)
        q.push({node->left, line - 1});
      if (node->right != NULL)
        q.push({node->right, line + 1});
    }

    // Finally traversing the map to get the elements in the array
    for (auto it : mpp)
      ans.push_back(it.second);

    return ans;
  }
};