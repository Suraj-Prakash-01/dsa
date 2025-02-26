// Define a Solution class to solve the problem
class Solution
{
public:
  // Function to find the maximum distance from the target node to any other node in the tree
  int findMaxDistance(std::map<Node *, Node *> &mpp, Node *target)
  {
    // Create a queue to store nodes to be processed
    std::queue<Node *> q;
    // Create a map to store the distance from the target node to each node
    std::map<Node *, int> dist;
    // Push the target node into the queue
    q.push(target);
    // Set the distance from the target node to itself as 0
    dist[target] = 0;

    // Initialize the maximum distance
    int maxi = 0;

    // Process nodes in the queue
    while (!q.empty())
    {
      // Get the front node from the queue
      Node *node = q.front();
      // Remove the front node from the queue
      q.pop();

      // Update the maximum distance
      maxi = std::max(maxi, dist[node]);

      // Check the left child
      if (node->left && dist.find(node->left) == dist.end())
      {
        // Set the distance from the target node to the left child
        dist[node->left] = dist[node] + 1;
        // Push the left child into the queue
        q.push(node->left);
      }

      // Check the right child
      if (node->right && dist.find(node->right) == dist.end())
      {
        // Set the distance from the target node to the right child
        dist[node->right] = dist[node] + 1;
        // Push the right child into the queue
        q.push(node->right);
      }

      // Check the parent node
      if (mpp[node] && dist.find(mpp[node]) == dist.end())
      {
        // Set the distance from the target node to the parent node
        dist[mpp[node]] = dist[node] + 1;
        // Push the parent node into the queue
        q.push(mpp[node]);
      }
    }

    // Return the maximum distance
    return maxi;
  }

  // Function to perform BFS to map parents of each node and find the target node
  Node *bfsToMapParents(Node *root, std::map<Node *, Node *> &mpp, int start)
  {
    // Create a queue to store nodes to be processed
    std::queue<Node *> q;
    // Push the root node into the queue
    q.push(root);
    // Initialize the target node
    Node *targetNode = nullptr;

    // Process nodes in the queue
    while (!q.empty())
    {
      // Get the front node from the queue
      Node *node = q.front();
      // Remove the front node from the queue
      q.pop();

      // Check if the current node is the target node
      if (node->data == start)
      {
        // Set the target node
        targetNode = node;
      }

      // Check the left child
      if (node->left)
      {
        // Set the parent of the left child
        mpp[node->left] = node;
        // Push the left child into the queue
        q.push(node->left);
      }

      // Check the right child
      if (node->right)
      {
        // Set the parent of the right child
        mpp[node->right] = node;
        // Push the right child into the queue
        q.push(node->right);
      }
    }

    // Return the target node
    return targetNode;
  }

  // Function to find the minimum time required to burn the binary tree
  int minTime(Node *root, int target)
  {
    // Create a map to store the parent of each node
    std::map<Node *, Node *> mpp;
    // Find the target node and map parents of each node
    Node *targetNode = bfsToMapParents(root, mpp, target);
    // Find the maximum distance from the target node to any other node
    return findMaxDistance(mpp, targetNode);
  }
};
