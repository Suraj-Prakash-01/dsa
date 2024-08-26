/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  // Function to mark the parent of each node in the binary tree
  void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track)
  {
    // Create a queue to store nodes to be processed
    queue<TreeNode *> queue;
    // Push the root node into the queue
    queue.push(root);
    // Continue processing nodes until the queue is empty
    while (!queue.empty())
    {
      // Get the front node from the queue
      TreeNode *current = queue.front();
      // Remove the front node from the queue
      queue.pop();
      // If the current node has a left child
      if (current->left)
      {
        // Mark the parent of the left child as the current node
        parent_track[current->left] = current;
        // Push the left child into the queue
        queue.push(current->left);
      }
      // If the current node has a right child
      if (current->right)
      {
        // Mark the parent of the right child as the current node
        parent_track[current->right] = current;
        // Push the right child into the queue
        queue.push(current->right);
      }
    }
  }

  // Function to find all nodes at a distance of k from the target node
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
  {
    // Create a map to store the parent of each node
    unordered_map<TreeNode *, TreeNode *> parent_track;
    // Mark the parent of each node in the binary tree
    markParents(root, parent_track);

    // Create a map to keep track of visited nodes
    unordered_map<TreeNode *, bool> visited;
    // Create a queue to store nodes to be processed
    queue<TreeNode *> queue;
    // Push the target node into the queue
    queue.push(target);
    // Mark the target node as visited
    visited[target] = true;
    // Initialize the current level to 0
    int curr_lvl = 0;

    // Continue processing nodes until the queue is empty
    while (!queue.empty())
    {
      // Get the size of the queue
      int size = queue.size();
      // If the current level is equal to k, break the loop
      if (curr_lvl++ == k)
        break;

      // Process each node in the queue
      for (int i = 0; i < size; i++)
      {
        // Get the front node from the queue
        TreeNode *current = queue.front();
        // Remove the front node from the queue
        queue.pop();
        // If the current node has a left child and it has not been visited
        if (current->left && !visited[current->left])
        {
          // Push the left child into the queue
          queue.push(current->left);
          // Mark the left child as visited
          visited[current->left] = true;
        }

        // If the current node has a right child and it has not been visited
        if (current->right && !visited[current->right])
        {
          // Push the right child into the queue
          queue.push(current->right);
          // Mark the right child as visited
          visited[current->right] = true;
        }

        // If the parent of the current node exists and it has not been visited
        if (parent_track.count(current) && !visited[parent_track[current]])
        {
          // Push the parent of the current node into the queue
          queue.push(parent_track[current]);
          // Mark the parent of the current node as visited
          visited[parent_track[current]] = true;
        }
      }
    }

    // Create a vector to store the result
    vector<int> result;
    // Process each node in the queue
    while (!queue.empty())
    {
      // Get the front node from the queue
      TreeNode *current = queue.front();
      // Remove the front node from the queue
      queue.pop();
      // Add the value of the current node to the result
      result.push_back(current->val);
    }
    // Return the result
    return result;
  }
};