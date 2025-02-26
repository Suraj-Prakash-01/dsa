class Solution
{
private:
  void solve(Node *root, vector<vector<int>> &ans, vector<int> &arr)
  {
    // Base case: if the current node is null, return
    if (!root)
      return;

    // Add the current node's data to the current path
    arr.push_back(root->data);

    // Check if the current node is a leaf node
    if (root->left == NULL && root->right == NULL)
    {
      // If it's a leaf, add the current path to the answer
      ans.push_back(arr);
    }
    else
    {
      // Recur for the left subtree
      solve(root->left, ans, arr);
      // Recur for the right subtree
      solve(root->right, ans, arr);
    }

    // Backtrack: remove the current node's data from the path
    arr.pop_back();
  }

public:
  // Public function to initiate the path finding process
  vector<vector<int>> Paths(Node *root)
  {
    // Vector to store all the paths
    vector<vector<int>> ans;
    // Vector to store the current path
    vector<int> arr;
    // Start the recursive function
    solve(root, ans, arr);
    // Return all paths found
    return ans;
  }
};
